"""Read and write Hydro Thunder Hurricane .apf asset archives.

    python ht_apf.py list <archive.apf>
    python ht_apf.py pack <folder> <archive.apf>
    python ht_apf.py json2db <file.json> <file.bin>     (and db2json)

Format (AKPF version 5), every integer big-endian:

    header   'AKPF', u32 version = 5, u32 toc_offset, u32 entry_count,
             u32 a, u32 b             (Base.apf has 0, 55; Pack01.apf 16, 1015)
    data     the entries, back to back from offset 24
    toc      per entry: u32 name_len, name ("AssetType/Path"), then
             u32 offset, u32 size, u32 packed_size, u32 kind, u32 crc, u32 flags
             kind  = a per-asset-type format version (KINDS below)
             crc   = zlib CRC-32 of the *unpacked* data (0 for Assets/ entries)
             flags = 1 on every entry of both shipped archives
    The TOC is read into a map by name (sub_82162D98), so its order is free.

Each entry is XMemCompress output: a sequence of frames, one per 32 KB of
unpacked data, each `u16 packed` (a full 0x8000 frame) or `FF, u16 size,
u16 packed`, followed by an LZX bitstream. We never compress. Every frame is
a single LZX *uncompressed* block - the game's own tools wrote its smallest
entries the same way (Assets/AkGenericAsset is exactly what pack_entry emits),
so no LZX encoder is needed.

`pack` takes a folder laid out like the archive: <folder>/<AssetType>/<Path>.
A `.json` file is converted to the asset's AKJB form first (DB, project and
index assets); any other file is stored as is.
"""
import os
import struct
import sys
import zlib

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
import ht_save_edit as akjb  # noqa: E402  (the save format is the same AKJB tree)

FRAME = 0x8000

# Format version per asset type, as recorded in Base.apf and Pack01.apf.
KINDS = {
    "Assets": 0, "AkAudioEventAsset": 1, "AkTemplateAsset": 2, "AkTimedEventAsset": 2,
    "AkDBAsset": 4, "AkProjectAsset": 4, "AkCubeTextureAsset": 4, "AkLoadingSequenceAsset": 4,
    "AkShaderAsset": 4, "AkPfxAsset": 4, "AkFluidsMeshAsset": 5, "AkFontAsset": 5,
    "AkAnimationAsset": 6, "AkTextureAsset": 8, "AkCollisionMeshAsset": 12,
    "AkAnimatedModelAsset": 15, "AkStaticModelAsset": 19, "AkGenericAsset": 0,
}

# How many u32 size words precede the AKJB tree, per asset type.
JSON_PREFIX = {"Assets": 0, "AkGenericAsset": 0, "AkDBAsset": 1}


def read_toc(path):
    """Return (header_tail, [(name, offset, size, packed, kind, crc, flags)])."""
    with open(path, "rb") as f:
        magic, version, toc, count, a, b = struct.unpack(">4sIIIII", f.read(24))
        if magic != b"AKPF" or version != 5:
            raise ValueError("%s is not an AKPF v5 archive" % path)
        f.seek(toc)
        t = f.read()
    entries, o = [], 0
    for _ in range(count):
        n = struct.unpack_from(">I", t, o)[0]
        name = t[o + 4:o + 4 + n].decode("latin-1")
        o += 4 + n
        entries.append((name,) + struct.unpack_from(">6I", t, o))
        o += 24
    return (a, b), entries


def pack_entry(data):
    """XMemCompress-framed LZX stream of uncompressed blocks, one per frame."""
    out = bytearray()
    for i, pos in enumerate(range(0, max(len(data), 1), FRAME)):
        chunk = data[pos:pos + FRAME]
        # Bits, MSB first in little-endian 16-bit words: on the first frame a
        # 0 for "no E8 translation", then block type 3 (uncompressed) and a
        # 24-bit block length. Padded to 32 bits, which is also the byte
        # alignment the uncompressed block needs.
        bits, nbits = 3, 3
        if i == 0:
            nbits += 1
        bits = (bits << 24) | len(chunk)
        nbits += 24
        bits <<= 32 - nbits
        block = struct.pack("<HH", bits >> 16, bits & 0xFFFF)
        block += struct.pack("<III", 1, 1, 1)  # R0, R1, R2
        block += chunk  # no pad byte for an odd length: only the last frame can be odd
        if len(chunk) == FRAME:
            out += struct.pack(">H", len(block))
        else:
            out += struct.pack(">BHH", 0xFF, len(chunk), len(block))
        out += block
    # Every shipped entry ends in 5 zero bytes. The game rejects an entry
    # without them ("storage device ... has been removed").
    return bytes(out) + b"\0" * 5


def write_archive(path, entries, header_tail=(16, 1015)):
    """entries: list of (name, data). Writes the archive; names stay in order."""
    body, toc = bytearray(), bytearray()
    for name, data in entries:
        kind = KINDS.get(name.split("/", 1)[0])
        if kind is None:
            raise ValueError("unknown asset type in %r" % name)
        packed = pack_entry(data)
        raw = name.encode("latin-1")
        toc += struct.pack(">I", len(raw)) + raw
        # The shipped archives leave the CRC of the Assets/ index entries at 0.
        crc = 0 if name.startswith("Assets/") else zlib.crc32(data)
        toc += struct.pack(">6I", 24 + len(body), len(data), len(packed), kind, crc, 1)
        body += packed
    with open(path, "wb") as f:
        f.write(struct.pack(">4sIIIII", b"AKPF", 5, 24 + len(body), len(entries), *header_tail))
        f.write(body)
        f.write(toc)


def sort_keys(value):
    # Every object in every shipped DB has its keys in sorted order, so treat
    # that as a requirement of the reader (it likely binary-searches).
    if isinstance(value, dict):
        return {k: sort_keys(value[k]) for k in sorted(value)}
    if isinstance(value, list):
        return [sort_keys(v) for v in value]
    return value


def json_to_asset(value, asset_type):
    """JSON value -> the bytes an asset of this type stores (AKJB, size-prefixed)."""
    tree = bytearray(b"AKJB" + struct.pack(">I", 1))
    akjb.write_node(akjb.from_json(sort_keys(value)), tree)
    prefix = JSON_PREFIX.get(asset_type)
    if prefix is None:
        raise ValueError("%s assets cannot be written from JSON yet" % asset_type)
    return struct.pack(">I", len(tree)) * prefix + bytes(tree)


def asset_to_json(data):
    start = data.find(b"AKJB")
    if start < 0 or start > 8:
        raise ValueError("no AKJB tree")
    node, _ = akjb.parse_node(data, start + 8)
    return akjb.to_json(node)


def collect(folder):
    """Walk <folder>/<AssetType>/<Path>[.json|.bin|...] into (name, data)."""
    entries = []
    for root, _, files in os.walk(folder):
        for fn in sorted(files):
            full = os.path.join(root, fn)
            rel = os.path.relpath(full, folder).replace(os.sep, "/")
            asset_type = rel.split("/", 1)[0]
            stem, ext = os.path.splitext(rel)
            if ext == ".json":
                import json
                with open(full, encoding="utf-8") as f:
                    entries.append((stem, json_to_asset(json.load(f), asset_type)))
            else:
                with open(full, "rb") as f:
                    entries.append((stem if ext == ".bin" else rel, f.read()))
    # Index entries first, like the shipped archives.
    entries.sort(key=lambda e: (not e[0].startswith("Assets/"), e[0]))
    return entries


def main(argv):
    import json
    if len(argv) >= 2 and argv[0] == "list":
        tail, entries = read_toc(argv[1])
        print("header tail", tail, "-", len(entries), "entries")
        for e in entries:
            print("%10d %10d  kind %2d  %08X  %s" % (e[2], e[3], e[4], e[5], e[0]))
    elif len(argv) == 3 and argv[0] == "pack":
        entries = collect(argv[1])
        write_archive(argv[2], entries)
        print("wrote %s: %d entries" % (argv[2], len(entries)))
    elif len(argv) == 3 and argv[0] == "json2db":
        with open(argv[1], encoding="utf-8") as f:
            data = json_to_asset(json.load(f), "AkDBAsset")
        with open(argv[2], "wb") as f:
            f.write(data)
    elif len(argv) == 3 and argv[0] == "db2json":
        with open(argv[1], "rb") as f:
            value = asset_to_json(f.read())
        with open(argv[2], "w", encoding="utf-8") as f:
            json.dump(value, f, indent=1)
    else:
        print(__doc__)
        return 2
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
