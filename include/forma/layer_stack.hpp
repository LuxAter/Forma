#ifndef FORMA_LAYER_STACK_HPP_
#define FORMA_LAYER_STACK_HPP_

#include <vector>

#include "core.hpp"
#include "layer.hpp"

namespace forma {
class FORMA_API LayerStack {
public:
  LayerStack();
  ~LayerStack();

  void push_layer(Layer *layer);
  void push_overlay(Layer *overlay);
  void pop_layer(Layer *layer);
  void pop_overlay(Layer *overlay);

  inline std::vector<Layer *>::iterator begin() { return layers.begin(); }
  inline std::vector<Layer *>::iterator end() { return layers.end(); }

private:
  std::vector<Layer *> layers;
  std::vector<Layer *>::iterator layer_insert;
};
} // namespace forma

#endif /* end of include guard: FORMA_LAYER_STACK_HPP_ */
