#ifndef FORMA_APPLICATION_HPP_
#define FORMA_APPLICATION_HPP_

#include <memory>

#include "core.hpp"
#include "events/application_event.hpp"
#include "events/event.hpp"
#include "layer.hpp"
#include "layer_stack.hpp"
#include "window.hpp"

namespace forma {
class FORMA_API Application {
public:
  Application();
  virtual ~Application();

  void on_event(Event &e);

  void push_layer(Layer *layer);
  void push_overlay(Layer *overlay);

  void run();

private:
  bool on_window_close(WindowCloseEvent &);

  std::unique_ptr<Window> window;
  bool running = true;
  LayerStack layer_stack;
};
Application *create_application();
} // namespace forma

#endif // FORMA_APPLICATION_HPP_
