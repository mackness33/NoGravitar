#ifndef FUELLABEL_H
#define FUELLABEL_H

#include "entity.hpp"
#include "essence.hpp"
#include "label.hpp"

//A special label for this information since it has to constatly update its value
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

    //---------------METHODS---------------
    void addFuel(int fuels);        //it adds the input value to the current one
    void reset();                   //it resets the value to the initial val

    //draws the object's body
    void Draw(sf::RenderWindow *window);

    //update of the object's data for each time that it is draw
    void Update();

    //return the class of the object
    virtual std::string Class();
};

#endif
