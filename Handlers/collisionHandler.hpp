//COLLISIONHANDLER
//Class that handle collision

/*

*/
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Classes/universe.hpp"

class collisionHandler{
  private:
    static bool checkSide(float side1, float side2);

  public:
    //------------METHODS-----------
    //It let the spaceship move or rotate based on the key pressed
    static void checkOutOfBounds(spaceship* Spaceship, viewer* Playground);

};
