#ifndef ENTRY_POINT_HPP_
#define ENTRY_POINT_HPP_

extern forma::Application* forma::create_application();
int main(int argc, char *argv[])
{
  auto app = forma::create_application();
  app->run();
  delete app;
  return 0;
}

#endif // ENTRY_POINT_HPP_
