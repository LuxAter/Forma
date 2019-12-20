#include "forma/platform/apple/apple_window.hpp"

#include <string>

#include <GLFW/glfw3.h>

#include <forma/log.hpp>
#include <forma/window.hpp>

static bool glfw_initalized = false;

forma::AppleWindow::AppleWindow(const WindowProps &props) { init(props); }
forma::AppleWindow::~AppleWindow() { term(); }
void forma::AppleWindow::on_update() {
  glfwPollEvents();
  glfwSwapBuffers(window);
}

void forma::AppleWindow::set_vsync(bool enabled) {
  if (enabled) {
    glfwSwapInterval(1);
  } else {
    glfwSwapInterval(0);
  }
  data.vsync = enabled;
}
bool forma::AppleWindow::is_vsync() const { return data.vsync; }

void forma::AppleWindow::init(const WindowProps &props) {
  data.title = props.title;
  data.width = props.width;
  data.height = props.height;

  LINFO("Creating window {} ({}, {}))", data.title, data.width, data.height);
  if (!glfw_initalized) {
    int success = glfwInit();
    FORMA_ASSERT(success, "Could not initalize GLFW");
    glfw_initalized = true;
  }
  window = glfwCreateWindow(static_cast<int>(data.width),
                            static_cast<int>(data.height), data.title.c_str(),
                            nullptr, nullptr);
  glfwMakeContextCurrent(window);
  glfwSetWindowUserPointer(window, &data);
  set_vsync(true);
}
void forma::AppleWindow::term() { glfwDestroyWindow(window); }

forma::Window *forma::Window::create(const WindowProps &props) {
  return new AppleWindow(props);
}
