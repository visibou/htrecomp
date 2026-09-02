cmake_minimum_required(VERSION 3.25)

if(POLICY CMP0091)
    cmake_policy(SET CMP0091 NEW)
endif()

option(HTRECOMP_STATIC_MSVC_RUNTIME
    "Link Windows MSVC-ABI builds with the static Visual C++ runtime"
    ON)
if(HTRECOMP_STATIC_MSVC_RUNTIME)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

project(hydrothunder VERSION 1.0.0 LANGUAGES CXX)

if(WIN32)
    enable_language(RC)
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "AMD64|x86_64")
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
        add_compile_options(-march=x86-64 -mtune=generic -mssse3)
    endif()
    set(SNAPPY_REQUIRE_AVX OFF CACHE BOOL "Do not require AVX" FORCE)
    set(SNAPPY_REQUIRE_AVX2 OFF CACHE BOOL "Do not require AVX2" FORCE)
    set(SNAPPY_HAVE_SSSE3 0 CACHE INTERNAL "Keep Snappy scalar" FORCE)
    set(SNAPPY_HAVE_X86_CRC32 0 CACHE INTERNAL "Keep Snappy scalar" FORCE)
    set(SNAPPY_HAVE_BMI2 0 CACHE INTERNAL "Keep Snappy scalar" FORCE)
endif()

set(REXSDK_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/third_party/rexglue-sdk"
    CACHE PATH "Path to the rexglue SDK source tree")
set(HT_GAME_DATA_ROOT
    "${CMAKE_CURRENT_SOURCE_DIR}/game_data"
    CACHE PATH "Path to an extracted Hydro Thunder retail game dump")

file(TO_CMAKE_PATH "${CMAKE_CURRENT_SOURCE_DIR}" HT_SOURCE_DIR_CONFIG)
file(TO_CMAKE_PATH "${HT_GAME_DATA_ROOT}" HT_GAME_DATA_ROOT_CONFIG)

set(HT_CODEGEN_ARGS "")
# hydrothunder_overrides.toml is listed as well as the generated functions file:
# it carries top-level scalars (setjmp_address) that live outside [functions],
# and tools/curate_function_config.py only merges the [functions] table across.
# Its [functions] entries therefore appear twice; merge semantics are last-wins
# with identical values, so that is harmless.
set(HT_FUNCTION_CONFIG_INCLUDES
    "  \"${HT_SOURCE_DIR_CONFIG}/config/hydrothunder_functions.toml\",\n  \"${HT_SOURCE_DIR_CONFIG}/config/hydrothunder_overrides.toml\",")
find_package(Python3 REQUIRED COMPONENTS Interpreter)

file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/manifests")

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/manifests/hydrothunder.toml.in
    ${CMAKE_CURRENT_BINARY_DIR}/manifests/hydrothunder.toml
    @ONLY
)

set(REXGLUE_ENABLE_TRACY OFF CACHE BOOL "Disable Tracy instrumentation for normal builds" FORCE)
set(REXGLUE_ENABLE_PERF_COUNTERS OFF CACHE BOOL "Enable lightweight rexglue perf counter instrumentation")

# Include rexglue targets
add_subdirectory(third_party/rexglue-sdk)

include(cmake/CodegenTargets.cmake)

set(HT_SOURCES
    src/main.cpp
    src/ht_settings_overlay.cpp
    src/ht_fps_overlay.cpp
    src/ht_setup.cpp
)

# Executable icon. enable_language(RC) is set above; the .rc references
# icon.ico relative to its own directory.
if(WIN32)
    list(APPEND HT_SOURCES resources/htrecomp.rc)
endif()

if(WIN32)
    add_executable(hydrothunder WIN32 ${HT_SOURCES})
else()
    add_executable(hydrothunder ${HT_SOURCES})
endif()

target_include_directories(hydrothunder PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}/include
    ${REXSDK_DIR}/thirdparty/imgui
    ${CMAKE_CURRENT_BINARY_DIR}/third_party/rexglue-sdk/include
)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/generated/sources.cmake")
    include(generated/sources.cmake)
    target_sources(hydrothunder PRIVATE ${GENERATED_SOURCES})
    target_include_directories(hydrothunder PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/generated)
    set_source_files_properties(${GENERATED_SOURCES} PROPERTIES COMPILE_OPTIONS "-include;${CMAKE_CURRENT_SOURCE_DIR}/fix_stdio.h")
else()
    message(STATUS "generated/sources.cmake not found; run the generate-all target before building")
endif()

target_link_libraries(hydrothunder PRIVATE rex::runtime)
# rexglue SDK provides a helper to apply standard config to the host target
if(COMMAND rexglue_configure_target)
    rexglue_configure_target(hydrothunder)
endif()

if(WIN32)
    # winmm: timeBeginPeriod, used to fix guest vblank pacing (see src/main.cpp)
    target_link_libraries(hydrothunder PRIVATE comdlg32 winhttp d3dcompiler gdiplus winmm)
endif()

add_custom_target(ht_stage_runtime_library
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:hydrothunder>"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:rexruntime>"
        "$<TARGET_FILE_DIR:hydrothunder>"
    DEPENDS rexruntime
    VERBATIM
)
add_dependencies(hydrothunder ht_stage_runtime_library)

if(MSVC)
    target_compile_options(hydrothunder PRIVATE /utf-8)
else()
    target_compile_options(hydrothunder PRIVATE -finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()
