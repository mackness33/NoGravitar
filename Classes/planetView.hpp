//UNIVERSE
//Class that handle everything that concerne the top of the window


#ifndef PLANETVIEW_H
#define PLANETVIEW_H

/*

*/
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "spaceship.hpp"
#include "viewer.hpp"

class planetView : public viewer{
  private:
    spaceship *S;
    //TODO: add Ground class

  private:

  public:
    //CONSTRUCTORS
    planetView(sf::RenderWindow* win, spaceship* spc);

    //GETS
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //SETS
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //---------------METHODS---------------

    //DRAW
    void Draw (/*sf::RenderWindow* window*/);
};

#endif
