#include "planetView.hpp"

//----------CONSTRUCTORS----------
planetView::planetView(sf::RenderWindow* win, spaceship* spc, game* actGame) : playground(win){
  currentGame = actGame;

  Player = spc;
  playground::addAlly(spc);
  Player->getEntity()->SetPosition(100, 200);
  bullets = Player->getBullets();

  sf::Vector2f plgBound = viewer::getDrawable()->getSize() - sf::Vector2f(100, 100);
  Ground = new ground(win->getSize().x, win->getSize().y);
  playground::addEnemy(Ground);
}

//----------GETS----------
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//----------SETS----------
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}

//----------METHODS---------------
std::string planetView::Class(){
  return "planetView";
}
