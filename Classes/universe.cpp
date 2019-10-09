//UNIVERSE
//Class that handle everything that concerne the top of the window

/*

*/
#include "universe.hpp"
#define PI 3.14159265

//CONSTRUCTORS
universe::universe(sf::RenderWindow* win, spaceship* spc){
  window = win;
  S = spc;

  // Setting bounding box
  size = new sf::Vector2f(win->getSize().x, win->getSize().y * 9/10);
  position = new sf::Vector2f(0, win->getSize().y/10);
  boundingBox = new sf::FloatRect(*position, *size);
  bound.setPosition(*position);
  bound.setSize(*size);
  bound.setFillColor(sf::Color(0, 0, 255));

  /*
  //texture.create((unsigned int)size->x, (unsigned int)size->y);
  if(!texture.loadFromFile("img/universe.png"))
    std::cout << "Error in load images" << std::endl;
  else
    std::cout << "PERFECT!" << std::endl;

  background.setTexture(texture);
  //background.setTextureRect(sf::IntRect(300, 300, 500, 300));
  background.setColor(sf::Color::Blue);
  background.setPosition(*position);
  //background.scale(200, 200);
  //sprite.setSize(0, 0);
  */
}

//GETS
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//SETS
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}

//---------------METHODS---------------

//DRAW
void universe::Draw (/*sf::RenderWindow* window*/){
  window->draw(bound);
  S->Draw(window);
  //window->draw(background);
}
