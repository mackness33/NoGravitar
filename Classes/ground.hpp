#ifndef GROUND_H
#define GROUND_H

#include "line.hpp"
#include "drawable.hpp"
#include "settings.hpp"
#include "utility.hpp"

class ground : public drawable{
  protected:
    line<sf::VertexArray>* body;


  public:
    //---------------CONSTRUCTORS---------------
    ground(float width, float height, sf::Color color = sf::Color::Green);

    //---------------DESTRUCTORS---------------
    ~ground();

    //---------------GETS---------------
    line<sf::VertexArray>* getLine();
    sf::VertexArray* getDrawable();
    sf::FloatRect GetGlobalBounds();

    //---------------SETS---------------

    //---------------METHODS---------------
    void Draw (sf::RenderWindow* window);

    //return the class of the object
    virtual std::string Class();
};

#endif
