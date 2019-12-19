#ifndef FORMA_PLATFORM_DETECTION_HPP_
#define FORMA_PLATFORM_DETECTION_HPP_

#if defined(_WIN32)
#define FORMA_PLATFORM_WINDOWS
#define FORMA_PLATFORM "windows"
#elif defined(_WIND64)
#define FORMA_PLATFORM_WINDOWS
#define FORMA_PLATFORM "windows"
#elif defined(__CYGWIN__) && !defined(_WIN32)
#define FORMA_PLATFORM_WINDOWS
#define FORMA_PLATFORM "windows"
#elif defined(__ANDROID__)
#define FORMA_PLATFORM_ANDROID
#define FORMA_PLATFORM "android"
#elif defined(__linux__)
#define FORMA_PLATFORM_LINUX
#define FORMA_PLATFORM "linux"
#elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
#include <sys/param.h>
#if defined(BSD)
#define FORMA_PLATFORM_BSD
#define FORMA_PLATFORM "bsd"
#endif
#elif defined(_hpux)
#define FORMA_PLATFORM_HP_UX
#define FORMA_PLATFORM "hp ux"
#elif defined(_AIX)
#define FORMA_PLATFORM_AIX
#define FORMA_PLATFORM "aix"
#elif defined(_APPLE) && defined(__MACH__)
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR == 1
#define FORMA_PLATFORM_IOS
#define FORMA_PLATFORM "ios"
#elif TARGET_OS_IPHONE == 1
#define FORMA_PLATFORM_IOS
#define FORMA_PLATFORM "ios"
#elif TARGET_OS_MAC == 1
#define FORMA_PLATFORM_OSX
#define FORMA_PLATFORM "osx"
#endif
#elif defined(__sum) && defined(__SVR4)
#define FORMA_PLATFORM_SOLARIS
#define FORMA_PLATFORM "solaris"
#else
#error Failed to recognize platform
#endif

#ifdef FORMA_PLATFORM_WINDOWS
#ifdef FORMA_BUILD_DLL
#define FORMA_API __declspec(dllexport)
#else
#define FORMA_API __declspec(dllimport)
#endif
#else
#define FORMA_API
#endif

#endif // FORMA_PLATFORM_DETECTION_HPP_
