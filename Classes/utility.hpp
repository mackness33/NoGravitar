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
    //static sf::Vector2f MaxVector(sf::Vector2f* p1, sf::Vector2f* p2);
    //static sf::Vector2f MaxVector(sf::Vector2f* p1, sf::Vector2f* p2);
    static int Proportion(int a, int b, int c = 100);
    static int RandInt(int x, int y = 0);
    static float RandFloat(int x, float y = 0);
    static sf::Vector2f RandVector(int x, int y, int offsetX = 0, int offsetY = 0);
};

#endif
