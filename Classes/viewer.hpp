//SPACESHIP
//Class that handle everything that concerne a spaceship
#ifndef VIEWER_H
#define VIEWER_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <list>
#include "entity.hpp"

/*
  BUG: change body into sprites
*/
#define PI 3.14159265

class viewer{
  protected:
    entity<sf::RectangleShape> *background;
    sf::RenderWindow *window;

  public:
    //TODO: add all the constructors of sf::Shape sf::RectangleShape .. etc
    //----------CONSTRUCTORS----------
    //viewer(sf::RenderWindow *w/*indow*/);

    //RectangleShape
    viewer(sf::RenderWindow *w/*indow*/, sf::Vector2f s/*ize*/ = sf::Vector2f(-1, -1), sf::Vector2f p/*osition*/ = sf::Vector2f(-1, -1), sf::Texture* i/*mage*/ = nullptr);

    //----------GETS----------
    entity<sf::RectangleShape>* getBackground();
    //*sf::FloatRect getBoundBox();
    //*sf::RectangleShape getBound();

    //----------SETS----------
    void setBackground(sf::Texture* texture);

    //----------METHODS------------
    virtual void Draw ();
};

//#include "viewer.tpp"
#endif // VIEWER_H
