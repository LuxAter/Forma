#ifndef FORMA_WINDOW_HPP_
#define FORMA_WINDOW_HPP_

#include <string>

#include <forma/core.hpp>
#include <forma/events/event.hpp>

namespace forma {
struct FORMA_API WindowProps {
public:
  WindowProps() : title("Forma Engine"), width(1280), height(720) {}
  WindowProps &set_title(const std::string &p_title) {
    title = p_title;
    return *this;
  }
  WindowProps &set_width(const unsigned &p_width) {
    width = p_width;
    return *this;
  }
  WindowProps &set_height(const unsigned &p_height) {
    height = p_height;
    return *this;
  }
  std::string title;
  unsigned width, height;
};

class FORMA_API Window {
public:
  using EventCallback = std::function<void(const Event &)>;
  virtual ~Window() {}
  virtual void on_update() = 0;
  virtual unsigned int get_width() const = 0;
  virtual unsigned int get_height() const = 0;

  virtual void set_event_callback(const EventCallback &callback) = 0;
  virtual void set_vsync(bool enabled) = 0;
  virtual bool is_vsync() const = 0;

  static Window *create(const WindowProps &props = WindowProps());
};
} // namespace forma

#endif // FORMA_WINDOW_HPP_
