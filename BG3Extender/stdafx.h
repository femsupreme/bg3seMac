#pragma once

#include "targetver.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#define NOMINMAX

// Windows Header Files
#include <windows.h>
#include <detours.h>
#elif defined(__APPLE__)
// macOS specific includes
#include <TargetConditionals.h>
// Detours is Windows only; placeholder for macOS hooking library if needed
#define DETOURS_STUB 1
#else
#error "Unsupported platform"
#endif

#include <memory>
#include <cstdint>
#include <array>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <cassert>
#include <optional>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <variant>
#include <span>

#include <Extender/Shared/Utils.h>
#include <GameDefinitions/Base/Base.h>
