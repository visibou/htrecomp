// htrecomp - mod support.
//
// A mod is a folder under <exe>/mods/ with a mod.toml that describes what it
// adds: new boats (an existing boat's model with its own stats) and new skins
// (for existing boats or the mod's own). Nothing a mod adds can replace
// anything: every name it creates is prefixed with the mod's id, and every
// asset lives under <id>/. See MODDING.md for the format.
//
// At launch each mod is built into a content package and installed where the
// DLC lives:
//
//   <exe>/user_data/0000000000000000/5841096A/00000002/Mod_<id>/
//   <exe>/user_data/0000000000000000/5841096A/Headers/00000002/Mod_<id>.header
//
// The game then mounts and merges it exactly like the Tempest Pack. Packages
// are rebuilt only when a mod changes, and a removed or broken mod's package
// is deleted, so the installed set always matches the mods folder.
//
// ht_mods_merge.cpp fixes the game's DB merge so that content added to
// existing boats does not hide everything loaded after it.

#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace ht {

// Builds, updates and removes mod packages to match <exe>/mods/. Never fails
// the launch: a mod that cannot be built is skipped, and every result is
// written to the log and to <exe>/mods/mods_log.txt.
void BuildMods(const std::filesystem::path& exe_dir);

// What BuildMods did with each mod folder, for the settings panel's Mods tab.
struct ModStatus {
  enum class State { kLoaded, kDisabled, kError };
  std::string folder, id, name, version, author;
  State state = State::kError;
  bool enabled = true;
  std::string message;  // "built", "up to date", or the error
  std::vector<std::string> warnings;
  int boats = 0, skins = 0;
};
const std::vector<ModStatus>& ModStatuses();

// Turns a mod on or off from the next launch: off is an empty file named
// "disabled" in the mod's folder.
bool SetModEnabled(const std::filesystem::path& exe_dir, const std::string& folder, bool enabled);

// Writes each boat's default skin (PNG) and settings (JSON) to
// <exe>/mods/_templates/. Returns a line saying what happened.
std::string ExportSkinTemplates(const std::filesystem::path& exe_dir);

}  // namespace ht
