#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <experimental/filesystem>
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
    static std::vector<sf::Texture*> images;

  private:
    /*static std::string getCurrentDirectory() {
      char path[PATH_MAX];
      if (getcwd(path, sizeof(path)) != NULL)
        printf("Current working dir: %s\n", path);
      else
        strcpy(path, "\0");

       return path;
    }*/

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
