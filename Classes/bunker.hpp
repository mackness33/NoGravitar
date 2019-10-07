#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class bunker{
  //if there are properties you must set and get them!!!
  private:

    sf::ConvexShape body;

  public:
    //CONSTRUCTORS
    bunker(){
      this->build();
    }


    void Disegna(sf::RenderWindow* window){
      window->draw(body);
    }


    void build (){
      body.setPointCount(6);

      body.setPoint(0, sf::Vector2f(30.f, 0.f));
      body.setPoint(1, sf::Vector2f(40.f, 0.f));
      body.setPoint(2, sf::Vector2f(40.f, 10.f));
      body.setPoint(3, sf::Vector2f(60.f, 30.f));
      body.setPoint(4, sf::Vector2f(10.f, 30.f));
      body.setPoint(5, sf::Vector2f(30.f, 10.f));

      body.setFillColor(sf::Color(000, 032, 128));
      //creo il contorno della navicella colorata
      body.setOutlineThickness(2.f);
      body.setOutlineColor(sf::Color(000, 224, 224));
      body.setPosition(100, 100);
    }
};
