//HEADER
//Class that handle everything that concerne the top of the window
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include "settings.hpp"
#include "drawable.hpp"
/*

*/
#define PI 3.14159265

class bullet : public drawable{
  private:
    movable<sf::CircleShape>* body;
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
    movable<sf::CircleShape>* getMovable();
    entity<sf::CircleShape>* getEntity();
    sf::CircleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();

    //SETS

    //---------------METHODS---------------

    //DRAW
    void Draw (sf::RenderWindow* window);

    void Update();

    void build();

    std::string Class();
};
