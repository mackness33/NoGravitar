//HEADER
//Class that handle everything that concerne the top of the window
#include "planetObj.hpp"
/*

*/
#define PI 3.14159265

//CONSTRUCTORS
planetObj::~planetObj(){
  body = new entity<sf::CircleShape>(100);

  body->SetPosition(sf::Vector2f(100, 100));
}

planetObj::planetObj(float radius){
  body = new entity<sf::CircleShape>(radius);

  body->SetPosition(500, 500);
}

planetObj::planetObj(sf::Vector2f p){
  body = new entity<sf::CircleShape>(100);

  body->SetPosition(p);
}

planetObj::planetObj(float radius, sf::Vector2f p){
  body = new entity<sf::CircleShape>(radius);

  body->SetPosition(p);
}


//GETS
entity<sf::CircleShape>* planetObj::getEntity() { return body; }
sf::CircleShape* planetObj::getDrawable() { return body->getBody(); }
sf::FloatRect planetObj::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect planetObj::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }

//SETS

//---------------METHODS---------------

//DRAW
void planetObj::Draw (sf::RenderWindow* window){
  body->DrawTest(window);
}

void planetObj::build(){
  body->getBody()->setFillColor(sf::Color::White);
}
