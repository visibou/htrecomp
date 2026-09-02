# Hydro Thunder Hurricane: Recompiled

A native PC build of the Xbox 360 game *Hydro Thunder Hurricane*, produced by
static recompilation with the [rexglue SDK](https://github.com/rexglue/rexglue-sdk).
The game's PowerPC code is translated ahead of time into native x86-64, so this
is a real port rather than an emulator running the original executable.

**No game content is included, and none ever will be.** You supply the files
from your own legally obtained copy. See [Game files](#game-files).

---

## What this build adds

Everything here is beyond what the Xbox 360 release could do:

| Feature | Description |
|---|---|
| **Uncapped frame rate** | The console was locked to 30. Run it as fast as your hardware allows, or cap it to any refresh rate you like. |
| **Any output resolution** | 1080p, 1440p, 4K. The game's own scene render target is a fixed size, so raising the output resolution costs essentially nothing - measured identical frame times from 1080p to 4K. |
| **Higher internal resolution** | A separate scale for the 3D scene itself, for when you do want to spend the GPU time. |
| **16x anisotropic filtering** | Sharpens the surface ahead of you. Nearly free on any modern GPU and the single best-looking change available. |
| **In-game settings menu** | Press **F5**. Display, Graphics, Audio, Input, Game and Fixes, with search and per-tab reset. No config editing. |
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
DLC is not supported yet - see [Known limitations](#known-limitations).

After that the game starts, and every later launch goes straight to the title
screen.

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

| Key | Action |
|---|---|
| **F5** | Settings menu |
| **F6** | Frame rate overlay |
| **F4** | Advanced view: every setting the engine exposes, by raw name |
| **F3** | Engine debug overlay |
| **`** | Console |

Key bindings are rebindable in the advanced dialog (F4) under Input/Keybinds.

## Settings worth knowing

- **Resolution** (Display) sets the output size and is effectively free. This
  is the one to raise.
- **Internal resolution scale** (Graphics) is the expensive one - it multiplies
  the cost of the 3D scene, and 2x measures roughly 8x the GPU time. Raise it
  one step at a time.
- **Frame rate** (Display) switches between uncapped and capped; the refresh
  rate is typed in directly rather than dragged on a slider.
- **Anisotropic filtering** (Graphics) is the best value in the panel.

Settings are written to `hydrothunder.toml` beside the executable when the
panel closes. The file is merged rather than rewritten, so any comments and
hand-edits you add to it survive.

## Building from source

Requires CMake 3.25+, Ninja, and Clang - rexglue requires Clang, so MSVC is
not supported. On Windows the toolchain that ships with Visual Studio's
"C++ Clang tools for Windows" component works.

```sh
cmake --preset relwithdebinfo
cmake --build --preset relwithdebinfo -- -j3
```

The recompiled C++ is committed under `generated/`, so **building does not
need the game**. Only running it does.

Keep the job count modest. The generated translation units are large and each
one can take 1-2 GB in the compiler; an unbounded `--parallel` will exhaust
memory on a 16 GB machine.

## Known limitations

- **DLC is not supported yet - planned for 1.1.0.** Installing it makes the
  game crash after booting, so the option is switched off rather
  than shipped broken. The base game is unaffected.

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
