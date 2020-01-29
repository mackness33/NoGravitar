#ifndef BULLET_H
#define BULLET_H

#include "entity.hpp"
#include "drawable.hpp"
#include "information.hpp"
#include "movable.hpp"
#include "shooter.hpp"
#include "utility.hpp"

class shooter;

class bullet : public drawable{
  protected:
    movable<sf::CircleShape>* body;
    shooter *parent;
    float speed;
    float direction;
    float totalTime;

  protected:
    virtual float GetRotation();

  public:
    //---------------CONSTRUCTORS---------------
    bullet(shooter *parent, float speed = information::BULLET_DEFAULT_SPEED, float direction = 0, sf::Vector2f position = sf::Vector2f(0, 0));

    //---------------DESTRUCTORS---------------
    ~bullet();

    //---------------GETS---------------
    movable<sf::CircleShape>* getMovable();
    entity<sf::CircleShape>* getEntity();
    sf::CircleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();
    shooter* getShooter();

    //---------------SETS---------------

    //---------------METHODS---------------
    void Draw (sf::RenderWindow* window);

    //update of the object's data for each time that it is draw
    void Update();

    //build all the information of object's body
    void build();

    //return the class of the object
    virtual std::string Class();
};

#endif
