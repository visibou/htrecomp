#include "ht_fps_overlay.h"

#include <algorithm>

#include <imgui.h>

#include "ht_frame_limit.h"

#if defined(_WIN32)
#include <rex/graphics/d3d12/ht_gpu_perf.h>
#endif

HtFpsOverlay::HtFpsOverlay(rex::ui::ImGuiDrawer* imgui_drawer)
    : rex::ui::ImGuiDialog(imgui_drawer) {}

void HtFpsOverlay::OnDraw(ImGuiIO& io) {
  (void)io;
  float frame_ms[ht::kGameFrameHistory];
  const uint64_t frames = ht::CopyGameFrameTimes(frame_ms);

  // The rate is averaged over the last half second or so; a single frame's
  // time flickers too fast to read.
  constexpr size_t kAverage = 30;
  float sum = 0.0f;
  size_t counted = 0;
  for (size_t i = ht::kGameFrameHistory; i-- > 0 && counted < kAverage;) {
    if (frame_ms[i] > 0.0f) {
      sum += frame_ms[i];
      ++counted;
    }
  }
  const float average_ms = counted ? sum / float(counted) : 0.0f;

  // Worst frame in the window: an average alone hides exactly the hitches that
  // make a game feel bad.
  const float worst = *std::max_element(std::begin(frame_ms), std::end(frame_ms));

  ImGui::SetNextWindowPos(ImVec2(10.0f, 10.0f), ImGuiCond_FirstUseEver);
  ImGui::SetNextWindowBgAlpha(0.45f);
  const ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize |
                                 ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav |
                                 ImGuiWindowFlags_NoMove;
  if (ImGui::Begin("##ht_fps", nullptr, flags)) {
    if (frames == 0 || average_ms <= 0.0f) {
      ImGui::TextUnformatted("-- FPS");
    } else {
      ImGui::Text("%.0f FPS   %.2f ms", 1000.0f / average_ms, average_ms);
    }
    ImGui::PlotLines("##ht_fps_graph", frame_ms, int(ht::kGameFrameHistory), 0, nullptr, 0.0f,
                     std::max(33.4f, worst * 1.1f), ImVec2(180.0f, 32.0f));
    ImGui::TextDisabled("worst %.1f ms", worst);
#if defined(_WIN32)
    // Only with ht_gpu_perf on: GPU time per frame, 5 second average.
    const auto gpu = rex::graphics::d3d12::GetHtGpuPerfSnapshot();
    if (gpu.valid) {
      ImGui::TextDisabled("GPU %.2f ms", gpu.total_ms);
      ImGui::TextDisabled("xfer %.2f  resolve %.2f  tex %.2f", gpu.transfer_ms, gpu.resolve_ms,
                          gpu.texture_load_ms);
    }
#endif
  }
  ImGui::End();
}
