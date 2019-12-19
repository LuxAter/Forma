#ifndef FORMA_APPLICATION_EVENT_HPP_
#define FORMA_APPLICATION_EVENT_HPP_

#include <fmt/format.h>

#include "forma/core.hpp"
#include "event.hpp"

namespace forma {
class FORMA_API WindowResizeEvent : public Event {
public:
  WindowResizeEvent(const unsigned &width, const unsigned &height)
      : width(width), height(height) {}
  inline unsigned get_width() const { return width; }
  inline unsigned get_height() const { return height; }

  std::string to_string() const override {
    return fmt::format("WindowResizeEvent: {}, {}", width, height);
  }

  EVENT_CLASS_TYPE(WINDOW_RESIZE);
  EVENT_CLASS_CATEGORY(APPLICATION_EVENT);

private:
  unsigned width, height;
};

class FORMA_API WindowCloseEvent : public Event {
public:
  WindowCloseEvent() {}
  EVENT_CLASS_TYPE(WINDOW_CLOSE);
  EVENT_CLASS_CATEGORY(APPLICATION_EVENT);
};
class FORMA_API AppTickEvent : public Event {
public:
  AppTickEvent() {}
  EVENT_CLASS_TYPE(APP_TICK);
  EVENT_CLASS_CATEGORY(APPLICATION_EVENT);
};
class FORMA_API AppUpdateEvent : public Event {
public:
  AppUpdateEvent() {}
  EVENT_CLASS_TYPE(APP_UPDATE);
  EVENT_CLASS_CATEGORY(APPLICATION_EVENT);
};
class FORMA_API AppRenderEvent : public Event {
public:
  AppRenderEvent() {}
  EVENT_CLASS_TYPE(APP_RENDER);
  EVENT_CLASS_CATEGORY(APPLICATION_EVENT);
};
} // namespace forma

#endif // FORMA_APPLICATION_EVENT_HPP_
