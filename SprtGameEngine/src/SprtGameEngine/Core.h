#pragma once

#ifdef SPRT_PLATFORM_WINDOWS
	#ifdef SPRT_BUILD_DLL
		#define SPRT_API __declspec(dllexport)
	#else
		#define SPRT_API __declspec(dllimport)
	#endif
#else
	#error SprtGameEngine only supports Windows.
#endif