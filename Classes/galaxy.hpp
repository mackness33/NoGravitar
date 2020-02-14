#ifndef GALAXY_H
#define GALAXY_H

#include <list>

#include "gameplay.hpp"
#include "planetObj.hpp"
#include "playground.hpp"
#include "spaceship.hpp"

class gameplay;
class planetObj;

class galaxy : public playground{
  protected:
    spaceship *Player;
    std::list<planetObj*> planets;
    gameplay *Gameplay;
    int level;
    bool conquer;

  protected:
    //check if the position of the planet is not on the same of another object
    bool checkPlanetPosition(planetObj* planet);

    //inizialization of the planets
    void inizializationPlanets();

    //handle the collision between aliies and enemies
    void collision(std::_List_iterator<drawable*>* ally, std::_List_iterator<drawable*>* enemy);

  public:
    //---------------CONSTRUCTORS---------------
    galaxy(sf::RenderWindow* win, spaceship* spc, unsigned int galaxyLevel, gameplay* actualGame);

    ~galaxy();

    //---------------GETS---------------
    int getLevel();                           //return the level of the galaxy

    //---------------METHODS---------------
    //overriding of the playground method
    //checks whether there's a collision
    void checkCollision();

    //return true if every planets has been conquer
    bool isConquer();
    //it handle the deletion of the object
    void delPlanet(planetObj *planet);

    void next();                            //go tho the next Galaxy
    void prev();                            //go tho the previous Galaxy

    //return the class of the object
    virtual std::string Class();

};

#endif
