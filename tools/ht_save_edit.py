#!/usr/bin/env python3
"""Read and edit Hydro Thunder Hurricane save files (ht2save.dat).

The save is not encrypted. It is a typed name/value tree, big-endian
throughout, written by the engine's AkDataUtil serializer:

    magic  'AKJB'
    u32    version (1)
    <node>                      the root object

    <node> := u32 type, then:
        type 0 -> nothing        (null: an uncollected HiddenPackage, etc.)
        type 1 -> s32 value
        type 2 -> f32 value      (lap / total times, volumes)
        type 3 -> u8  value      (bool)
        type 4 -> u32 length + chars, no terminator (string)
        type 5 -> u32 count, then `count` * <node>                   (array)
        type 6 -> u32 count, then `count` * (u32 keylen + key, <node>) (object)
        type 7 -> 8 raw bytes    (the reader accepts it; this game never
                                  writes one, and calcCrc32 rejects it)

The root object holds three keys: Crc32, Data and Version. Only 0.4% of the
256 KB file is non-zero; the rest is padding, which this tool preserves.

Why edited saves are rejected
-----------------------------
On load the game requires root Version == 6 and root Crc32 ==
AkDataUtil::calcCrc32(root["Data"], 0) (sub_82167708). That is plain zlib
CRC-32, chained, over a walk of the *values* rather than the file bytes:

    every node:   crc(type as 4 BE bytes)
    int / float:  crc(4 BE value bytes)
    bool:         crc(1 byte)
    string:       crc(chars)
    array:        crc(count as 4 BE bytes), then each element
    object:       crc(count as 4 BE bytes), then per member crc(key chars)
                  followed by the member's value

Key lengths are not hashed, which is why no byte range of the file matches.
This tool recomputes the checksum on every write.

    python ht_save_edit.py <save>                       # dump the tree
    python ht_save_edit.py <save> --check               # verify the checksum
    python ht_save_edit.py <save> --set KEY=VALUE ...   # edit and re-sign
    python ht_save_edit.py <save> --fix                 # re-sign a hand edit
    python ht_save_edit.py <save> --export save.json    # tree -> JSON
    python ht_save_edit.py <save> --import save.json    # JSON -> tree, re-sign

<save> is the ht2save.dat file, or the ht2save.dat folder that holds it.

KEY is the leaf name (e.g. TotalCredits) or a slash path
(e.g. Data/Unlock/TotalCredits) when a leaf name is ambiguous. VALUE keeps the
leaf's existing type. A null leaf has no type to keep, so give one with a
prefix: int:, float:, bool:, str: or none (e.g. HiddenPackage3=bool:1).

In JSON, objects keep the file's key order. Integers and floats are told apart
by JSON itself, so write 2000 for an int and 2000.0 for a float; changing a
leaf's type can make the game misread it.

Every write first backs the save up to ~/.ht_save_backups/.
"""
import argparse
import json
import os
import shutil
import struct
import sys
import time
import zlib

MAGIC = b"AKJB"
FORMAT_VERSION = 1
SAVE_VERSION = 6
T_NONE, T_INT, T_FLOAT, T_BOOL, T_STR, T_ARRAY, T_OBJECT, T_RAW8 = range(8)
TYPE_NAMES = {T_NONE: "none", T_INT: "int", T_FLOAT: "float", T_BOOL: "bool",
              T_STR: "str", T_ARRAY: "array", T_OBJECT: "object", T_RAW8: "raw8"}


class Node:
    """One value. `value` is a list of (key, Node) for an object, a list of
    Node for an array, bytes for raw8, and a plain Python value otherwise."""

    def __init__(self, typ, value=None):
        self.type = typ
        self.value = value


def _u32(buf, off):
    return struct.unpack_from(">I", buf, off)[0]


def parse_node(buf, off):
    """Parse one node at `off`; return (node, offset just past it)."""
    typ = _u32(buf, off)
    off += 4
    if typ == T_NONE:
        return Node(T_NONE), off
    if typ == T_INT:
        return Node(T_INT, struct.unpack_from(">i", buf, off)[0]), off + 4
    if typ == T_FLOAT:
        return Node(T_FLOAT, struct.unpack_from(">f", buf, off)[0]), off + 4
    if typ == T_BOOL:
        return Node(T_BOOL, buf[off]), off + 1
    if typ == T_STR:
        n = _u32(buf, off)
        return Node(T_STR, bytes(buf[off + 4:off + 4 + n]).decode("latin-1")), off + 4 + n
    if typ == T_ARRAY:
        count = _u32(buf, off)
        off += 4
        items = []
        for _ in range(count):
            item, off = parse_node(buf, off)
            items.append(item)
        return Node(T_ARRAY, items), off
    if typ == T_OBJECT:
        count = _u32(buf, off)
        off += 4
        members = []
        for _ in range(count):
            klen = _u32(buf, off)
            key = bytes(buf[off + 4:off + 4 + klen]).decode("latin-1")
            off += 4 + klen
            child, off = parse_node(buf, off)
            members.append((key, child))
        return Node(T_OBJECT, members), off
    if typ == T_RAW8:
        return Node(T_RAW8, bytes(buf[off:off + 8])), off + 8
    raise ValueError("unknown node type %d at 0x%X" % (typ, off - 4))


def write_node(node, out):
    out += struct.pack(">I", node.type)
    if node.type == T_INT:
        out += struct.pack(">i", node.value)
    elif node.type == T_FLOAT:
        out += struct.pack(">f", node.value)
    elif node.type == T_BOOL:
        out.append(node.value)
    elif node.type == T_STR:
        raw = node.value.encode("latin-1")
        out += struct.pack(">I", len(raw)) + raw
    elif node.type == T_ARRAY:
        out += struct.pack(">I", len(node.value))
        for item in node.value:
            write_node(item, out)
    elif node.type == T_OBJECT:
        out += struct.pack(">I", len(node.value))
        for key, child in node.value:
            raw = key.encode("latin-1")
            out += struct.pack(">I", len(raw)) + raw
            write_node(child, out)
    elif node.type == T_RAW8:
        out += node.value


def calc_crc32(node, crc=0):
    """AkDataUtil::calcCrc32 (sub_82167708). See the module docstring."""
    crc = zlib.crc32(struct.pack(">I", node.type), crc)
    if node.type == T_INT:
        crc = zlib.crc32(struct.pack(">i", node.value), crc)
    elif node.type == T_FLOAT:
        crc = zlib.crc32(struct.pack(">f", node.value), crc)
    elif node.type == T_BOOL:
        crc = zlib.crc32(bytes([node.value]), crc)
    elif node.type == T_STR:
        # Hashed up to the first NUL, as the game walks a C string.
        crc = zlib.crc32(node.value.encode("latin-1").split(b"\0")[0], crc)
    elif node.type == T_ARRAY:
        crc = zlib.crc32(struct.pack(">I", len(node.value)), crc)
        for item in node.value:
            crc = calc_crc32(item, crc)
    elif node.type == T_OBJECT:
        crc = zlib.crc32(struct.pack(">I", len(node.value)), crc)
        for key, child in node.value:
            crc = zlib.crc32(key.encode("latin-1").split(b"\0")[0], crc)
            crc = calc_crc32(child, crc)
    elif node.type == T_RAW8:
        sys.exit("a raw8 (type 7) value is in Data; the game cannot checksum "
                 "that and would reject the save")
    return crc


def member(obj, key):
    for k, child in obj.value:
        if k == key:
            return child
    return None


def resolve(path):
    if os.path.isdir(path):
        path = os.path.join(path, "ht2save.dat")
    if not os.path.isfile(path):
        sys.exit("no save file at %s" % path)
    return path


def load(path):
    buf = open(path, "rb").read()
    if buf[:4] != MAGIC:
        sys.exit("not an AKJB save: %s" % path)
    root, _ = parse_node(buf, 8)   # skip magic + format version
    if root.type != T_OBJECT or member(root, "Data") is None:
        sys.exit("save has no Data object: %s" % path)
    return root, len(buf)


def stored_and_computed(root):
    stored = member(root, "Crc32")
    stored = None if stored is None else stored.value & 0xFFFFFFFF
    return stored, calc_crc32(member(root, "Data"))


def save(path, root, size):
    crc = calc_crc32(member(root, "Data"))
    node = member(root, "Crc32")
    if node is None:
        node = Node(T_INT)
        root.value.insert(0, ("Crc32", node))
    node.type = T_INT
    node.value = struct.unpack(">i", struct.pack(">I", crc))[0]

    out = bytearray(MAGIC + struct.pack(">I", FORMAT_VERSION))
    write_node(root, out)
    # The game writes a fixed 256 KB file; keep the original size.
    out += bytes(max(0, size - len(out)))
    with open(path, "wb") as f:
        f.write(out)
    print("written, Crc32 = 0x%08X" % crc)


def leaves(node, path="", out=None):
    """Flatten to [(path, parent list, index, node)] for --set and the dump."""
    if out is None:
        out = []
    if node.type == T_OBJECT:
        for i, (key, child) in enumerate(node.value):
            sub = path + "/" + key if path else key
            if child.type in (T_OBJECT, T_ARRAY):
                leaves(child, sub, out)
            else:
                out.append((sub, node.value, i, child))
    elif node.type == T_ARRAY:
        for i, child in enumerate(node.value):
            sub = "%s[%d]" % (path, i)
            if child.type in (T_OBJECT, T_ARRAY):
                leaves(child, sub, out)
            else:
                out.append((sub, node.value, i, child))
    return out


def find(flat, key):
    exact = [l for l in flat if l[0] == key or l[0].endswith("/" + key)]
    if not exact:
        sys.exit("key not found: %s" % key)
    if len(exact) > 1:
        sys.exit("ambiguous key %r, matches:\n  %s"
                 % (key, "\n  ".join(l[0] for l in exact)))
    return exact[0]


def parse_value(raw, current):
    """Turn a --set VALUE into a Node, keeping `current`'s type by default."""
    typ = current.type
    prefix, sep, rest = raw.partition(":")
    if sep and prefix in ("int", "float", "bool", "str"):
        typ = {"int": T_INT, "float": T_FLOAT, "bool": T_BOOL, "str": T_STR}[prefix]
        raw = rest
    elif raw == "none":
        return Node(T_NONE)
    if typ == T_INT:
        return Node(T_INT, int(raw, 0))
    if typ == T_FLOAT:
        return Node(T_FLOAT, float(raw))
    if typ == T_BOOL:
        return Node(T_BOOL, 1 if raw.lower() in ("1", "true", "yes", "on") else 0)
    if typ == T_STR:
        return Node(T_STR, raw)
    if typ == T_NONE:
        sys.exit("that leaf is null, so it has no type to keep; prefix the value "
                 "with int:, float:, bool: or str: (e.g. bool:1)")
    sys.exit("cannot set a %s value" % TYPE_NAMES[typ])


def describe(node):
    return "null" if node.type == T_NONE else repr(node.value)


def to_json(node):
    if node.type == T_NONE:
        return None
    if node.type == T_BOOL:
        return bool(node.value)
    if node.type in (T_INT, T_FLOAT, T_STR):
        return node.value
    if node.type == T_ARRAY:
        return [to_json(item) for item in node.value]
    if node.type == T_OBJECT:
        return {key: to_json(child) for key, child in node.value}
    return {"$raw8": node.value.hex()}


def from_json(value):
    if value is None:
        return Node(T_NONE)
    if isinstance(value, bool):
        return Node(T_BOOL, int(value))
    if isinstance(value, int):
        return Node(T_INT, value)
    if isinstance(value, float):
        return Node(T_FLOAT, value)
    if isinstance(value, str):
        return Node(T_STR, value)
    if isinstance(value, list):
        return Node(T_ARRAY, [from_json(item) for item in value])
    if isinstance(value, dict):
        if list(value) == ["$raw8"]:
            return Node(T_RAW8, bytes.fromhex(value["$raw8"]))
        # Keys must be in sorted order: the game reports a save whose keys are
        # not as damaged (verified by adding a key out of order). Every object
        # the game writes is already sorted, so this changes nothing on a
        # plain export/import round trip.
        return Node(T_OBJECT, [(key, from_json(value[key])) for key in sorted(value)])
    sys.exit("unsupported JSON value: %r" % (value,))


def backup(path):
    # Back up OUTSIDE the save directory. The game recreates the whole
    # ht2save.dat/ folder when it rejects a save, which deletes anything
    # kept alongside it - that is how a previous backup was lost.
    stamp = time.strftime("%Y%m%d-%H%M%S")
    dest_dir = os.path.join(os.path.expanduser("~"), ".ht_save_backups")
    os.makedirs(dest_dir, exist_ok=True)
    dest = os.path.join(dest_dir, "ht2save-%s.dat" % stamp)
    shutil.copy2(path, dest)
    print("backup -> %s" % dest)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("save")
    mode = ap.add_mutually_exclusive_group()
    mode.add_argument("--set", action="append", default=[], metavar="KEY=VALUE")
    mode.add_argument("--check", action="store_true", help="verify the checksum")
    mode.add_argument("--fix", action="store_true", help="recompute the checksum")
    mode.add_argument("--export", metavar="FILE.json")
    mode.add_argument("--import", dest="import_", metavar="FILE.json")
    ap.add_argument("--no-backup", action="store_true")
    args = ap.parse_args()

    path = resolve(args.save)
    root, size = load(path)
    stored, computed = stored_and_computed(root)
    version = member(root, "Version")
    if version is not None and version.value != SAVE_VERSION:
        print("note: Version is %s; this game loads version %d"
              % (version.value, SAVE_VERSION))

    if args.check:
        ok = stored == computed
        print("Crc32 stored 0x%08X, computed 0x%08X: %s"
              % (stored or 0, computed, "OK" if ok else "MISMATCH (the game "
                 "will reject this save; run --fix)"))
        sys.exit(0 if ok else 1)

    if args.export:
        with open(args.export, "w", encoding="utf-8") as f:
            json.dump(to_json(root), f, indent=2)
            f.write("\n")
        print("exported -> %s" % args.export)
        return

    if not (args.set or args.fix or args.import_):
        flat = leaves(root)
        width = max(len(l[0]) for l in flat)
        for p, _, _, node in flat:
            print("  %-*s  %-5s %s" % (width, p, TYPE_NAMES[node.type], describe(node)))
        print("\n%d leaves, Crc32 %s" % (len(flat), "OK" if stored == computed
                                          else "MISMATCH"))
        return

    if args.import_:
        with open(args.import_, encoding="utf-8") as f:
            root = from_json(json.load(f))
        if root.type != T_OBJECT or member(root, "Data") is None:
            sys.exit("%s has no top-level Data object" % args.import_)

    flat = leaves(root)
    edits = []
    for assignment in args.set:
        key, sep, raw = assignment.partition("=")
        if not sep:
            sys.exit("--set needs KEY=VALUE, got %r" % assignment)
        p, parent, index, current = find(flat, key)
        new = parse_value(raw, current)
        if isinstance(parent[index], tuple):
            parent[index] = (parent[index][0], new)
        else:
            parent[index] = new
        edits.append("  %s: %s -> %s" % (p, describe(current), describe(new)))

    if not args.no_backup:
        backup(path)
    for line in edits:
        print(line)
    save(path, root, size)


if __name__ == "__main__":
    main()
