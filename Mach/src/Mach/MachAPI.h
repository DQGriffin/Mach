#pragma once

#if MACH_WINDOWS
	#if MACH_BUILD
		#define MACH_API __declspec(dllexport)
	#else
		#define MACH_API __declspec(dllimport)
	#endif
#else
	#define MACH_API
#endif