#ifndef FORMA_PLATFORM_WINDOWS_WINDOW_HPP_
#define FORMA_PLATFORM_WINDOWS_WINDOW_HPP_

#include <string>

#include <GLFW/glfw3.h>

#include <forma/window.hpp>

namespace forma {
class WindowsWindow : public Window {
public:
  WindowsWindow(const WindowProps &props);
  virtual ~WindowsWindow();
  void on_update() override;

  inline unsigned get_width() const override { return data.width; }
  inline unsigned get_height() const override { return data.height; }

  inline void set_event_callback(const EventCallback &callback) override {
    data.callback = callback;
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

    EventCallback callback;
  };
  WindowData data;
};
} // namespace forma

#endif // FORMA_PLATFORM_WINDOWS_WINDOW_HPP_
