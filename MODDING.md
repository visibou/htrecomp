# Making mods

Mods **add** content to the game. They never replace anything: a mod boat is a
new boat next to the originals, and a mod skin is a new choice in a boat's skin
list. Removing a mod removes exactly what it added, and your save keeps
working.

What a mod can add today:

- **Boats with their own handling**, built on an existing boat's model.
- **Skins**, for existing boats or for the mod's own boats.

Everything a mod adds is unlocked from the start; it costs no credits.

## Installing a mod

Put the mod's folder in `mods/` next to the executable and start the game:

```
Hydro Thunder Hurricane Recompiled/
├─ hydrothunder.exe
└─ mods/
   └─ speedvector/
      ├─ mod.toml
      └─ skins/
         └─ azure.png
```

The game builds each mod when it starts, and again whenever the mod changes.
**F5 > Mods** lists every mod and what happened to it; so does
`mods/mods_log.txt`. A mod with a mistake in it is skipped, with the reason in
both places and in a `build_error.txt` inside the mod's folder, and the game
starts without it.

To turn a mod off without deleting it, untick it in F5 > Mods and restart the
game. (That leaves an empty file named `disabled` in the mod's folder; delete
it to turn the mod back on.)

## Writing a mod

A mod is a folder holding a `mod.toml` and the files it names:

```toml
id = "speedvector"          # 2-24 lowercase letters and digits
name = "Speed Vector"
version = "1.0"
author = "you"

[[boat]]
id = "Rocket"
base = "Vector"             # model, sounds and handling start from this boat
name = "Rocket"
description = "A Vector with a far bigger engine."

[boat.tuning]               # changes from the base boat, see below
Engine = { "Max Forward Speed" = 250, "Max Thrust" = 260000 }
Stats = { TopSpeed = 10, Acceleration = 10 }

[[skin]]
id = "Azure"
boats = ["Vector", "Rocket"]    # existing boats and/or this mod's boats
name = "Azure"
texture = "skins/azure.png"
```

The `id` is your mod's namespace. Everything the mod creates is named after it
(the boat above is `speedvector_Rocket`), which is how two mods can never
collide and a mod can never overwrite the game's own content. Pick something
distinctive, and do not change it once people use your mod.

### Boats

| Key | |
|---|---|
| `id` | Letters and digits, unique within your mod. |
| `base` | The boat whose model, animations, sounds and handling the new boat starts from. Any boat in the game, including the Tempest Pack's if it is installed. |
| `name` | Shown in the boat list (in capitals, like the game's own). |
| `description` | Shown under the boat list. |
| `[boat.tuning]` | Settings that differ from the base boat. |

A boat without skins of its own wears its base boat's skins.

#### Tuning

`[boat.tuning]` is merged over the base boat's settings. You only write what
you change, and nested tables merge too:

```toml
[boat.tuning]
Mass = 2600
Engine = { "Max Forward Speed" = 200, "Boost Thrust Modifier" = 2.0 }
Hull = { "Air Control Max" = 1.5 }
Stats = { TopSpeed = 9, Acceleration = 8, Handling = 7, AirControl = 6 }
```

- `Stats` are the bars in the boat menu, from 0 to 10. They are display only,
  so set them to match what your tuning actually does.
- Names with spaces need quotes, exactly as the game spells them.
- A setting the base boat does not have is ignored, and reported in
  `mods_log.txt` as a warning. That catches most typos.

To see every setting a boat has, use the templates (below): each boat's
`<Boat>.json` is its complete entry. `Engine` and `Hull` hold the handling.
For scale, Vector's `Max Forward Speed` is 140 and its `Max Thrust` 104000.

### Skins

| Key | |
|---|---|
| `id` | Letters and digits, unique within your mod. |
| `boats` | The boats the skin is offered on: game boats by name (`"Vector"`), or your own boats by their `id`. |
| `name` | Shown in the skin list. |
| `texture` | A PNG in your mod folder. |
| `texture_asset` | Instead of `texture`: reuse a texture that ships with the game, such as `"Boats/Vector_pirate"`. |

The PNG must be a power of two in each dimension. Boat skins are 1024x1024;
use that. It is converted to the game's own texture format when the mod is
built.

A skin is painted over one boat's model, so it only looks right on boats that
share that model: Vector and a mod boat based on Vector, for example.

### Skin templates

To get each boat's own skin to paint over, press **Export skin templates** in
F5 > Mods. It writes each boat's default skin to `mods/_templates/` as
`<Boat>.png`, and its settings as `<Boat>.json`. That's about 20 MB, which is
why it only happens when you ask. (An empty `mods/_templates` folder does the
same at the next launch.)

The textures are your copy of the game's files. Use them to paint your own
skins, but do not redistribute them.

## Sharing a mod

Share the mod folder: `mod.toml` and your own files, nothing else. Mods are
built on each player's machine from their own copy of the game, so a mod never
needs to include, and must not include, files from the game.

## How it works

This is for the curious. Nothing here is needed to make a mod.

The Tempest Pack DLC is not a patch. It is a second asset archive carrying
small fragments of the game's databases, which the game merges into its own.
Each mod is built into an archive of the same kind and installed the same
way, as `user_data/.../00000002/Mod_<id>/`. The game cannot tell a mod from
DLC.

The recompilation fixes one bug in that merge, so that mods can add skins to
existing boats (`src/ht_mods_merge.cpp`). As shipped, the game treated an
addition to an existing boat as a second copy of that boat, and the boat menu
then looped before reaching anything after it. That bug is also why the
Tempest Pack's own extra skins for the original boats never appeared.

The research tools behind this are in the source repository, under
`tools/modding/`, not in the release:

| | |
|---|---|
| `ht_apf.py` | List and pack `.apf` archives; convert databases to and from JSON. |
| `ht_tex.py` | Convert between PNG and the game's textures. |
| `ht_mod.py` | The reference implementation of the mod builder, in Python. |
| `apfx.c` | Extract `.apf` archives (needs libmspack). |

The Python tools need Python 3.11 or later, and `ht_tex.py` also needs numpy
and Pillow. `MODDING_PLAN.md`, also in the source repository, covers the
research, the formats and what comes next.
