#pragma once

#ifdef LL_PLATFORM_WINDOWS
	#ifdef LL_BUILD_DLL
		#define LILAC_API __declspec(dllexport)
	#else
		#define LILAC_API __declspec(dllimport)
	#endif
#else
	#error Lilac only supports Windows!
#endif

#define BIT(x) (1 << x)
