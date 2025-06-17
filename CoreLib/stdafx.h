#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#define NOMINMAX
#include <windows.h>
#elif defined(__APPLE__)
#include <TargetConditionals.h>
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

#include <CoreLib/Utils.h>
#include <CoreLib/Base/Base.h>
