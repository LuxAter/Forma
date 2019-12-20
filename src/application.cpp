#include "forma/application.hpp"

#include "forma/log.hpp"

#define BIND_EVENT(x) std::bind(&Application::x, this, std::placeholders::_1)

forma::Application::Application() {
  window = std::unique_ptr<Window>(Window::create());
  window->set_event_callback(BIND_EVENT(on_event));
}
forma::Application::~Application() {}

void forma::Application::on_event(Event &e) {
  EventDispatcher dispatcher(e);
  dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT(on_window_close));

  for (auto it = layer_stack.end(); it != layer_stack.begin();) {
    (*--it)->on_event(e);
    if (e.handled)
      break;
  }
  LTRACE("{}", e);
}

bool forma::Application::on_window_close(WindowCloseEvent &) {
  running = false;
  return true;
}

void forma::Application::push_layer(Layer *layer) {
  layer_stack.push_layer(layer);
}
void forma::Application::push_overlay(Layer *overlay) {
  layer_stack.push_overlay(overlay);
}

void forma::Application::run() {
  while (running) {
    window->on_update();
    for(Layer* layer : layer_stack) {
      layer->on_update();
    }
  }
}
