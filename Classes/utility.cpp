#include "utility.hpp"

float utility::deltaTime ; // You MUST declare it in a CPP
float utility::switchTime ; // You MUST declare it in a CPP

//----------CONSTRUCTORS----------
//probably I don't need it
utility::utility(){

}

//----------GETS----------
//sf::Sprite getBackground(){ return this->background;}

//----------SETS----------
//void setTexture(sf::Texture t){ this->background.setTexture(t);}

//----------METHODS----------
int utility::Proportion(int a, int b, int c){ return c * b / a; }
int utility::RandInt(int x, int y){ return rand() % x + y; }
float utility::RandFloat(int x, float y){ return rand() % x + y; }
sf::Vector2f utility::RandVector(int x, int y, int offsetX, int offsetY){ return sf::Vector2f(rand() % x + offsetX, rand() % y + offsetY); }
