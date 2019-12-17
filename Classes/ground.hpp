#ifndef GROUND_H
#define GROUND_H

#include "movable.hpp"
#include "entity.hpp"
#include "drawable.hpp"
#include "viewer.hpp"

class ground : public drawable{
  protected:
    entity<sf::VertexArray>* body;


  public:
    //---------------CONSTRUCTORS---------------
    ground(float w, float h);

    //---------------DESTRUCTORS---------------
    ~ground();

    //---------------GETS---------------
    entity<sf::VertexArray>* getEntity();
    sf::VertexArray* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();

    //---------------SETS---------------

    //---------------METHODS---------------
    void Draw (sf::RenderWindow* window);

    //return the class of the object
    std::string Class();
};

#endif
