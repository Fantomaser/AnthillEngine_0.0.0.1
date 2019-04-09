#pragma once


#ifdef DLL_LEVEL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

extern "C" void _stdcall DLL_API CreateWindow(int, int, int, int, const char*, const char*, int);