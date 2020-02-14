#ifndef PLANETVIEW_H
#define PLANETVIEW_H

#include "gameplay.hpp"
#include "bunker.hpp"
#include "ground.hpp"
#include "spaceship.hpp"
#include "playground.hpp"
#include "galaxy.hpp"
#include "planetObj.hpp"
#include "shooter.hpp"
#include "fuel.hpp"

class gameplay;
class galaxy;
class planetObj;

class planetView : public playground{
  private:
    spaceship *Player;
    ground *Ground;
    std::list<bunker*> bunkers;
    std::list<fuel*> fuels;
    gameplay *Gameplay;
    galaxy *Galaxy;
    planetObj *Planet;
    sf::Texture *image;
    bool changeViewer;
    bool restartViewer;

  private:
    void inizializeBunker();            //inizialization of the bunkers and fuels
    //general collison handling
    void collision(std::_List_iterator<drawable*>* object, bool isAlly);
    void collision(std::_List_iterator<drawable*>* ally, std::_List_iterator<drawable*>* enemy);
    //specific collision handling
    void collisionBullet(std::_List_iterator<drawable*>* spaceship, std::_List_iterator<drawable*>* enemy);
    void collisionSpaceship(std::_List_iterator<drawable*>* bullet, std::_List_iterator<drawable*>* enemy);

  public:
    //----------CONSTRUCTORS----------
    planetView(sf::RenderWindow* window, spaceship* spaceship, gameplay* actualGame, galaxy* lastGalaxy, planetObj* planet);

    ~planetView();

    //----------METHODS----------
    void back();                      //return back to the last View (galaxy)
    void restart();                   //restart the view. It happend when spaceship die
    void checkCollision();            //check of collision between objects

    //return the class of the object
    virtual std::string Class();
};

#endif
