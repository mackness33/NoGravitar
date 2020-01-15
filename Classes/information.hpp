#ifndef INFORMATION_H
#define INFORMATION_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class information{
  protected:
    static sf::Vector2u WINDOW_SIZE;

  public:
    //----------CONSTRUCTORS----------
    static sf::Vector2f MENU_DEFAULT_SIZE;
    static sf::Vector2f MENU_DEFAULT_POSITION;
    static sf::Vector2f HEADER_DEFAULT_SIZE;
    static sf::Vector2f HEADER_DEFAULT_POSITION;
    static sf::Vector2f PLAYGROUND_DEFAULT_SIZE;
    static sf::Vector2f PLAYGROUND_DEFAULT_POSITION;
    static float SPACESHIP_DEFAULT_SPEED;
    static float SPACESHIP_DEFAULT_ANGULAR_SPEED;
    static float PLANET_DEFAULT_RADIUS;
    static float BULLET_DEFAULT_SPEED;
    static float BULLET_DEFAULT_RADIUS;
    static float BULLET_DEFAULT_DIRECTION;
    static sf::Vector2f PLAYER_DEFAULT_POSITION;

    static const float MAX_GROUND_HEIGHT;             //30%
    static const float MIN_GROUND_HEIGHT;             //30%

    static const void inizialize(sf::Vector2u windowSize);

    virtual std::string Class();
};

#endif // ENTITY_H