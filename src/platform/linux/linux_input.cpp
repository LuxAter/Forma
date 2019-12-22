#include "forma/platform/linux/linux_input.hpp"

#include <utility>

#include <GLFW/glfw3.h>

#include "forma/application.hpp"

forma::Input *forma::Input::instance = new LinuxInput();

bool forma::LinuxInput::is_key_pressed_impl(int keycode) {
  auto window = static_cast<GLFWwindow *>(
      Application::get().get_window().get_native_window());
  auto state = glfwGetKey(window, keycode);
  return state == GLFW_PRESS || state == GLFW_REPEAT;
}
bool forma::LinuxInput::is_mouse_button_pressed_impl(int button) {
  auto window = static_cast<GLFWwindow *>(
      Application::get().get_window().get_native_window());
  auto state = glfwGetMouseButton(window, button);
  return state == GLFW_PRESS;
}
float forma::LinuxInput::get_mouse_x_impl() {
  auto window = static_cast<GLFWwindow *>(
      Application::get().get_window().get_native_window());
  double xpos, ypos;
  glfwGetCursorPos(window, &xpos, &ypos);
  return static_cast<float>(xpos);
}
float forma::LinuxInput::get_mouse_y_impl() {
  auto window = static_cast<GLFWwindow *>(
      Application::get().get_window().get_native_window());
  double xpos, ypos;
  glfwGetCursorPos(window, &xpos, &ypos);
  return static_cast<float>(ypos);
}
std::pair<float, float> forma::LinuxInput::get_mouse_pos_impl() {
  auto window = static_cast<GLFWwindow *>(
      Application::get().get_window().get_native_window());
  double xpos, ypos;
  glfwGetCursorPos(window, &xpos, &ypos);
  return std::make_pair(static_cast<float>(xpos), static_cast<float>(ypos));
}