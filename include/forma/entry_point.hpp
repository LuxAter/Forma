#ifndef FORMA_ENTRY_POINT_HPP_
#define FORMA_ENTRY_POINT_HPP_

extern forma::Application* forma::create_application();
int main(int argc, char *argv[])
{
  forma::Log::init();
  LWARN("INITALIZED LOGGER");
  INFO(" VAL: {}", 4);

  auto app = forma::create_application();
  app->run();
  delete app;
  return 0;
}

#endif // FORMA_ENTRY_POINT_HPP_
