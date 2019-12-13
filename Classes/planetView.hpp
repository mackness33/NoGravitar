#ifndef PLANETVIEW_H
#define PLANETVIEW_H

#include "spaceship.hpp"
#include "viewer.hpp"

class planetView : public viewer{
  private:
    spaceship *Player;
    //TODO: add Ground class

  private:

  public:
    //----------CONSTRUCTORS----------
    planetView(sf::RenderWindow* win, spaceship* spc);

    //----------GETS----------
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //----------SETS----------
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //----------METHODS----------
    void Draw (/*sf::RenderWindow* window*/);
};

#endif
