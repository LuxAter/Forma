#ifndef FORMA_EVENT_HPP_
#define FORMA_EVENT_HPP_

#include <functional>
#include <string>

#include "../core.hpp"

#define EVENT_CLASS_TYPE(type)                                                 \
  static EventType get_static_type() { return EventType::type; }               \
  virtual EventType get_type() const override { return get_static_type(); }    \
  virtual const char *get_name() const override { return #type; }
#define EVENT_CLASS_CATEGORY(category)                                         \
  virtual int get_category() const override { return category; }

namespace forma {
enum class EventType {
  NONE,
  WINDOW_CLOSE,
  WINDOW_RESIZE,
  WINDOW_FOCUS,
  WINDOW_LOST_FOCUS,
  WINDOW_MOVED,
  APP_TICK,
  APP_UPDATE,
  APP_RENDER,
  KEY_PRESSED,
  KEY_RELEASED,
  KEY_TYPED,
  MOUSE_BUTTON_PRESSED,
  MOUSE_BUTTON_RELEASED,
  MOUSE_MOVED,
  MOUSE_SCROLLED
};
enum EventCategory {
  NONE = 0 << 0,
  APPLICATION_EVENT = 1 << 0,
  INPUT_EVENT = 1 << 1,
  KEYBOARD_EVENT = 1 << 2,
  MOUSE_EVENT = 1 << 3,
  MOUSE_BUTTON_EVENT = 1 << 4
};
class FORMA_API Event {
  friend class EventDispatcher;

public:
  virtual EventType get_type() const = 0;
  virtual const char *get_name() const = 0;
  virtual int get_category() const = 0;
  virtual std::string to_string() const { return get_name(); }

  inline bool is_in(const EventCategory &category) {
    return get_category() & category;
  }

  bool handled = false;
};

class EventDispatcher {
  template <typename T> using EventFn = std::function<bool(T &)>;

public:
  EventDispatcher(Event &event) : event(event) {}
  template <typename T>
  typename std::enable_if<std::is_base_of<Event, T>::value, bool>::type
  dispatch(EventFn<T> func) {
    if (event.get_type() == T::get_static_type()) {
      event.handled = func(*(T *)&event);
      return true;
    }
    return false;
  }

private:
  Event &event;
};
inline std::ostream &operator<<(std::ostream &out, const Event &e) {
  return out << e.to_string();
}
} // namespace forma

#endif // FORMA_EVENT_HPP_
