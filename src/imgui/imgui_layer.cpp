#include <forma/imgui/imgui_layer.hpp>

#include <imgui.h>

#include <forma/application.hpp>
#include <forma/events/event.hpp>
#include <forma/layer.hpp>
#include <forma/log.hpp>
#include <forma/platform/opengl/imgui_impl_opengl3.h>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

forma::ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}
forma::ImGuiLayer::~ImGuiLayer() {}

void forma::ImGuiLayer::on_attach() {
  ImGui::CreateContext();
  ImGui::StyleColorsDark();

  ImGuiIO &io = ImGui::GetIO();
  io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
  io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
  io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
  io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
  io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
  io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
  io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
  io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
  io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
  io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
  io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
  io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
  io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
  io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
  io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
  io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
  io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
  io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
  io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
  io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
  io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
  io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
  io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
  io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

  ImGui_ImplOpenGL3_Init("#version 410");
}
void forma::ImGuiLayer::on_detach() {}

void forma::ImGuiLayer::on_update() {
  Application &app = Application::get();
  ImGuiIO &io = ImGui::GetIO();

  io.DisplaySize =
      ImVec2(app.get_window().get_width(), app.get_window().get_height());

  float current_time = static_cast<float>(glfwGetTime());
  io.DeltaTime = time > 0.0 ? (current_time - time) : 1.0 / 60.0f;
  time = current_time;

  ImGui_ImplOpenGL3_NewFrame();
  ImGui::NewFrame();

  static bool show = true;
  ImGui::ShowDemoWindow(&show);

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
void forma::ImGuiLayer::on_event(Event &event) {
  LINFO("IMGUI LAYER EVENT HANDLING");
  EventDispatcher dispatcher(event);
  dispatcher.dispatch<MouseButtonPressedEvent>(
      FORMA_BIND_EVENT_FN(ImGuiLayer::on_mouse_button_pressed));
  dispatcher.dispatch<MouseButtonReleasedEvent>(
      FORMA_BIND_EVENT_FN(ImGuiLayer::on_mouse_button_released));
  dispatcher.dispatch<MouseMovedEvent>(
      FORMA_BIND_EVENT_FN(ImGuiLayer::on_mouse_moved));
  dispatcher.dispatch<MouseScrolledEvent>(
      FORMA_BIND_EVENT_FN(ImGuiLayer::on_mouse_scrolled));
  dispatcher.dispatch<KeyPressedEvent>(
      FORMA_BIND_EVENT_FN(ImGuiLayer::on_key_pressed));
  dispatcher.dispatch<KeyReleasedEvent>(
      FORMA_BIND_EVENT_FN(ImGuiLayer::on_key_released));
  dispatcher.dispatch<KeyTypedEvent>(
      FORMA_BIND_EVENT_FN(ImGuiLayer::on_key_typed));
  dispatcher.dispatch<WindowResizeEvent>(
      FORMA_BIND_EVENT_FN(ImGuiLayer::on_window_resized));
}

bool forma::ImGuiLayer::on_mouse_button_pressed(
    MouseButtonPressedEvent &event) {
  ImGuiIO &io = ImGui::GetIO();
  io.MouseDown[event.get_mouse_button()] = true;
  return false;
}
bool forma::ImGuiLayer::on_mouse_button_released(
    MouseButtonReleasedEvent &event) {
  ImGuiIO &io = ImGui::GetIO();
  io.MouseDown[event.get_mouse_button()] = false;
  return false;
}
bool forma::ImGuiLayer::on_mouse_moved(MouseMovedEvent &event) {
  ImGuiIO &io = ImGui::GetIO();
  LINFO("Mouse: {}, {}", event.get_x(), event.get_y());
  io.MousePos = ImVec2(event.get_x(), event.get_y());
  return false;
}
bool forma::ImGuiLayer::on_mouse_scrolled(MouseScrolledEvent &event) {
  ImGuiIO &io = ImGui::GetIO();
  io.MouseWheelH += event.get_x();
  io.MouseWheel += event.get_y();
  return false;
}
bool forma::ImGuiLayer::on_key_pressed(KeyPressedEvent &event) {
  ImGuiIO &io = ImGui::GetIO();
  io.KeysDown[event.get_keycode()] = true;
  io.KeyCtrl =
      io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
  io.KeyShift =
      io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
  io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
  io.KeySuper =
      io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
  return false;
}
bool forma::ImGuiLayer::on_key_released(KeyReleasedEvent &event) {
  ImGuiIO &io = ImGui::GetIO();
  io.KeysDown[event.get_keycode()] = false;
  return false;
}
bool forma::ImGuiLayer::on_key_typed(KeyTypedEvent &event) {
  ImGuiIO &io = ImGui::GetIO();
  int keycode = event.get_keycode();
  if (keycode > 0 && keycode < 0x10000) {
    io.AddInputCharacter(static_cast<unsigned short>(keycode));
  }
  return false;
}
bool forma::ImGuiLayer::on_window_resized(WindowResizeEvent &event) {
  ImGuiIO &io = ImGui::GetIO();
  io.DisplaySize = ImVec2(event.get_width(), event.get_height());
  io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
  glViewport(0, 0, event.get_width(), event.get_height());
  return false;
}