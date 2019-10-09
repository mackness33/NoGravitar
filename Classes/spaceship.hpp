//SPACESHIP
//Class that handle everything that concerne a spaceship

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

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
    sf::ConvexShape body;

  public:
    //CONSTRUCTORS
    spaceship();
    //spaceship(const spaceship& S);

    //GETS
    bool getXOutOfBounds();
    bool getYOutOfBounds();
    bool getLeftOutOfBounds();
    bool getTopOutOfBounds();
    float getSpatialVersor();
    float getRotationVersor();
    sf::ConvexShape getBody();

    //SETS
    void setXOutOfBounds(bool x);
    void setYOutOfBounds(bool y);
    void setLeftOutOfBounds(bool l);
    void setTopOutOfBounds(bool t);
    void setSpatialVersor(float sv);
    void setRotationVersor(float rv);
    void setBody(sf::ConvexShape b);

    //----------METHODS------------

    //MOVEMENT
    //It let the spaceship move or rotate based on the key pressed
    void movement(sf::Keyboard::Key k);

    //for testing use
    void movement(sf::Keyboard::Key k, sf::RectangleShape *Bound);

    //FLY
    //for testing use
    void fly(float module, sf::RectangleShape *Bound);

    //It handle spaceship translation in the window
    void fly(float module);

    //OPPOSITE_DIRECTION
    //It understand if the spaceship want o go OutOfBOunds
    bool opposite_direction(bool side, float direction);

    void Draw (sf::RenderWindow* window);

    //BUILD
    //It build up the spaceship shape
    void build (sf::ConvexShape body);
};
