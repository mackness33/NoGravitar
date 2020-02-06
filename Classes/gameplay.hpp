#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <vector>
#include "scene.hpp"
#include "galaxy.hpp"
#include "keyVector.hpp"
#include "header.hpp"
#include "settings.hpp"
#include "startView.hpp"
#include "../Handlers/eventHandler.hpp"

class galaxy;
class gameplay : public scene{
  protected:
    spaceship *Player;
    header *Header;
    galaxy *Galaxy;
    startView *StartView;
    //settings *Settings;

    playground *Playground;
    //classes to handle input commands in smooth trasformations of object
    keyVector rotation;
    keyVector translation;

  protected:
    void draw ();
    void eventHandler(const sf::Event &event);

  public:
    //----------CONSTRUCTORS----------
    gameplay(sf::RenderWindow* window);
    ~gameplay();

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
    virtual std::string Class();

};

#endif
