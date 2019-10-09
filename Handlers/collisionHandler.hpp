//COLLISIONHANDLER
//Class that handle collision

/*

*/
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Classes/spaceship.hpp"

class collisionHandler{
  public:
    //------------METHODS-----------
    //It let the spaceship move or rotate based on the key pressed
    void checkOutOfBounds(spaceship *S, sf::VideoMode *desktop);

    bool checkSide(float side1, float side2);
};
