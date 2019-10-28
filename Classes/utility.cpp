//UNIVERSE
//Class that handle everything that concerne the top of the window

/*

*/
#include "utility.hpp"
#define PI 3.14159265

float utility::deltaTime ; // You MUST declare it in a CPP
float utility::switchTime ; // You MUST declare it in a CPP

//CONSTRUCTORS
//probably I don't need it
utility::utility(){

}

//GETS
//sf::Sprite getBackground(){ return this->background;}

//SETS
//void setTexture(sf::Texture t){ this->background.setTexture(t);}

//---------------METHODS---------------
sf::Vector2f utility::RandVector(int x, int y, int offsetX, int offsetY){ return sf::Vector2f(rand() % x + offsetX, rand() % y + offsetY); }

int utility::Rand(int x, int y){ return rand() % x + y; }
