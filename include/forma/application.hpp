#ifndef FORMA_APPLICATION_HPP_
#define FORMA_APPLICATION_HPP_

#include "core.hpp"

namespace forma {
class FORMA_API Application {
public:
  Application();
  virtual ~Application();
  void run();
};
Application* create_application();
} // namespace forma

#endif // FORMA_APPLICATION_HPP_
