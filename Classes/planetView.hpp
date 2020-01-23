#ifndef PLANETVIEW_H
#define PLANETVIEW_H

#include "game.hpp"
#include "bunker.hpp"
#include "ground.hpp"
#include "spaceship.hpp"
#include "playground.hpp"
#include "galaxy.hpp"
#include "planetObj.hpp"

class game;
class galaxy;
class planetObj;

class planetView : public playground{
  private:
    spaceship *Player;
    ground *Ground;
    std::list<bunker*> bunkers;
    game *currentGame;
    galaxy *Galaxy;
    planetObj *Planet;
    sf::Texture *image;

  private:
    //template <typename E> void collisionSpaceship(spaceship* Spaceship, E* e, bool* cv);
    void collision(std::_List_iterator<drawable*>* ally, std::_List_iterator<drawable*>* enemy, bool* changeViewer);
    void collisionBullet(std::_List_iterator<drawable*>* spaceship, std::_List_iterator<drawable*>* enemy, bool* changeViewer);
    void collisionSpaceship(std::_List_iterator<drawable*>* bullet, std::_List_iterator<drawable*>* enemy, bool* changeViewer);
    void inizializeBunker();

  public:
    //----------CONSTRUCTORS----------
    planetView(sf::RenderWindow* window, spaceship* spaceship, game* actualGame, galaxy* lastGalaxy, planetObj* planet);

    ~planetView();
    //----------GETS----------
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //----------SETS----------
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //----------METHODS----------
    void checkCollision();

    virtual std::string Class();
};

#endif
