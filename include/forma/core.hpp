#ifndef CORE_HPP_
#define CORE_HPP_

#ifdef __APPLE__
#define FORMA_PLATFORM_APPLE
#elif __MINGW32__
#define FORMA_PLATFORM_WINDOWS
#elif __linux__
#define FORMA_PLATFORM_LINUX
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

#endif // CORE_HPP_
