#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "../Handlers/eventHandler.hpp"
#include "viewer.hpp"

class scene {
  protected:
    sf::RenderWindow *Window;
    viewer *Viewer;
    bool isActive;

  protected:

  public:
    //----------CONSTRUCTORS----------
    scene(sf::RenderWindow* window);
    ~scene();
    virtual void eventHandler(const sf::Event &event);

    //----------GETS----------
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //----------SETS----------
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //----------METHODS----------
    virtual void Draw ();
    void swap (scene* scene);

    //friend void eventHandler::changePlaygroundHandler(); // Friend function
    virtual std::string Class();

};

#endif
