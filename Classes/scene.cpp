#include "scene.hpp"

//CONSTRUCTORS
scene::scene(sf::RenderWindow* wnd) : Window(wnd), isActive(false), Viewer(nullptr){}

scene::~scene(){
  std::cout << "DELETING SCENE" << std::endl;

  if(!!Viewer)
    delete Viewer;

  Viewer = nullptr;
  Window = nullptr;
}


//GETS
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//SETS
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}


//---------------METHODS---------------

void scene::stop (){ isActive = false; }

void scene::swap (scene* next){
  this->stop();
  next->start();
}

void scene::start (){
  this->isActive = true;
  // run the program as long as the window is open
  while (this->isActive){
    if(!isActive)
      break;
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;

    while (Window->waitEvent(event)){
      this->eventHandler(event);
    }

    Window->clear();
    Viewer->Draw();
    Window->display();

  }
}

std::string scene::Class(){
  return "scene";
}
