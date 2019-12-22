#ifndef FORMA_PLATFORM_LINUX_INPUT_HPP_

#include <utility>

#include "../../core.hpp"
#include "../../input.hpp"

namespace forma {
class LinuxInput : public Input {
protected:
  virtual bool is_key_pressed_impl(int keycode) override;
  virtual bool is_mouse_button_pressed_impl(int button) override;
  virtual float get_mouse_x_impl() override;
  virtual float get_mouse_y_impl() override;
  virtual std::pair<float, float> get_mouse_pos_impl() override;
};
} // namespace forma

#endif // FORMA_PLATFORM_LINUX_INPUT_HPP_
