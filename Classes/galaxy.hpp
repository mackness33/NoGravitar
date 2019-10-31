//UNIVERSE
//Class that handle everything that concerne the top of the window

/*

*/


#ifndef GALAXY_H
#define GALAXY_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <list>
#include "spaceship.hpp"
#include "planetObj.hpp"
#include "utility.hpp"
#include "viewer.hpp"
#include "../Handlers/collisionHandler.hpp"

class galaxy : public viewer{
  private:
    spaceship *S;
    std::list <planetObj*> planets;

  private:
    void DrawPlanets (/*sf::RenderWindow* window*/);

    bool checkPlanetPosition(std::list<sf::FloatRect>* posPlanets, sf::Vector2f pos);

  public:
    //CONSTRUCTORS
    galaxy(sf::RenderWindow* win, spaceship* spc, unsigned int numPlanets);

    //GETS
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //SETS
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //---------------METHODS---------------

    //DRAW
    void Draw (/*sf::RenderWindow* window*/);

    void checkCollision();
};

#endif
