#ifndef FORMA_PLATFORM_APPLE_WINDOW_HPP_
#define FORMA_PLATFORM_APPLE_WINDOW_HPP_

#include <string>

#include <GLFW/glfw3.h>

#include <forma/window.hpp>

namespace forma {
class AppleWindow : public Window {
public:
  AppleWindow(const WindowProps &props);
  virtual ~AppleWindow();
  void on_update() override;

  inline unsigned get_width() const override { return data.width; }
  inline unsigned get_height() const override { return data.height; }

  inline void set_event_event_callback(const EventCallback &event_callback) override {
    data.event_callback = event_callback;
  }
  void set_vsync(bool enabled) override;
  bool is_vsync() const override;

private:
  virtual void init(const WindowProps &props);
  virtual void term();

  GLFWwindow *window;
  struct WindowData {
    std::string title;
    unsigned int width, height;
    bool vsync;

    EventCallback event_callback;
  };
  WindowData data;
};
} // namespace forma

#endif // FORMA_PLATFORM_APPLE_WINDOW_HPP_
