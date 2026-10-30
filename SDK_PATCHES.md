# Local changes to `third_party/rexglue-sdk`

The SDK is a vendored dependency. Every change listed here lives **inside** that
tree, so an SDK upgrade will silently drop it unless it is re-applied. Nothing
below is upstreamable as-is.

Keep this file current. If you add an SDK-side change, add it here in the same
turn — the cost of rediscovering one of these is measured in days.

---

## 1. Depth-test additive draws the guest issued with depth disabled

**Files**
- `src/graphics/d3d12/pipeline_cache.cpp` — in `ConfigurePipeline`, just before
  `host_msaa_samples` is computed
- `src/graphics/flags.cpp`, `include/rex/graphics/flags.h` — the
  `force_additive_depth_test` cvar (GPU category, `kHotReload`, default **on**)

**Symptom** Point lights drew through terrain and through the player's boat,
from the first working boot onward.

**Cause (as far as it was established)** The game draws its point lights as four
additive `SRC_ALPHA/ONE` billboard quads (6 indices each) with
`RB_DEPTHCONTROL.z_enable` clear, while still leaving `zfunc=LESS` programmed and
a depth target bound.

**Why nothing else occluded them** — all verified from RenderDoc captures, do not
re-chase:
- no host occlusion queries anywhere in the frame (zero query chunks)
- no `PM4_VIZ_QUERY` (the handler logs on use and never fired)
- the pixel shader samples one `texture2darray`, with no depth read and no discard
- the vertex shader only does `ld_raw` from shared memory (vertex fetch emulation)
- `RB_MODECONTROL.edram_mode` was `kColorDepth`, so `GetNormalizedDepthControl`
  was NOT the one disabling depth

**Fix** Re-enable the depth test for that exact draw signature, using the compare
function the guest left in the register rather than assuming one. Skipped when
the guest programmed `kAlways`, since there would be nothing to gain.

> ⚠ **This is a workaround, not a root-cause fix.** We never established *why*
> the guest clears `z_enable` here. It pattern-matches on blend mode, so it could
> in principle catch an unrelated additive effect that genuinely wants to draw on
> top. If it ever misfires, the next diagnostic is to trace which PM4 packet last
> wrote `RB_DEPTHCONTROL` before those draws, to see whether a register write is
> being lost. Set `force_additive_depth_test = false` to compare instantly.

---

## 2. ImGui overlays drew nothing (obsolete CmdListsCount)

**File** `src/ui/imgui_drawer.cpp` - `RenderDrawLists`

**Symptom** Every overlay was invisible: F3 debug, F4 settings, backtick
console, and our own F5 panel. The keybind fired, the dialog was constructed,
ImGui ran a full frame - and nothing appeared on screen.

**Cause** `ImDrawData::CmdListsCount` has been obsolete since Dear ImGui 1.89.8
and is **not maintained by the normal render path**. Only the public
`ImDrawData::AddDrawList()` helper updates it; `ImGui::Render()` populates
`CmdLists` through `AddDrawListToDrawDataEx`, and `SetupViewportDrawData` resets
the counter to 0. The loop `for (i = 0; i < data->CmdListsCount; ++i)` therefore
never executed a single iteration.

Measured against the vendored imgui 1.92.9, after `ImGui::Render()`:

    CmdListsCount = 0        <- what the SDK iterated
    CmdLists.Size = 1        <- the real count
    TotalVtxCount = 1284     <- geometry was there all along

**Fix** Iterate `data->CmdLists.Size`.

This is a straightforward upstream bug introduced by an ImGui version bump, not
a game-specific workaround - it is worth reporting to the SDK author, and it
should be dropped from this file once fixed upstream.

---

## 3. `fov_probe` diagnostic cvar

**Files** `src/graphics/d3d12/command_processor.cpp`, `src/graphics/flags.cpp`,
`include/rex/graphics/flags.h`

Samples the guest vertex float constants over 900 depth-tested draws and logs
the low-variance slots, to locate camera matrices. Armed by F7 in htrecomp,
self-clearing, off by default, one branch per draw when off.

This is how the main camera was located: **`c8..c11`, column-major, 100.000
degrees horizontal at exactly 16:9** (`|c8.xyz| = cot(50 deg) = 0.83910`).
The FOV *override* built on that was reverted - see investigation-map.md for
both attempts and why they failed.

---

## 4. XMA context merge no longer clobbers the guest's read offset

**File** `src/audio/xma_context.cpp` — `StoreContextMerged`

Dropped `fresh.output_buffer_read_offset = data.output_buffer_read_offset;`.
The guest owns that field via `XMASetOutputBufferReadOffset`; copying it back
fights the guest for ownership.

> ⚠ **Unproven.** Written while chasing the audio stutter, which turned out to be
> timer resolution (see below). This was never independently shown to fix
> anything. It matches Xenia's ownership model, which is the only reason it is
> still here. A candidate for reverting if audio ever misbehaves.

---

## 5. XMA decoder context kick made asynchronous

**File** `src/audio/xma_decoder.cpp`

Removed the blocking `WaitForWorkDone()` loop on the context-kick path, matching
Xenia.

> ⚠ **Unproven.** Same caveat as #4 — same debugging session, same lack of
> independent evidence.

---

## 6. DLC enumeration returned an uninitialized record

**File** `src/system/xam/content_manager.cpp` — `ContentManager::ListContent`

**Symptom** With the DLC installed, pressing Start on the title screen ended the
game. Whether the process then crashed or just sat there varied run to run, which
is why it was first reported as "crashes most of the time". The guest dying was
deterministic every time: the log shows `Execution complete` right after the press.

**Cause** `ListContent` tested `ReadContentHeaderFile` with `XSUCCEEDED`. That
macro is an NTSTATUS test (`(s & 0xC0000000) == 0`), but the function returns
Win32-style `X_RESULT`s, and `X_ERROR_FILE_NOT_FOUND` (2) passes it. So a package
with no `.header` file went down the "header was read" branch and was enumerated
as an **uninitialized** `XCONTENT_AGGREGATE_DATA` (host stack garbage). The game
opens each enumerated package using its file name as the root name, so
`XamContentCreate` got that garbage, `rex::to_path` threw `utf8::invalid_utf8`
from `ResolvePackagePath`, and the C++ exception unwound through the guest
thread. The randomness came from the stack contents, not from the DLC.

**Evidence** A C++-exception backtrace in the VEH (`XamContentCreateEx ->
ContentExists -> ResolvePackagePath -> to_path -> utf8to16`). Hooking
`XContentCreate` (`sub_823EDCE0`) and `XEnumerate` (`sub_823EDE50`) showed
`XamEnumerate` returning count 1 with host stack pointers in the buffer.
`ListContent` called directly returned the same garbage. With a valid `.header`
written, 3/3 runs survived where 3/3 had died, and a DLC race loaded.

**Fix** Compare against `X_ERROR_SUCCESS`. The no-header fallback that
synthesises the record from the directory name now runs as intended, so a
header-less package no longer kills the game. It is still **hidden**, though: with
no header, `OpenContent` reports license mask 0 and the game leaves unlicensed DLC
out of the track list. That is why `src/ht_setup.cpp` writes a real `.header`
(display name plus the full license mask) on import, and backfills one for any
installed DLC folder that lacks it. The mask is the full one rather than the
package's own bit 0, which shows the DLC's tracks but hides its boats.

> The other `XSUCCEEDED(result)` uses in `src/kernel/xam/xam_content.cpp` have
> the same mismatch but are harmless here (they only decide whether to write a
> header or a license mask after a call that already failed). Left alone.

---

## 7. Profile name setter

**File** `include/rex/system/xam/user_profile.h`

**Change** One line in `UserProfile`, after `name()`:

```cpp
void set_name(std::string name) { name_ = std::move(name); }
```

**Why** The profile's gamertag is hardcoded to "User" in its constructor and
has no setter. `src/ht_player_name.cpp` sets it from the `player_name` setting
before the game's main thread starts. The setter is inline, so the SDK library
itself does not change.

Saves are filed by the profile's XUID, so renaming never moves a save. The name
does appear in one path, `ResolveGameUserContentPath` (title-specific profile
settings, `<title>/profile/<name>/`), but Hydro Thunder never writes any.

---

## 8. GPU timing (`ht_gpu_perf`)

**Files** `include/rex/graphics/d3d12/ht_gpu_perf.h` and
`src/graphics/d3d12/ht_gpu_perf.cpp` (new; add the .cpp to
`src/graphics/CMakeLists.txt`), `include/rex/graphics/d3d12/command_processor.h`,
`src/graphics/d3d12/command_processor.cpp`,
`src/graphics/d3d12/render_target_cache.cpp`,
`src/graphics/d3d12/texture_cache.cpp`

**Change**
- **Timestamps.** D3D12 timestamp queries bracket each submission's command list (in `EndSubmission`, around `deferred_command_list_.Execute`). They also bracket three kinds of work: `HtGpuPerf::Scope` around `D3D12RenderTargetCache::PerformTransfersAndResolveClears`, `D3D12RenderTargetCache::Resolve` and `D3D12TextureCache::LoadTextureDataFromResidentMemoryImpl`.
- **Readback.** Results are read back when the submission's fence completes (`BeginSubmission`), averaged over 5 seconds, logged as `[ht-perf]` and exposed through `GetHtGpuPerfSnapshot()`, which the F6 overlay reads.
- **Nesting.** Nested scopes count only toward the outermost one.

The transfer scope opens only when a call has transfers or clears to do. The function runs for every draw, and timing empty calls added two queries per draw and overflowed a submission's 1023 pairs. The log also gives the number of transfers, resolves and texture loads per frame.

Sub-scopes (`Scope(..., sub = true)`) time parts inside those without touching the nesting depth: the texture copy in a load, the dump (`DumpRenderTargets`) and the copy dispatch in a resolve. A second `[ht-perf] parts:` line reports them.

**Why** Without it there is no way to tell what the GPU is spending its time on. It found that render target transfers were 41% of a race's GPU time. Off by default, and it costs one branch per scope when off.

---

## 9. 4x MSAA clears drawn at 1x (`ht_msaa_clear_remap`)

**Files** `include/rex/graphics/pipeline/render_target/cache.h` and
`src/graphics/pipeline/render_target/cache.cpp` (`HtClearCanUse1x`),
`include/rex/graphics/util/draw_extent_estimator.h` and
`src/graphics/util/draw_extent_estimator.cpp` (`HtRectangleOutputsConstant`),
`src/graphics/d3d12/command_processor.cpp` (`IssueDraw`, before primitive
processing)

**Change** A qualifying draw gets its registers rewritten for that draw only and restored by an RAII guard:
- `RB_SURFACE_INFO` set to 1x with double the pitch;
- the viewport transform enabled with scale 2 (plus a half-pixel offset when `half_pixel_offset` applies);
- the window and screen scissors doubled.

A draw qualifies when all of these hold:
- **The draw itself:** a 4x screen-space, auto-indexed 3-vertex rectangle (VTE off, `vtx_xy_fmt` set).
- **State:** no alpha test or alpha to mask, no polygon offset, no window offset, full AA mask, and depth either disabled or `kAlways`.
- **Pixel shader:** no textures, kill or depth write.
- **Vertex shader:** gives all three vertices identical depth and interpolators, checked by running it on the CPU.
- **Ownership:** 1x render targets already own every tile the clear touches and the 4x ones do not.

**Why** The game clears its shadow and depth buffers through a 4x view of memory that it then draws into at 1x, about five times a frame. Each such clear cost two whole-target ownership transfers (1x to 4x before it, 4x back to 1x at the next draw). A clear writes one value to every sample, so drawing it at 1x over the same tiles leaves EDRAM identical. Transfers went from 4.2 to 1.1 ms per frame on an RTX 3050 laptop. A pixel comparison of a paused race with it on and off differs by 0 pixels; a deliberately shifted variant differs by thousands.

The idea comes from HydroThunderPORT's Vulkan renderer. This is a separate implementation for D3D12.

---

## 10. `execute_unclipped_draw_vs_on_cpu` defaults to true

**File** `src/graphics/util/draw_extent_estimator.cpp`

**Change** The cvar's default changes from `false` to `true`, as in Xenia.

**Why** With it off, a screen-space draw without clipping (every clear) is assumed to cover the whole render target height, up to all of EDRAM. That causes ownership transfers for memory the draw never touches. It also gives patch 9 the clears' real extents to work with. GPU time per frame drops by about 7% on its own.

---

## 11. Known-register table in `CommandProcessor::WriteRegister`

**File** `src/graphics/command_processor.cpp`

**Change** The `GetRegisterInfo(index)` check, which only decides whether to log a debug line about an unknown register, reads a `std::vector<bool>` built once instead.

**Why** `GetRegisterInfo` is a `switch` over about a thousand sparse cases, each with a guarded function-local static. Called on every register write, it was 7% of the GPU command thread's time. Race fps went from 106 to 115.

---

## 12. No debug file write in the exception handler

**File** `src/core/exception_handler_win.cpp`

**Change** Removed a block in `ExceptionHandlerCallback` that, on every access violation, opened `D:\htrecomp-main\htrecomp\veh_crash_dump.txt` and wrote the registers to it.

**Why** Access violations are not crashes here: they are how the GPU emulation's write watches see the game write to memory it caches, hundreds of times a second in a race. Where that folder exists, the render thread spent 73% of its time opening the file, and race fps went from 65 to 92 once it was gone. Elsewhere each open failed quickly, but it was still a system call per fault. The path shows it was a local debugging change, so check that your copy
doesn't have it.

---

## 13. Type-0 register runs written in bulk (`ht_register_range_writes`)

**File** `src/graphics/command_processor.cpp` (`ExecutePacketType0`)

**Change** A type-0 packet that writes a run of registers (not the one-register form) goes through `WriteRegisterRangeFromRing`. The D3D12 backend's `WriteRegistersFromMem` then copies shader constants, bool/loop constants and fetch constants in bulk, with the same invalidation, and falls back to `WriteRegister` for anything else.

**Why** Two virtual calls per register were about 10% of the GPU command thread. A paused-race pixel comparison is identical.

---

## 14. Float constants copied in runs (`ht_float_constant_runs`)

**File** `src/graphics/d3d12/command_processor.cpp` (`UpdateBindings`, helper `HtCopyFloatConstants`)

**Change** The vertex and pixel float constant buffers are filled with one `memcpy` per run of consecutive used constants, instead of one per constant. The buffer contents are the same.

**Why** Shaders use constants mostly in runs (matrices, arrays). It cut the command thread's CPU from 954 to 912 ms/s in a race. The pixel comparison is identical.

---

## 15. Direct texture loads (`ht_direct_texture_load`)

**Files**
- New: `src/graphics/shaders/ht_texture_load_direct_32bpb.cs.hlsl`, plus its compiled headers `src/graphics/shaders/bytecode/d3d12_5_1/ht_texture_load_direct_32bpb_float_cs.h`, `..._32bpb_rgba8_cs.h` and `ht_texture_load_direct_depth_unorm_cs.h`.
- Changed: `include/rex/graphics/d3d12/texture_cache.h`, `src/graphics/d3d12/texture_cache.cpp`.

**Change**
- **Qualifying textures** are 2D, one mip, unscaled, and use either the 32bpb copy load (R32_FLOAT or R8G8B8A8_TYPELESS resource) or the 24-bit unorm depth load (R32_FLOAT). They are created with `ALLOW_UNORDERED_ACCESS`, decided at creation whatever the cvar says.
- **Loading them** (`HtLoadTextureDirect`) runs one compute pass, on the load root signature and constants. It untiles with `GetTiledOffset2D`, swaps endianness as `texture_load_32bpb` does, and writes the texel into the texture's UAV: R32_FLOAT, R8G8B8A8_UINT, or depth converted as `texture_load_depth_unorm` does (`n + (n >> 23)`, times 2^-24). No scratch buffer and no `CopyTextureRegion`.

**Why** The buffer-to-texture copy was half the cost of texture loads: 13 of the 18 loads in a race frame are render-to-texture results reloaded every frame, plus 4 depth loads. Texture loads went from 1.15 to 0.50 ms per frame. A paused-race pixel comparison is identical; a wrong-byte-order control differs by 917,457 px.

Shaders are compiled with `fxc /T cs_5_1 /E main /O3` (Windows SDK), with the defines in the source's header comment.

---

## 16. Direct resolve (`ht_direct_resolve`)

**Files**
- New: `src/graphics/shaders/ht_resolve_direct_32bpp.cs.hlsl`, plus its compiled headers `ht_resolve_direct_32bpp_uint_cs.h`, `..._unorm8_cs.h` and `..._depth_4x_cs.h`.
- Changed: `include/rex/graphics/d3d12/render_target_cache.h`, `src/graphics/d3d12/render_target_cache.cpp` (`Resolve`, `InitializeShaders`).

**Change** When a resolve uses the fast 32bpp copy, and a single render target owns its whole EDRAM range, it skips `DumpRenderTargets`. Instead it runs a shader that reads that render target through its own SRV, the one the dump reads. Supported sources: 1x `k_32_FLOAT`, 1x `k_8_8_8_8`, and 4x `kD24S8` depth with sample 0.

The shader computes the EDRAM dword addresses exactly as `resolve_fast_32bpp_1x2xmsaa` / `_4xmsaa` do. That includes their depth column swap of only the first sample of each 8- or 16-sample group, which a per-sample swap gets wrong at 40-sample boundaries. Each address is mapped to the texel the dump stores there and converted the dump's way:
- **`k_32_FLOAT`:** raw bits.
- **8888:** `mad(v, 255, 0.5)`, then pack.
- **Depth:** `round_ne(d * 0xFFFFFF) << 8 | stencil`.

The red/blue swap, tiled destination addressing and endian swap are the fast shader's.

**Root signature** The resolve copy layout with 10 root constants, the stencil SRV in t1 and the resolve-to-texture UAV in u1.

**Why** The dump was 0.84 of the 1.51 ms of resolves per race frame. Resolves went to 0.87 ms. A paused-race pixel comparison is identical, and a one-tile-off control differs by 880,122 px.

The 4x averaged color resolves (full 32bpp shader, 3 a frame) still dump: what's left of the dump is 0.18 ms, not worth porting the 1,331-instruction conversion shader bit-exactly.

---

## 17. Resolve to texture (`ht_resolve_to_texture`)

**Files** `include/rex/graphics/d3d12/texture_cache.h`, `src/graphics/d3d12/texture_cache.cpp` (index of direct-load textures by base page, `HtFindResolveTexture`, `HtPrepareResolveTexture`, `HtMarkResolveTextureUpToDate`), `src/graphics/d3d12/render_target_cache.cpp`, and the u1 output of `ht_resolve_direct_32bpp.cs.hlsl`.

**Change** For a direct resolve at destination offset 0, look up exactly one direct-load texture with:
- the same base address,
- tiled, with the same pitch,
- of the matching kind,
- and no larger than the resolve.

If there is one, the resolve shader also writes it, with what loading it from the just-written memory would produce (the texture's own endian swap, then the load's conversion). After `MarkRangeAsResolved`, the texture is made up to date and watched again (`MakeUpToDateAndWatch` under the global lock), as after a load. Memory is still written, so other textures and the CPU see the same data as before.

**Why** It saves the reload that follows each resolve: texture loads went from 18 to 7 per frame and from 0.49 to 0.18 ms. Resolves cost 0.28 ms more, for about 2% of GPU time net. A paused-race pixel comparison is identical; a wrong-byte-order control differs by 917,531 px.

`D3D12TextureCache` declares `D3D12RenderTargetCache` a friend for the texture pointers.

---

## Not an SDK patch, but easy to lose

The actual audio stutter fix is `timeBeginPeriod(1)` in `src/main.cpp`
(`OnPreSetup`), plus `winmm` in `CMakeLists.txt`. That one **is** proven: the
guest vblank generator paces with `Sleep(1ms)` against a default ~15.6 ms Windows
timer resolution, and nothing else in the process raises it.
