"""Build a mod folder into a content package the game loads next to the DLC.

    python ht_mod.py build <mod folder> <user_data> --base-db <folder>

<user_data> is the recompilation's user_data folder. The package is written
to user_data/0000000000000000/5841096A/00000002/<package>/ with its content
header, exactly where an installed DLC lives. --base-db is a folder holding
the base game's (and DLC's) DB assets as AkDBAsset/<Name>.bin, used to copy
the boat a new boat is based on.

This is the reference implementation of the mod format, used to prove it in
game. Players do not need it: the recompilation builds mods/ itself at launch
(src/ht_mods.cpp, which follows this file). It stays useful for checking a mod
without starting the game.

A mod folder holds mod.toml and the files it names:

    id = "mymod"            namespace: lowercase letters and digits
    name = "My Mod"
    version = "1.0"

    [[boat]]
    id = "Rocket"           becomes mymod_Rocket
    base = "Vector"         model, sounds and handling start from this boat
    name = "ROCKET"
    description = "..."
    [boat.tuning]           merged over the base boat's BoatBodyDB entry
    Engine = { "Max Forward Speed" = 230 }

    [[skin]]
    id = "Gold"             becomes mymod_Gold
    boats = ["Vector", "Rocket"]   existing boats and/or this mod's boats
    name = "GOLD"
    texture = "textures/gold.png"  1024x1024 PNG (or a ready AkTextureAsset .bin)
    # or: texture_asset = "Boats/Vector_skinC" to reuse a shipped texture

Everything a mod adds is named <id>_<Name> and stored under <id>/, so it can
never replace a base, DLC or other-mod entry. Mod content costs 0 credits.
"""
import copy
import json
import os
import re
import shutil
import struct
import sys
import tomllib
from xml.sax.saxutils import escape

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ht_apf  # noqa: E402

TITLE = "5841096A"
MARKETPLACE = "00000002"
ID_RE = re.compile(r"^[a-z][a-z0-9]{1,23}$")
NAME_RE = re.compile(r"^[A-Za-z][A-Za-z0-9]{0,31}$")


class ModError(Exception):
    pass


def load_db(base_db, name):
    """Merged view of a shipped DB: base first, then each DLC fragment."""
    merged = {}
    for root in base_db:
        path = os.path.join(root, "AkDBAsset", name + ".bin")
        if os.path.exists(path):
            with open(path, "rb") as f:
                frag = ht_apf.asset_to_json(f.read())["AkDBAsset"]
            for k, v in frag.items():
                merged.setdefault(k, v) if isinstance(v, list) else merged.__setitem__(k, v)
    return merged


def deep_merge(dst, src, path=""):
    """Tuning over a copy of the base boat. Keys the base boat lacks are
    almost always typos, so they are reported and skipped (as ht_mods.cpp)."""
    for k, v in src.items():
        here = path + k
        if k not in dst:
            print("warning: tuning.%s is not a setting of the base boat; ignored" % here)
        elif isinstance(v, dict) and isinstance(dst[k], dict):
            deep_merge(dst[k], v, here + ".")
        elif isinstance(dst[k], float) and isinstance(v, int) and not isinstance(v, bool):
            dst[k] = float(v)
        else:
            dst[k] = copy.deepcopy(v)
    return dst


def find_choice(option_db, boat):
    for group in option_db.get("BoatConfig", []):
        for c in group.get("Choices", []):
            if c.get("Value") == boat:
                return c
    return None


def find_unlock(unlock_db, name):
    for u in unlock_db.get("Unlockables", []):
        if u.get("Name") == name:
            return u
    return None


def build(mod_dir, base_db):
    with open(os.path.join(mod_dir, "mod.toml"), "rb") as f:
        mod = tomllib.load(f)
    mid = mod.get("id", "")
    if not ID_RE.match(mid):
        raise ModError("id %r: use 2-24 lowercase letters and digits, starting with a letter" % mid)

    bodies = load_db(base_db, "BoatBodyDB")
    skins_db = load_db(base_db, "BoatSkinDB")
    options = {"BoatConfig": []}
    for root in base_db:  # BoatConfig choices are a list per fragment
        p = os.path.join(root, "AkDBAsset", "OptionDB.bin")
        if os.path.exists(p):
            with open(p, "rb") as f:
                options["BoatConfig"] += ht_apf.asset_to_json(f.read())["AkDBAsset"].get("BoatConfig", [])
    unlocks = {"Unlockables": []}
    for root in base_db:
        p = os.path.join(root, "AkDBAsset", "UnlockDB.bin")
        if os.path.exists(p):
            with open(p, "rb") as f:
                unlocks["Unlockables"] += ht_apf.asset_to_json(f.read())["AkDBAsset"].get("Unlockables", [])

    out_body, out_skin, out_unlock, choices, strings, assets = {}, {}, [], [], {}, []
    tex_index = {}
    mod_boats = {}

    def ns(name, what):
        if not NAME_RE.match(name):
            raise ModError("%s id %r: letters and digits only" % (what, name))
        return "%s_%s" % (mid, name)

    for b in mod.get("boat", []):
        key = ns(b["id"], "boat")
        base = b.get("base")
        if base not in bodies:
            raise ModError("boat %s: base boat %r does not exist" % (b["id"], base))
        if key in bodies:
            raise ModError("boat %s already exists" % key)
        entry = deep_merge(copy.deepcopy(bodies[base]), b.get("tuning", {}))
        entry["StringID"] = "BoatBody_" + key
        mod_boats[b["id"]] = (key, base, entry)
        strings["BoatBody_" + key] = b.get("name", b["id"]).upper()
        strings["BoatBody_%s_Info" % key] = b.get("description", "")
        strings["Unlock_" + key] = b.get("name", b["id"])
        strings["Unlock_%s_Info" % key] = b.get("description", "")

    skins_for = {}  # boat value -> [skin keys] this mod adds to it
    for s in mod.get("skin", []):
        key = ns(s["id"], "skin")
        if key in skins_db:
            raise ModError("skin %s already exists" % key)
        if "texture_asset" in s:
            tex = s["texture_asset"]
        else:
            tex = "%s/Skins/%s" % (mid, s["id"])
            path = os.path.join(mod_dir, s["texture"])
            if path.lower().endswith(".png"):
                import ht_tex
                from PIL import Image
                assets.append(("AkTextureAsset/" + tex, ht_tex.encode(Image.open(path))))
            else:
                with open(path, "rb") as f:
                    assets.append(("AkTextureAsset/" + tex, f.read()))
            tex_index[tex] = {"File": tex + ".tga", "Type": "DEFAULT"}
        out_skin[key] = {"Textures": {"DiffuseTexture": tex}}
        strings["BoatSkin_" + key] = s.get("name", s["id"]).upper()
        strings["Unlock_" + key] = s.get("name", s["id"])
        strings["Unlock_%s_Info" % key] = s.get("description", "")
        for boat in s.get("boats", []):
            target = mod_boats[boat][0] if boat in mod_boats else boat
            if target not in bodies and boat not in mod_boats:
                raise ModError("skin %s: boat %r does not exist" % (s["id"], boat))
            skins_for.setdefault(target, []).append(key)
        out_unlock.append({"Name": key, "Type": "Skin", "Credits": 0, "AvailableInTrial": True,
                           "StringID": "Unlock_" + key, "InfoStringID": "Unlock_%s_Info" % key,
                           "Image": "UI/Award/Boat/Vector"})

    for bid, (key, base, entry) in mod_boats.items():
        base_choice = find_choice(options, base)
        base_skins = [c for o in base_choice["Options"] if o["Name"] == "Skin" for c in o["Choices"]]
        own = [{"StringID": "BoatSkin_" + k, "Value": k} for k in skins_for.pop(key, [])]
        team = [c for c in base_skins if "Team" in c["Value"]]
        if own:
            skin_choices = own + team
        else:
            skin_choices = copy.deepcopy(base_skins)
        entry["AISkins"] = [c["Value"] for c in skin_choices if "Team" not in c["Value"]][:3]
        out_body[key] = entry
        choices.append({"InfoStringID": "BoatBody_%s_Info" % key, "StringID": "BoatBody_" + key,
                        "Value": key,
                        "Options": [{"Name": "Skin", "StringID": "Option_Skin", "Choices": skin_choices}]})
        base_unlock = find_unlock(unlocks, base) or {}
        out_unlock.append({"Name": key, "Type": "Body", "Credits": 0, "AvailableInTrial": True,
                           "StringID": "Unlock_" + key, "InfoStringID": "Unlock_%s_Info" % key,
                           "Image": base_unlock.get("Image", "UI/Award/Boat/Vector")})

    # Skins added to existing boats merge into that boat's choice by Value,
    # the way the DLC gave Vector its fourth skin.
    for boat, keys in skins_for.items():
        choices.append({"Value": boat, "Options": [{"Name": "Skin", "Choices": [
            {"StringID": "BoatSkin_" + k, "Value": k} for k in keys]}]})

    dbs = {}
    if out_body: dbs["BoatBodyDB"] = out_body
    if out_skin: dbs["BoatSkinDB"] = out_skin
    if choices: dbs["OptionDB"] = {"BoatConfig": [{"Name": "Body", "Choices": choices}]}
    if out_unlock: dbs["UnlockDB"] = {"Unlockables": out_unlock}

    entries = [("Assets/AkGenericAsset", ht_apf.json_to_asset(None, "Assets"))]  # null, as in Pack01
    entries.append(("Assets/AkDBAsset", ht_apf.json_to_asset(
        {n: {"File": "%s/DB/%s.json" % (mid, n)} for n in dbs}, "Assets")))
    if tex_index:
        entries.append(("Assets/AkTextureAsset", ht_apf.json_to_asset(tex_index, "Assets")))
    for n, v in dbs.items():
        entries.append(("AkDBAsset/" + n, ht_apf.json_to_asset({"AkDBAsset": v}, "AkDBAsset")))
    entries += assets
    return mid, mod, entries, strings, dbs


def write_resx(path, strings):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8", newline="\r\n") as f:
        f.write('<?xml version="1.0" encoding="utf-8"?>\n<root>\n')
        for k, v in strings.items():
            f.write('  <data name="%s">\n    <value>%s</value>\n  </data>\n' % (escape(k), escape(v)))
        f.write("</root>\n")


def write_header(path, package, display):
    """XCONTENT_AGGREGATE_DATA + host-endian license mask (see ht_setup.cpp)."""
    d = bytearray(0x148)
    struct.pack_into(">II", d, 0, 1, 2)  # device HDD, marketplace content
    name16 = display.encode("utf-16-be")[:0xFE]
    d[8:8 + len(name16)] = name16
    fn = package.encode("ascii")[:42]
    d[0x108:0x108 + len(fn)] = fn
    struct.pack_into(">I", d, 0x140, int(TITLE, 16))
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "wb") as f:
        f.write(d + struct.pack("<I", 0xFFFFFFFF))


def install(user_data, mid, mod, entries, strings):
    root = os.path.join(user_data, "0000000000000000", TITLE)
    package = "Mod_" + mid
    target = os.path.join(root, MARKETPLACE, package)
    if os.path.isdir(target):
        shutil.rmtree(target)
    os.makedirs(target)
    ht_apf.write_archive(os.path.join(target, mid + ".apf"), entries)
    write_resx(os.path.join(target, "Strings", "en-us.resx"), strings)
    write_header(os.path.join(root, "Headers", MARKETPLACE, package + ".header"),
                 package, mod.get("name", mid))
    return target


def main(argv):
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument("cmd", choices=["build"])
    ap.add_argument("mod")
    ap.add_argument("user_data")
    ap.add_argument("--base-db", action="append", required=True)
    ap.add_argument("--dump", help="also write the generated DBs as JSON here")
    a = ap.parse_args(argv)
    try:
        mid, mod, entries, strings, dbs = build(a.mod, a.base_db)
    except ModError as e:
        print("mod error:", e)
        return 1
    if a.dump:
        with open(a.dump, "w", encoding="utf-8") as f:
            json.dump({"dbs": dbs, "strings": strings}, f, indent=1)
    print("installed", install(a.user_data, mid, mod, entries, strings), "-", len(entries), "entries")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
