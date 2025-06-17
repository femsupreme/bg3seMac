cmake_minimum_required(VERSION 3.16)
project(bg3se_stub)

if(APPLE)
    add_library(bg3se_stub SHARED macos/bg3se_stub.cpp)
    set_target_properties(bg3se_stub PROPERTIES
        OUTPUT_NAME bg3se
        MACOSX_RPATH ON
    )
else()
    message(FATAL_ERROR "This CMake setup only supports macOS")
endif()
