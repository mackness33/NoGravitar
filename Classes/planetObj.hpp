//HEADER
//Class that handle everything that concerne the top of the window
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "drawable.hpp"
#include "planetView.hpp"
/*

*/
#define PI 3.14159265

class planetObj : public drawable{
  private:
    entity<sf::CircleShape>* body;
    bool life;
    planetView* view;
    //sf::Vector2f *size;
    sf::RenderWindow* window;

  public:
    //CONSTRUCTORS
    planetObj();

    planetObj(float radius);

    planetObj(sf::Vector2f position);

    planetObj(float radius, sf::Vector2f position);

    ~planetObj();

    //GETS
    entity<sf::CircleShape>* getEntity();
    sf::CircleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();
    bool isDead();
    planetView* getPlanetView();
    //planetView* isDead();

    //SETS
    void setLife(bool l);
    void setPlanetView(planetView* newView);

    //---------------METHODS---------------

    //DRAW
    void Draw (sf::RenderWindow* window);

    void build();
};
