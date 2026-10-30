// Frame rate cap.
//
// The settings panel's "Capped" mode sets `vsync`, which does two things in the
// SDK: the guest vblank generator ticks at video_mode_refresh_rate instead of
// 1000 Hz, and the presenter waits for the display's vblank. Neither caps this
// game. It does not pace itself on vblank (the 360 original ran unlocked at
// roughly 40 fps), and with d3d12_allow_variable_refresh_rate_and_tearing on,
// the default, the presenter never waits either. Measured on a 144 Hz monitor:
// 218 fps "capped" with tearing allowed, 144 with it off, and never the 60 that
// was typed in.
//
// Uncapped is harmless on a desktop, but on a handheld (ROG Ally, Steam Deck)
// the CPU and GPU share one power budget. Rendering 100+ frames a second keeps
// both at full clock, and the frame rate swings with whichever runs out first
// instead of holding a steady 60.
//
// So the cap is applied here, on the game's own thread: sub_822CF950 is the
// game's D3D swap (the only caller of VdSwap), run once per frame, and while
// capped each call waits for its slot before the frame is handed over. The
// game simulates with a variable timestep, so it simply sees steadier frames.

//
// The same hook times each frame for the F6 overlay. The overlay used to show
// ImGui's own redraw rate, which runs on the UI thread independently of the
// game: it read 206 fps while the game itself was capped at 60.

#include <atomic>
#include <chrono>
#include <cstdint>
#include <string>
#include <thread>

#include <immintrin.h>

#include <rex/cvar.h>
#include <rex/hook.h>

#include "hydrothunder_init.h"
#include "ht_frame_limit.h"

#if defined(_WIN32)
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

namespace {

constexpr double kMinRate = 20.0;
constexpr double kMaxRate = 1000.0;
// Sleep until this close to the deadline, then spin. A high-resolution timer
// wakes within a few hundred microseconds.
constexpr int64_t kSpinNs = 1'000'000;
// Re-read the settings this often, in frames, so a change made in the panel
// applies without a restart.
constexpr int kRefreshFrames = 30;

int64_t NowNs() {
  return std::chrono::duration_cast<std::chrono::nanoseconds>(
             std::chrono::steady_clock::now().time_since_epoch())
      .count();
}

void SleepNs(int64_t ns) {
#if defined(_WIN32)
  thread_local HANDLE timer = CreateWaitableTimerExW(
      nullptr, nullptr, CREATE_WAITABLE_TIMER_HIGH_RESOLUTION, TIMER_ALL_ACCESS);
  if (timer) {
    LARGE_INTEGER due;
    due.QuadPart = -(ns / 100);  // relative, in 100 ns units
    if (SetWaitableTimer(timer, &due, 0, nullptr, nullptr, FALSE)) {
      WaitForSingleObject(timer, INFINITE);
      return;
    }
  }
#endif
  std::this_thread::sleep_for(std::chrono::nanoseconds(ns));
}

// 0 when uncapped.
int64_t PeriodNs() {
  if (rex::cvar::GetFlagByName("vsync") != "true") {
    return 0;
  }
  double rate = 0.0;
  try {
    rate = std::stod(rex::cvar::GetFlagByName("video_mode_refresh_rate"));
  } catch (...) {
    return 0;
  }
  if (!(rate >= kMinRate)) {
    return 0;
  }
  if (rate > kMaxRate) {
    rate = kMaxRate;
  }
  return int64_t(1e9 / rate);
}

void Pace() {
  static int frames = 0;
  static int64_t period = 0;
  static int64_t next = 0;
  if (frames++ % kRefreshFrames == 0) {
    period = PeriodNs();
  }
  if (period == 0) {
    next = 0;
    return;
  }
  int64_t now = NowNs();
  // First capped frame, or a stall (loading, a breakpoint): start over rather
  // than rush a burst of frames to catch up.
  if (next == 0 || now - next > 2 * period) {
    next = now + period;
    return;
  }
  if (next - now > kSpinNs) {
    SleepNs(next - now - kSpinNs);
  }
  while ((now = NowNs()) < next) {
    _mm_pause();
  }
  next += period;
}

// Written by the game's render thread, read by the UI thread. A torn read can
// only mix two neighbouring frames' times in one sample, which a readout
// cannot show anyway.
std::atomic<float> g_frame_ms[ht::kGameFrameHistory];
std::atomic<uint64_t> g_frames{0};

void RecordFrame() {
  static int64_t last = 0;
  const int64_t now = NowNs();
  if (last != 0) {
    const uint64_t n = g_frames.load(std::memory_order_relaxed);
    g_frame_ms[n % ht::kGameFrameHistory].store(float(now - last) / 1e6f,
                                                std::memory_order_relaxed);
    g_frames.store(n + 1, std::memory_order_release);
  }
  last = now;
}

}  // namespace

namespace ht {

uint64_t CopyGameFrameTimes(float (&out)[kGameFrameHistory]) {
  const uint64_t n = g_frames.load(std::memory_order_acquire);
  for (size_t i = 0; i < kGameFrameHistory; ++i) {
    // Oldest first: slot n is the next to be overwritten.
    out[i] = n + i >= kGameFrameHistory
                 ? g_frame_ms[(n + i) % kGameFrameHistory].load(std::memory_order_relaxed)
                 : 0.0f;
  }
  return n;
}

}  // namespace ht

REX_HOOK_RAW(sub_822CF950) {
  Pace();
  RecordFrame();
  __imp__sub_822CF950(ctx, base);
}
