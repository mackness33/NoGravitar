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

class utility{
  private:


  public:
    static float deltaTime;
    static float switchTime;

  public:
    //CONSTRUCTORS
    utility();

    //GETS
    //sf::Texture getTexture(){ return this->background.getTexture();}

    //SETS
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}

    //---------------METHODS---------------
    static void default_utility(){
      switchTime = 60;
    }
};
