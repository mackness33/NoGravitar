#ifndef GALAXY_H
#define GALAXY_H

#include <list>
#include "spaceship.hpp"
#include "planetObj.hpp"
#include "planetView.hpp"
#include "utility.hpp"
#include "playground.hpp"
#include "gameplay.hpp"
#include "../Handlers/collisionHandler.hpp"

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
    bool checkPlanetPosition(planetObj* planet);
    void inizializePlanets();
    //TODO: create a .tpp and convert collision in template <typename T> void galaxy::collision(T* obj, planetObj* planet){ return nullptr; }
    void collision(std::_List_iterator<drawable*>* ally, std::_List_iterator<drawable*>* enemy);

  public:
    //CONSTRUCTORS
    galaxy(sf::RenderWindow* win, spaceship* spc, unsigned int galaxyLevel, gameplay* actualGame);

    ~galaxy();

    //GETS
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //SETS
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //---------------METHODS---------------
    void checkCollision();
    int getLevel();

    bool isConquer();
    void delPlanet(planetObj *planet);

    void next();
    void prev();
    virtual std::string Class();

};

//#include "galaxy.tpp"
#endif
