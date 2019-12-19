#include "forma/application.hpp"

#include "forma/events/application_event.hpp"
#include "forma/log.hpp"

forma::Application::Application() {}
forma::Application::~Application() {}
void forma::Application::run() {
  WindowResizeEvent e(1280, 720);
  LTRACE(e);
  while (true) {
  }
}
