#include "settings.hpp"

float settings::deltaTime; // You MUST declare it in a CPP
float settings::switchTime; // You MUST declare it in a CPP
const float settings::MAX_GROUND_HEIGHT = 0.4;             //30%
const float settings::MIN_GROUND_HEIGHT = 0.1;             //30%

//----------CONSTRUCTORS----------

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
