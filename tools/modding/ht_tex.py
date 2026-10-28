"""Convert between PNG and the game's boat-skin textures (AkTextureAsset).

    python ht_tex.py decode <texture.bin> <out.png> [mip]
    python ht_tex.py encode <in.png> <texture.bin>

Needs numpy and Pillow. Skins are 1024x1024 DXT1 with a full mip chain, the
format every shipped boat skin uses; encode produces exactly that.

Layout (verified against the shipped skins; the rules are the ones in the
SDK's texture_util.cpp, derived from Xenia):

    header   u32 width, u32 height, u32 mip count, u32 D3DFORMAT, u32 data size
             (big-endian). D3DFMT_DXT1 = 0x1A200152: format k_DXT1, 8-in-16
             endian swap, tiled.
    level 0  tiled, pitch rounded up to 32 blocks
    1 .. 5   each tiled in its own 32-block-aligned image, back to back
    6 .. 10  (16x16 texels and smaller) packed together into one more 32x32
             block image, at the offsets GetPackedMipOffset gives
"""
import struct
import sys

import numpy as np
from PIL import Image

D3DFMT_DXT1 = 0x1A200152
BLOCK = 8  # bytes per DXT1 block


def tiled_offset(x, y, pitch, bpb_log2=3):
    """GetTiledOffset2D (texture_util.cpp), vectorised. Byte offset of block x, y."""
    pitch = (pitch + 31) & ~31
    macro = ((x >> 5) + (y >> 5) * (pitch >> 5)) << (bpb_log2 + 7)
    micro = ((x & 7) + ((y & 0xE) << 2)) << bpb_log2
    offset = macro + ((micro & ~0xF) << 1) + (micro & 0xF) + ((y & 1) << 4)
    return (((offset & ~0x1FF) << 3) + ((y & 16) << 7) + ((offset & 0x1C0) << 2) +
            (((((y & 8) >> 2) + (x >> 3)) & 3) << 6) + (offset & 0x3F))


def log2_ceil(v):
    return (v - 1).bit_length()


def packed_mip_offset(width, height, mip):
    """GetPackedMipOffset for 2D DXT textures: (x, y) in blocks, or None."""
    lw, lh = log2_ceil(width), log2_ceil(height)
    size = min(lw, lh)
    if size > 4 + mip:
        return None
    base = size - 4 if size > 4 else 0
    p = mip - base
    if p < 3:
        x, y = (0, 16 >> p) if lw > lh else (16 >> p, 0)
    else:
        if lw > lh:
            x, y = (1 << (lw - base)) >> (p - 2), 0
        else:
            x, y = 0, (1 << (lh - base)) >> (p - 2)
    return x // 4, y // 4


def layout(width, height, mips):
    """[(level, byte offset of its image, pitch in blocks, x0, y0, w_blocks, h_blocks)]."""
    out, offset = [], 0
    tail_offset = None
    for level in range(mips):
        w, h = max(width >> level, 1), max(height >> level, 1)
        bw, bh = (w + 3) // 4, (h + 3) // 4
        packed = packed_mip_offset(width, height, level) if level else None
        if level and packed is not None:
            if tail_offset is None:
                tail_offset = offset
                offset += 32 * 32 * BLOCK
            out.append((level, tail_offset, 32, packed[0], packed[1], bw, bh))
            continue
        # Mips use the power-of-two size; both are rounded up to 32 blocks.
        pw = (((1 << log2_ceil(width)) >> level) + 3) // 4 if level else bw
        ph = (((1 << log2_ceil(height)) >> level) + 3) // 4 if level else bh
        pw, ph = (max(pw, 1) + 31) & ~31, (max(ph, 1) + 31) & ~31
        out.append((level, offset, pw, 0, 0, bw, bh))
        offset += pw * ph * BLOCK
    return out, offset


def swap16(b):
    a = np.frombuffer(b, dtype=np.uint8).reshape(-1, 2)
    return a[:, ::-1].tobytes()


# ---- DXT1 ------------------------------------------------------------------

def rgb565_to_rgb(c):
    r = ((c >> 11) & 31) * 255 // 31
    g = ((c >> 5) & 63) * 255 // 63
    b = (c & 31) * 255 // 31
    return np.stack([r, g, b], -1).astype(np.int32)


def decode_blocks(blocks, bw, bh):
    """blocks: (bh*bw, 8) little-endian DXT1 -> RGBA image (bh*4, bw*4)."""
    c0 = blocks[:, 0].astype(np.int32) | (blocks[:, 1].astype(np.int32) << 8)
    c1 = blocks[:, 2].astype(np.int32) | (blocks[:, 3].astype(np.int32) << 8)
    idx = (blocks[:, 4].astype(np.uint32) | (blocks[:, 5].astype(np.uint32) << 8) |
           (blocks[:, 6].astype(np.uint32) << 16) | (blocks[:, 7].astype(np.uint32) << 24))
    p0, p1 = rgb565_to_rgb(c0), rgb565_to_rgb(c1)
    four = (c0 > c1)[:, None]
    p2 = np.where(four, (2 * p0 + p1) // 3, (p0 + p1) // 2)
    p3 = np.where(four, (p0 + 2 * p1) // 3, 0)
    pal = np.stack([p0, p1, p2, p3], 1)  # (n, 4, 3)
    alpha = np.where(four, 255, np.array([255, 255, 255, 0]))  # (n, 4)
    sel = np.stack([(idx >> (2 * i)) & 3 for i in range(16)], 1)  # (n, 16)
    n = len(blocks)
    rgb = pal[np.arange(n)[:, None], sel]  # (n, 16, 3)
    a = np.broadcast_to(alpha, (n, 4))[np.arange(n)[:, None], sel]
    px = np.concatenate([rgb, a[..., None]], -1).reshape(bh, bw, 4, 4, 4)
    return px.transpose(0, 2, 1, 3, 4).reshape(bh * 4, bw * 4, 4).astype(np.uint8)


def encode_blocks(img):
    """RGB image (h, w, 3), h and w multiples of 4 -> (n, 8) DXT1 blocks.
    Endpoints from the block's colour range along its principal axis; always
    the opaque 4-colour mode."""
    h, w, _ = img.shape
    px = img.reshape(h // 4, 4, w // 4, 4, 3).transpose(0, 2, 1, 3, 4).reshape(-1, 16, 3)
    px = px.astype(np.float32)
    mean = px.mean(1, keepdims=True)
    d = px - mean
    cov = np.einsum('nki,nkj->nij', d, d)
    axis = np.ones((len(px), 3), np.float32)
    for _ in range(8):  # power iteration
        axis = np.einsum('nij,nj->ni', cov, axis)
        axis /= np.linalg.norm(axis, axis=1, keepdims=True) + 1e-9
    t = np.einsum('nki,ni->nk', d, axis)
    lo = mean[:, 0] + axis * t.min(1, keepdims=True)
    hi = mean[:, 0] + axis * t.max(1, keepdims=True)

    def to565(c):
        c = np.clip(np.rint(c), 0, 255).astype(np.int32)
        return ((c[:, 0] * 31 + 127) // 255 << 11) | ((c[:, 1] * 63 + 127) // 255 << 5) | ((c[:, 2] * 31 + 127) // 255)

    c0, c1 = to565(hi), to565(lo)
    swap = c0 < c1
    c0, c1 = np.where(swap, c1, c0), np.where(swap, c0, c1)
    p0, p1 = rgb565_to_rgb(c0).astype(np.float32), rgb565_to_rgb(c1).astype(np.float32)
    pal = np.stack([p0, p1, (2 * p0 + p1) / 3, (p0 + 2 * p1) / 3], 1)  # (n, 4, 3)
    dist = ((px[:, :, None, :] - pal[:, None, :, :]) ** 2).sum(-1)  # (n, 16, 4)
    sel = dist.argmin(-1).astype(np.uint32)
    sel = np.where((c0 == c1)[:, None], 0, sel)  # c0 == c1 would mean 3-colour mode
    idx = np.zeros(len(px), np.uint32)
    for i in range(16):
        idx |= sel[:, i] << (2 * i)
    out = np.zeros((len(px), 8), np.uint8)
    out[:, 0], out[:, 1] = c0 & 255, c0 >> 8
    out[:, 2], out[:, 3] = c1 & 255, c1 >> 8
    for i in range(4):
        out[:, 4 + i] = (idx >> (8 * i)) & 255
    return out


# ---- texture files ------------------------------------------------------------

def read_header(data):
    w, h, mips, fmt, size = struct.unpack_from(">5I", data, 0)
    return w, h, mips, fmt, size


def decode(data, mip=0):
    w, h, mips, fmt, size = read_header(data)
    if fmt != D3DFMT_DXT1:
        raise ValueError("format %08X: only DXT1 textures are supported" % fmt)
    levels, total = layout(w, h, mips)
    body = data[20:]
    level, off, pitch, x0, y0, bw, bh = levels[mip]
    ys, xs = np.mgrid[0:bh, 0:bw]
    offs = off + tiled_offset(xs + x0, ys + y0, pitch).reshape(-1)
    raw = np.frombuffer(body, np.uint8)
    blocks = raw[offs[:, None] + np.arange(BLOCK)]
    blocks = blocks.reshape(-1, 4, 2)[:, :, ::-1].reshape(-1, 8)  # undo 8-in-16
    img = decode_blocks(blocks, bw, bh)
    return img[:max(h >> mip, 1), :max(w >> mip, 1)]


def encode(img):
    """RGB(A) image -> texture asset bytes. Width and height must be powers of two."""
    img = np.asarray(img.convert("RGB"))
    h, w, _ = img.shape
    if w & (w - 1) or h & (h - 1) or w < 4 or h < 4:
        raise ValueError("texture must be a power of two in each dimension, at least 4x4")
    mips = max(log2_ceil(w), log2_ceil(h)) + 1
    levels, total = layout(w, h, mips)
    body = np.zeros(total, np.uint8)
    level_img = Image.fromarray(img)
    for level, off, pitch, x0, y0, bw, bh in levels:
        lw, lh = max(w >> level, 1), max(h >> level, 1)
        src = np.asarray(level_img.resize((lw, lh), Image.LANCZOS)) if level else img
        pad = np.zeros((bh * 4, bw * 4, 3), np.uint8)
        pad[:lh, :lw] = src
        pad[lh:, :lw] = src[-1:, :] if lh < bh * 4 else pad[lh:, :lw]
        pad[:, lw:] = pad[:, lw - 1:lw]
        blocks = encode_blocks(pad)
        blocks = blocks.reshape(-1, 4, 2)[:, :, ::-1].reshape(-1, 8)  # 8-in-16
        ys, xs = np.mgrid[0:bh, 0:bw]
        offs = off + tiled_offset(xs + x0, ys + y0, pitch).reshape(-1)
        body[offs[:, None] + np.arange(BLOCK)] = blocks
    return struct.pack(">5I", w, h, mips, D3DFMT_DXT1, total) + body.tobytes()


def main(argv):
    if len(argv) >= 3 and argv[0] == "decode":
        with open(argv[1], "rb") as f:
            img = decode(f.read(), int(argv[3]) if len(argv) > 3 else 0)
        Image.fromarray(img).save(argv[2])
    elif len(argv) == 3 and argv[0] == "encode":
        data = encode(Image.open(argv[1]))
        with open(argv[2], "wb") as f:
            f.write(data)
    else:
        print(__doc__)
        return 2
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
