#pragma once

#include <rex/rex_app.h>
#include <rex/filesystem.h>
#include <rex/system.h>
#include <rex/cvar.h>
#include <rex/runtime.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

// Defined in ht_version.h so the settings panel can show the build without
// pulling in the whole app framework. One definition, two consumers.
#include "ht_setup.h"
#include "ht_version.h"

// Debug console, off unless the build asks for it. See where it is used.
#ifndef HT_DEV_CONSOLE
#define HT_DEV_CONSOLE 0
#endif

class HtBaseApp : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;

  virtual std::string_view GetBuildTitle() const = 0;
  virtual std::string_view GetBuildStamp() const = 0;

  bool SetupEnvironment() override {
    FILE* f = fopen("startup_debug.txt", "w");
    if (f) { fprintf(f, "Entered SetupEnvironment\n"); fflush(f); }

    // 1. Determine local paths
    auto exe_dir = rex::filesystem::GetExecutableFolder();
    if (f) { fprintf(f, "Got exe_dir: %s\n", exe_dir.string().c_str()); fflush(f); }

    auto game_data = (exe_dir / "game_data").string();
    auto user_data = (exe_dir / "user_data").string();
    auto cache_data = (exe_dir / "cache").string();
    if (f) { fprintf(f, "Constructed path strings\n"); fflush(f); }

    // 2. Override CVARs to force portable mode and bypass the GetUserFolder() hang
    REXCVAR_SET(game_data_root, game_data);
    REXCVAR_SET(user_data_root, user_data);
    REXCVAR_SET(cache_path, cache_data);
    if (f) { fprintf(f, "Set CVARs\n"); fflush(f); }

    // 3. Call base implementation
    if (f) { fprintf(f, "Calling rex::ReXApp::SetupEnvironment()\n"); fflush(f); }
    bool res = rex::ReXApp::SetupEnvironment();
    if (f) { fprintf(f, "Finished rex::ReXApp::SetupEnvironment(): %d\n", res); fflush(f); }

    if (!res) {
      if (f) fclose(f);
      return false;
    }

    // 4. Optional debug console.
    //
    // Off in a release build. AllocConsole gives the process a SECOND visible
    // window - a black console titled with the exe path - which looks broken
    // to a player and is the window most scripts and screenshot tools pick up
    // by mistake. Build with -DHT_DEV_CONSOLE=1 when you want the live log.
    // The rex_log.txt file sink below is always active either way, so nothing
    // is lost for bug reports.
#if HT_DEV_CONSOLE
#if defined(_WIN32)
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
#endif
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_pattern("[%l] [%n] %v");
    spdlog::default_logger()->sinks().push_back(console_sink);
#endif

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("rex_log.txt", true);
    file_sink->set_pattern("[%l] [%n] %v");
    spdlog::default_logger()->sinks().push_back(file_sink);

    // 5. Game files.
    //
    // This port ships no game content. If game_data is not there yet, walk the
    // player through importing it from their own copy - see src/ht_setup.h.
    // Does nothing once the files are in place.
    if (!ht::EnsureGameData(exe_dir)) {
      return false;
    }

    if (f) { fprintf(f, "SetupEnvironment complete\n"); fclose(f); }
    return true;
  }
};
