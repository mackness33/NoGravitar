#include "scene.hpp"

//---------------CONSTRUCTORS---------------
scene::scene(sf::RenderWindow* wnd) : Window(wnd), isActive(false), Viewer(nullptr){}

scene::~scene(){
  Viewer = nullptr;
  Window = nullptr;
}

//---------------METHODS---------------
void scene::eventHandler(const sf::Event &event){}

void scene::Draw (){ Viewer->Draw(); }

//It handle Event::Closed
//it close the window if pressed 'Q', 'ESC' or close button
void scene::windowClosedHandler (const sf::Event& e){
  // "close requested" event: we close the window
  if (e.type == sf::Event::Closed || (e.type == sf::Event::KeyPressed && (e.key.code == 16 || e.key.code == 36)))
    Window->close();
}

std::string scene::Class(){
  return "scene";
}
