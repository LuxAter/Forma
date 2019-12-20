#include "forma/layer_stack.hpp"

#include <vector>
#include <algorithm>

forma::LayerStack::LayerStack() : layers(), layer_insert(layers.begin()) {}
forma::LayerStack::~LayerStack() {
  for (Layer *layer : layers) {
    delete layer;
  }
}

void forma::LayerStack::push_layer(Layer *layer) {
  layer_insert = layers.emplace(layer_insert, layer);
}
void forma::LayerStack::push_overlay(Layer *overlay) {
  layers.emplace_back(overlay);
}

void forma::LayerStack::pop_layer(Layer *layer) {
  auto it = std::find(layers.begin(), layers.end(), layer);
  if (it != layers.end()) {
    layers.erase(it);
    layer_insert--;
  }
}
void forma::LayerStack::pop_overlay(Layer *overlay) {
  auto it = std::find(layers.begin(), layers.end(), overlay);
  if (it != layers.end()) {
    layers.erase(it);
  }
}
