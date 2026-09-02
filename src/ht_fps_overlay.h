// htrecomp - compact frame rate readout.
//
// Small always-on-top window showing the rate at which frames actually reach
// the screen, plus frame time and a short history graph.
//
// Caveat worth knowing: an open ImGui dialog forces the presenter into
// UI-thread painting (see Presenter::GetDesiredPaintModeFromUIThread), so
// having this up is not entirely free and can itself move the number slightly.
// It measures presented frames, which is what the player sees - not the guest's
// internal simulation rate.

#pragma once

#include <array>
#include <cstddef>

#include <rex/ui/imgui_dialog.h>

class HtFpsOverlay : public rex::ui::ImGuiDialog {
 public:
  explicit HtFpsOverlay(rex::ui::ImGuiDrawer* imgui_drawer);

 protected:
  void OnDraw(ImGuiIO& io) override;

 private:
  static constexpr size_t kHistory = 120;
  std::array<float, kHistory> frame_ms_{};
  size_t history_index_ = 0;
};
