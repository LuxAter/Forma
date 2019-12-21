#ifndef FORMA_LAYER_HPP_
#define FORMA_LAYER_HPP_

#include <forma/core.hpp>
#include <forma/events/event.hpp>

namespace forma {
class FORMA_API Layer {
public:
  Layer(const std::string &name = "Layer");
  virtual ~Layer();

  virtual void on_attach() {}
  virtual void on_detach() {}
  virtual void on_update() {}
  virtual void on_event(Event &) {}

  inline const std::string &get_name() const { return layer_name; }

protected:
  std::string layer_name;
};
} // namespace forma

#endif /* end of include guard: FORMA_LAYER_HPP_ */
