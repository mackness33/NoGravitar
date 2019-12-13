#ifndef ground_H
#define ground_H

#include "movable.hpp"
#include "entity.hpp"
#include "drawable.hpp"
#include "viewer.hpp"

class ground : public drawable{
  protected:
    movable<sf::CircleShape>* body;
    float speed;
    float direction;
    float totalTime;

  public:
    //---------------CONSTRUCTORS---------------
    ground(float s = 12, float d = 0, sf::Vector2f p = sf::Vector2f(0, 0));

    //---------------DESTRUCTORS---------------
    ~ground();

    //---------------GETS---------------
    movable<sf::CircleShape>* getMovable();
    entity<sf::CircleShape>* getEntity();
    sf::CircleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();

    //---------------SETS---------------

    //---------------METHODS---------------
    void Draw (sf::RenderWindow* window);

    //return the class of the object
    std::string Class();
};

#endif
