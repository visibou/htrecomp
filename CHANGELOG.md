# Changelog

## 2.2.0 - Faster rendering

The GPU does about a quarter less work per frame in a race: 6.9 ms became
5.3 ms on the development PC (RTX 3050 laptop), on top of 2.1.0's gains. That
matters most where the GPU is the limit, as on handhelds like the ROG Ally.
Every change was checked by comparing frames with it on and off: identical to
the pixel.

- **Textures the game renders to are loaded straight into the texture.**
  Shadow maps, depth and other render-to-texture results used to be converted
  into a buffer and then copied into the texture. A new shader writes the
  texture directly.
- **Resolves read the render target directly.** Copying a render target to
  memory used to go through a full copy of it into the emulated EDRAM first.
  For the formats this game resolves most, the copy now reads the render
  target itself.
- **Resolved textures don't get reloaded.** When a resolve rewrites a whole
  texture, it now writes that texture too, so it isn't reloaded from memory
  right after.

## 2.1.0 - Performance

### Faster

Measured in a race on the development PC (RTX 3050 laptop): 65 fps became 115,
the worst frame went from 36 ms to 20, and frames slower than 25 ms (the
visible stutters) went from about a hundred a minute to none. Part of that was
a debug leftover that was slow mainly on that PC (below). The rest applies
everywhere: GPU time per frame fell from 10 ms to 7, which matters most on
handhelds, where the GPU is the limit.

- **Clears no longer copy whole render targets.** The game clears its shadow
  and depth buffers through a 4x MSAA view of memory it then draws into at 1x,
  about five times a frame, and every one of those clears made the renderer
  copy the whole buffer to 4x and back. Those clears are now drawn at 1x over
  the same memory, which leaves it identical and needs neither copy. Render
  target copies went from 41% of the GPU's time to 15%. Verified pixel-identical.
- **Clears are measured at their real size.** Screen-space draws such as clears
  are now run on the CPU to find how much of the render target they cover, as
  in Xenia, instead of being assumed to cover all of it.
- **A debug file write on every memory fault is gone.** Leftover development
  code opened and wrote a file each time the GPU emulation caught a write to
  memory it watches, hundreds of times a second. The file lived in a folder on
  the development PC (`D:\htrecomp-main\htrecomp`): there it cost the render
  thread most of its time, elsewhere each attempt failed quickly.
- **The game's memory copy runs natively**, and the GPU command processor no
  longer looks up debug information on every register write.
- **Less CPU work per draw.** Runs of GPU registers and shader constants are
  copied in bulk instead of one at a time.

### Added

- **GPU timing in the F6 overlay.** Set `ht_gpu_perf = true` in
  `hydrothunder.toml` and F6 also shows GPU time per frame, with how much of it
  goes to render target copies, resolves and texture loads. Useful when
  reporting performance.
- **Player name.** F5 > Game > Player name sets the name the game calls you
  by, instead of "User" (up to 15 characters). It takes effect the next time
  the game starts. Saves are kept by profile, not by name, so changing it
  never moves or hides a save.

### Fixed

- **The frame rate cap now caps.** "Capped" in F5 > Display only slowed the
  emulated vblank and waited for the display, neither of which limits this
  game: with tearing allowed (the default) it ran as fast as it could, and
  without, at the monitor's refresh rate rather than the one set. The game is
  now held at the chosen rate on its own thread. The cap applies at once, and
  30 and 40 join the presets. On a handheld, a cap the game can always reach
  is steadier and leaves the GPU more of the shared power budget.
- **The F6 overlay shows the game's frame rate.** It used to show how often
  the overlay itself redrew, which runs independently of the game: it read
  over 200 fps on a title screen the game was drawing at 85. It now times the
  game's own frames.

## 2.0.0 - Initial mod support

### Mods

Mods add content to the game without replacing any of it. Put a mod's folder
in `mods/` next to the executable and start the game; [MODDING.md](MODDING.md)
explains how to make one, and `examples/mods/speedvector/` is one to start
from.

- **New boats with their own handling.** A mod boat starts from any existing
  boat's model, sounds and handling, and changes what it likes: top speed,
  thrust, mass, hull and air control, and the bars shown in the boat menu. It
  appears at the end of the boat list, next to the originals.
- **New skins**, for the game's boats or a mod's own. Paint a 1024x1024 PNG;
  the game converts it when the mod is built. A skin added to an existing boat
  joins that boat's skin list and leaves the others untouched.
- **Nothing is ever replaced.** Everything a mod adds is named after the mod,
  so two mods cannot collide and a mod cannot overwrite the game's content.
  Several mods load at once, alongside the Tempest Pack.
- **Unlocked from the start.** Mod content costs no credits, so it needs
  nothing in your save. Removing a mod leaves the save loading normally.
- **Safe to get wrong.** A mod with a mistake in it is skipped with the reason
  shown, and the game starts without it. A misspelt setting is reported
  rather than silently ignored.
- **F5 > Mods** lists installed mods and what each one added, shows why one did
  not load, turns mods on and off, and exports every boat's skin and settings
  as templates to work from.
- Mods are rebuilt only when they change; an unchanged mod adds next to
  nothing to the launch.

### Also new

- **Tempest Pack DLC.** The three extra tracks (Bermuda Triangle, Castle Von
  Boom and Atlantis), its boats (Whiplash, Psyclone and six "X" versions of the
  original boats) and its skins, installed from your own copy during setup or
  from a `dlc` folder at any time. Like everything else, the boats unlock with
  credits.
- **Field of view** for the race camera, under F5 > Game. The console was fixed
  at 100 degrees.
- **Keyboard and mouse bindings** can now be changed under F5 > Input.
- **Save editing.** `tools/ht_save_edit.py` reads and edits the save and fixes
  its checksum, which is why hand-edited saves used to be rejected.

### Fixed

- The game merged extra content for an existing boat as a duplicate boat, and
  the boat menu then looped before reaching anything listed after it. That hid
  the Tempest Pack's six X boats and its extra skins for the original boats,
  and it is fixed.
- With the DLC installed, pressing Start on the title screen no longer
  crashes the game.

### Changed

- The window is titled "Hydro Thunder Hurricane Recompiled".
- The engine's developer overlays (F3 debug overlay, the console and the F4
  raw settings dialog) are no longer in the release build. Everything a player
  needs is in the F5 panel.

### Known limitations

- Mods add boats and skins only, for now. A mod boat uses an existing boat's
  model; new models, tracks and music are not supported yet.
- Changes to mods take effect on the next launch.

## 1.0.0

Initial release.
