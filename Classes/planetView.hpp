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
    //template <typename E> void collisionSpaceship(spaceship* Spaceship, E* e, bool* cv);
    void collision(std::_List_iterator<drawable*>* object, bool isAlly);
    void collision(std::_List_iterator<drawable*>* ally, std::_List_iterator<drawable*>* enemy);
    void collisionBullet(std::_List_iterator<drawable*>* spaceship, std::_List_iterator<drawable*>* enemy);
    void collisionSpaceship(std::_List_iterator<drawable*>* bullet, std::_List_iterator<drawable*>* enemy);
    void inizializeBunker();

  public:
    //----------CONSTRUCTORS----------
    planetView(sf::RenderWindow* window, spaceship* spaceship, gameplay* actualGame, galaxy* lastGalaxy, planetObj* planet);

    ~planetView();
    //----------GETS----------
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //----------SETS----------
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}
    void restart();
    //----------METHODS----------
    void checkCollision();

    virtual std::string Class();
};

#endif
