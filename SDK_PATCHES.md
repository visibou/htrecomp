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

## Not an SDK patch, but easy to lose

The actual audio stutter fix is `timeBeginPeriod(1)` in `src/main.cpp`
(`OnPreSetup`), plus `winmm` in `CMakeLists.txt`. That one **is** proven: the
guest vblank generator paces with `Sleep(1ms)` against a default ~15.6 ms Windows
timer resolution, and nothing else in the process raises it.
