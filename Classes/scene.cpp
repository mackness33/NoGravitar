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

std::string scene::Class(){
  return "scene";
}
