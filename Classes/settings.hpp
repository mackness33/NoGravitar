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
    static float deltaTime;
    static float switchTime;
    static std::vector<sf::Texture*> images;
    

  public:
    //----------CONSTRUCTORS----------

    //----------GETS----------
    //sf::Clock getClock(){ return this->clock;}

    //----------SETS----------
    //void setClock(sf::Clock c){ this->clock = c;}

    static void loadImages(){
      std::string path = std::experimental::filesystem::current_path();
      for (const auto & entry : std::experimental::filesystem::directory_iterator(path + "/img")){
        sf::Texture *image = new sf::Texture();
        if (image->loadFromFile(entry.path()))
          settings::images.push_back(image);
      }
    }

    //----------METHODS----------
    static void default_settings();
};

#endif
