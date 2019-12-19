#ifndef FORMA_CORE_HPP_
#define FORMA_CORE_HPP_

#include "os/compiler.hpp"
#include "os/platform.hpp"

namespace forma {
FORMA_CONSTEXPR const char *get_platform_name() { return FORMA_PLATFORM; }
} // namespace forma

#endif // FORMA_CORE_HPP_
