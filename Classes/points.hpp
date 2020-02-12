#ifndef POINTS_H
#define POINTS_H

#include <iostream>
#include "label.hpp"

class points : public label{
  protected:
    unsigned int totalPoint;

  public:
    //---------------CONSTRUCTORS---------------
    points(std::string font = "CafeBrewery", unsigned int inizialPoints = 0, sf::Vector2f position = sf::Vector2f(0, 0));

    //---------------DESTRUCTORS---------------
    ~points();

    //---------------GETS---------------
    unsigned int getPoints();
    //---------------SETS---------------

    //---------------METHODS---------------
    virtual void deathBunker();
    virtual void deathPlanet();
    void reset();

    //return the class of the object
    virtual std::string Class();
};

#endif
