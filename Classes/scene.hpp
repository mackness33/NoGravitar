#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "../Handlers/eventHandler.hpp"
#include "viewer.hpp"
#include "game.hpp"

class game;

class scene {
  protected:
    sf::RenderWindow *Window;
    game *Game;
    viewer *Viewer;
    bool isActive;

  protected:
    virtual void eventHandler(const sf::Event &event) = 0;

  public:
    //----------CONSTRUCTORS----------
    scene(sf::RenderWindow* window, const game &Game);
    ~scene();

    //----------GETS----------
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //----------SETS----------
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //----------METHODS----------
    virtual void start () = 0;
    virtual void stop ();
    //void pause () = 0;
    void swap (scene* scene);

    //friend void eventHandler::changePlaygroundHandler(); // Friend function
    virtual std::string Class();

};

#endif
