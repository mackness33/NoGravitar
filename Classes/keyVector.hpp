#ifndef KEYVECTOR_H
#define KEYVECTOR_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class keyVector{
  private:
    sf::Keyboard::Key key;
    bool transformation;

  public:
    //----------CONSTRUCTORS----------
    keyVector(sf::Keyboard::Key k/*ey*/, bool t/*ransfomation*/);

    keyVector();

    //copy constructor
    keyVector(const keyVector& V);

    //----------OPERATORS----------
    keyVector& operator=(const keyVector& V);

    //----------GETS----------
    sf::Keyboard::Key getKey();
    bool getTransformation();

    //----------SETS----------
    void setKey(sf::Keyboard::Key k);
    void setTransformation(bool t);

    //----------METHODS----------
    //the method understand which key has been pressed and sets the boolean for the smoothness of the trasformation
    void isUsed(sf::Keyboard::Key key1, sf::Keyboard::Key key2);

};

#endif
