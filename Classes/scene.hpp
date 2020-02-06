#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "galaxy.hpp"
#include "keyVector.hpp"
#include "header.hpp"
#include "settings.hpp"
#include "../Handlers/eventHandler.hpp"

class scene {
  protected:
    sf::RenderWindow *Window;
    viewer *Viewer;
    bool isActive;

  protected:
    void eventHandler(const sf::Event &event);

  public:
    //----------CONSTRUCTORS----------
    scene(sf::RenderWindow* window);
    ~scene();

    //----------GETS----------
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //----------SETS----------
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //----------METHODS----------
    void start ();
    void stop ();
    void swap (scene* scene);

    //friend void eventHandler::changePlaygroundHandler(); // Friend function
    virtual std::string Class();

};

#endif
