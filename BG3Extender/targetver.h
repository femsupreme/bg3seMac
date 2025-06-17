#pragma once

// Including SDKDDKVer.h defines the highest available Windows platform.

// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.

#ifdef _WIN32
#define _WIN32_WINNT _WIN32_WINNT_WIN8
#include <SDKDDKVer.h>
#elif defined(__APPLE__)
// Target macOS Sequoia 15.5
#include <AvailabilityMacros.h>
#define MACOSX_DEPLOYMENT_TARGET "15.5"
#else
#error "Unsupported platform"
#endif
