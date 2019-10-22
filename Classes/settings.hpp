//UNIVERSE
//Class that handle everything that concerne the top of the window

/*

*/
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#define PI 3.14159265

class settings{
  private:
    //sf::Texture texture;
    //sf::Sprite background;
    sf::RenderWindow *window;
    sf::FloatRect *boundingBox;
    sf::RectangleShape bound;       //FOR TESTING ONLY
    sf::Vector2f *position;
    sf::Vector2f *size;
    sf::Clock clock;

  public:
    static float deltaTime;
    static float switchTime;

  public:
    //CONSTRUCTORS
    settings(sf::RenderWindow* win);

    //GETS
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}
    sf::Clock getClock(){ return this->clock;}

    //SETS
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}
    void setClock(sf::Clock c){ this->clock = c;}


    //---------------METHODS---------------
    static void default_settings(){
      switchTime = 60;
    }

    //DRAW
    void Draw (/*sf::RenderWindow* window*/);
};
