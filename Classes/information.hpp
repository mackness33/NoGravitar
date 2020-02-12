#ifndef INFORMATION_H
#define INFORMATION_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <experimental/filesystem>
#include <iostream>
#include <string>
#include "utility.hpp"

template <typename T>
struct file {
  T *object;
  std::string name;
};


class information{
  protected:
    static sf::Vector2u WINDOW_SIZE;
    template <typename T> static const void loadFiles(std::string path, std::vector<file<T>*> &array);
    static std::string filenameFromPath(std::string path);

  public:
    //----------CONSTRUCTORS----------
    static sf::Vector2f MENU_DEFAULT_SIZE;
    static sf::Vector2f MENU_DEFAULT_POSITION;
    static sf::Vector2f FUEL_DEFAULT_SIZE;
    static sf::Vector2f HEADER_DEFAULT_SIZE;
    static sf::Vector2f HEADER_DEFAULT_POSITION;
    static sf::Vector2f PLAYGROUND_DEFAULT_SIZE;
    static sf::Vector2f PLAYGROUND_DEFAULT_POSITION;
    static sf::Vector2f PLAYER_DEFAULT_POSITION;
    static sf::Vector2f PLAYER_DEFAULT_SIZE;
    static sf::Vector2f TRACTORBEAM_DEFAULT_SIZE;
    static float SPACESHIP_DEFAULT_SPEED;
    static float SPACESHIP_DEFAULT_ANGULAR_SPEED;
    static float PLANET_DEFAULT_RADIUS;
    static float BULLET_DEFAULT_SPEED;
    static float BULLET_DEFAULT_RADIUS;
    static float BULLET_DEFAULT_DIRECTION;
    static float DELTA_TIME; // You MUST declare it in a CPP
    static float SWITCH_TIME; // You MUST declare it in a CPP
    static float SHOOTER_SWITCH_TIME; // You MUST declare it in a CPP
    static std::vector<file<sf::Texture>*> images;
    static std::vector<file<sf::Font>*> fonts;

    static const float MAX_GROUND_HEIGHT;             //30%
    static const float MIN_GROUND_HEIGHT;             //30%

    static const void inizialize(sf::Vector2u windowSize);
    static sf::Texture* getImage(std::string name);
    static sf::Font* getFont(std::string name);

    virtual std::string Class();
};

#include "information.tpp"

#endif // ENTITY_H
