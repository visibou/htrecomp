#include "ht_setup.h"
#include "ht_version.h"

#include <cstdio>
#include <cstring>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

#include <rex/filesystem.h>
#include <rex/filesystem/devices/stfs_container_device.h>
#include <rex/filesystem/entry.h>
#include <rex/filesystem/file.h>
#include <rex/logging.h>
#include <rex/system.h>
#include <rex/system/xam/content_device.h>
#include <rex/system/xam/content_manager.h>

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <commdlg.h>
#endif

namespace ht {
namespace {

// X_STATUS_SUCCESS is a macro that expands to a cast - ((X_STATUS)0) - so the
// type has to be visible unqualified for it to compile at all. Qualifying our
// own declarations is not enough.
using rex::X_STATUS;

// Hardcoded because this is a single-title port and the import happens before
// the kernel exists, so there is nothing to ask.
constexpr const char* kTitleId = "5841096A";
constexpr uint32_t kTitleIdValue = 0x5841096A;
constexpr const char* kDlcContentType = "00000002";  // XContentType::kMarketplaceContent
constexpr const char* kDlcXuid = "0000000000000000";

// Read in chunks rather than whole files: the game package is ~460 MB and some
// entries inside it are large.
constexpr size_t kCopyChunk = 1u << 20;

// Titled with the game's name: the SDK's ShowSimpleMessageBox calls every box
// "ReXGlue", which means nothing to a player.
constexpr const char* kDialogTitle = HT_WINDOW_TITLE;

void Info(const std::string& message) {
#if defined(_WIN32)
  ::MessageBoxA(nullptr, message.c_str(), kDialogTitle, MB_OK | MB_ICONINFORMATION | MB_SETFOREGROUND);
#else
  rex::ShowSimpleMessageBox(rex::SimpleMessageBoxType::Help, message);
#endif
}

void Error(const std::string& message) {
#if defined(_WIN32)
  ::MessageBoxA(nullptr, message.c_str(), kDialogTitle, MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
#else
  rex::ShowSimpleMessageBox(rex::SimpleMessageBoxType::Error, message);
#endif
}

#if defined(_WIN32)

bool AskYesNo(const std::string& message, const std::string& title) {
  const int result = ::MessageBoxA(nullptr, message.c_str(), title.c_str(),
                                   MB_YESNO | MB_ICONQUESTION | MB_SETFOREGROUND);
  return result == IDYES;
}

// A plain "pick a file" dialog. The packages have no extension - their name is
// a content id - so the filter has to allow everything.
bool PickFile(const std::string& title, std::filesystem::path* out_path) {
  wchar_t buffer[MAX_PATH * 4] = {};
  std::wstring wide_title(title.begin(), title.end());

  OPENFILENAMEW ofn = {};
  ofn.lStructSize = sizeof(ofn);
  ofn.hwndOwner = nullptr;
  ofn.lpstrFilter = L"Game package (any file)\0*.*\0";
  ofn.lpstrFile = buffer;
  ofn.nMaxFile = DWORD(std::size(buffer));
  ofn.lpstrTitle = wide_title.c_str();
  ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR | OFN_EXPLORER;

  if (!::GetOpenFileNameW(&ofn)) {
    return false;  // cancelled, or the dialog failed
  }
  *out_path = std::filesystem::path(buffer);
  return true;
}

#else

bool AskYesNo(const std::string&, const std::string&) { return false; }
bool PickFile(const std::string&, std::filesystem::path*) { return false; }

#endif  // _WIN32

// Writes one entry out of the package. Returns false on the first real error -
// a partial extraction is worse than none, because the missing-file check
// would then pass while the install is incomplete.
bool WriteEntry(rex::filesystem::Entry* entry, const std::filesystem::path& dest) {
  rex::filesystem::File* file = nullptr;
  if (entry->Open(rex::filesystem::FileAccess::kGenericRead, &file) != X_STATUS_SUCCESS || !file) {
    REXLOG_ERROR("[ht-setup] could not open '{}' inside the package", entry->name());
    return false;
  }

  std::FILE* out = std::fopen(dest.string().c_str(), "wb");
  if (!out) {
    REXLOG_ERROR("[ht-setup] could not create '{}'", dest.string());
    file->Destroy();
    return false;
  }

  std::vector<uint8_t> chunk(kCopyChunk);
  size_t offset = 0;
  const size_t total = entry->size();
  bool ok = true;
  while (offset < total) {
    const size_t want = (total - offset) < kCopyChunk ? (total - offset) : kCopyChunk;
    size_t got = 0;
    if (file->ReadSync(std::span<uint8_t>(chunk.data(), want), offset, &got) != X_STATUS_SUCCESS ||
        got == 0) {
      REXLOG_ERROR("[ht-setup] read failed in '{}' at offset {}", entry->name(), offset);
      ok = false;
      break;
    }
    if (std::fwrite(chunk.data(), 1, got, out) != got) {
      REXLOG_ERROR("[ht-setup] write failed for '{}' - is the disk full?", dest.string());
      ok = false;
      break;
    }
    offset += got;
  }

  std::fclose(out);
  file->Destroy();
  return ok;
}

bool ExtractTree(rex::filesystem::Entry* entry, const std::filesystem::path& dest, int* files,
                 const std::string& prefix) {
  std::error_code ec;
  for (const auto& child : entry->children()) {
    const auto target = dest / child->name();
    const std::string rel = prefix.empty() ? child->name() : prefix + "/" + child->name();
    if (child->attributes() & rex::filesystem::kFileAttributeDirectory) {
      REXLOG_INFO("[ht-setup]   dir  {}", rel);
      std::filesystem::create_directories(target, ec);
      if (!ExtractTree(child.get(), target, files, rel)) {
        return false;
      }
    } else {
      // Logged per file: the package's own directory table is the only way to
      // settle questions about odd layouts, and this is the SDK's parse of it
      // rather than a guess.
      REXLOG_INFO("[ht-setup]   file {} ({} bytes)", rel, child->size());
      std::filesystem::create_directories(dest, ec);
      if (!WriteEntry(child.get(), target)) {
        return false;
      }
      ++(*files);
    }
  }
  return true;
}

// Packages are extracted VERBATIM - never "tidy" what comes out.
//
// The DLC is the case that proves it. Its directory table holds both
//
//     Audio/Xbox360/Pack01Track01.fsb            16 bytes  ("Pack01Track01 \r\n")
//     Audio/Xbox360Pack01Track01.fsb     11,267,136 bytes  (the real FSB4 audio)
//
// and the game opens the SECOND one: during a Bermuda Triangle race it asks for
// 'dlc:\Audio\Xbox360Pack01Track01.fsb', with no separator. That is how it
// behaves on a console too, and the packer laid the files out to match - the
// stubs are just the names the game lists. An earlier build "repaired" this
// by moving the big file onto the stub, which deleted the very file the game
// reads. Whatever the package says is what the console sees, so that is what
// goes on disk.

// Reads a XEX's encryption and compression flags.
//
// This matters more than it looks. A package straight off the marketplace
// holds an ENCRYPTED, LZX-compressed default.xex, and while that loads far
// enough to show the title screen, the game dies the moment it actually needs
// the image - measured: identical binaries and config, only the xex differing,
// crash on START versus a healthy 991 MB process.
//
// So a raw retail xex has to be reported, not silently accepted. An install
// that boots and then dies is far worse than one that refuses up front and
// says why.
//
// Layout: 'XEX2', then at 0x14 the optional header count, then that many
// (key, value) pairs from 0x18. The key whose top 24 bits are 0x000003 is the
// file-format info, and its value is a file offset holding, at +4, a u16
// encryption type and a u16 compression type.
bool ReadXexFormat(const std::filesystem::path& xex, uint16_t* encryption,
                   uint16_t* compression) {
  std::FILE* f = std::fopen(xex.string().c_str(), "rb");
  if (!f) {
    return false;
  }
  std::vector<uint8_t> head(0x4000);
  const size_t got = std::fread(head.data(), 1, head.size(), f);
  std::fclose(f);
  if (got < 0x100 || std::memcmp(head.data(), "XEX2", 4) != 0) {
    return false;
  }

  auto be32 = [&](size_t off) -> uint32_t {
    return (uint32_t(head[off]) << 24) | (uint32_t(head[off + 1]) << 16) |
           (uint32_t(head[off + 2]) << 8) | uint32_t(head[off + 3]);
  };
  auto be16 = [&](size_t off) -> uint16_t {
    return uint16_t((uint32_t(head[off]) << 8) | head[off + 1]);
  };

  const uint32_t count = be32(0x14);
  for (uint32_t i = 0; i < count && (0x18 + i * 8 + 8) <= got; ++i) {
    const uint32_t key = be32(0x18 + i * 8);
    const uint32_t value = be32(0x18 + i * 8 + 4);
    if ((key >> 8) == 0x000003 && size_t(value) + 8 <= got) {
      *encryption = be16(value + 4);
      *compression = be16(value + 6);
      return true;
    }
  }
  return false;
}

// Creates game_data/DataCache if it is missing.
//
// The game opens 'game:\DataCache\' at startup. The directory is NOT in the
// retail package, and the game: mount cannot create it - the call comes back
// ACCESS_DENIED (0xC0000022) and the guest dies shortly after. When the
// directory already exists the same call returns OBJECT_NAME_COLLISION
// (0xC0000035), which is harmless and is what a working install looks like.
//
// Measured both ways on the same build: absent = dead, present = healthy.
// Runs on every launch, because a hand-assembled game_data will not have it
// either.
void EnsureDataCache(const std::filesystem::path& game_data) {
  const auto cache = game_data / "DataCache";
  std::error_code ec;
  if (std::filesystem::exists(cache, ec)) {
    return;
  }
  if (std::filesystem::create_directories(cache, ec)) {
    REXLOG_INFO("[ht-setup] created missing game_data/DataCache");
  } else {
    REXLOG_WARN("[ht-setup] could not create game_data/DataCache: {}", ec.message());
  }
}

#if defined(_WIN32)

// Looks for XEXTool. Beside the game first, then inside game_data, then PATH.
bool FindXexTool(const std::filesystem::path& exe_dir, std::filesystem::path* out) {
  std::error_code ec;
  const std::filesystem::path candidates[] = {
      exe_dir / "xextool.exe",
      exe_dir / "tools" / "xextool.exe",
      exe_dir / "game_data" / "xextool.exe",
  };
  for (const auto& candidate : candidates) {
    if (std::filesystem::exists(candidate, ec)) {
      *out = candidate;
      return true;
    }
  }
  wchar_t found[MAX_PATH] = {};
  if (::SearchPathW(nullptr, L"xextool.exe", nullptr, MAX_PATH, found, nullptr)) {
    *out = std::filesystem::path(found);
    return true;
  }
  return false;
}

// Runs XEXTool to decrypt and decompress the image in place.
//
// '-c u -e u' is what produces a runnable file: verified by converting a raw
// retail xex and getting a byte-identical match (same MD5) to a known-good
// one. The output goes to a temporary file first, so a failed run cannot
// destroy the original.
bool RunXexTool(const std::filesystem::path& tool, const std::filesystem::path& xex) {
  const auto temp = xex.parent_path() / "default_converted.xex";
  std::error_code ec;
  std::filesystem::remove(temp, ec);

  std::wstring cmd = L"\"" + tool.wstring() + L"\" -c u -e u -o \"" + temp.wstring() +
                     L"\" \"" + xex.wstring() + L"\"";

  STARTUPINFOW si = {};
  si.cb = sizeof(si);
  si.dwFlags = STARTF_USESHOWWINDOW;
  si.wShowWindow = SW_HIDE;
  PROCESS_INFORMATION pi = {};
  std::vector<wchar_t> mutable_cmd(cmd.begin(), cmd.end());
  mutable_cmd.push_back(L'\0');

  if (!::CreateProcessW(nullptr, mutable_cmd.data(), nullptr, nullptr, FALSE, CREATE_NO_WINDOW,
                        nullptr, nullptr, &si, &pi)) {
    REXLOG_ERROR("[ht-setup] could not run XEXTool");
    return false;
  }
  ::WaitForSingleObject(pi.hProcess, INFINITE);
  DWORD exit_code = 1;
  ::GetExitCodeProcess(pi.hProcess, &exit_code);
  ::CloseHandle(pi.hProcess);
  ::CloseHandle(pi.hThread);

  if (!std::filesystem::exists(temp, ec) || std::filesystem::file_size(temp, ec) == 0) {
    REXLOG_ERROR("[ht-setup] XEXTool exited {} without producing a file", exit_code);
    std::filesystem::remove(temp, ec);
    return false;
  }

  std::filesystem::remove(xex, ec);
  std::filesystem::rename(temp, xex, ec);
  if (ec) {
    REXLOG_ERROR("[ht-setup] could not replace default.xex: {}", ec.message());
    return false;
  }
  REXLOG_INFO("[ht-setup] converted default.xex with XEXTool");
  return true;
}

#else
bool FindXexTool(const std::filesystem::path&, std::filesystem::path*) { return false; }
bool RunXexTool(const std::filesystem::path&, const std::filesystem::path&) { return false; }
#endif  // _WIN32

// Checks default.xex is in a form the game can actually run, and explains the
// fix if it is not.
//
// Runs on EVERY launch, not just after an import. The first version of this
// only checked freshly imported files, so anyone who assembled game_data by
// hand - which the README documents as the supported route for an
// already-extracted copy - still got the silent boot-then-die.
bool ValidateXexUsable(const std::filesystem::path& exe_dir, const std::filesystem::path& xex) {
  uint16_t encryption = 0, compression = 0;
  if (!ReadXexFormat(xex, &encryption, &compression)) {
    return true;  // unreadable header: let the runtime have its say
  }
  if (encryption == 0 && compression != 2) {
    return true;  // already runnable
  }

  REXLOG_WARN("[ht-setup] default.xex is encryption={} compression={}; converting",
              encryption, compression);

  // Convert it automatically if XEXTool is available - the player should not
  // have to run a command line to play a game.
  std::filesystem::path tool;
  if (FindXexTool(exe_dir, &tool)) {
    REXLOG_INFO("[ht-setup] using XEXTool at '{}'", tool.string());
    if (RunXexTool(tool, xex) && ReadXexFormat(xex, &encryption, &compression) &&
        encryption == 0 && compression != 2) {
      Info("Your game executable needed converting before it could run, and\n"
           "that has been done automatically.\n\n"
           "This only happens once.");
      return true;
    }
    Error("XEXTool was found, but converting default.xex did not work.\n\n"
          "See the log next to this program for details. You can convert it\n"
          "yourself with:\n\n"
          "    xextool -c u -e u -o default.xex default.xex\n\n"
          "then put the result in the game_data folder.");
    return false;
  }

  // xextool.exe ships beside the game, so reaching here means the install is
  // incomplete rather than the user having missed a step.
  Error("xextool.exe is missing from this folder.\n\n"
        "It ships with the game and is needed to convert the game executable,\n"
        "which is encrypted and compressed inside a retail package. Without\n"
        "that step the game reaches the title screen and then closes as soon\n"
        "as you press Start.\n\n"
        "Re-extract the download, keeping all of its files together.\n\n"
        "Or convert it yourself with:\n"
        "    xextool -c u -e u -o default.xex default.xex");
  return false;
}

// Mounts an STFS package and unpacks all of it into `dest`.
bool ExtractPackage(const std::filesystem::path& package, const std::filesystem::path& dest) {
  // Validate before touching anything, so a wrong pick is a clear message
  // rather than an empty folder.
  if (!rex::filesystem::StfsContainerDevice::ReadPackageHeader(package)) {
    Error("That file is not an Xbox 360 content package.\n\n"
          "Expected the package file itself - the one whose name is a long\n"
          "string of hex characters, with no file extension.");
    return false;
  }

  rex::filesystem::StfsContainerDevice device("\\SETUP", package);
  if (!device.Initialize()) {
    Error("That package could not be opened. It may be incomplete or corrupted.");
    return false;
  }

  auto* root = device.ResolvePath("");
  if (!root) {
    Error("That package opened but appears to be empty.");
    return false;
  }

  std::error_code ec;
  std::filesystem::create_directories(dest, ec);

  int files = 0;
  if (!ExtractTree(root, dest, &files, "")) {
    Error("Extracting the package failed part-way through.\n\n"
          "The partly written files were left in place so you can inspect them;\n"
          "delete the folder and try again. See the log for details.");
    return false;
  }
  REXLOG_INFO("[ht-setup] extracted {} file(s) from '{}' to '{}'", files, package.string(),
              dest.string());
  return true;
}

// --- DLC ---------------------------------------------------------------------

// content_root/0000000000000000/5841096A/00000002/ - see ht_setup.h.
std::filesystem::path DlcRoot(const std::filesystem::path& exe_dir) {
  return exe_dir / "user_data" / kDlcXuid / kTitleId / kDlcContentType;
}

// content_root/0000000000000000/5841096A/Headers/00000002/<name>.header
std::filesystem::path DlcHeaderPath(const std::filesystem::path& exe_dir, const std::string& name) {
  return exe_dir / "user_data" / kDlcXuid / kTitleId / "Headers" / kDlcContentType /
         (name + ".header");
}

// The game uses this as the content's root name and the SDK as its directory
// name, so both must be the same string - and XCONTENT_DATA holds 42 chars.
std::string DlcName(const std::filesystem::path& package) {
  std::string name = rex::path_to_utf8(package.filename());
  if (name.size() > sizeof(rex::system::xam::XCONTENT_DATA::file_name_raw)) {
    name.resize(sizeof(rex::system::xam::XCONTENT_DATA::file_name_raw));
  }
  return name;
}

bool AnyDlcInstalled(const std::filesystem::path& exe_dir) {
  std::error_code ec;
  for (auto it = std::filesystem::directory_iterator(DlcRoot(exe_dir), ec);
       it != std::filesystem::directory_iterator(); it.increment(ec)) {
    if (!ec && it->is_directory(ec)) {
      return true;
    }
  }
  return false;
}

// Is this the marketplace content of THIS game? Checked before anything is
// written, so picking the wrong file is a message rather than a stray folder.
std::unique_ptr<rex::filesystem::StfsHeader> ReadDlcHeader(const std::filesystem::path& package) {
  auto header = rex::filesystem::StfsContainerDevice::ReadPackageHeader(package);
  if (!header) {
    return nullptr;
  }
  if (header->metadata.content_type != rex::system::XContentType::kMarketplaceContent ||
      uint32_t(header->metadata.execution_info.title_id) != kTitleIdValue) {
    return nullptr;
  }
  return header;
}

// The license every installed DLC gets: all of it.
//
// The package's own licence entries (what ContentManager::InstallContent
// would derive) grant the Tempest Pack only bit 0. That is enough for its
// tracks, but the boat menu hides a boat whose AssetDB names a package without
// the bits it checks (sub_82226C88), so with bit 0 alone the DLC's own boats -
// Whiplash, Psyclone and the X boats - never appear. Verified both ways on the
// same install. The player supplied the package from their own copy, so it is
// licensed in full.
constexpr uint32_t kDlcLicenseMask = 0xFFFFFFFFu;

// Writes the .header file ContentManager reads when it enumerates the DLC.
//
// This file is NOT optional, whatever an earlier note here claimed:
//   * without it the stock SDK enumerated the package as an uninitialised
//     record and the game died on Start (SDK_PATCHES.md #6);
//   * with that fixed, the package is enumerated but opens with license mask
//     0, and the game HIDES unlicensed DLC - the track list simply ends at the
//     base game's last track. Verified both ways on the same install.
//
// Layout matches ContentManager::WriteContentHeaderFile: the raw
// XCONTENT_AGGREGATE_DATA, then the license mask as a host-endian u32.
bool WriteDlcHeader(const std::filesystem::path& exe_dir, const std::string& name,
                    const std::u16string& display_name, uint32_t license_mask) {
  rex::system::xam::XCONTENT_AGGREGATE_DATA data;
  std::memset(&data, 0, sizeof(data));
  data.device_id = static_cast<uint32_t>(rex::system::xam::DummyDeviceId::HDD);
  data.content_type = rex::system::XContentType::kMarketplaceContent;
  data.set_display_name(display_name.empty() ? rex::path_to_utf16(name) : display_name);
  data.set_file_name(name);
  data.xuid = 0;
  data.title_id = kTitleIdValue;

  const auto path = DlcHeaderPath(exe_dir, name);
  std::error_code ec;
  std::filesystem::create_directories(path.parent_path(), ec);
  std::FILE* out = std::fopen(path.string().c_str(), "wb");
  if (!out) {
    REXLOG_ERROR("[ht-setup] could not create '{}'", path.string());
    return false;
  }
  const bool ok = std::fwrite(&data, sizeof(data), 1, out) == 1 &&
                  std::fwrite(&license_mask, sizeof(license_mask), 1, out) == 1;
  std::fclose(out);
  REXLOG_INFO("[ht-setup] wrote DLC header '{}' (license mask {:08X})", path.string(),
              license_mask);
  return ok;
}

// Unpacks one DLC package into place. Returns true only if it was installed.
//
// Extracts into a staging folder OUTSIDE the content root and moves it in only
// once complete. Every directory under the content root is enumerated as a
// package, so a half-written one there would be handed to the game.
bool InstallDlc(const std::filesystem::path& exe_dir, const std::filesystem::path& package,
                const rex::filesystem::StfsHeader& header) {
  const std::string name = DlcName(package);
  const auto dest = DlcRoot(exe_dir) / name;
  const auto staging = exe_dir / "user_data" / "dlc_staging" / name;

  std::error_code ec;
  std::filesystem::remove_all(staging, ec);
  if (!ExtractPackage(package, staging)) {
    std::filesystem::remove_all(staging, ec);
    return false;
  }
  std::filesystem::create_directories(dest.parent_path(), ec);
  std::filesystem::remove_all(dest, ec);
  std::filesystem::rename(staging, dest, ec);
  if (ec) {
    REXLOG_ERROR("[ht-setup] could not move DLC into place: {}", ec.message());
    Error("The DLC unpacked, but could not be moved into place.\n\n"
          "See the log next to this program for details.");
    std::filesystem::remove_all(staging, ec);
    return false;
  }
  std::filesystem::remove(staging.parent_path(), ec);  // only if now empty

  if (!WriteDlcHeader(exe_dir, name,
                      header.metadata.display_name(rex::system::XLanguage::kEnglish),
                      kDlcLicenseMask)) {
    Error("The DLC unpacked, but its content header could not be written.\n\n"
          "See the log next to this program for details.");
    return false;
  }
  return true;
}

// Asks for the DLC and installs it. Returns true only if it was installed.
bool ImportOptionalDlc(const std::filesystem::path& exe_dir) {
  if (!AskYesNo("Do you also have the Hydro Thunder Hurricane DLC (the Tempest Pack)?\n\n"
                "This is optional - the game runs fine without it. To add it later,\n"
                "put the DLC package file in the 'dlc' folder next to this program\n"
                "and start the game again.\n\n"
                "Select it now?",
                "Optional DLC")) {
    return false;
  }

  std::filesystem::path package;
  if (!PickFile("Select your Hydro Thunder Hurricane DLC package", &package)) {
    return false;
  }
  auto header = ReadDlcHeader(package);
  if (!header) {
    Error("That file is not Hydro Thunder Hurricane DLC.\n\n"
          "Expected the DLC package itself - a file whose name is a long string\n"
          "of hex characters, with no file extension.");
    return false;
  }
  if (!InstallDlc(exe_dir, package, *header)) {
    return false;
  }
  Info("DLC installed.");
  return true;
}

// Offers the DLC once to an install that predates DLC support. The answer is
// remembered so a player who has no DLC is not asked on every launch.
void OfferDlcOnce(const std::filesystem::path& exe_dir) {
  const auto marker = exe_dir / "user_data" / "dlc_offered";
  std::error_code ec;
  if (AnyDlcInstalled(exe_dir) || std::filesystem::exists(marker, ec)) {
    return;
  }
  ImportOptionalDlc(exe_dir);
  std::filesystem::create_directories(marker.parent_path(), ec);
  if (std::FILE* f = std::fopen(marker.string().c_str(), "wb")) {
    std::fclose(f);
  }
}

// Gives every installed DLC folder a .header with the full license:
//   * a folder without one (DLC copied in by hand, without its Headers
//     folder) gets one. The package is not available here, so the display
//     name is the folder name - the game shows neither;
//   * a header from an earlier build, which copied the package's bit 0 and so
//     hid the DLC's boats, has its license raised in place.
// Mod packages (Mod_*) are written by ht_mods.cpp and left alone.
void EnsureDlcHeaders(const std::filesystem::path& exe_dir) {
  std::error_code ec;
  for (auto it = std::filesystem::directory_iterator(DlcRoot(exe_dir), ec);
       it != std::filesystem::directory_iterator(); it.increment(ec)) {
    if (ec || !it->is_directory(ec)) {
      continue;
    }
    const std::string name = rex::path_to_utf8(it->path().filename());
    if (name.rfind("Mod_", 0) == 0) {
      continue;
    }
    const auto path = DlcHeaderPath(exe_dir, name);
    if (!std::filesystem::exists(path, ec)) {
      REXLOG_WARN("[ht-setup] DLC '{}' has no content header; writing one", name);
      WriteDlcHeader(exe_dir, name, {}, kDlcLicenseMask);
      continue;
    }
    // The mask is the host-endian u32 after the aggregate data.
    constexpr auto kMaskOffset = sizeof(rex::system::xam::XCONTENT_AGGREGATE_DATA);
    std::fstream f(path, std::ios::binary | std::ios::in | std::ios::out);
    uint32_t mask = 0;
    if (f.seekg(kMaskOffset) && f.read(reinterpret_cast<char*>(&mask), sizeof(mask)) &&
        mask != kDlcLicenseMask) {
      f.seekp(kMaskOffset);
      f.write(reinterpret_cast<const char*>(&kDlcLicenseMask), sizeof(kDlcLicenseMask));
      REXLOG_INFO("[ht-setup] DLC '{}': license {:08X} -> {:08X}", name, mask, kDlcLicenseMask);
    }
  }
}

// Installs any DLC package the player dropped into <exe>/dlc/. This is the
// "add it later" route; packages already installed are skipped, so the files
// can stay there. Anything that is not this game's DLC is only logged - a
// popup would come back on every launch.
void ImportDroppedDlc(const std::filesystem::path& exe_dir) {
  std::error_code ec;
  for (auto it = std::filesystem::directory_iterator(exe_dir / "dlc", ec);
       it != std::filesystem::directory_iterator(); it.increment(ec)) {
    if (ec || !it->is_regular_file(ec)) {
      continue;
    }
    const auto package = it->path();
    if (std::filesystem::exists(DlcRoot(exe_dir) / DlcName(package), ec)) {
      continue;
    }
    auto header = ReadDlcHeader(package);
    if (!header) {
      REXLOG_WARN("[ht-setup] dlc/{} is not Hydro Thunder Hurricane DLC; ignored",
                  rex::path_to_utf8(package.filename()));
      continue;
    }
    if (InstallDlc(exe_dir, package, *header)) {
      Info("DLC installed from the dlc folder.");
    }
  }
}

}  // namespace

bool EnsureGameData(const std::filesystem::path& exe_dir) {
  const auto game_data = exe_dir / "game_data";
  const auto xex = game_data / "default.xex";

  std::error_code ec;
  if (std::filesystem::exists(xex, ec)) {
    // Already installed - but still make sure DataCache is there and the
    // executable is runnable. A hand-assembled game_data has neither.
    EnsureDataCache(game_data);
    if (!ValidateXexUsable(exe_dir, xex)) {
      return false;
    }
    ImportDroppedDlc(exe_dir);
    OfferDlcOnce(exe_dir);
    EnsureDlcHeaders(exe_dir);
    return true;
  }

  Info("Hydro Thunder Hurricane Recompiled\n\n"
       "This port does not include any game content, so it needs the files\n"
       "from your own copy of the game.\n\n"
       "On the next screen, select your Hydro Thunder Hurricane package - the\n"
       "file whose name is a long string of hex characters, with no extension.\n\n"
       "It will be unpacked next to this program. This only happens once.");

  std::filesystem::path package;
  if (!PickFile("Select your Hydro Thunder Hurricane game package", &package)) {
    Error("No game files selected, so the game cannot start.\n\n"
          "Run it again when you have your copy to hand.");
    return false;
  }

  if (!ExtractPackage(package, game_data)) {
    return false;
  }

  // Prove the import actually produced what the runtime needs, rather than
  // trusting that it succeeded.
  if (!std::filesystem::exists(xex, ec)) {
    Error("That package unpacked, but it does not contain default.xex, so it\n"
          "is not Hydro Thunder Hurricane.\n\n"
          "Delete the game_data folder next to this program and try again with\n"
          "the correct package.");
    return false;
  }

  // The game creates neither of these for itself.
  EnsureDataCache(game_data);
  if (!ValidateXexUsable(exe_dir, xex)) {
    return false;
  }

  // DLC. In 1.0.0 this was switched off because Start "crashed most of the
  // time" with it installed. The guest actually died EVERY time - only the
  // teardown afterwards varied - and the cause was the SDK enumerating a
  // header-less package as an uninitialised record (SDK_PATCHES.md #6). Both
  // that and the missing header are fixed, so it is offered again.
  ImportDroppedDlc(exe_dir);
  if (!AnyDlcInstalled(exe_dir)) {
    ImportOptionalDlc(exe_dir);
  }
  // Asked here already; do not ask again on the next launch.
  const auto marker = exe_dir / "user_data" / "dlc_offered";
  std::filesystem::create_directories(marker.parent_path(), ec);
  if (std::FILE* f = std::fopen(marker.string().c_str(), "wb")) {
    std::fclose(f);
  }

  Info("Setup complete. The game will start now.");
  return true;
}

}  // namespace ht
