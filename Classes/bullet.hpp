//BULLET
//Class that draw and move a bullet
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
    float speed;
    float direction;
    float totalTime;

  public:
    //CONSTRUCTORS
    bullet(float speed = 12, float direction = 0, sf::Vector2f position = sf::Vector2f(0,0));

    //DESTRUCTORS
    ~bullet();

    //GETS
    movable<sf::CircleShape>* getMovable();
    entity<sf::CircleShape>* getEntity();
    sf::CircleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();

    //SETS

    //---------------METHODS---------------
    //draw of the body of the object
    void Draw (sf::RenderWindow* window);

    //update of the object's data for each time that it is draw
    void Update();

    //build all the settings of object's body
    void build();

    //return the class of the object
    std::string Class();
};
