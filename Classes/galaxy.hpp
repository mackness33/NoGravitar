#ifndef GALAXY_H
#define GALAXY_H

#include <list>
#include "spaceship.hpp"
#include "planetObj.hpp"
#include "planetView.hpp"
#include "utility.hpp"
#include "viewer.hpp"
#include "game.hpp"
#include "../Handlers/collisionHandler.hpp"

class game;

class galaxy : public viewer{
  protected:
    spaceship *S;
    std::list<planetObj*> planets;
    std::list<bullet*>* bullets;
    game *currentGame;

  protected:
    void DrawList (std::list<drawable*> objects);

    bool checkPlanetPosition(std::list<sf::FloatRect>* posPlanets, sf::Vector2f pos);

  public:
    //CONSTRUCTORS
    galaxy(sf::RenderWindow* win, spaceship* spc, unsigned int numPlanets, game* actualGame);

    //GETS
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //SETS
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //---------------METHODS---------------
    void Draw ();

    void checkCollision();

    void collision(bullet* bullet, planetObj* planet);

    void collision(spaceship* spaceship, planetObj* planet);

};

#endif
