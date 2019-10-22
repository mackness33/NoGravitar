//HEADER
//Class that handle everything that concerne the top of the window
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "settings.hpp"
/*

*/
#define PI 3.14159265

class bullet{
  private:
    sf::CircleShape body;
    //sf::FloatRect *boundingBox;
    //sf::RectangleShape bound;       //FOR TESTING ONLY
    //sf::Vector2f *position;
    //sf::Vector2f *size;
    float speed;
    float direction;
    float totalTime;

  public:
    //CONSTRUCTORS
    bullet();
    bullet(float s, float d, sf::Vector2f p);
    ~bullet();

    //GETS
    sf::CircleShape getBody();
    //SETS

    //---------------METHODS---------------

    //DRAW
    void Draw (sf::RenderWindow* window);

    void Update();

    void build();
};
