#include "game.hpp"

//CONSTRUCTORS
game::game(sf::RenderWindow* wnd) : Window(wnd){
  this->inizialize();
}

game::~game(){
  std::cout << "DELETING GAME" << std::endl;
  
  if(!!Gameplay)
    delete Gameplay;

  if(!!Menu)
    delete Menu;

  //Window = nullptr;
  mainScene = nullptr;
  Menu = nullptr;
  Gameplay = nullptr;
}


//GETS
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//SETS
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}


//---------------METHODS---------------
void game::inizialize(){
  information::inizialize(Window->getSize());

  Menu = new menu(Window, this);
  Gameplay = new gameplay(Window, this);

  mainScene = Menu;
}

//DRAW
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

//TODO: std::string name for scene
void game::setMainScene(std::string name){
  switch(name[0]){
    case 'm': {
      mainScene = Menu;
      //this->start();
    }break;

    case 'g': {
      mainScene = Gameplay;
      std::cout << "name: " << name[0] << std::endl;
      // this->start();
    }break;

    default: {};
  }
}

void game::restart(){
  std::cout << "Imma trhink: " << std::endl;
  this->~game();
  std::cout << "Is here dawg: " << std::endl;
  inizialize();
  std::cout << "You ain't seeing it: " << std::endl;
}

std::string game::Class(){
  return "game";
}
