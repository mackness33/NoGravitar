//SPACESHIP
//Class that handle everything that concerne a spaceship

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <list>
#include "bullet.hpp"

/*
  BUG: change body into sprites
*/
#define PI 3.14159265

class ientity{
  protected:
    sf::Drawable *bodyDraw;

  public:
    //----------METHODS------------
    void Draw (sf::RenderWindow* window);
};
