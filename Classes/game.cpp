#include "game.hpp"

unsigned int game::bestScore = 0;

//----------CONSTRUCTORS----------
game::game(sf::RenderWindow* wnd) : Window(wnd){ this->inizialize(); }

game::~game(){
  if(!!Gameplay)
    delete Gameplay;

  if(!!Menu)
    delete Menu;

  mainScene = nullptr;
  Menu = nullptr;
  Gameplay = nullptr;
}

//----------SETS----------
void game::setMainScene(std::string name){
  switch(name[0]){
    case 'm': { mainScene = Menu; }break;

    case 'g': { mainScene = Gameplay; }break;

    default: ;
  }
}

//---------------METHODS---------------
void game::inizialize(){
  Menu = new menu(Window, this);
  Gameplay = new gameplay(Window, this);

  mainScene = Menu;
}

void game::start (){
  // run the program as long as the window is open
  while (Window->isOpen()){
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;

    while (Window->pollEvent(event))
      mainScene->eventHandler(event);

    Window->clear();

    mainScene->Draw();

    // end the current frame
    Window->display();

  }
}


void game::restart(){
  this->~game();
  inizialize();
  mainScene = Gameplay;
}

std::string game::Class(){
  return "game";
}
