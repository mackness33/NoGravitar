#ifndef FUELLABEL_H
#define FUELLABEL_H

#include <iostream>
#include "label.hpp"

class fuelLabel : public label{
  protected:
    unsigned int totalFuel;

  public:
    //---------------CONSTRUCTORS---------------
    fuelLabel(std::string font = "CafeBrewery", unsigned int inizialFuels = information::FUELS_DEFAULT_CAPACITY, sf::Vector2f position = sf::Vector2f(0, 0));

    //---------------DESTRUCTORS---------------
    ~fuelLabel();

    //---------------GETS---------------
    unsigned int getFuels();
    //---------------SETS---------------
    //---------------METHODS---------------
    void addFuel(int fuels);
    void reset();
    void Draw(sf::RenderWindow *window);
    void Update();

    //return the class of the object
    virtual std::string Class();
};

#endif
