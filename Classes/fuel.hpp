#ifndef FUEL_H
#define FUEL_H

#include "line.hpp"
#include "utility.hpp"
#include "drawable.hpp"
#include "information.hpp"

class fuel : public drawable{
  protected:
    entity<sf::RectangleShape>* body;
    sf::Texture *image;
    int value;

  protected:
  public:
    //---------------CONSTRUCTORS---------------
    fuel(line l, bool special);

    //---------------DESTRUCTORS---------------
    ~fuel();

    //---------------GETS---------------
    entity<sf::RectangleShape>* getEntity();
    essence<sf::RectangleShape>* getEssence();
    sf::RectangleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();
    int getValue();

    //---------------SETS---------------

    //---------------METHODS---------------
    void Draw (sf::RenderWindow* window);

    //return the class of the object
    virtual std::string Class();
};

#endif
