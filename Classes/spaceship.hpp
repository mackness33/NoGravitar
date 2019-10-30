//SPACESHIP
//Class that handle everything that concerne a spaceship


#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <list>
#include "bullet.hpp"
#include "viewer.hpp"

/*
  BUG: change body into sprites
*/
#define PI 3.14159265

class spaceship{
  private:
    bool xOutOfBound;                   //XOutOfBounds
    bool yOutOfBound;                   //YOutOfBounds
    bool leftOOB;                   //leftOutOfBounds
    bool topOOB;                   //topOutOfBounds
    float spatial_Versor;
    float rotation_Versor;
    movable<sf::Sprite>* body;
    sf::Texture* image;
    //bullet *b;
    std::list <bullet*> bullets;
    viewer *playground;

  public:
    //CONSTRUCTORS
    spaceship(viewer* playground);
    spaceship(viewer* playground, sf::Texture* img);
    //spaceship(const spaceship& S);

    //GETS
    bool getXOutOfBounds();
    bool getYOutOfBounds();
    bool getLeftOutOfBounds();
    bool getTopOutOfBounds();
    float getSpatialVersor();
    float getRotationVersor();
    movable<sf::Sprite>* getMovable();
    entity<sf::Sprite>* getEntity();
    sf::Sprite* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();

    //SETS
    void setXOutOfBounds(bool x);
    void setYOutOfBounds(bool y);
    void setLeftOutOfBounds(bool l);
    void setTopOutOfBounds(bool t);
    void setSpatialVersor(float sv);
    void setRotationVersor(float rv);
    void setBody(sf::Sprite* b);
    void setPlayground(viewer* b);
    //TODO: setTexture(sf::Texture* t);

    //----------METHODS------------

    //MOVEMENT
    //It let the spaceship move or rotate based on the key pressed
    void movement(sf::Keyboard::Key k);

    //FLY
    //It handle spaceship translation in the window
    void fly(float module);

    //OPPOSITE_DIRECTION
    //It understand if the spaceship want o go OutOfBOunds
    bool opposite_direction(bool side, float direction);

    void Draw (sf::RenderWindow* window);

    //BUILD
    //It build up the spaceship shape
    void build ();

    void Shoot();
};

#endif
