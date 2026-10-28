// htrecomp - mod support: build mods/ into content packages. See ht_mods.h.
//
// This is the C++ version of tools/modding/ht_mod.py, the reference
// implementation the formats were proven with. The pieces, in file order:
//
//   Value / AKJB   the typed value tree every DB (and the save) is stored in
//   APF            the asset archive: read entries (LZX), write entries (LZX
//                  uncompressed blocks, as the game's own tools do)
//   Texture        PNG -> Xbox 360 DXT1 with a full, tiled mip chain
//   Build          mod.toml -> DB fragments, strings, textures
//   Install        package folder, content header, change detection

#include "ht_mods.h"

#include <algorithm>
#include <array>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <functional>
#include <map>
#include <optional>
#include <regex>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

#include <rex/logging.h>

#include <toml++/toml.hpp>

#include <lzx.h>
#include <mspack.h>

#if defined(_WIN32)
#define NOMINMAX
#include <windows.h>
namespace Gdiplus {
using std::max;
using std::min;
}  // namespace Gdiplus
#include <gdiplus.h>
#endif

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#define STBI_ONLY_PNG
#define STBI_NO_STDIO
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include HT_STB_IMAGE_H  // set by CMakeLists.txt
#pragma clang diagnostic pop

namespace fs = std::filesystem;

namespace ht {
namespace {

constexpr const char* kTitleId = "5841096A";
constexpr const char* kMarketplace = "00000002";
constexpr const char* kPackagePrefix = "Mod_";
// An empty file of this name in a mod's folder turns the mod off (F5 > Mods).
constexpr const char* kDisabledMarker = "disabled";
// Bump when the build output changes, so every mod is rebuilt once.
constexpr const char* kBuilderVersion = "ht-mods 1";
// Every language the game ships strings for. A mod's text is written to all.
constexpr std::array<const char*, 9> kLanguages = {
    "de-de", "en-us", "es-es", "fr-fr", "it-it", "ja-jp", "ko-kr", "pt-pt", "zh-cht"};

struct ModError : std::runtime_error {
  using std::runtime_error::runtime_error;
};

// ===========================================================================
// Value / AKJB
// ===========================================================================
//
// 'AKJB', u32 version 1, then one node: u32 type, then
//   0 null | 1 s32 | 2 f32 | 3 u8 bool | 4 u32 length + bytes
//   5 u32 count + nodes | 6 u32 count + (u32 length + key, node)
// all big-endian. Every object in every shipped DB has its keys sorted, so we
// always write them sorted.

struct Value {
  enum class Type : uint32_t { Null = 0, Int = 1, Float = 2, Bool = 3, Str = 4, Array = 5, Object = 6 };
  Type type = Type::Null;
  int32_t i = 0;
  float f = 0;
  bool b = false;
  std::string s;
  std::vector<Value> a;
  std::vector<std::pair<std::string, Value>> o;

  static Value Obj() { Value v; v.type = Type::Object; return v; }
  static Value Arr() { Value v; v.type = Type::Array; return v; }
  static Value Str(std::string x) { Value v; v.type = Type::Str; v.s = std::move(x); return v; }
  static Value Int(int32_t x) { Value v; v.type = Type::Int; v.i = x; return v; }
  static Value Bool(bool x) { Value v; v.type = Type::Bool; v.b = x; return v; }

  bool is_object() const { return type == Type::Object; }
  bool is_array() const { return type == Type::Array; }

  const Value* find(std::string_view key) const {
    if (type != Type::Object) return nullptr;
    for (const auto& [k, v] : o) {
      if (k == key) return &v;
    }
    return nullptr;
  }
  Value* find(std::string_view key) {
    return const_cast<Value*>(static_cast<const Value*>(this)->find(key));
  }
  // Object member, created (as null) if missing.
  Value& operator[](std::string_view key) {
    if (type != Type::Object) { *this = Obj(); }
    if (Value* v = find(key)) return *v;
    o.emplace_back(std::string(key), Value{});
    return o.back().second;
  }
  std::string str(std::string_view key) const {
    const Value* v = find(key);
    return v && v->type == Type::Str ? v->s : std::string();
  }
};

class Reader {
 public:
  Reader(const uint8_t* data, size_t size) : p_(data), end_(data + size) {}
  uint32_t u32() {
    need(4);
    const uint32_t v = (uint32_t(p_[0]) << 24) | (uint32_t(p_[1]) << 16) | (uint32_t(p_[2]) << 8) | p_[3];
    p_ += 4;
    return v;
  }
  uint8_t u8() { need(1); return *p_++; }
  std::string bytes(uint32_t n) { need(n); std::string s(reinterpret_cast<const char*>(p_), n); p_ += n; return s; }

 private:
  void need(size_t n) const {
    if (size_t(end_ - p_) < n) throw ModError("truncated data");
  }
  const uint8_t* p_;
  const uint8_t* end_;
};

Value ParseNode(Reader& r, int depth = 0) {
  if (depth > 64) throw ModError("data nested too deeply");
  Value v;
  const uint32_t type = r.u32();
  switch (type) {
    case 0: break;
    case 1: v = Value::Int(int32_t(r.u32())); break;
    case 2: {
      v.type = Value::Type::Float;
      const uint32_t bits = r.u32();
      std::memcpy(&v.f, &bits, 4);
      break;
    }
    case 3: v = Value::Bool(r.u8() != 0); break;
    case 4: v = Value::Str(r.bytes(r.u32())); break;
    case 5: {
      v = Value::Arr();
      for (uint32_t n = r.u32(); n; --n) v.a.push_back(ParseNode(r, depth + 1));
      break;
    }
    case 6: {
      v = Value::Obj();
      for (uint32_t n = r.u32(); n; --n) {
        std::string key = r.bytes(r.u32());
        v.o.emplace_back(std::move(key), ParseNode(r, depth + 1));
      }
      break;
    }
    default: throw ModError("unknown value type " + std::to_string(type));
  }
  return v;
}

void PutU32(std::vector<uint8_t>& out, uint32_t v) {
  out.push_back(uint8_t(v >> 24)); out.push_back(uint8_t(v >> 16));
  out.push_back(uint8_t(v >> 8)); out.push_back(uint8_t(v));
}

void WriteNode(const Value& v, std::vector<uint8_t>& out) {
  PutU32(out, uint32_t(v.type));
  switch (v.type) {
    case Value::Type::Null: break;
    case Value::Type::Int: PutU32(out, uint32_t(v.i)); break;
    case Value::Type::Float: {
      uint32_t bits;
      std::memcpy(&bits, &v.f, 4);
      PutU32(out, bits);
      break;
    }
    case Value::Type::Bool: out.push_back(v.b ? 1 : 0); break;
    case Value::Type::Str:
      PutU32(out, uint32_t(v.s.size()));
      out.insert(out.end(), v.s.begin(), v.s.end());
      break;
    case Value::Type::Array:
      PutU32(out, uint32_t(v.a.size()));
      for (const auto& item : v.a) WriteNode(item, out);
      break;
    case Value::Type::Object: {
      std::vector<const std::pair<std::string, Value>*> members;
      for (const auto& m : v.o) members.push_back(&m);
      std::sort(members.begin(), members.end(), [](auto* x, auto* y) { return x->first < y->first; });
      PutU32(out, uint32_t(members.size()));
      for (const auto* m : members) {
        PutU32(out, uint32_t(m->first.size()));
        out.insert(out.end(), m->first.begin(), m->first.end());
        WriteNode(m->second, out);
      }
      break;
    }
  }
}

// A DB asset is u32 size + AKJB; an index ("Assets/...") is the bare AKJB.
std::vector<uint8_t> EncodeTree(const Value& root, bool size_prefix) {
  std::vector<uint8_t> tree = {'A', 'K', 'J', 'B'};
  PutU32(tree, 1);
  WriteNode(root, tree);
  if (!size_prefix) return tree;
  std::vector<uint8_t> out;
  PutU32(out, uint32_t(tree.size()));
  out.insert(out.end(), tree.begin(), tree.end());
  return out;
}

Value DecodeTree(const std::vector<uint8_t>& data) {
  for (size_t start = 0; start <= 8 && start + 8 <= data.size(); start += 4) {
    if (std::memcmp(data.data() + start, "AKJB", 4) == 0) {
      Reader r(data.data() + start + 8, data.size() - start - 8);
      return ParseNode(r);
    }
  }
  throw ModError("not an AKJB tree");
}

// ===========================================================================
// APF archives
// ===========================================================================
//
// 'AKPF', u32 version 5, u32 toc offset, u32 count, u32, u32; entries from
// offset 24; the TOC at the end: u32 name length, "Type/Path", then u32
// offset, size, packed size, kind, crc32 of the unpacked data, flags. Entries
// are XMemCompress output: per 32 KB frame `u16 packed` or `FF u16 size u16
// packed`, then LZX. Every entry ends in 5 zero bytes, without which the game
// reports the storage device as removed.

constexpr uint32_t kFrame = 0x8000;

uint32_t Crc32(const uint8_t* data, size_t size) {
  static const std::array<uint32_t, 256> table = [] {
    std::array<uint32_t, 256> t{};
    for (uint32_t n = 0; n < 256; ++n) {
      uint32_t c = n;
      for (int k = 0; k < 8; ++k) c = c & 1 ? 0xEDB88320u ^ (c >> 1) : c >> 1;
      t[n] = c;
    }
    return t;
  }();
  uint32_t c = 0xFFFFFFFFu;
  for (size_t i = 0; i < size; ++i) c = table[(c ^ data[i]) & 0xFF] ^ (c >> 8);
  return c ^ 0xFFFFFFFFu;
}

std::vector<uint8_t> ReadFile(const fs::path& path) {
  std::ifstream f(path, std::ios::binary);
  if (!f) throw ModError("cannot read " + path.string());
  return std::vector<uint8_t>(std::istreambuf_iterator<char>(f), {});
}

void WriteFile(const fs::path& path, const void* data, size_t size) {
  fs::create_directories(path.parent_path());
  std::ofstream f(path, std::ios::binary | std::ios::trunc);
  f.write(static_cast<const char*>(data), std::streamsize(size));
  if (!f) throw ModError("cannot write " + path.string());
}

struct ApfEntry {
  std::string name;
  uint32_t offset = 0, size = 0, packed = 0;
};

uint32_t Be32(const uint8_t* p) {
  return (uint32_t(p[0]) << 24) | (uint32_t(p[1]) << 16) | (uint32_t(p[2]) << 8) | p[3];
}

std::vector<ApfEntry> ReadToc(std::ifstream& f) {
  uint8_t header[24];
  if (!f.read(reinterpret_cast<char*>(header), 24) || std::memcmp(header, "AKPF", 4) != 0 ||
      Be32(header + 4) != 5) {
    throw ModError("not an AKPF v5 archive");
  }
  const uint32_t toc = Be32(header + 8), count = Be32(header + 12);
  f.seekg(0, std::ios::end);
  const uint64_t end = uint64_t(f.tellg());
  if (toc > end) throw ModError("bad TOC offset");
  std::vector<uint8_t> t(size_t(end - toc));
  f.seekg(toc);
  f.read(reinterpret_cast<char*>(t.data()), std::streamsize(t.size()));
  Reader r(t.data(), t.size());
  std::vector<ApfEntry> entries;
  for (uint32_t i = 0; i < count; ++i) {
    ApfEntry e;
    e.name = r.bytes(r.u32());
    e.offset = r.u32();
    e.size = r.u32();
    e.packed = r.u32();
    r.u32(); r.u32(); r.u32();
    entries.push_back(std::move(e));
  }
  return entries;
}

// libmspack over memory buffers.
struct MemFile {
  uint8_t* buf;
  size_t size, off;
};
int MemRead(mspack_file* file, void* buffer, int bytes) {
  auto* m = reinterpret_cast<MemFile*>(file);
  const size_t n = std::min(size_t(bytes), m->size - m->off);
  std::memcpy(buffer, m->buf + m->off, n);
  m->off += n;
  return int(n);
}
int MemWrite(mspack_file* file, void* buffer, int bytes) {
  auto* m = reinterpret_cast<MemFile*>(file);
  const size_t n = std::min(size_t(bytes), m->size - m->off);
  std::memcpy(m->buf + m->off, buffer, n);
  m->off += n;
  return int(n);
}
void* MemAlloc(mspack_system*, size_t bytes) { return std::calloc(bytes, 1); }
void MemFree(void* p) { std::free(p); }
void MemCopy(void* src, void* dst, size_t bytes) { std::memmove(dst, src, bytes); }
void MemMessage(mspack_file*, const char*, ...) {}

std::vector<uint8_t> Unpack(const std::vector<uint8_t>& src, uint32_t size) {
  std::vector<uint8_t> lzx;
  for (size_t p = 0; p + 2 <= src.size();) {
    uint32_t packed;
    if (src[p] == 0xFF) {
      if (p + 5 > src.size()) break;
      packed = (uint32_t(src[p + 3]) << 8) | src[p + 4];
      p += 5;
    } else {
      packed = (uint32_t(src[p]) << 8) | src[p + 1];
      p += 2;
    }
    if (packed == 0 || p + packed > src.size()) break;
    lzx.insert(lzx.end(), src.begin() + p, src.begin() + p + packed);
    p += packed;
  }
  mspack_system sys{};
  sys.read = MemRead;
  sys.write = MemWrite;
  sys.alloc = MemAlloc;
  sys.free = MemFree;
  sys.copy = MemCopy;
  sys.message = MemMessage;
  std::vector<uint8_t> out(size);
  for (int window_bits : {17, 15, 16, 18, 19, 20, 21}) {
    MemFile in{lzx.data(), lzx.size(), 0}, dst{out.data(), out.size(), 0};
    lzxd_stream* z = lzxd_init(&sys, reinterpret_cast<mspack_file*>(&in),
                               reinterpret_cast<mspack_file*>(&dst), window_bits, 0, kFrame,
                               off_t(size), 0);
    const int rc = z ? lzxd_decompress(z, off_t(size)) : -1;
    if (z) lzxd_free(z);
    if (rc == 0) return out;
  }
  throw ModError("could not decompress an archive entry");
}

// name -> unpacked data, for the entries whose name `want` accepts.
std::map<std::string, std::vector<uint8_t>> ReadEntries(
    const fs::path& path, const std::function<bool(const std::string&)>& want) {
  std::ifstream f(path, std::ios::binary);
  if (!f) throw ModError("cannot open " + path.string());
  std::map<std::string, std::vector<uint8_t>> out;
  for (const auto& e : ReadToc(f)) {
    if (!want(e.name)) continue;
    std::vector<uint8_t> packed(e.packed);
    f.seekg(e.offset);
    f.read(reinterpret_cast<char*>(packed.data()), e.packed);
    out[e.name] = Unpack(packed, e.size);
  }
  return out;
}

// One LZX uncompressed block per 32 KB frame. The bitstream (MSB first in
// little-endian 16-bit words) is: on the first frame a 0 bit (no E8
// translation), then block type 3 and a 24-bit length, padded to 32 bits;
// then R0..R2 and the raw bytes.
std::vector<uint8_t> PackEntry(const std::vector<uint8_t>& data) {
  std::vector<uint8_t> out;
  size_t frame = 0;
  for (size_t pos = 0; frame == 0 || pos < data.size(); pos += kFrame, ++frame) {
    const size_t n = std::min<size_t>(kFrame, data.size() - pos);
    uint32_t bits = (3u << 24) | uint32_t(n);
    const int nbits = 27 + (frame == 0 ? 1 : 0);
    bits <<= 32 - nbits;
    std::vector<uint8_t> block = {uint8_t(bits >> 16), uint8_t(bits >> 24), uint8_t(bits),
                                  uint8_t(bits >> 8)};
    for (int r = 0; r < 3; ++r) block.insert(block.end(), {1, 0, 0, 0});
    block.insert(block.end(), data.begin() + pos, data.begin() + pos + n);
    if (n == kFrame) {
      out.push_back(uint8_t(block.size() >> 8));
      out.push_back(uint8_t(block.size()));
    } else {
      out.insert(out.end(), {0xFF, uint8_t(n >> 8), uint8_t(n), uint8_t(block.size() >> 8),
                             uint8_t(block.size())});
    }
    out.insert(out.end(), block.begin(), block.end());
    if (data.empty()) break;
  }
  out.insert(out.end(), 5, 0);
  return out;
}

uint32_t AssetKind(std::string_view type) {
  // Per-asset-type format version, as recorded in the shipped archives.
  if (type == "AkDBAsset") return 4;
  if (type == "AkTextureAsset") return 8;
  return 0;  // Assets/ index entries, AkGenericAsset
}

void WriteArchive(const fs::path& path,
                  const std::vector<std::pair<std::string, std::vector<uint8_t>>>& entries) {
  std::vector<uint8_t> body, toc;
  for (const auto& [name, data] : entries) {
    const std::vector<uint8_t> packed = PackEntry(data);
    const bool index = name.rfind("Assets/", 0) == 0;
    PutU32(toc, uint32_t(name.size()));
    toc.insert(toc.end(), name.begin(), name.end());
    PutU32(toc, uint32_t(24 + body.size()));
    PutU32(toc, uint32_t(data.size()));
    PutU32(toc, uint32_t(packed.size()));
    PutU32(toc, AssetKind(name.substr(0, name.find('/'))));
    PutU32(toc, index ? 0 : Crc32(data.data(), data.size()));  // the shipped index CRCs are 0
    PutU32(toc, 1);
    body.insert(body.end(), packed.begin(), packed.end());
  }
  std::vector<uint8_t> out = {'A', 'K', 'P', 'F'};
  PutU32(out, 5);
  PutU32(out, uint32_t(24 + body.size()));
  PutU32(out, uint32_t(entries.size()));
  PutU32(out, 16);    // Pack01.apf's values; their meaning is not known
  PutU32(out, 1015);
  out.insert(out.end(), body.begin(), body.end());
  out.insert(out.end(), toc.begin(), toc.end());
  WriteFile(path, out.data(), out.size());
}

// ===========================================================================
// Texture: PNG -> AkTextureAsset (Xbox 360 DXT1, tiled, full mip chain)
// ===========================================================================
//
// u32 width, height, mip count, D3DFORMAT, data size, then the data. Level 0
// is tiled with a 32-block-aligned pitch; levels 1.. each in their own
// 32-block-aligned power-of-two image; levels of 16 texels and smaller packed
// together into one more 32x32-block image. The rules are the SDK's
// texture_util.cpp (from Xenia); tools/modding/ht_tex.py decodes the shipped
// skins with them, which is how they were checked.

constexpr uint32_t kD3dFmtDxt1 = 0x1A200152;

uint32_t Log2Ceil(uint32_t v) {
  uint32_t r = 0;
  while ((1u << r) < v) ++r;
  return r;
}

uint32_t TiledOffset(uint32_t x, uint32_t y, uint32_t pitch) {  // GetTiledOffset2D, 8-byte blocks
  constexpr int32_t bpb_log2 = 3;
  pitch = (pitch + 31) & ~31u;
  const int32_t ix = int32_t(x), iy = int32_t(y);
  const int32_t macro = ((ix >> 5) + (iy >> 5) * int32_t(pitch >> 5)) << (bpb_log2 + 7);
  const int32_t micro = ((ix & 7) + ((iy & 0xE) << 2)) << bpb_log2;
  const int32_t offset = macro + ((micro & ~0xF) << 1) + (micro & 0xF) + ((iy & 1) << 4);
  return uint32_t(((offset & ~0x1FF) << 3) + ((iy & 16) << 7) + ((offset & 0x1C0) << 2) +
                  (((((iy & 8) >> 2) + (ix >> 3)) & 3) << 6) + (offset & 0x3F));
}

struct Level {
  uint32_t offset, pitch, x0, y0, bw, bh;
};

std::vector<Level> TextureLayout(uint32_t width, uint32_t height, uint32_t mips, uint32_t* total) {
  std::vector<Level> out;
  uint32_t offset = 0;
  std::optional<uint32_t> tail;
  const uint32_t lw = Log2Ceil(width), lh = Log2Ceil(height), size = std::min(lw, lh);
  const uint32_t packed_base = size > 4 ? size - 4 : 0;
  for (uint32_t level = 0; level < mips; ++level) {
    const uint32_t w = std::max(width >> level, 1u), h = std::max(height >> level, 1u);
    const uint32_t bw = (w + 3) / 4, bh = (h + 3) / 4;
    if (level && size <= 4 + level) {  // GetPackedMipOffset
      const uint32_t p = level - packed_base;
      uint32_t x, y;
      if (p < 3) {
        x = lw > lh ? 0 : 16 >> p;
        y = lw > lh ? 16 >> p : 0;
      } else {
        x = lw > lh ? (1u << (lw - packed_base)) >> (p - 2) : 0;
        y = lw > lh ? 0 : (1u << (lh - packed_base)) >> (p - 2);
      }
      if (!tail) {
        tail = offset;
        offset += 32 * 32 * 8;
      }
      out.push_back({*tail, 32, x / 4, y / 4, bw, bh});
      continue;
    }
    uint32_t pw = bw, ph = bh;
    if (level) {
      pw = std::max(((1u << lw) >> level) + 3, 4u) / 4;
      ph = std::max(((1u << lh) >> level) + 3, 4u) / 4;
    }
    pw = (pw + 31) & ~31u;
    ph = (ph + 31) & ~31u;
    out.push_back({offset, pw, 0, 0, bw, bh});
    offset += pw * ph * 8;
  }
  *total = offset;
  return out;
}

uint16_t To565(float r, float g, float b) {
  auto q = [](float v, int max) {
    return std::clamp(int(std::lround(std::clamp(v, 0.f, 255.f))) * max + 127, 0, 255 * max) / 255;
  };
  return uint16_t((q(r, 31) << 11) | (q(g, 63) << 5) | q(b, 31));
}

void From565(uint16_t c, float* rgb) {
  rgb[0] = float(((c >> 11) & 31) * 255 / 31);
  rgb[1] = float(((c >> 5) & 63) * 255 / 63);
  rgb[2] = float((c & 31) * 255 / 31);
}

// One opaque 4-colour DXT1 block from 16 RGB pixels: endpoints at the ends of
// the colours' principal axis, each pixel to its nearest palette entry.
// Returned in the PC byte order.
std::array<uint8_t, 8> EncodeBlock(const float (&px)[16][3]) {
  float mean[3] = {0, 0, 0};
  for (const auto& p : px) for (int c = 0; c < 3; ++c) mean[c] += p[c] / 16;
  float cov[3][3] = {};
  for (const auto& p : px) {
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) cov[i][j] += (p[i] - mean[i]) * (p[j] - mean[j]);
  }
  float axis[3] = {1, 1, 1};
  for (int it = 0; it < 8; ++it) {
    float n[3];
    for (int i = 0; i < 3; ++i) n[i] = cov[i][0] * axis[0] + cov[i][1] * axis[1] + cov[i][2] * axis[2];
    const float len = std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]) + 1e-9f;
    for (int i = 0; i < 3; ++i) axis[i] = n[i] / len;
  }
  float tmin = 1e30f, tmax = -1e30f;
  for (const auto& p : px) {
    const float t = (p[0] - mean[0]) * axis[0] + (p[1] - mean[1]) * axis[1] + (p[2] - mean[2]) * axis[2];
    tmin = std::min(tmin, t);
    tmax = std::max(tmax, t);
  }
  uint16_t c0 = To565(mean[0] + axis[0] * tmax, mean[1] + axis[1] * tmax, mean[2] + axis[2] * tmax);
  uint16_t c1 = To565(mean[0] + axis[0] * tmin, mean[1] + axis[1] * tmin, mean[2] + axis[2] * tmin);
  if (c0 < c1) std::swap(c0, c1);
  float pal[4][3];
  From565(c0, pal[0]);
  From565(c1, pal[1]);
  for (int c = 0; c < 3; ++c) {
    pal[2][c] = (2 * pal[0][c] + pal[1][c]) / 3;
    pal[3][c] = (pal[0][c] + 2 * pal[1][c]) / 3;
  }
  uint32_t indices = 0;
  if (c0 != c1) {  // equal endpoints would select the 3-colour mode
    for (int i = 0; i < 16; ++i) {
      int best = 0;
      float best_d = 1e30f;
      for (int k = 0; k < 4; ++k) {
        float d = 0;
        for (int c = 0; c < 3; ++c) d += (px[i][c] - pal[k][c]) * (px[i][c] - pal[k][c]);
        if (d < best_d) { best_d = d; best = k; }
      }
      indices |= uint32_t(best) << (2 * i);
    }
  }
  return {uint8_t(c0), uint8_t(c0 >> 8), uint8_t(c1), uint8_t(c1 >> 8),
          uint8_t(indices), uint8_t(indices >> 8), uint8_t(indices >> 16), uint8_t(indices >> 24)};
}

std::vector<uint8_t> EncodeTexture(const fs::path& png) {
  const std::vector<uint8_t> file = ReadFile(png);
  int w = 0, h = 0, n = 0;
  uint8_t* rgb = stbi_load_from_memory(file.data(), int(file.size()), &w, &h, &n, 3);
  if (!rgb) throw ModError(png.filename().string() + " is not a readable PNG");
  std::vector<float> img(size_t(w) * h * 3);
  for (size_t i = 0; i < img.size(); ++i) img[i] = rgb[i];
  stbi_image_free(rgb);
  auto pow2 = [](int v) { return v >= 4 && v <= 4096 && (v & (v - 1)) == 0; };
  if (!pow2(w) || !pow2(h)) {
    throw ModError(png.filename().string() + " is " + std::to_string(w) + "x" + std::to_string(h) +
                   "; textures must be a power of two in each dimension (boat skins are 1024x1024)");
  }
  const uint32_t mips = std::max(Log2Ceil(w), Log2Ceil(h)) + 1;
  uint32_t total = 0;
  const std::vector<Level> levels = TextureLayout(w, h, mips, &total);
  std::vector<uint8_t> out(20 + total, 0);
  const uint32_t header[5] = {uint32_t(w), uint32_t(h), mips, kD3dFmtDxt1, total};
  for (int i = 0; i < 5; ++i) {
    out[i * 4] = uint8_t(header[i] >> 24); out[i * 4 + 1] = uint8_t(header[i] >> 16);
    out[i * 4 + 2] = uint8_t(header[i] >> 8); out[i * 4 + 3] = uint8_t(header[i]);
  }
  uint32_t lw = w, lh = h;
  for (uint32_t level = 0; level < mips; ++level) {
    if (level) {  // 2x2 box filter from the previous level
      const uint32_t nw = std::max(lw / 2, 1u), nh = std::max(lh / 2, 1u);
      std::vector<float> next(size_t(nw) * nh * 3);
      for (uint32_t y = 0; y < nh; ++y) {
        for (uint32_t x = 0; x < nw; ++x) {
          for (int c = 0; c < 3; ++c) {
            float sum = 0;
            for (uint32_t dy = 0; dy < 2; ++dy) for (uint32_t dx = 0; dx < 2; ++dx) {
              const uint32_t sx = std::min(x * 2 + dx, lw - 1), sy = std::min(y * 2 + dy, lh - 1);
              sum += img[(size_t(sy) * lw + sx) * 3 + c];
            }
            next[(size_t(y) * nw + x) * 3 + c] = sum / 4;
          }
        }
      }
      img = std::move(next);
      lw = nw;
      lh = nh;
    }
    const Level& L = levels[level];
    for (uint32_t by = 0; by < L.bh; ++by) {
      for (uint32_t bx = 0; bx < L.bw; ++bx) {
        float px[16][3];
        for (uint32_t i = 0; i < 16; ++i) {
          const uint32_t x = std::min(bx * 4 + i % 4, lw - 1), y = std::min(by * 4 + i / 4, lh - 1);
          for (int c = 0; c < 3; ++c) px[i][c] = img[(size_t(y) * lw + x) * 3 + c];
        }
        const auto block = EncodeBlock(px);
        const size_t at = 20 + size_t(L.offset) + TiledOffset(bx + L.x0, by + L.y0, L.pitch);
        for (int k = 0; k < 8; k += 2) {  // 8-in-16 endian swap
          out[at + k] = block[k + 1];
          out[at + k + 1] = block[k];
        }
      }
    }
  }
  return out;
}

// ===========================================================================
// Build
// ===========================================================================

struct GameDbs {
  Value bodies = Value::Obj();     // BoatBodyDB, base + DLC
  Value skins = Value::Obj();      // BoatSkinDB
  std::vector<Value> choices;      // every OptionDB/BoatConfig choice
  std::vector<Value> unlockables;  // UnlockDB/Unlockables
  std::vector<fs::path> sources;   // the archives these came from
};

void AddDbs(GameDbs& dbs, const fs::path& apf) {
  auto entries = ReadEntries(apf, [](const std::string& n) {
    return n == "AkDBAsset/BoatBodyDB" || n == "AkDBAsset/BoatSkinDB" ||
           n == "AkDBAsset/OptionDB" || n == "AkDBAsset/UnlockDB";
  });
  for (auto& [name, data] : entries) {
    Value root = DecodeTree(data);
    Value* db = root.find("AkDBAsset");
    if (!db || !db->is_object()) continue;
    if (name == "AkDBAsset/BoatBodyDB" || name == "AkDBAsset/BoatSkinDB") {
      Value& into = name == "AkDBAsset/BoatBodyDB" ? dbs.bodies : dbs.skins;
      for (auto& [k, v] : db->o) into[k] = std::move(v);
    } else if (name == "AkDBAsset/OptionDB") {
      if (Value* groups = db->find("BoatConfig"); groups && groups->is_array()) {
        for (auto& g : groups->a) {
          if (Value* c = g.find("Choices"); c && c->is_array()) {
            for (auto& choice : c->a) dbs.choices.push_back(std::move(choice));
          }
        }
      }
    } else if (Value* u = db->find("Unlockables"); u && u->is_array()) {
      for (auto& x : u->a) dbs.unlockables.push_back(std::move(x));
    }
  }
  dbs.sources.push_back(apf);
}

// The base game and every installed content package that is not a mod.
GameDbs LoadGameDbs(const fs::path& exe_dir, const fs::path& content_root) {
  GameDbs dbs;
  AddDbs(dbs, exe_dir / "game_data" / "Base.apf");
  std::error_code ec;
  std::vector<fs::path> packs;
  for (const auto& dir : fs::directory_iterator(content_root, ec)) {
    if (!dir.is_directory() || dir.path().filename().string().rfind(kPackagePrefix, 0) == 0) continue;
    for (const auto& f : fs::directory_iterator(dir.path(), ec)) {
      if (f.path().extension() == ".apf") packs.push_back(f.path());
    }
  }
  std::sort(packs.begin(), packs.end());
  for (const auto& p : packs) {
    try {
      AddDbs(dbs, p);
    } catch (const std::exception& e) {
      REXLOG_WARN("[ht-mods] skipping {} as a source of boats: {}", p.string(), e.what());
    }
  }
  return dbs;
}

const Value* FindChoice(const GameDbs& dbs, const std::string& boat) {
  for (const auto& c : dbs.choices) {
    if (c.str("Value") == boat && c.find("StringID")) return &c;  // the boat's own entry, not a skin merge
  }
  return nullptr;
}

const Value* FindUnlock(const GameDbs& dbs, const std::string& name) {
  for (const auto& u : dbs.unlockables) {
    if (u.str("Name") == name) return &u;
  }
  return nullptr;
}

Value FromToml(const toml::node& node, const std::string& where) {
  if (auto* t = node.as_table()) {
    Value v = Value::Obj();
    for (const auto& [k, child] : *t) v[std::string(k.str())] = FromToml(child, where);
    return v;
  }
  if (auto* a = node.as_array()) {
    Value v = Value::Arr();
    for (const auto& child : *a) v.a.push_back(FromToml(child, where));
    return v;
  }
  if (auto i = node.value_exact<int64_t>()) return Value::Int(int32_t(*i));
  if (auto d = node.value_exact<double>()) {
    Value v;
    v.type = Value::Type::Float;
    v.f = float(*d);
    return v;
  }
  if (auto b = node.value_exact<bool>()) return Value::Bool(*b);
  if (auto s = node.value_exact<std::string>()) return Value::Str(*s);
  throw ModError(where + ": unsupported value (dates and times are not allowed)");
}

// Tuning is merged over a copy of the base boat. Keys the base boat does not
// have are almost always typos, so they are reported rather than added.
void MergeTuning(Value& dst, const Value& src, const std::string& path, std::vector<std::string>& warnings) {
  for (const auto& [k, v] : src.o) {
    Value* have = dst.find(k);
    const std::string here = path.empty() ? k : path + "." + k;
    if (!have) {
      warnings.push_back("tuning." + here + " is not a setting of the base boat; ignored");
      continue;
    }
    if (v.is_object() && have->is_object()) {
      MergeTuning(*have, v, here, warnings);
    } else if (have->type == Value::Type::Float && v.type == Value::Type::Int) {
      have->type = Value::Type::Float;
      have->f = float(v.i);
    } else {
      *have = v;
    }
  }
}

struct BuiltMod {
  std::string id, name;
  std::vector<std::pair<std::string, std::vector<uint8_t>>> entries;
  std::vector<std::pair<std::string, std::string>> strings;
  std::vector<std::string> warnings;
};

const std::regex kModId("^[a-z][a-z0-9]{1,23}$");
const std::regex kItemId("^[A-Za-z][A-Za-z0-9]{0,31}$");

std::string RequireString(const toml::table& t, const char* key, const std::string& where) {
  auto v = t[key].value<std::string>();
  if (!v || v->empty()) throw ModError(where + ": '" + key + "' is required");
  return *v;
}

BuiltMod Build(const fs::path& dir, const toml::table& mod, const GameDbs& dbs) {
  BuiltMod out;
  out.id = RequireString(mod, "id", "mod.toml");
  if (!std::regex_match(out.id, kModId)) {
    throw ModError("id '" + out.id + "': use 2-24 lowercase letters and digits, starting with a letter");
  }
  out.name = mod["name"].value_or(out.id);
  const std::string& id = out.id;

  auto key_for = [&](const toml::table& t, const std::string& what) {
    const std::string item = RequireString(t, "id", what);
    if (!std::regex_match(item, kItemId)) {
      throw ModError(what + " id '" + item + "': letters and digits only, starting with a letter");
    }
    return std::make_pair(item, id + "_" + item);
  };
  auto text = [&](const std::string& k, const std::string& v) { out.strings.emplace_back(k, v); };
  auto upper = [](std::string s) {
    for (auto& c : s) c = char(std::toupper(static_cast<unsigned char>(c)));
    return s;
  };

  Value bodies = Value::Obj(), skins = Value::Obj(), choices = Value::Arr(), unlocks = Value::Arr();
  Value texture_index = Value::Obj();
  std::vector<std::pair<std::string, std::vector<uint8_t>>> textures;

  // Boats first, so skins can name them.
  struct Boat { std::string item, key, base; Value entry; };
  std::vector<Boat> boats;
  std::set<std::string> taken;
  if (auto* list = mod["boat"].as_array()) {
    for (const auto& node : *list) {
      const auto* t = node.as_table();
      if (!t) throw ModError("[[boat]] entries must be tables");
      auto [item, key] = key_for(*t, "boat");
      const std::string where = "boat " + item;
      const std::string base = RequireString(*t, "base", where);
      const Value* base_entry = dbs.bodies.find(base);
      if (!base_entry || !FindChoice(dbs, base)) {
        throw ModError(where + ": base boat '" + base + "' does not exist");
      }
      if (dbs.bodies.find(key) || !taken.insert(key).second) throw ModError(where + ": already exists");
      Value entry = *base_entry;
      if (auto* tuning = (*t)["tuning"].as_table()) {
        MergeTuning(entry, FromToml(*tuning, where + ".tuning"), "", out.warnings);
      }
      entry["StringID"] = Value::Str("BoatBody_" + key);
      const std::string name = (*t)["name"].value_or(item);
      const std::string info = (*t)["description"].value_or(std::string());
      text("BoatBody_" + key, upper(name));
      text("BoatBody_" + key + "_Info", info);
      text("Unlock_" + key, name);
      text("Unlock_" + key + "_Info", info);
      boats.push_back({item, key, base, std::move(entry)});
    }
  }
  auto boat_key = [&](const std::string& name) -> std::optional<std::string> {
    for (const auto& b : boats) if (b.item == name) return b.key;
    if (FindChoice(dbs, name)) return name;
    return std::nullopt;
  };

  std::map<std::string, std::vector<std::string>> skins_for;  // boat -> skin keys
  if (auto* list = mod["skin"].as_array()) {
    for (const auto& node : *list) {
      const auto* t = node.as_table();
      if (!t) throw ModError("[[skin]] entries must be tables");
      auto [item, key] = key_for(*t, "skin");
      const std::string where = "skin " + item;
      if (dbs.skins.find(key) || !taken.insert(key).second) throw ModError(where + ": already exists");
      std::string texture;
      if (auto reuse = (*t)["texture_asset"].value<std::string>()) {
        texture = *reuse;
      } else {
        const fs::path file = dir / RequireString(*t, "texture", where);
        texture = id + "/Skins/" + item;
        textures.emplace_back("AkTextureAsset/" + texture,
                              file.extension() == ".bin" ? ReadFile(file) : EncodeTexture(file));
        texture_index[texture]["File"] = Value::Str(texture + ".tga");
        texture_index[texture]["Type"] = Value::Str("DEFAULT");
      }
      skins[key]["Textures"]["DiffuseTexture"] = Value::Str(texture);
      const std::string name = (*t)["name"].value_or(item);
      text("BoatSkin_" + key, upper(name));
      text("Unlock_" + key, name);
      text("Unlock_" + key + "_Info", (*t)["description"].value_or(std::string()));
      std::string image = "UI/Award/Boat/Vector";
      const auto* on = (*t)["boats"].as_array();
      if (!on || on->empty()) throw ModError(where + ": 'boats' must list at least one boat");
      for (const auto& b : *on) {
        const std::string name_of = b.value_or(std::string());
        auto target = boat_key(name_of);
        if (!target) throw ModError(where + ": boat '" + name_of + "' does not exist");
        skins_for[*target].push_back(key);
        if (const Value* u = FindUnlock(dbs, name_of)) image = u->str("Image").empty() ? image : u->str("Image");
      }
      Value unlock = Value::Obj();
      unlock["Name"] = Value::Str(key);
      unlock["Type"] = Value::Str("Skin");
      unlock["Credits"] = Value::Int(0);
      unlock["AvailableInTrial"] = Value::Bool(true);
      unlock["StringID"] = Value::Str("Unlock_" + key);
      unlock["InfoStringID"] = Value::Str("Unlock_" + key + "_Info");
      unlock["Image"] = Value::Str(image);
      unlocks.a.push_back(std::move(unlock));
    }
  }

  for (auto& b : boats) {
    const Value* base_choice = FindChoice(dbs, b.base);
    std::vector<Value> base_skins, team;
    if (const Value* opts = base_choice->find("Options"); opts && opts->is_array()) {
      for (const auto& o : opts->a) {
        if (o.str("Name") != "Skin") continue;
        if (const Value* c = o.find("Choices"); c && c->is_array()) {
          for (const auto& s : c->a) {
            (s.str("Value").find("Team") != std::string::npos ? team : base_skins).push_back(s);
          }
        }
      }
    }
    Value skin_choices = Value::Arr();
    auto own = skins_for.find(b.key);
    if (own != skins_for.end()) {
      for (const auto& k : own->second) {
        Value c = Value::Obj();
        c["StringID"] = Value::Str("BoatSkin_" + k);
        c["Value"] = Value::Str(k);
        skin_choices.a.push_back(std::move(c));
      }
      skins_for.erase(own);
    } else {
      skin_choices.a = base_skins;  // no skins of its own: wear the base boat's
    }
    Value ai = Value::Arr();
    for (const auto& c : skin_choices.a) if (ai.a.size() < 3) ai.a.push_back(Value::Str(c.str("Value")));
    for (auto& t : team) skin_choices.a.push_back(t);
    b.entry["AISkins"] = std::move(ai);
    bodies[b.key] = std::move(b.entry);

    Value choice = Value::Obj();
    choice["Value"] = Value::Str(b.key);
    choice["StringID"] = Value::Str("BoatBody_" + b.key);
    choice["InfoStringID"] = Value::Str("BoatBody_" + b.key + "_Info");
    Value option = Value::Obj();
    option["Name"] = Value::Str("Skin");
    option["StringID"] = Value::Str("Option_Skin");
    option["Choices"] = std::move(skin_choices);
    choice["Options"].type = Value::Type::Array;
    choice["Options"].a.push_back(std::move(option));
    choices.a.push_back(std::move(choice));

    const Value* base_unlock = FindUnlock(dbs, b.base);
    Value unlock = Value::Obj();
    unlock["Name"] = Value::Str(b.key);
    unlock["Type"] = Value::Str("Body");
    unlock["Credits"] = Value::Int(0);
    unlock["AvailableInTrial"] = Value::Bool(true);
    unlock["StringID"] = Value::Str("Unlock_" + b.key);
    unlock["InfoStringID"] = Value::Str("Unlock_" + b.key + "_Info");
    unlock["Image"] = Value::Str(base_unlock && !base_unlock->str("Image").empty()
                                     ? base_unlock->str("Image") : "UI/Award/Boat/Vector");
    unlocks.a.push_back(std::move(unlock));
  }

  // Skins for existing boats: an entry with only the boat's Value, merged
  // into its choice by ht_mods_merge.cpp.
  for (const auto& [boat, keys] : skins_for) {
    Value list = Value::Arr();
    for (const auto& k : keys) {
      Value c = Value::Obj();
      c["StringID"] = Value::Str("BoatSkin_" + k);
      c["Value"] = Value::Str(k);
      list.a.push_back(std::move(c));
    }
    Value option = Value::Obj();
    option["Name"] = Value::Str("Skin");
    option["Choices"] = std::move(list);
    Value choice = Value::Obj();
    choice["Value"] = Value::Str(boat);
    choice["Options"].type = Value::Type::Array;
    choice["Options"].a.push_back(std::move(option));
    choices.a.push_back(std::move(choice));
  }

  std::vector<std::pair<std::string, Value>> dbs_out;
  if (!bodies.o.empty()) dbs_out.emplace_back("BoatBodyDB", std::move(bodies));
  if (!skins.o.empty()) dbs_out.emplace_back("BoatSkinDB", std::move(skins));
  if (!choices.a.empty()) {
    Value group = Value::Obj();
    group["Name"] = Value::Str("Body");
    group["Choices"] = std::move(choices);
    Value db = Value::Obj();
    db["BoatConfig"].type = Value::Type::Array;
    db["BoatConfig"].a.push_back(std::move(group));
    dbs_out.emplace_back("OptionDB", std::move(db));
  }
  if (!unlocks.a.empty()) {
    Value db = Value::Obj();
    db["Unlockables"] = std::move(unlocks);
    dbs_out.emplace_back("UnlockDB", std::move(db));
  }
  if (dbs_out.empty()) throw ModError("mod.toml adds nothing (no [[boat]] or [[skin]])");

  // Index entries first, like the shipped archives.
  Value generic;  // null, as in Pack01.apf
  out.entries.emplace_back("Assets/AkGenericAsset", EncodeTree(generic, false));
  Value db_index = Value::Obj();
  for (const auto& [n, v] : dbs_out) db_index[n]["File"] = Value::Str(id + "/DB/" + n + ".json");
  out.entries.emplace_back("Assets/AkDBAsset", EncodeTree(db_index, false));
  if (!texture_index.o.empty()) out.entries.emplace_back("Assets/AkTextureAsset", EncodeTree(texture_index, false));
  for (auto& [n, v] : dbs_out) {
    Value root = Value::Obj();
    root["AkDBAsset"] = std::move(v);
    out.entries.emplace_back("AkDBAsset/" + n, EncodeTree(root, true));
  }
  for (auto& t : textures) out.entries.push_back(std::move(t));
  return out;
}

// ===========================================================================
// Install
// ===========================================================================

std::string XmlEscape(const std::string& s) {
  std::string out;
  for (char c : s) {
    switch (c) {
      case '&': out += "&amp;"; break;
      case '<': out += "&lt;"; break;
      case '>': out += "&gt;"; break;
      case '"': out += "&quot;"; break;
      default: out += c;
    }
  }
  return out;
}

void WriteStrings(const fs::path& dir, const std::vector<std::pair<std::string, std::string>>& strings) {
  std::string xml = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n<root>\r\n";
  for (const auto& [k, v] : strings) {
    xml += "  <data name=\"" + XmlEscape(k) + "\">\r\n    <value>" + XmlEscape(v) + "</value>\r\n  </data>\r\n";
  }
  xml += "</root>\r\n";
  for (const char* lang : kLanguages) {
    WriteFile(dir / "Strings" / (std::string(lang) + ".resx"), xml.data(), xml.size());
  }
}

// XCONTENT_AGGREGATE_DATA, then the license mask as a host-endian u32 - the
// layout ContentManager reads (see WriteDlcHeader in ht_setup.cpp).
void WriteHeader(const fs::path& path, const std::string& package, const std::string& display) {
  std::vector<uint8_t> d(0x148 + 4, 0);
  d[3] = 1;  // device: HDD
  d[7] = 2;  // content type: marketplace
  for (size_t i = 0; i < display.size() && i < 127; ++i) d[8 + i * 2 + 1] = uint8_t(display[i]);
  std::memcpy(d.data() + 0x108, package.data(), std::min<size_t>(package.size(), 42));
  d[0x140] = 0x58; d[0x141] = 0x41; d[0x142] = 0x09; d[0x143] = 0x6A;  // title id
  const uint32_t license = 0xFFFFFFFFu;
  std::memcpy(d.data() + 0x148, &license, 4);
  WriteFile(path, d.data(), d.size());
}

uint64_t Fnv1a(uint64_t h, const void* data, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    h ^= static_cast<const uint8_t*>(data)[i];
    h *= 1099511628211ull;
  }
  return h;
}

// Everything a build depends on: the builder, every file in the mod, and the
// archives its base boats come from.
std::string Stamp(const fs::path& dir, const GameDbs& dbs) {
  uint64_t h = 1469598103934665603ull;
  h = Fnv1a(h, kBuilderVersion, std::strlen(kBuilderVersion));
  std::vector<fs::path> files;
  std::error_code ec;
  for (const auto& f : fs::recursive_directory_iterator(dir, ec)) {
    if (f.is_regular_file() && f.path().filename() != "build_error.txt") files.push_back(f.path());
  }
  std::sort(files.begin(), files.end());
  for (const auto& f : files) {
    const std::string rel = fs::relative(f, dir).generic_string();
    h = Fnv1a(h, rel.data(), rel.size());
    const auto data = ReadFile(f);
    h = Fnv1a(h, data.data(), data.size());
  }
  for (const auto& s : dbs.sources) {
    const std::string name = s.generic_string();
    const uint64_t size = fs::file_size(s, ec);
    h = Fnv1a(h, name.data(), name.size());
    h = Fnv1a(h, &size, sizeof size);
  }
  char hex[17];
  std::snprintf(hex, sizeof hex, "%016llx", static_cast<unsigned long long>(h));
  return hex;
}

std::string ReadText(const fs::path& path) {
  std::ifstream f(path, std::ios::binary);
  return std::string(std::istreambuf_iterator<char>(f), {});
}

ModError ManifestError(const toml::parse_error& e) {
  return ModError("mod.toml line " + std::to_string(e.source().begin.line) + ": " +
                  std::string(e.description()));
}

toml::table ParseManifest(const fs::path& path) {
  const std::string text = ReadText(path);
#if TOML_EXCEPTIONS
  try {
    return toml::parse(std::string_view(text), std::string_view("mod.toml"));
  } catch (const toml::parse_error& e) {
    throw ManifestError(e);
  }
#else
  toml::parse_result result = toml::parse(std::string_view(text), std::string_view("mod.toml"));
  if (!result) throw ManifestError(result.error());
  return std::move(result).table();
#endif
}

// ===========================================================================
// Skin templates
// ===========================================================================
//
// A skin is painted over a boat's UV layout, so modders start from the
// boat's own texture. If <exe>/mods/_templates/ exists and is empty, each
// boat's default skin is written there as <Boat>.png, with its full
// BoatBodyDB entry as <Boat>.json (the settings [boat.tuning] can change).
// Opt-in, because the set is around 20 MB.

// Level 0 of a DXT1 texture asset as 8-bit RGB.
std::vector<uint8_t> DecodeTexture(const std::vector<uint8_t>& data, uint32_t* width, uint32_t* height) {
  if (data.size() < 20 || Be32(data.data() + 12) != kD3dFmtDxt1) throw ModError("not a DXT1 texture");
  const uint32_t w = Be32(data.data()), h = Be32(data.data() + 4), mips = Be32(data.data() + 8);
  uint32_t total = 0;
  const Level L = TextureLayout(w, h, std::max(mips, 1u), &total)[0];
  if (data.size() < 20 + size_t(total)) throw ModError("truncated texture");
  std::vector<uint8_t> rgb(size_t(w) * h * 3);
  for (uint32_t by = 0; by < L.bh; ++by) {
    for (uint32_t bx = 0; bx < L.bw; ++bx) {
      const uint8_t* p = data.data() + 20 + L.offset + TiledOffset(bx, by, L.pitch);
      const uint16_t c0 = uint16_t(p[0] << 8 | p[1]), c1 = uint16_t(p[2] << 8 | p[3]);  // 8-in-16
      const uint32_t idx = uint32_t(p[5]) | uint32_t(p[4]) << 8 | uint32_t(p[7]) << 16 | uint32_t(p[6]) << 24;
      float pal[4][3];
      From565(c0, pal[0]);
      From565(c1, pal[1]);
      for (int c = 0; c < 3; ++c) {
        pal[2][c] = c0 > c1 ? (2 * pal[0][c] + pal[1][c]) / 3 : (pal[0][c] + pal[1][c]) / 2;
        pal[3][c] = c0 > c1 ? (pal[0][c] + 2 * pal[1][c]) / 3 : 0;
      }
      for (uint32_t i = 0; i < 16; ++i) {
        const uint32_t x = bx * 4 + i % 4, y = by * 4 + i / 4;
        if (x >= w || y >= h) continue;
        for (int c = 0; c < 3; ++c) rgb[(size_t(y) * w + x) * 3 + c] = uint8_t(pal[(idx >> (2 * i)) & 3][c]);
      }
    }
  }
  *width = w;
  *height = h;
  return rgb;
}

// Value as indented JSON, for the templates' tuning reference.
void WriteJson(const Value& v, std::string& out, int indent) {
  const std::string pad(size_t(indent) * 2, ' '), inner(size_t(indent + 1) * 2, ' ');
  switch (v.type) {
    case Value::Type::Null: out += "null"; break;
    case Value::Type::Int: out += std::to_string(v.i); break;
    case Value::Type::Float: {
      char buf[32];
      std::snprintf(buf, sizeof buf, "%.7g", double(v.f));
      out += buf;
      if (!std::strpbrk(buf, ".eEn")) out += ".0";  // keep it a float
      break;
    }
    case Value::Type::Bool: out += v.b ? "true" : "false"; break;
    case Value::Type::Str: {
      out += '"';
      for (char c : v.s) {
        if (c == '"' || c == '\\') out += '\\';
        out += c;
      }
      out += '"';
      break;
    }
    case Value::Type::Array:
      out += "[";
      for (size_t i = 0; i < v.a.size(); ++i) {
        out += (i ? ",\n" : "\n") + inner;
        WriteJson(v.a[i], out, indent + 1);
      }
      out += v.a.empty() ? "]" : "\n" + pad + "]";
      break;
    case Value::Type::Object:
      out += "{";
      for (size_t i = 0; i < v.o.size(); ++i) {
        out += (i ? ",\n" : "\n") + inner + "\"" + v.o[i].first + "\": ";
        WriteJson(v.o[i].second, out, indent + 1);
      }
      out += v.o.empty() ? "}" : "\n" + pad + "}";
      break;
  }
}

#if defined(_WIN32)
bool SavePng(const fs::path& path, const std::vector<uint8_t>& rgb, uint32_t w, uint32_t h) {
  std::vector<uint8_t> bgr(rgb.size());
  for (size_t i = 0; i < rgb.size(); i += 3) {
    bgr[i] = rgb[i + 2];
    bgr[i + 1] = rgb[i + 1];
    bgr[i + 2] = rgb[i];
  }
  Gdiplus::Bitmap bitmap(int(w), int(h), int(w * 3), PixelFormat24bppRGB, bgr.data());
  static const CLSID kPng = {0x557CF406, 0x1A04, 0x11D3, {0x9A, 0x73, 0x00, 0x00, 0xF8, 0x1E, 0xF3, 0x2E}};
  return bitmap.Save(path.wstring().c_str(), &kPng, nullptr) == Gdiplus::Ok;
}

size_t ExportTemplates(const fs::path& out_dir, const fs::path& exe_dir, const fs::path& content_root) {
  GameDbs dbs = LoadGameDbs(exe_dir, content_root);
  std::map<std::string, std::string> wanted;  // texture asset -> boat
  for (const auto& choice : dbs.choices) {
    const std::string boat = choice.str("Value");
    if (boat.empty() || !choice.find("StringID")) continue;
    // Every setting a [boat.tuning] table can change.
    if (const Value* body = dbs.bodies.find(boat)) {
      std::string json;
      WriteJson(*body, json, 0);
      json += "\n";
      WriteFile(out_dir / (boat + ".json"), json.data(), json.size());
    }
    const Value* opts = choice.find("Options");
    if (!opts || !opts->is_array()) continue;
    for (const auto& o : opts->a) {
      const Value* c = o.find("Choices");
      if (o.str("Name") != "Skin" || !c || !c->is_array() || c->a.empty()) continue;
      const Value* skin = dbs.skins.find(c->a[0].str("Value"));
      const Value* tex = skin ? skin->find("Textures") : nullptr;
      if (tex && !tex->str("DiffuseTexture").empty()) wanted["AkTextureAsset/" + tex->str("DiffuseTexture")] = boat;
    }
  }
  ULONG_PTR token = 0;
  Gdiplus::GdiplusStartupInput input;
  if (Gdiplus::GdiplusStartup(&token, &input, nullptr) != Gdiplus::Ok) throw ModError("GDI+ is unavailable");
  size_t written = 0;
  for (const auto& src : dbs.sources) {
    std::map<std::string, std::vector<uint8_t>> found;
    try {
      found = ReadEntries(src, [&](const std::string& n) { return wanted.count(n) != 0; });
    } catch (const std::exception&) {
      continue;
    }
    for (const auto& [name, data] : found) {
      try {
        uint32_t w = 0, h = 0;
        const auto rgb = DecodeTexture(data, &w, &h);
        if (SavePng(out_dir / (wanted[name] + ".png"), rgb, w, h)) ++written;
      } catch (const std::exception& e) {
        REXLOG_WARN("[ht-mods] template {}: {}", name, e.what());
      }
    }
  }
  Gdiplus::GdiplusShutdown(token);
  REXLOG_INFO("[ht-mods] wrote {} skin templates to {}", written, out_dir.string());
  return written;
}
#endif

}  // namespace

namespace {

std::vector<ModStatus> g_status;

struct Paths {
  fs::path mods, title, content, headers;
  explicit Paths(const fs::path& exe_dir)
      : mods(exe_dir / "mods"),
        title(exe_dir / "user_data" / "0000000000000000" / kTitleId),
        content(title / kMarketplace),
        headers(title / "Headers" / kMarketplace) {}
};

}  // namespace

void BuildMods(const fs::path& exe_dir) {
  const Paths paths(exe_dir);
  std::error_code ec;
  fs::create_directories(paths.mods, ec);

  std::ostringstream report;
  std::set<std::string> keep;  // package names that belong to a current mod
  std::optional<GameDbs> dbs;
  g_status.clear();

  std::vector<fs::path> dirs;
  for (const auto& d : fs::directory_iterator(paths.mods, ec)) {
    if (d.is_directory() && fs::exists(d.path() / "mod.toml")) dirs.push_back(d.path());
  }
  std::sort(dirs.begin(), dirs.end());

  for (const auto& dir : dirs) {
    ModStatus st;
    st.folder = dir.filename().string();
    try {
      toml::table mod = ParseManifest(dir / "mod.toml");
      st.id = mod["id"].value_or(std::string());
      st.name = mod["name"].value_or(st.id.empty() ? st.folder : st.id);
      st.version = mod["version"].value_or(std::string());
      st.author = mod["author"].value_or(std::string());
      if (auto* b = mod["boat"].as_array()) st.boats = int(b->size());
      if (auto* s = mod["skin"].as_array()) st.skins = int(s->size());
      if (fs::exists(dir / kDisabledMarker) || !mod["enabled"].value_or(true)) {
        st.enabled = false;
        st.state = ModStatus::State::kDisabled;
        report << st.folder << ": disabled\n";
        g_status.push_back(std::move(st));
        continue;
      }
      const std::string package = kPackagePrefix + st.id;
      if (keep.count(package)) throw ModError("another mod already uses the id '" + st.id + "'");
      if (!dbs) dbs = LoadGameDbs(exe_dir, paths.content);
      const std::string stamp = Stamp(dir, *dbs);
      const fs::path target = paths.content / package;
      if (!st.id.empty() && ReadText(target / "mod.stamp") == stamp &&
          fs::exists(paths.headers / (package + ".header"))) {
        keep.insert(package);
        st.state = ModStatus::State::kLoaded;
        st.message = "up to date";
        report << st.folder << ": up to date (" << st.id << ")\n";
        g_status.push_back(std::move(st));
        continue;
      }

      BuiltMod built = Build(dir, mod, *dbs);
      // Write the package beside the content root and move it in complete:
      // every folder in the content root is mounted as a package.
      const fs::path staging = paths.title / ("." + package + ".tmp");
      fs::remove_all(staging, ec);
      WriteArchive(staging / (st.id + ".apf"), built.entries);
      WriteStrings(staging, built.strings);
      WriteFile(staging / "mod.stamp", stamp.data(), stamp.size());
      fs::remove_all(target, ec);
      fs::create_directories(paths.content, ec);
      fs::rename(staging, target);
      WriteHeader(paths.headers / (package + ".header"), package, built.name);
      fs::remove(dir / "build_error.txt", ec);
      keep.insert(package);

      st.state = ModStatus::State::kLoaded;
      st.message = "built";
      st.warnings = built.warnings;
      report << st.folder << ": built (" << st.id << ") - " << st.boats << " boat(s), " << st.skins
             << " skin(s)\n";
      REXLOG_INFO("[ht-mods] built mod '{}': {} boat(s), {} skin(s)", st.id, st.boats, st.skins);
      for (const auto& w : built.warnings) {
        report << "  warning: " << w << "\n";
        REXLOG_WARN("[ht-mods] {}: {}", st.id, w);
      }
    } catch (const std::exception& e) {
      st.state = ModStatus::State::kError;
      st.message = e.what();
      report << st.folder << ": NOT LOADED - " << e.what() << "\n";
      REXLOG_ERROR("[ht-mods] {}: {}", st.folder, e.what());
      try {
        WriteFile(dir / "build_error.txt", st.message.data(), st.message.size());
      } catch (const std::exception&) {
      }
    }
    g_status.push_back(std::move(st));
  }

  // Packages whose mod is gone, disabled or broken.
  for (const auto& d : fs::directory_iterator(paths.content, ec)) {
    const std::string name = d.path().filename().string();
    if (!d.is_directory() || name.rfind(kPackagePrefix, 0) != 0 || keep.count(name)) continue;
    fs::remove_all(d.path(), ec);
    fs::remove(paths.headers / (name + ".header"), ec);
    report << "removed package " << name << "\n";
    REXLOG_INFO("[ht-mods] removed package {}", name);
  }

#if defined(_WIN32)
  const fs::path templates = paths.mods / "_templates";
  if (fs::is_directory(templates, ec) && fs::is_empty(templates, ec)) {
    report << ExportSkinTemplates(exe_dir) << "\n";
  }
#endif

  const std::string text = report.str().empty() ? std::string("no mods installed\n") : report.str();
  try {
    WriteFile(paths.mods / "mods_log.txt", text.data(), text.size());
  } catch (const std::exception&) {
  }
}

const std::vector<ModStatus>& ModStatuses() { return g_status; }

bool SetModEnabled(const fs::path& exe_dir, const std::string& folder, bool enabled) {
  const fs::path marker = Paths(exe_dir).mods / folder / kDisabledMarker;
  std::error_code ec;
  if (enabled) return fs::remove(marker, ec) || !fs::exists(marker, ec);
  try {
    WriteFile(marker, "", 0);
    return true;
  } catch (const std::exception&) {
    return false;
  }
}

std::string ExportSkinTemplates(const fs::path& exe_dir) {
#if defined(_WIN32)
  const Paths paths(exe_dir);
  const fs::path out = paths.mods / "_templates";
  try {
    fs::create_directories(out);
    const size_t written = ExportTemplates(out, exe_dir, paths.content);
    return "wrote " + std::to_string(written) + " skin templates to mods/_templates";
  } catch (const std::exception& e) {
    return std::string("could not write skin templates: ") + e.what();
  }
#else
  (void)exe_dir;
  return "skin templates need Windows";
#endif
}

}  // namespace ht
