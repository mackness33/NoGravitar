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
#include <string>
#include "bullet.hpp"
#include "viewer.hpp"

/*
  BUG: change body into sprites
*/
#define PI 3.14159265

class spaceship : public drawable{
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
    ~spaceship();

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
    std::list<bullet*>* getBullets();

    //SETS
    void setXOutOfBounds(bool x);
    void setYOutOfBounds(bool y);
    void setLeftOutOfBounds(bool left);
    void setTopOutOfBounds(bool top);
    void setSpatialVersor(float spatialVersor);
    void setRotationVersor(float rotationVersor);
    void setBody(sf::Sprite* body);
    void setPlayground(viewer* playground);
    //TODO: setTexture(sf::Texture* t);

    //DELETES
    void deleteBullet(bullet* bullet);
    void deleteBullets();

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

    std::string Class();
};

#endif
