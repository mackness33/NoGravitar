#ifndef BULLET_H
#define BULLET_H

#include "movable.hpp"
#include "entity.hpp"
#include "settings.hpp"
#include "drawable.hpp"
#include "information.hpp"
#include "utility.hpp"

class bullet : public drawable{
  protected:
    movable<sf::CircleShape>* body;
    float speed;
    float direction;
    float totalTime;

  protected:
    virtual float GetRotation();

  public:
    //---------------CONSTRUCTORS---------------
    bullet(float speed = information::BULLET_DEFAULT_SPEED, float direction = 0, sf::Vector2f position = sf::Vector2f(0, 0));

    //---------------DESTRUCTORS---------------
    ~bullet();

    //---------------GETS---------------
    movable<sf::CircleShape>* getMovable();
    entity<sf::CircleShape>* getEntity();
    sf::CircleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();

    //---------------SETS---------------

    //---------------METHODS---------------
    void Draw (sf::RenderWindow* window);

    //update of the object's data for each time that it is draw
    void Update();

    //build all the settings of object's body
    void build();

    //return the class of the object
    virtual std::string Class();
};

#endif
