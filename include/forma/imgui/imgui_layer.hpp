#ifndef FORMA_IMGUI_LAYER_HPP_
#define FORMA_IMGUI_LAYER_HPP_

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
  float time = 0.0f;
};
} // namespace forma

#endif // FORMA_IMGUI_LAYER_HPP_