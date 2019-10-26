//SPACESHIP
//Class that handle everything that concerne a spaceship
#ifndef MOVABLE_H
#define MOVABLE_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <list>
#include "entity.hpp"

/*
  BUG: change body into sprites
*/
#define PI 3.14159265

template <class T> class movable : public entity<T>{

  public:
    //----------CONSTRUCTORS----------
    //TODO: add all the constructors of sf::Shape sf::Sprite .. etc
    movable(T* b);

    movable();

    //CircleShape
    movable(float radius, std::size_t pointCount = 30);

    void 	Move (float offsetX, float offsetY);
    void 	Move (const sf::Vector2f &offset);

    void 	Rotate (float angle);

    void 	Scale (float factorX, float factorY);
    void 	Scale (const sf::Vector2f &factor);

};

#include "movable.tpp"
#endif // MOVABLE_H
