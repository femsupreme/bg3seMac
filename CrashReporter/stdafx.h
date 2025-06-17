// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#elif defined(__APPLE__)
#include <TargetConditionals.h>
#endif

#include <string>

std::string ToUTF8(std::wstring const & s);
std::wstring FromUTF8(std::string const & s);
