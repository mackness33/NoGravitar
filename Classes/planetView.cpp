#include "planetView.hpp"

//----------CONSTRUCTORS----------
planetView::planetView(sf::RenderWindow* win, spaceship* spc) : viewer(win){
  Player = spc;
}

//----------GETS----------
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//----------SETS----------
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}

//----------METHODS---------------
void planetView::Draw (/*sf::RenderWindow* window*/){
  viewer::Draw();
  Player->Draw(window);
}
