#ifndef FORMA_MOUSE_EVENT_HPP_
#define FORMA_MOUSE_EVENT_HPP_

#include <fmt/format.h>

#include "forma/core.hpp"
#include "event.hpp"

namespace forma {
class FORMA_API MouseMovedEvent : public Event {
public:
  MouseMovedEvent(const float &x, const float &y) : xpos(x), ypos(y) {}
  inline float get_x() const { return xpos; }
  inline float get_y() const { return ypos; }
  std::string to_string() const override {
    return fmt::format("MouseMovedEvent: {}, {}", xpos, ypos);
  }
  EVENT_CLASS_TYPE(MOUSE_MOVED);
  EVENT_CLASS_CATEGORY(MOUSE_EVENT | INPUT_EVENT);

private:
  float xpos, ypos;
};
class FORMA_API MouseScrolledEvent : public Event {
public:
  MouseScrolledEvent(const float &x, const float &y) : xoffset(x), yoffset(y) {}
  inline float get_x() const { return xoffset; }
  inline float get_y() const { return yoffset; }
  std::string to_string() const override {
    return fmt::format("MouseScrolledEvent: {}, {}", xoffset, yoffset);
  }
  EVENT_CLASS_TYPE(MOUSE_SCROLLED);
  EVENT_CLASS_CATEGORY(MOUSE_EVENT | INPUT_EVENT);

private:
  float xoffset, yoffset;
};
class FORMA_API MouseButtonEvent : public Event {
public:
  inline float get_x() const { return xpos; }
  inline float get_y() const { return ypos; }
  inline int get_mouse_button() const { return button; }

  EVENT_CLASS_CATEGORY(MOUSE_EVENT | INPUT_EVENT);

protected:
  MouseButtonEvent(const int &button, const float &x, const float &y)
      : button(button), xpos(x), ypos(y) {}
  MouseButtonEvent(const int &button) : button(button), xpos(), ypos() {}
  int button;
  float xpos, ypos;
};
class FORMA_API MouseButtonPressedEvent : public MouseButtonEvent {
  MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}
  std::string to_string() const override {
    return fmt::format("MouseButtonPressedEvent: {} ({}, {})", button, xpos,
                       ypos);
  }
  EVENT_CLASS_TYPE(MOUSE_BUTTON_PRESSED);
};
class FORMA_API MouseButtonReleasedEvent : public MouseButtonEvent {
  MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}
  std::string to_string() const override {
    return fmt::format("MouseButtonReleasedEvent: {} ({}, {})", button, xpos,
                       ypos);
  }
  EVENT_CLASS_TYPE(MOUSE_BUTTON_RELEASED);
};
} // namespace forma

#endif // FORMA_MOUSE_EVENT_HPP_
