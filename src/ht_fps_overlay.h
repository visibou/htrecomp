// htrecomp - compact frame rate readout.
//
// Small always-on-top window showing the game's frame rate, plus frame time and
// a short history graph. The frames are timed at the game's own swap
// (ht_frame_limit.cpp), not by ImGui: the UI redraws on its own thread at its
// own rate, so ImGuiIO::Framerate says nothing about the game.
//
// Caveat worth knowing: an open ImGui dialog forces the presenter into
// UI-thread painting (see Presenter::GetDesiredPaintModeFromUIThread), so
// having this up is not entirely free and can itself move the number slightly.

#pragma once

#include <array>
#include <cstddef>

#include <rex/ui/imgui_dialog.h>

class HtFpsOverlay : public rex::ui::ImGuiDialog {
 public:
  explicit HtFpsOverlay(rex::ui::ImGuiDrawer* imgui_drawer);

 protected:
  void OnDraw(ImGuiIO& io) override;
};
