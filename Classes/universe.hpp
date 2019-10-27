//UNIVERSE
//Class that handle everything that concerne the top of the window

/*

*/
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "spaceship.hpp"
#include "planetObj.hpp"

class universe{
  private:
    //sf::Texture texture;
    //sf::Sprite background;
    spaceship *S;
    sf::RenderWindow *window;
    sf::FloatRect *boundingBox;
    sf::RectangleShape bound;       //FOR TESTING ONLY
    sf::Vector2f *position;
    sf::Vector2f *size;
    std::list <planetObj*> planets;

  private:
    void DrawPlanets (/*sf::RenderWindow* window*/);

  public:
    //CONSTRUCTORS
    universe(sf::RenderWindow* win, spaceship* spc, unsigned int numPlanets);

    //GETS
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //SETS
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //---------------METHODS---------------

    //DRAW
    void Draw (/*sf::RenderWindow* window*/);
};
