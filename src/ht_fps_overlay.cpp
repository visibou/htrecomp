#include "ht_fps_overlay.h"

#include <algorithm>

#include <imgui.h>

HtFpsOverlay::HtFpsOverlay(rex::ui::ImGuiDrawer* imgui_drawer)
    : rex::ui::ImGuiDialog(imgui_drawer) {
  frame_ms_.fill(0.0f);
}

void HtFpsOverlay::OnDraw(ImGuiIO& io) {
  const float frame_ms = (io.Framerate > 0.0f) ? (1000.0f / io.Framerate) : 0.0f;
  frame_ms_[history_index_] = frame_ms;
  history_index_ = (history_index_ + 1) % kHistory;

  // Worst frame in the window: an average alone hides exactly the hitches that
  // make a game feel bad.
  const float worst = *std::max_element(frame_ms_.begin(), frame_ms_.end());

  ImGui::SetNextWindowPos(ImVec2(10.0f, 10.0f), ImGuiCond_FirstUseEver);
  ImGui::SetNextWindowBgAlpha(0.45f);
  const ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize |
                                 ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav |
                                 ImGuiWindowFlags_NoMove;
  if (ImGui::Begin("##ht_fps", nullptr, flags)) {
    ImGui::Text("%.0f FPS   %.2f ms", io.Framerate, frame_ms);
    ImGui::PlotLines("##ht_fps_graph", frame_ms_.data(), static_cast<int>(kHistory),
                     static_cast<int>(history_index_), nullptr, 0.0f,
                     std::max(33.4f, worst * 1.1f), ImVec2(180.0f, 32.0f));
    ImGui::TextDisabled("worst %.1f ms", worst);
  }
  ImGui::End();
}
