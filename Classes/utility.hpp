#ifndef UTILITY_H
#define UTILITY_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class utility{
  public:
    static float deltaTime;
    static float switchTime;

  public:
    //----------CONSTRUCTORS----------
    utility();

    //----------GETS----------
    //sf::Texture getTexture(){ return this->background.getTexture();}

    //----------SETS----------
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}

    //----------METHODS----------
    static sf::Vector2f RandVector(int x, int y, int offsetX = 0, int offsetY = 0);
    static int Rand(int x, int y = 0);
};

#endif
