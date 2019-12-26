#ifndef PLANETVIEW_H
#define PLANETVIEW_H

#include "ground.hpp"
#include "spaceship.hpp"
#include "playground.hpp"
#include "game.hpp"

class game;

class planetView : public playground{
  private:
    spaceship *Player;
    ground *Ground;
    std::list<bullet*>* bullets;
    game *currentGame;

  private:

  public:
    //----------CONSTRUCTORS----------
    planetView(sf::RenderWindow* win, spaceship* spc, game* actualGame);

    //----------GETS----------
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //----------SETS----------
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //----------METHODS----------
    void checkCollision();

    //TODO: create a .tpp and convert collision in template <typename T> void galaxy::collision(T* obj, planetObj* planet){ return nullptr; }
    //template <typename A, typename E> void collision(A* ally, E* enemy);
    //template <typename E, typename A> void collision(E* e, A* a, bool* cv);
    //template <typename E> void collisionBullet(bullet* Bullet, E* e);
    //template <typename E> void collisionSpaceship(spaceship* Spaceship, E* e, bool* cv);
    void collision(std::_List_iterator<drawable*>* ally, std::_List_iterator<drawable*>* enemy, bool* changeViewer);
    void collisionBullet(std::_List_iterator<drawable*>* spaceship, std::_List_iterator<drawable*>* enemy);
    void collisionSpaceship(std::_List_iterator<drawable*>* bullet, std::_List_iterator<drawable*>* enemy, bool* changeViewer);

    virtual std::string Class();
};

#endif
