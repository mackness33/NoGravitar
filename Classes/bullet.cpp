//HEADER
//Class that handle everything that concerne the top of the window
#include "bullet.hpp"
/*

*/
#define PI 3.14159265

//CONSTRUCTORS
bullet::bullet(){
  body = new movable<sf::CircleShape>(5);

  speed = 12;
  direction = 0 * PI / 180.0f;
  totalTime = 0;
  this->build();
}

bullet::bullet(float s, float d, sf::Vector2f p){
  body = new movable<sf::CircleShape>(5);

  speed = s;
  direction = d * PI / 180.0f;
  totalTime = 0;

  body->SetPosition(p);
  this->build();
}

bullet::~bullet(){}


//GETS
movable<sf::CircleShape>* bullet::getMovable() { return body; }
entity<sf::CircleShape>* bullet::getEntity() { return static_cast<entity<sf::CircleShape>*> (body); }
sf::CircleShape* bullet::getDrawable() { return body->getBody(); }
sf::FloatRect bullet::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect bullet::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }

//SETS

//---------------METHODS---------------

//DRAW
void bullet::Draw (sf::RenderWindow* window){
  body->DrawTest(window);
}

void bullet::Update(){
  totalTime += settings::deltaTime;

  if(totalTime >= settings::switchTime){
    totalTime -= settings::switchTime;
    body->Move(cos(direction) * speed, sin(direction) * speed);
    sf::Vector2f pos = body->getBody()->getPosition();
    //std::cout << "Position x:" << pos.x << std::endl;
    //std::cout << "Position y:" << pos.y << std::endl;
    //std::cout << "switchTime:" << settings::switchTime << std::endl;
  }

  //std::cout << "totalTime:" << totalTime << std::endl;
  //std::cout << "deltaTime:" << settings::deltaTime << std::endl;
}

void bullet::build(){
  body->getBody()->setFillColor(sf::Color::White);
  //body->getBody()->setSmooth(true);
}
