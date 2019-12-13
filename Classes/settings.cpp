#include "settings.hpp"

float settings::deltaTime; // You MUST declare it in a CPP
float settings::switchTime; // You MUST declare it in a CPP

//----------CONSTRUCTORS----------
settings::settings(sf::RenderWindow* win){
  window = win;

  // Setting bounding box
  size = new sf::Vector2f(win->getSize().x, win->getSize().y * 9/10);
  position = new sf::Vector2f(0, win->getSize().y/10);
  boundingBox = new sf::FloatRect(*position, *size);
  bound.setPosition(*position);
  bound.setSize(*size);
  bound.setFillColor(sf::Color(0, 0, 0));
}

//----------GETS----------
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//----------SETS----------
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}

//---------------METHODS---------------
void settings::default_settings(){
  switchTime = 60;
}
