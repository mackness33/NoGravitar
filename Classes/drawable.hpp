//SPACESHIP
//Class that handle everything that concerne a spaceship
#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <list>
#include "movable.hpp"

/*
  BUG: change body into sprites
*/
#define PI 3.14159265

class drawable{
  public:
    //----------GETS----------
    //ugly solution, but it's the only thing that can be done
    //Templates can't also b e virtual!
    template <typename T> movable<T>* getMovable();
    template <typename T> entity<T>* getEntity();
    template <typename T> T* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();

    //----------METHODS------------
    virtual void Draw (sf::RenderWindow* window) = 0;
};

#include "drawable.tpp"
#endif // DRAWABLE_H
