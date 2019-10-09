//HEADER
//Class that handle everything that concerne the top of the window
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
/*

*/
#define PI 3.14159265

class header{
  private:
    sf::Text points;
    sf::Text title;
    sf::Font font;
    sf::RenderWindow *window;
    sf::FloatRect *boundingBox;
    sf::RectangleShape bound;       //FOR TESTING ONLY
    sf::Vector2f *position;
    sf::Vector2f *size;

  public:
    //CONSTRUCTORS
    header(sf::RenderWindow* win);

    //GETS
    sf::Text getPoints();
    sf::Text getTitle();
    sf::Font getFont();

    //SETS
    void setPoints(sf::Text p);
    void setTitle(sf::Text t);
    void setFont(sf::Font f);

    //---------------METHODS---------------

    //DRAW
    void Draw (/*sf::RenderWindow* window*/);
};
