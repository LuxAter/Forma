#ifndef FORMA_IMGUI_LAYER_HPP_
#define FORMA_IMGUI_LAYER_HPP_

#include <forma/events/application_event.hpp>
#include <forma/events/event.hpp>
#include <forma/events/key_event.hpp>
#include <forma/events/mouse_event.hpp>
#include <forma/layer.hpp>

namespace forma {
class FORMA_API ImGuiLayer : public Layer {
public:
  ImGuiLayer();
  ~ImGuiLayer();

  void on_attach() override;
  void on_detach() override;
  void on_update() override;
  void on_event(Event &event) override;

private:
  bool on_mouse_button_pressed(MouseButtonPressedEvent &event);
  bool on_mouse_button_released(MouseButtonReleasedEvent &event);
  bool on_mouse_moved(MouseMovedEvent &event);
  bool on_mouse_scrolled(MouseScrolledEvent &event);
  bool on_key_pressed(KeyPressedEvent &event);
  bool on_key_released(KeyReleasedEvent &event);
  bool on_key_typed(KeyTypedEvent &event);
  bool on_window_resized(WindowResizeEvent &event);

  float time = 0.0f;
};
} // namespace forma

#endif // FORMA_IMGUI_LAYER_HPP_