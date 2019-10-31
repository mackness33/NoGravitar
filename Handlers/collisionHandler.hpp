//COLLISIONHANDLER
//Class that handle collision

/*

*/


#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Classes/keyVector.hpp"
#include "../Classes/galaxy.hpp"

class collisionHandler{
  private:
    //static
  private:
    static bool checkSide(float side1, float side2);

  public:
    //------------METHODS-----------
    //It let the spaceship move or rotate based on the key pressed
    static void checkOutOfBounds(spaceship* Spaceship, viewer* Playground);

    static bool checkCollision(drawable* first_object, drawable* second_object);
};

#include "collisionHandler.tpp"

#endif
