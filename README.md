<div align="center">

# Hydro Thunder Hurricane Recompiled

[![Listed on PlayPorted](https://playported.com/badge.svg)](https://playported.com/ports/90-hydro-thunder-hurricane/)

</div>

A native PC build of the Xbox 360 game *Hydro Thunder Hurricane*, produced by
static recompilation with the [rexglue SDK](https://github.com/rexglue/rexglue-sdk).
The game's PowerPC code is translated ahead of time into native x86-64, so this
is a real port rather than an emulator running the original executable.

**No game content is included, and none ever will be.** You supply the files
from your own legally obtained copy. See [Game files](#game-files).

---

## What this build adds

Everything here is beyond what the Xbox 360 release could do:

| | |
|---|---|
| **Uncapped frame rate** | The console was locked to 30. Run it as fast as your hardware allows, or cap it to any refresh rate you like. |
| **Any output resolution** | 1080p, 1440p, 4K. The game's own scene render target is a fixed size, so raising the output resolution costs essentially nothing - measured identical frame times from 1080p to 4K. |
| **Higher internal resolution** | A separate scale for the 3D scene itself, for when you do want to spend the GPU time. |
| **16x anisotropic filtering** | Sharpens the surface ahead of you. Nearly free on any modern GPU and the single best-looking change available. |
| **Mods** | Add new boats with your own handling and new skins, without replacing anything. See [Mods](#mods). |
| **Field of view** | Widen (or narrow) the race camera from the Game tab. The console was fixed at 100 degrees. |
| **Tempest Pack DLC** | The three extra tracks, installed from your own copy. See [DLC](#dlc). |
| **In-game settings menu** | Press **F5**. Display, Graphics, Audio, Input, Game, Mods and Fixes, with search and per-tab reset. No config editing. |
| **Frame rate overlay** | Press **F6** for frame rate, frame time, a history graph and worst-frame tracking. |
| **Mouse & keyboard support** | Optional, alongside full controller support. |
| **Modern display handling** | V-Sync or tearing/VRR, letterboxing, safe-area cropping, output dithering, monitor selection. |

## Getting started

1. Extract the release.
2. Run the executable.
3. It asks for your copy of the game and unpacks it. This happens once.

Settings, saves and the shader cache are all kept next to the executable, so
the whole install stays portable - move the folder and everything comes with it.

## Game files

You must provide the game's files yourself, from a copy you own.

The first time you run it, the game walks you through this:

1. A message explains that no game content is included.
2. A file picker asks for your **Hydro Thunder Hurricane package**. Hydro
   Thunder Hurricane was a digital title, so this is a single file whose name
   is a long string of hex characters, with no file extension.
3. The package is unpacked into a `game_data` folder beside the executable.
   This takes a moment and only happens once.
4. You are asked whether you also have the DLC. This is optional - see
   [DLC](#dlc).

After that the game starts, and every later launch goes straight to the title
screen.

### DLC

The Tempest Pack DLC is supported from 2.0.0: three extra tracks (Bermuda
Triangle, Castle Von Boom and Atlantis) with their events and music, two new
boats (Whiplash and Psyclone), six "X" versions of the original boats, and new
skins. Like the game, it is a single package file named with a long string of
hex characters.

There are two ways to add it:

- **During setup**, answer yes when asked and pick the package. Installs that
  came from 1.0.0 are asked once, on the first launch after updating.
- **At any time**, put the package file in a folder called `dlc` next to the
  executable and start the game. It is installed on that launch, and you can
  leave the file there or delete it afterwards.

It is unpacked into `user_data`, so your saves are not touched. The new tracks
then appear at the end of the track list and the new boats at the end of the
boat list. As on the console, they unlock with credits like everything else.

### About the game executable

The executable inside a retail package is encrypted and compressed, and the
game cannot run it in that state - it would reach the title screen and then
close as soon as you press Start.

**This is handled for you.** `xextool.exe` ships alongside the game, and the
conversion happens automatically during setup - you will just see a short
message saying it was done. The check runs on every launch, so a `game_data`
folder you assembled by hand gets converted too.

If you ever need to do it yourself, the command is:

```
xextool -c u -e u -o default.xex default.xex
```

### If you have a different kind of dump

The picker expects the packaged form. If your copy is already extracted into
loose files, skip the prompts entirely by creating the folder yourself before
first launch:

```
Hydro Thunder Hurricane Recompiled/
├─ hydrothunder.exe
├─ rexruntimerd.dll
└─ game_data/
   ├─ default.xex        <- required
   ├─ Base.apf
   ├─ Audio/
   ├─ Video/
   └─ ...
```

`default.xex` has to sit at the top level of `game_data`, with the rest of the
game's files and folders beside it as they are laid out in your copy. When that
folder is present the game boots straight into the title screen and never asks.

This project does not provide, and will not help you obtain, game files you do
not already own.

## Controls

Xbox controllers work out of the box. Mouse and keyboard can be enabled under
**Input** in the settings menu.

| Key | |
|---|---|
| **F5** | Settings menu |
| **F6** | Frame rate overlay |

The keyboard and mouse bindings are listed, and can be changed, under
**Input** in the settings menu.

## Settings worth knowing

- **Resolution** (Display) sets the output size and is effectively free. This
  is the one to raise.
- **Internal resolution scale** (Graphics) is the expensive one - it multiplies
  the cost of the 3D scene, and 2x measures roughly 8x the GPU time. Raise it
  one step at a time.
- **Frame rate** (Display) switches between uncapped and capped; the refresh
  rate is typed in directly rather than dragged on a slider.
- **Anisotropic filtering** (Graphics) is the best value in the panel.
- **Field of view** (Game) widens the race camera. 0 keeps the game's own 100
  degrees; 110 to 120 suits a wide monitor. It takes effect when the next race
  starts.

Settings are written to `hydrothunder.toml` beside the executable when the
panel closes. The file is merged rather than rewritten, so any comments and
hand-edits you add to it survive.

## Editing saves

The save is `user_data/<profile>/5841096A/00000001/ht2save.dat/ht2save.dat`.
It is not encrypted, but it carries a checksum, and the game discards a save
whose checksum does not match. `tools/ht_save_edit.py` (Python 3) edits it and
fixes the checksum for you:

```
python tools/ht_save_edit.py <save>                            # list every value
python tools/ht_save_edit.py <save> --set TotalCredits=50000   # edit
python tools/ht_save_edit.py <save> --export save.json         # or edit as JSON...
python tools/ht_save_edit.py <save> --import save.json         # ...and write it back
python tools/ht_save_edit.py <save> --fix                      # after a hex edit
```

Every write backs the save up to `~/.ht_save_backups/` first. Close the game
before editing.

## Mods

Mods add new boats (an existing boat's model with your own handling) and new
skins, for the game's boats or your own. They never replace anything, and
removing one leaves your save working. Everything a mod adds is unlocked from
the start.

### Installing a mod

Put the mod's folder in `mods/` next to the executable and start the game:

```
Hydro Thunder Hurricane Recompiled/
├─ hydrothunder.exe
└─ mods/
   └─ speedvector/
      └─ mod.toml
```

**F5 > Mods** lists what is installed, shows why a mod did not load, and turns
mods on and off. Changes take effect the next time the game starts.

### Tutorial: your first mod

This makes a faster Vector called *Rocket*, with a skin of your own.

**1. Get a template to paint over.** Start the game, press **F5**, open
**Mods** and press **Export skin templates**. Each boat's skin is written to
`mods/_templates/` as a PNG, with its settings as JSON. Close the game.

**2. Make the mod's folder.** Create `mods/rocket/`, and a `skins/` folder
inside it.

**3. Paint the skin.** Copy `mods/_templates/Vector.png` to
`mods/rocket/skins/rocket.png` and paint over it in any image editor. Keep it
1024x1024. The layout is Vector's own, so the paint lands where you expect on
the boat.

**4. Describe the mod.** Create `mods/rocket/mod.toml` with this in it:

```toml
id = "rocket"
name = "Rocket"
version = "1.0"
author = "you"

[[boat]]
id = "Rocket"
base = "Vector"
name = "Rocket"
description = "A Vector with a far bigger engine."

[boat.tuning]
Engine = { "Max Forward Speed" = 200, "Max Thrust" = 180000 }
Stats = { TopSpeed = 9, Acceleration = 9 }

[[skin]]
id = "Red"
boats = ["Rocket", "Vector"]
name = "Rocket Red"
texture = "skins/rocket.png"
```

- `id` is the mod's name inside the game: lowercase letters and digits.
  Everything the mod adds is named after it, which is what keeps mods from
  ever overwriting anything.
- `[[boat]]` adds a boat. `base` is the boat it starts from, and
  `[boat.tuning]` lists only what you change. Vector's own values are 140 and
  104000; `mods/_templates/Vector.json` has every setting there is. `Stats` are
  the 0-10 bars in the boat menu.
- `[[skin]]` adds a skin, here to both Rocket and the original Vector.

**5. Play it.** Start the game. Rocket is at the end of the boat list, wearing
your skin, and Vector has your skin as an extra choice. If something is wrong,
F5 > Mods says what, and the game runs without the mod until you fix it.

To share the mod, share the `mods/rocket/` folder, which holds only your own
files. [MODDING.md](MODDING.md) is the full reference, and
`examples/mods/speedvector/` is another mod to start from.

## Building from source

Requires CMake 3.25+, Ninja, and Clang - rexglue requires Clang, so MSVC is
not supported. On Windows the toolchain that ships with Visual Studio's
"C++ Clang tools for Windows" component works.

The [rexglue SDK](https://github.com/rexglue/rexglue-sdk) is not part of this
repository. Put it in `third_party/rexglue-sdk/` (or point `REXSDK_DIR` at it)
and apply the changes described in [SDK_PATCHES.md](SDK_PATCHES.md).

```sh
cmake --preset relwithdebinfo
cmake --build --preset relwithdebinfo -- -j3
```

The recompiled C++ is committed under `generated/`, so **building does not
need the game**. Only running it does.

Keep the job count modest. The generated translation units are large and each
one can take 1-2 GB in the compiler; an unbounded `--parallel` will exhaust
memory on a 16 GB machine.

A build has no developer tools in it. To get the SDK's debug overlay (F3),
log console (backtick) and raw settings dialog (F4) back while working on the
port, configure with `-DCMAKE_CXX_FLAGS=-DHT_DEV_TOOLS=1`.

## Known limitations

- **DLC copied in by hand.** If you placed DLC files under `user_data`
  yourself and moved or renamed anything inside `Audio`, the DLC tracks lose
  their music. The package's odd-looking layout (`Audio/Xbox360Pack01Track01.fsb`
  next to tiny `Audio/Xbox360/Pack01Track01.fsb` files) is what the game reads.
  Delete `user_data/0000000000000000/5841096A/` and add the DLC again with one
  of the methods above.
- **Mods add boats and skins only, for now.** A mod boat uses an existing
  boat's model; new models, tracks and music are not supported yet.
- **Mod changes need a restart.** Mods are built when the game starts, so
  adding, changing or switching off a mod takes effect on the next launch.

## Credits

- [rexglue SDK](https://github.com/rexglue/rexglue-sdk) - the recompilation SDK
  this project is built on.
- [Xenia](https://github.com/xenia-project/xenia) - whose Xbox 360 research
  underpins much of the tooling this ecosystem relies on.
- **XEXTool by xorloser** - bundled with this release and used to convert the
  game executable during setup. All credit for that tool goes to its author;
  it is included unmodified.

Hydro Thunder Hurricane is the property of its respective owners. This project
is an unofficial, non-commercial port and is not affiliated with or endorsed by
them.
