#pragma once


#ifdef _WIN32
#ifdef NEKO_DLL
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#else
#define NekoApi __attribute__((visibility("default")))
#endif

#define BIT(x) (1 << x)
