#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "../Classes/keyVector.hpp"
#include "../Classes/galaxy.hpp"

class collisionHandler{
  private:
    static bool checkSide(float side1, float side2);

  public:
    //------------METHODS-----------
    //It let the spaceship move or rotate based on the key pressed
    static void checkOutOfBounds(spaceship* Spaceship, viewer* Playground);

    static bool checkCollision(drawable* first_object, drawable* second_object);
};

#endif
