//HEADER
//Class that handle everything that concerne the top of the window
#include "planetObj.hpp"
/*

*/
#define PI 3.14159265

//CONSTRUCTORS
planetObj::~planetObj(){
  body = new entity<sf::CircleShape>(100);
  view = nullptr;
  body->SetPosition(sf::Vector2f(100, 100));
}

planetObj::planetObj(float radius){
  body = new entity<sf::CircleShape>(radius);
  view = nullptr;

  body->SetPosition(500, 500);
}

planetObj::planetObj(sf::Vector2f p){
  body = new entity<sf::CircleShape>(100);
  view = nullptr;

  body->SetPosition(p);
}

planetObj::planetObj(float radius, sf::Vector2f p){
  body = new entity<sf::CircleShape>(radius);
  view = nullptr;

  body->SetPosition(p);
}


//GETS
entity<sf::CircleShape>* planetObj::getEntity() { return body; }
sf::CircleShape* planetObj::getDrawable() { return body->getBody(); }
sf::FloatRect planetObj::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect planetObj::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }
planetView* planetObj::getPlanetView() { return view; }

//SETS
void planetObj::setPlanetView(planetView* newView){ view = newView; }

//---------------METHODS---------------

//DRAW
void planetObj::Draw (sf::RenderWindow* window){
  body->DrawTest(window);
}


//TODO: randomize the color of the planets
void planetObj::build(){
  body->getBody()->setFillColor(sf::Color::White);
}
