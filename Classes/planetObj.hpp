//HEADER
//Class that handle everything that concerne the top of the window
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "entity.hpp"
/*

*/
#define PI 3.14159265

class planetObj{
  private:
    entity<sf::CircleShape>* body;
    bool life;
    //sf::Vector2f *size;

  public:
    //CONSTRUCTORS
    planetObj();

    planetObj(float radius);

    planetObj(sf::Vector2f p);

    planetObj(float radius, sf::Vector2f p);

    ~planetObj();

    //GETS
    entity<sf::CircleShape>* getBody();
    bool isDead();

    //SETS
    void setLife(bool l);

    //---------------METHODS---------------

    //DRAW
    void Draw (sf::RenderWindow* window);

    void build();
};
