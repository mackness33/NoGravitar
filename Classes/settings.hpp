#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <experimental/filesystem>
#include <cmath>
#include <vector>

class settings{
  public:
    //----------CONSTRUCTORS----------

    //----------GETS----------
    //sf::Clock getClock(){ return this->clock;}

    //----------SETS----------
    //void setClock(sf::Clock c){ this->clock = c;}



    //----------METHODS----------
    static void default_settings();
};

#endif
