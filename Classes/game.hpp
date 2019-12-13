#ifndef GAME_H
#define GAME_H

#include <vector>
#include "galaxy.hpp"
#include "keyVector.hpp"
#include "header.hpp"
#include "../Handlers/eventHandler.hpp"

class galaxy;
class game{
  protected:
    /*std::vector<*/sf::Texture spaceshipImage;

    sf::RenderWindow *Window;
    spaceship *Player;
    header *Header;
    settings *Settings;
    galaxy *Galaxy;

    viewer *Playground;

    //classes to handle input commands in smooth trasformations of object
    keyVector rotation;
    keyVector translation;

  protected:
    void draw ();

  public:
    //----------CONSTRUCTORS----------
    game(sf::RenderWindow* window);

    //----------GETS----------
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //----------SETS----------
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}
    void setMainViewer(viewer* newViewer);

    //----------METHODS----------
    void start ();

    //friend void eventHandler::changePlaygroundHandler(); // Friend function

};

#endif
