#pragma once

#include <cstddef>
#include <cstdint>

namespace ht {

// Times of the game's most recent frames, in milliseconds, measured at its
// swap (see ht_frame_limit.cpp). This is the game's real frame rate; the UI's
// own redraw rate (ImGuiIO::Framerate) runs independently of it.
constexpr size_t kGameFrameHistory = 120;

// Copies the history oldest first into `out` and returns the total number of
// frames seen so far (0 until the game presents its first frame).
uint64_t CopyGameFrameTimes(float (&out)[kGameFrameHistory]);

}  // namespace ht
