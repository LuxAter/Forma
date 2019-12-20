#ifndef FORMA_APPLICATION_HPP_
#define FORMA_APPLICATION_HPP_

#include <memory>

#include "core.hpp"
#include "events/event.hpp"
#include "window.hpp"

namespace forma {
class FORMA_API Application {
public:
  Application();
  virtual ~Application();
  void run();
private:
  std::unique_ptr<Window> window;
  bool running = true;
};
Application* create_application();
} // namespace forma

#endif // FORMA_APPLICATION_HPP_
