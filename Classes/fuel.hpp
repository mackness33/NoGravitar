#ifndef FUEL_H
#define FUEL_H

#include "drawable.hpp"
#include "entity.hpp"
#include "essence.hpp"
#include "line.hpp"

class fuel : public drawable{
  protected:
    entity<sf::RectangleShape>* body;
    sf::Texture *image;
    int value;

  public:
    //---------------CONSTRUCTORS---------------
    fuel(line l, bool special = false);

    //---------------DESTRUCTORS---------------
    ~fuel();

    //---------------GETS---------------
    entity<sf::RectangleShape>* getEntity();
    essence<sf::RectangleShape>* getEssence();
    sf::RectangleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();
    int getValue();

    //---------------METHODS---------------
    //draws the object's body
    void Draw (sf::RenderWindow* window);

    //return the class of the object
    virtual std::string Class();
};

#endif
