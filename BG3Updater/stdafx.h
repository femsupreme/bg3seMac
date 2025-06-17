// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#ifdef _WIN32
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#elif defined(__APPLE__)
#include <TargetConditionals.h>
#endif

#include <string>
#include <memory>
#include <optional>
#include <sstream>
#include <vector>

#include <CoreLib/Base/Base.h>
#include <CoreLib/Utils.h>
#include "Defines.h"
#include "GameHelpers.h"
