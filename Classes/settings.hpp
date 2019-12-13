#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class settings{
  private:
    //sf::RenderWindow *window;
    //sf::FloatRect *boundingBox;
    //sf::RectangleShape bound;       //FOR TESTING ONLY
    //sf::Vector2f *position;
    //sf::Vector2f *size;
    //sf::Clock clock;

  public:
    static float deltaTime;
    static float switchTime;

  public:
    //----------CONSTRUCTORS----------
    settings(sf::RenderWindow* win);

    //----------GETS----------
    //sf::Clock getClock(){ return this->clock;}

    //----------SETS----------
    //void setClock(sf::Clock c){ this->clock = c;}


    //----------METHODS----------
    static void default_settings(){
      switchTime = 60;
    }
};

#endif
