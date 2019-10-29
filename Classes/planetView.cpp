//UNIVERSE
//Class that handle everything that concerne the top of the window

/*

*/
#include "planetView.hpp"
#define PI 3.14159265

//CONSTRUCTORS
planetView::planetView(sf::RenderWindow* win, spaceship* spc) : viewer(win){
  S = spc;
}

//GETS
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//SETS
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}


//---------------METHODS---------------


//DRAW
void planetView::Draw (/*sf::RenderWindow* window*/){
  viewer::Draw();
  S->Draw(window);
}
