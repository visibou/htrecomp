#pragma once

namespace rex::system {
class KernelState;
}

namespace ht {

// Gives the signed-in profile the player_name setting as its gamertag. Call
// before the game's main thread starts.
void ApplyPlayerName(rex::system::KernelState* kernel_state);

}  // namespace ht
