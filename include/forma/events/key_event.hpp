#ifndef FORM_KEY_EVENT_HPP_
#define FORM_KEY_EVENT_HPP_

#include <fmt/format.h>

#include "../core.hpp"
#include "event.hpp"

namespace forma {
class FORMA_API KeyEvent : public Event {
public:
  inline int get_keycode() const { return key_code; }
  EVENT_CLASS_CATEGORY(KEYBOARD_EVENT | INPUT_EVENT);

protected:
  KeyEvent(int keycode) : key_code(keycode) {}
  int key_code;
};
class FORMA_API KeyPressedEvent : public KeyEvent {
public:
  KeyPressedEvent(int keycode, int repeat_count)
      : KeyEvent(keycode), repeat_count(repeat_count) {}
  inline int get_repeat_count() const { return repeat_count; }
  std::string to_string() const override {
    return fmt::format("KeyPressedEvent: {} ({} repeats)", key_code,
                       repeat_count);
  }
  EVENT_CLASS_TYPE(KEY_PRESSED);

private:
  int repeat_count;
};
class FORMA_API KeyReleasedEvent : public KeyEvent {
public:
  KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}
  std::string to_string() const override {
    return fmt::format("KeyReleasedEvent: {}", key_code);
  }
  EVENT_CLASS_TYPE(KEY_RELEASED);
};
class FORMA_API KeyTypedEvent : public KeyEvent {
public:
  KeyTypedEvent(int keycode) : KeyEvent(keycode) {}
  std::string to_string() const override {
    return fmt::format("KeyTypeEvent: {}", key_code);
  }
  EVENT_CLASS_TYPE(KEY_TYPED);
};
} // namespace forma

#endif // FORM_KEY_EVENT_HPP_
