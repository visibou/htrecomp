// Player name.
//
// The game shows the signed-in profile's gamertag wherever it names the player.
// The SDK's profile always calls itself "User" (user_profile.cpp), so this
// replaces it with the player_name setting before the game's main thread runs.
// Needs the set_name() setter from SDK_PATCHES.md #7.
//
// Saves are filed under the profile's XUID, not its name, so renaming never
// moves or hides a save.

#include <string>

#include <rex/cvar.h>
#include <rex/logging.h>
#include <rex/system/kernel_state.h>
#include <rex/system/xam/user_profile.h>

#include "ht_player_name.h"

REXCVAR_DEFINE_STRING(player_name, "User", "Game",
                      "Your name in the game, up to 15 letters, digits and spaces. Takes "
                      "effect the next time the game starts.")
    .lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

namespace ht {

namespace {

// Xbox gamertags are at most 15 characters, and the XAM name calls copy into
// 16-byte buffers. The game's fonts only cover printable ASCII.
constexpr size_t kMaxLength = 15;

std::string Sanitize(const std::string& raw) {
  std::string name;
  for (char c : raw) {
    if (c >= 0x20 && c <= 0x7E) {
      name += c;
    }
  }
  const auto first = name.find_first_not_of(' ');
  if (first == std::string::npos) {
    return {};
  }
  name = name.substr(first, name.find_last_not_of(' ') - first + 1);
  if (name.size() > kMaxLength) {
    name.resize(kMaxLength);
    name.erase(name.find_last_not_of(' ') + 1);
  }
  return name;
}

}  // namespace

void ApplyPlayerName(rex::system::KernelState* kernel_state) {
  auto* profile = kernel_state ? kernel_state->user_profile() : nullptr;
  if (!profile) {
    return;
  }
  const std::string& setting = REXCVAR_GET(player_name);
  std::string name = Sanitize(setting);
  if (name.empty()) {
    name = "User";
  }
  if (name != setting) {
    REXLOG_WARN("[ht] player_name \"{}\" is not usable as is; using \"{}\"", setting, name);
  }
  profile->set_name(name);
  REXLOG_INFO("[ht] player name: {}", name);
}

}  // namespace ht
