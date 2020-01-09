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
    std::list<bullet*>* bullets;
    game *currentGame;

  protected:
    bool checkPlanetPosition(std::list<sf::FloatRect>* posPlanets, sf::Vector2f pos);
    void inizializePlanets(unsigned int numPlanets);

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
    void checkCollision();

    //TODO: create a .tpp and convert collision in template <typename T> void galaxy::collision(T* obj, planetObj* planet){ return nullptr; }
    //template <typename A, typename E> void collision(A* ally, E* enemy);
    //template <typename E, typename A> void collision(E* e, A* a, bool* cv);
    //template <typename E> void collisionBullet(bullet* Bullet, E* e);
    //template <typename E> void collisionSpaceship(spaceship* Spaceship, E* e, bool* cv);
    void collision(std::_List_iterator<drawable*>* ally, std::_List_iterator<drawable*>* enemy, bool* changeViewer);
    void collisionBullet(std::_List_iterator<drawable*>* spaceship, std::_List_iterator<drawable*>* enemy);
    void collisionSpaceship(std::_List_iterator<drawable*>* bullet, std::_List_iterator<drawable*>* enemy, bool* changeViewer);
    //void collision(bullet* bullet, planetObj* planet);

    //void collision(spaceship* spaceship, planetObj* planet);
    virtual std::string Class();

};

//#include "galaxy.tpp"
#endif
