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
    std::list<bullet*>* bullets;
    game *currentGame;
    ground *Ground;

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
    virtual std::string Class();
};

#endif
