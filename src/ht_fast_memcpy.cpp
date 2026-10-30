// Native memcpy for the game's C runtime memcpy.
//
// sub_826A1E70 is the CRT memcpy (dst in r3, src in r4, size in r5, returns
// dst; copies forward, 8 bytes at a time when aligned). It is called from
// 1500 places, and the render thread spends about a third of its time in it,
// copying vertex and constant data for the GPU. Recompiled, every 8 bytes is
// a volatile, byte-swapped load and store: no vectorisation, and the swaps
// cancel out. The main thread waits for the render thread each frame, so this
// copy sits on the critical path of every frame.
//
// A byte copy is a byte copy in either byte order, so a host memmove through
// the same address translation leaves guest memory exactly as the original
// would. The original runs instead whenever that could differ:
// - overlapping ranges, where its forward 8-byte chunks define the result;
// - ranges touching the GPU registers, which trap and are decoded per
//   instruction by the MMIO handler;
// - ranges crossing 0xE0000000, where the host offset changes.

#include <cstdint>
#include <cstring>

#include <rex/cvar.h>
#include <rex/hook.h>

#include "hydrothunder_init.h"

REXCVAR_DEFINE_BOOL(ht_native_memcpy, true, "Performance",
                    "Run the game's memcpy natively. Same result, several times faster");

namespace {

constexpr uint64_t kMmioBegin = 0x7FC00000;
constexpr uint64_t kMmioEnd = 0x80000000;
constexpr uint64_t kHostOffsetBoundary = 0xE0000000;

bool RangeIsPlain(uint64_t begin, uint64_t end) {
  if (end > (uint64_t(1) << 32)) {
    return false;
  }
  if (begin < kMmioEnd && end > kMmioBegin) {
    return false;
  }
  return end <= kHostOffsetBoundary || begin >= kHostOffsetBoundary;
}

}  // namespace

REX_HOOK_RAW(sub_826A1E70) {
  const uint32_t dst = ctx.r3.u32;
  const uint32_t src = ctx.r4.u32;
  const uint32_t size = ctx.r5.u32;
  const uint64_t dst_end = uint64_t(dst) + size;
  const uint64_t src_end = uint64_t(src) + size;
  if (!size || !REXCVAR_GET(ht_native_memcpy) || (dst < src_end && src < dst_end) ||
      !RangeIsPlain(dst, dst_end) || !RangeIsPlain(src, src_end)) {
    __imp__sub_826A1E70(ctx, base);
    return;
  }
  // The original's first instruction; r3 is left as dst, its return value.
  REX_STORE_U64(ctx.r1.u32 + -8, ctx.r3.u64);
  std::memcpy(REX_RAW_ADDR(dst), REX_RAW_ADDR(src), size);
}
