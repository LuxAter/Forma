#include <forma/forma.hpp>

class Sandbox : public forma::Application {
public:
  Sandbox() {}
  ~Sandbox() {}
};

forma::Application* forma::create_application(){
  return new Sandbox();
}
