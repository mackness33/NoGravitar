#ifndef BULLET_H
#define BULLET_H

#include "essence.hpp"
#include "entity.hpp"
#include "drawable.hpp"
#include "information.hpp"
#include "movable.hpp"
#include "shooter.hpp"

class shooter;

class bullet : public drawable{
  protected:
    movable<sf::CircleShape>* body;
    shooter *parent;
    float speed;
    float direction;
    float totalTime;

  public:
    //---------------CONSTRUCTORS---------------
    bullet(shooter *parent, float speed = information::BULLET_DEFAULT_SPEED, float direction = 0, sf::Vector2f position = sf::Vector2f(0, 0), sf::Color color = sf::Color::White);

    //---------------DESTRUCTORS---------------
    ~bullet();

    //---------------GETS---------------
    movable<sf::CircleShape>* getMovable();
    entity<sf::CircleShape>* getEntity();
    sf::CircleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();
    shooter* getShooter();

    //---------------METHODS---------------
    //draws the object's body
    void Draw (sf::RenderWindow* window);

    //update of the object's data for each time that it is draw
    void Update();

    //return the class of the object
    virtual std::string Class();
};

#endif
