//UNIVERSE
//Class that handle everything that concerne the top of the window

/*

*/
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include "header.hpp"
#include "../Handlers/eventHandler.hpp"

class game{
  private:
    /*std::vector<*/sf::Texture spaceshipImage;

    sf::RenderWindow *Window;
    spaceship *Spaceship;
    header *Header;
    settings *Settings;
    galaxy *Galaxy;

    viewer *Playground;

    //classes to handle input commands in smooth trasformations of object
    keyVector rotation;
    keyVector translation;

  private:
    void draw ();

  public:
    //CONSTRUCTORS
    game(sf::RenderWindow* window);

    //GETS
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //SETS
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //---------------METHODS---------------

    //DRAW
    void start ();
};
