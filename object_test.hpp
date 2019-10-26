//OBJECT
//A prototype of a class

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <list>
#include "Classes/entity.hpp"

template <class T> class object_test {
  //if there are properties you must set and get them!!!
  private:
    int property;
    entity<sf::CircleShape> *body;

  public:
    //CONSTRUCTORS
    object_test(sf::RenderWindow* w);

    //if there's no property, you don't need get and set!!!
    //GETS
    int getFroperty();

    //SETS
    void setFroperty(int p);

    //METHODS
    //build the shape of the object
    /*void build (){
      //you mostly have to write; your code here!
      //creo quattro punti per la spezzata chiusa dell'astronave
      this->setPointCount(4);

      this->setPoint(0, sf::Vector2f(0.f, 0.f));
      this->setPoint(1, sf::Vector2f(0.f, 20.f));
      this->setPoint(2, sf::Vector2f(20.f, 20.f));
      this->setPoint(3, sf::Vector2f(20.f, 0.f));

      //creo il contorno della navicella colorata
      this->setOutlineThickness(2.f);
      this->setOutlineColor(sf::Color(000, 255, 000));
      this->setOrigin(10.f, 10.f);
      this->setPosition(80.f, 70.f);
      this->rotate(90);
    }Classes*/

    void Draw (sf::RenderWindow* window);
};
