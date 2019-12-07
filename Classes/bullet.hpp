#ifndef BULLET_H
#define BULLET_H

#include "movable.hpp"
#include "entity.hpp"
#include "settings.hpp"
#include "drawable.hpp"

class bullet : public drawable{
  protected:
    movable<sf::CircleShape>* body;
    float speed;
    float direction;
    float totalTime;

  public:
    //---------------CONSTRUCTORS---------------
    bullet(float s = 12, float d = 0, sf::Vector2f p = sf::Vector2f(0, 0));

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

    void Update();

    void build();

    std::string Class();
};

#endif
