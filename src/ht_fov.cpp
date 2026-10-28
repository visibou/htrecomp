// Field of view for the race camera.
//
// The game builds each race viewport's camera in createViewports
// (sub_821FE2F8, AkActionGameModeImpl): it picks a horizontal FOV from a
// constant table - 100 degrees for one player at 16:9, 90 at 4:3, 120 in
// splitscreen - converts it to radians and passes it, with the aspect ratio
// and the near and far planes, to sub_8216AD88, which stores it on the camera
// (+432) and builds the projection from it.
//
// sub_8216AD88 has other callers: the front-end cameras, and sub_821FE4B0,
// which changes the far plane by passing each camera's STORED fov straight
// back. So the fov is replaced only while createViewports is running; every
// later call then re-applies the value we set, without compounding.
//
// An earlier attempt wrote the projection matrix at 0x82960110. That matrix
// belongs to the title-screen camera, so it never changed a race - which is
// why the old slider did nothing in game.
//
// The setting is a horizontal FOV in degrees for one player at 16:9. Other
// layouts keep their proportion to it (splitscreen at 130 is 156).

#include <cmath>

#include <rex/cvar.h>
#include <rex/hook.h>
#include <rex/logging.h>

#include "hydrothunder_init.h"

REXCVAR_DEFINE_DOUBLE(fov_horizontal, 0.0, "Game",
                      "Horizontal field of view of the race camera, in degrees. 0 keeps the "
                      "game's own 100. Takes effect when a race starts.")
    .range(0.0, 140.0)
    .lifecycle(rex::cvar::Lifecycle::kHotReload);

namespace {

constexpr double kStockDegrees = 100.0;
constexpr double kMinDegrees = 60.0, kMaxDegrees = 140.0;
// Above this the projection degenerates (tan of half the angle).
constexpr double kMaxRadians = 170.0 * 3.14159265358979323846 / 180.0;

constexpr double kDegrees = 180.0 / 3.14159265358979323846;

thread_local bool g_creating_viewports = false;
thread_local bool g_logged = false;

}  // namespace

REX_HOOK_RAW(sub_821FE2F8) {
  g_creating_viewports = true;
  g_logged = false;
  __imp__sub_821FE2F8(ctx, base);
  g_creating_viewports = false;
}

REX_HOOK_RAW(sub_8216AD88) {
  if (g_creating_viewports) {
    // 0 (or anything below 1) means the game's own; the rest is clamped to
    // what the slider offers.
    const double setting = REXCVAR_GET(fov_horizontal);
    const double want = std::fmin(std::fmax(setting, kMinDegrees), kMaxDegrees);
    if (setting >= 1.0 && want != kStockDegrees) {
      const double stock = ctx.f1.f64;
      ctx.f1.f64 = std::fmin(stock * want / kStockDegrees, kMaxRadians);
      if (!g_logged) {  // once per race; there is a camera per viewport
        g_logged = true;
        REXLOG_INFO("[ht] race camera fov {:.1f} -> {:.1f} degrees", stock * kDegrees,
                    ctx.f1.f64 * kDegrees);
      }
    }
  }
  __imp__sub_8216AD88(ctx, base);
}
