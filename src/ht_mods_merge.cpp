// Mod support: changes to the game's own code that additive content needs.
//
// See MODDING_PLAN.md for the whole design. Content packs (the DLC, and mods
// installed the same way) carry DB *fragments* that the engine merges into the
// base game's databases.
//
// ---------------------------------------------------------------------------
// The fragment merge matches array items by "Name" only
// ---------------------------------------------------------------------------
// sub_821A8FD0 merges a fragment node into the loaded one: objects by key,
// scalars must be equal, and arrays item by item - an item whose "Name"
// matches an existing item's is merged into it, anything else is appended.
//
// Boat choices in OptionDB/BoatConfig have no "Name"; they are keyed by
// "Value". So a fragment entry meant to add a skin to an existing boat,
//     {"Value": "Vector", "Options": [{"Name": "Skin", "Choices": [...]}]}
// is appended as a SECOND "Vector" choice instead. The boat menu steps through
// choices by looking up the current Value, so it reaches the duplicate, jumps
// back to the first "Vector" and loops: every boat after the duplicate is
// unreachable. That is why the DLC's six "X" boats never appear and its extra
// skins for the base boats are missing, and it would hide every mod boat that
// loads after any skin added to an existing boat.
//
// The fix: an array item with no "Name" is matched by "Value" instead.
// Simulated over the base game and the DLC, this changes exactly the nine
// duplicate BoatConfig entries in the DLC and nothing else.

#include <cstdint>
#include <string>

#include <rex/hook.h>
#include <rex/logging.h>

#include "hydrothunder_init.h"

namespace {

// Keys the game itself uses, as guest C strings.
constexpr uint32_t kKeyName = 0x820CBC70;   // "Name"
constexpr uint32_t kKeyValue = 0x820CBCF4;  // "Value"

constexpr uint32_t kNodeArray = 5;

using GuestFn = void (*)(PPCContext&, uint8_t*);

uint32_t Call(PPCContext& ctx, uint8_t* base, GuestFn fn, uint32_t r3, uint32_t r4 = 0,
              uint32_t r5 = 0) {
  ctx.r3.u64 = r3;
  ctx.r4.u64 = r4;
  ctx.r5.u64 = r5;
  fn(ctx, base);
  return ctx.r3.u32;
}

// A node is 16 bytes: u32 type, then for an array a pointer at +8 to its
// element vector (begin, end).
uint32_t ArrayLength(uint8_t* base, uint32_t node) {
  if (REX_LOAD_U32(node) != kNodeArray) return 0;
  const uint32_t vec = REX_LOAD_U32(node + 8);
  return (REX_LOAD_U32(vec + 4) - REX_LOAD_U32(vec)) >> 4;
}

// The guest's std::string: 16-byte inline buffer or pointer, size at +16,
// capacity at +20.
std::string GuestString(uint8_t* base, uint32_t str) {
  const uint32_t size = REX_LOAD_U32(str + 16);
  const uint32_t data = REX_LOAD_U32(str + 20) < 16 ? str : REX_LOAD_U32(str);
  std::string out(size, '\0');
  for (uint32_t i = 0; i < size; ++i) out[i] = static_cast<char>(base[data + i]);
  return out;
}

// item[key] as a string; empty when the item is not an object, lacks the key
// or holds something else. Same accessors the original uses.
std::string MemberString(PPCContext& ctx, uint8_t* base, uint32_t item, uint32_t key) {
  const uint32_t member = Call(ctx, base, sub_8215F338, item, key);
  return GuestString(base, Call(ctx, base, sub_8215FA30, member));
}

}  // namespace

REX_HOOK_RAW(sub_821A8FD0) {
  const uint32_t self = ctx.r3.u32, dst = ctx.r4.u32, src = ctx.r5.u32;
  if (REX_LOAD_U32(src) != kNodeArray || REX_LOAD_U32(dst) != kNodeArray) {
    __imp__sub_821A8FD0(ctx, base);
    return;
  }

  // The original array branch, with "Value" as the fallback key.
  const uint32_t count = ArrayLength(base, src);
  for (uint32_t i = 0; i < count; ++i) {
    uint32_t key = kKeyName;
    std::string want = MemberString(ctx, base, Call(ctx, base, sub_8215F1B0, src, i), kKeyName);
    if (want.empty()) {
      key = kKeyValue;
      want = MemberString(ctx, base, Call(ctx, base, sub_8215F1B0, src, i), kKeyValue);
    }

    bool merged = false;
    if (!want.empty()) {
      const uint32_t have = ArrayLength(base, dst);
      for (uint32_t j = 0; j < have && !merged; ++j) {
        if ((Call(ctx, base, sub_8215F418, Call(ctx, base, sub_8215F200, dst, j), key) & 0xFF) == 0) {
          continue;
        }
        const uint32_t member =
            Call(ctx, base, sub_8215F670, Call(ctx, base, sub_8215F200, dst, j), key);
        if (GuestString(base, Call(ctx, base, sub_8215FA30, member)) != want) continue;

        const uint32_t from = Call(ctx, base, sub_8215F1B0, src, i);
        const uint32_t into = Call(ctx, base, sub_8215F200, dst, j);
        if ((Call(ctx, base, sub_821A8FD0, self, into, from) & 0xFF) == 0) {
          ctx.r3.u64 = 0;
          return;
        }
        if (key == kKeyValue) {
          REXLOG_INFO("[ht-mods] merged a content-pack entry into '{}' by Value", want);
        }
        merged = true;
      }
    }
    if (!merged) {
      const uint32_t from = Call(ctx, base, sub_8215F1B0, src, i);
      const uint32_t slot = Call(ctx, base, sub_8215F270, dst);
      Call(ctx, base, sub_8215EFB0, slot, from);
    }
  }
  ctx.r3.u64 = 1;
}
