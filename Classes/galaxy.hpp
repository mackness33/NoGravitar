#ifndef GALAXY_H
#define GALAXY_H

#include <list>
#include "spaceship.hpp"
#include "planetObj.hpp"
#include "planetView.hpp"
#include "utility.hpp"
#include "playground.hpp"
#include "game.hpp"
#include "../Handlers/collisionHandler.hpp"

class game;
class planetObj;

class galaxy : public playground{
  protected:
    spaceship *Player;
    std::list<planetObj*> planets;
    game *currentGame;

  protected:
    bool checkPlanetPosition(planetObj* planet);
    void inizializePlanets(unsigned int numPlanets);
    //TODO: create a .tpp and convert collision in template <typename T> void galaxy::collision(T* obj, planetObj* planet){ return nullptr; }
    void collision(std::_List_iterator<drawable*>* ally, std::_List_iterator<drawable*>* enemy, bool* changeViewer);
    void collisionBullet(std::_List_iterator<drawable*>* spaceship, std::_List_iterator<drawable*>* enemy);
    void collisionSpaceship(std::_List_iterator<drawable*>* bullet, std::_List_iterator<drawable*>* enemy, bool* changeViewer);

  public:
    //CONSTRUCTORS
    galaxy(sf::RenderWindow* win, spaceship* spc, unsigned int numPlanets, game* actualGame);

    ~galaxy();

    //GETS
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //SETS
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //---------------METHODS---------------
    void checkCollision();

    void delPlanet(planetObj *planet);

    virtual std::string Class();

};

//#include "galaxy.tpp"
#endif
