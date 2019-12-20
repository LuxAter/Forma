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
  LTRACE("{}", e);
}

bool forma::Application::on_window_close(WindowCloseEvent &) {
  running = false;
  return true;
}

void forma::Application::run() {
  while (running) {
    window->on_update();
  }
}
