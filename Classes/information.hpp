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
    // You MUST declare it in a CPP
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
    static sf::Vector2f BUNKER_DEFAULT_SIZE;
    static bool TRACTORBEAM_IS_ACTIVE;
    static float SPACESHIP_DEFAULT_SPEED;
    static float SPACESHIP_DEFAULT_ANGULAR_SPEED;
    static float PLANET_DEFAULT_RADIUS;
    static float BULLET_DEFAULT_SPEED;
    static float BULLET_DEFAULT_RADIUS;
    static float BULLET_DEFAULT_DIRECTION;
    static float SHOOTER_SWITCH_TIME;
    static float DELTA_TIME;
    static float SWITCH_TIME;
    static int GROUND_RAND_VERTEX;
    static int GROUND_MIN_NUM_VERTEX;
    static int FUELS_DEFAULT_CAPACITY;
    static int FUELS_DEFAULT_VALUE;
    static int GALAXY_DEFAULT_QUANTITY;
    static int GALAXY_DEFAULT_PLANETS;
    static int BUNKER_DEFAULT_LIFES;
    static int BUNKER_DEFAULT_BULLETSXSHOOTING;
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
