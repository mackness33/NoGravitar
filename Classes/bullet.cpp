#include "bullet.hpp"

//---------------CONSTRUCTORS---------------
bullet::bullet(float s, float d, sf::Vector2f p){
  body = new movable<sf::CircleShape>(10);

  speed = s;
  direction = d * PI / 180.0f;
  totalTime = 0;

  body->SetPosition(p);
  this->build();
}

bullet::~bullet(){
  std::cout << "DELETING BULLET" << std::endl;

  delete body;
  body = nullptr;
}


//---------------GETS---------------
movable<sf::CircleShape>* bullet::getMovable() { return body; }
entity<sf::CircleShape>* bullet::getEntity() { return static_cast<entity<sf::CircleShape>*> (body); }
sf::CircleShape* bullet::getDrawable() { return body->getBody(); }
sf::FloatRect bullet::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect bullet::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }

//---------------SETS---------------



//---------------METHODS---------------

void bullet::Draw (sf::RenderWindow* window){
  body->DrawTest(window);
}

void bullet::Update(){
  totalTime += settings::deltaTime;

  if(totalTime >= settings::switchTime){
    totalTime -= settings::switchTime;
    body->Move(cos(direction) * speed, sin(direction) * speed);
    sf::Vector2f pos = body->getBody()->getPosition();
  }
}

void bullet::build(){
  body->getBody()->setFillColor(sf::Color::White);
  //body->getBody()->setSmooth(true);
}


float bullet::GetRotation(){ return this->body->getBody()->getRotation(); }

std::string bullet::Class(){
  return "bullet";
}
