#include <forma/forma.hpp>

class ExampleLayer : public forma::Layer {
public:
  ExampleLayer() : Layer("Example") {}
  void on_update() override {}
  void on_event(forma::Event &event) override { TRACE("Layer: {}", event); }
};

class Sandbox : public forma::Application {
public:
  Sandbox() {
    push_layer(new ExampleLayer());
    push_overlay(new forma::ImGuiLayer());
  }
  ~Sandbox() {}
};

forma::Application *forma::create_application() { return new Sandbox(); }
