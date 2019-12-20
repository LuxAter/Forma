#include "forma/platform/linux/linux_window.hpp"

#include <string>

#include <GLFW/glfw3.h>

#include <forma/events/application_event.hpp>
#include <forma/events/key_event.hpp>
#include <forma/events/mouse_event.hpp>
#include <forma/log.hpp>
#include <forma/window.hpp>

static bool glfw_initalized = false;

static void glfw_error_callback(int error, const char *description) {
  LERROR("GLFW[{}]: {}", error, description);
}

forma::LinuxWindow::LinuxWindow(const WindowProps &props) { init(props); }
forma::LinuxWindow::~LinuxWindow() { term(); }
void forma::LinuxWindow::on_update() {
  glfwPollEvents();
  glfwSwapBuffers(window);
}

void forma::LinuxWindow::set_vsync(bool enabled) {
  if (enabled) {
    glfwSwapInterval(1);
  } else {
    glfwSwapInterval(0);
  }
  data.vsync = enabled;
}
bool forma::LinuxWindow::is_vsync() const { return data.vsync; }

void forma::LinuxWindow::init(const WindowProps &props) {
  data.title = props.title;
  data.width = props.width;
  data.height = props.height;

  LINFO("Creating window {} ({}, {}))", data.title, data.width, data.height);
  if (!glfw_initalized) {
    int success = glfwInit();
    FORMA_ASSERT(success, "Could not initalize GLFW");
    glfwSetErrorCallback(glfw_error_callback);
    glfw_initalized = true;
  }
  window = glfwCreateWindow(static_cast<int>(data.width),
                            static_cast<int>(data.height), data.title.c_str(),
                            nullptr, nullptr);
  glfwMakeContextCurrent(window);
  glfwSetWindowUserPointer(window, &data);
  set_vsync(true);

  glfwSetWindowSizeCallback(
      window, [](GLFWwindow *window, int width, int height) {
        WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
        data.width = width;
        data.height = height;
        WindowResizeEvent event(width, height);
        data.event_callback(event);
      });
  glfwSetWindowCloseCallback(window, [](GLFWwindow *window) {
    WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
    WindowCloseEvent event;
    data.event_callback(event);
  });
  glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode,
                                int action, int mods) {
    WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
    switch (action) {
    case GLFW_PRESS: {
      KeyPressedEvent event(key, 0);
      data.event_callback(event);
      break;
    }
    case GLFW_RELEASE: {
      KeyReleasedEvent event(key);
      data.event_callback(event);
      break;
    }
    case GLFW_REPEAT: {
      KeyPressedEvent event(key, 1);
      data.event_callback(event);
      break;
    }
    }
  });
  glfwSetMouseButtonCallback(
      window, [](GLFWwindow *window, int button, int action, int mods) {
        WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
        switch (action) {
        case GLFW_PRESS: {
          MouseButtonPressedEvent event(button);
          data.event_callback(event);
          break;
        }
        case GLFW_RELEASE: {
          MouseButtonReleasedEvent event(button);
          data.event_callback(event);
          break;
        }
        }
      });
  glfwSetScrollCallback(
      window, [](GLFWwindow *window, double x_offset, double y_offset) {
        WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
        MouseScrolledEvent event(static_cast<float>(x_offset),
                                 static_cast<float>(y_offset));
        data.event_callback(event);
      });
  glfwSetCursorPosCallback(window, [](GLFWwindow *window, double x_pos,
                                      double y_pos) {
    WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
    MouseMovedEvent event(static_cast<float>(x_pos), static_cast<float>(y_pos));
    data.event_callback(event);
  });
}
void forma::LinuxWindow::term() { glfwDestroyWindow(window); }

forma::Window *forma::Window::create(const WindowProps &props) {
  return new LinuxWindow(props);
}
