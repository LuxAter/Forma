#ifndef FORMA_CORE_HPP_
#define FORMA_CORE_HPP_

#include <csignal>

#include "compiler/compiler.hpp"
#include "platform/platform.hpp"

#ifdef FORMA_PLATFORM_WINDOWS
#ifdef FORMA_BUILD_DLL
#define FORMA_API __declspec(dllexport)
#else
#define FORMA_API __declspec(dllimport)
#endif
#else
#define FORMA_API
#endif

#ifdef __DEBUG__
#define FORMA_ENABLE_ASSERTS
#endif

#ifdef FORMA_ENABLE_ASSERTS
#define FORMA_ASSERT(x, ...)                                                   \
  {                                                                            \
    if (!(x)) {                                                                \
      LERROR("Assertion Failed: {}", __VA_ARGS__);                             \
      std::raise(SIGTRAP);                                                          \
    }                                                                          \
  }
#else
#define FORMA_ASSERT(x, ...)
#endif

namespace forma {
inline FORMA_CONSTEXPR const char *get_platform_name() {
  return FORMA_PLATFORM;
}
} // namespace forma

#endif // FORMA_CORE_HPP_
