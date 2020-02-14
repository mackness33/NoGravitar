#include "bullet.hpp"

//---------------CONSTRUCTORS---------------
bullet::bullet(shooter *dad, float s, float d, sf::Vector2f p, sf::Color c) : parent(dad), direction(utility::toRadiant(d)), totalTime(0), speed(s){
  body = new movable<sf::CircleShape>(information::BULLET_DEFAULT_RADIUS);

  body->SetPosition(p);
  body->getBody()->setFillColor(c);
}

bullet::~bullet(){
  if(!!body)
    delete body;

  body = nullptr;
  parent = nullptr;
}

//---------------GETS---------------
movable<sf::CircleShape>* bullet::getMovable() { return body; }
entity<sf::CircleShape>* bullet::getEntity() { return static_cast<entity<sf::CircleShape>*> (body); }
sf::CircleShape* bullet::getDrawable() { return body->getBody(); }
sf::FloatRect bullet::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect bullet::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }
shooter* bullet::getShooter() { return parent; }


//---------------METHODS---------------
void bullet::Draw (sf::RenderWindow* window){ body->Draw(window); }

void bullet::Update(){
  totalTime += information::DELTA_TIME;

  if(totalTime >= information::SWITCH_TIME){
    totalTime -= information::SWITCH_TIME;
    body->Move(cos(direction) * speed, sin(direction) * speed);
    sf::Vector2f pos = body->getBody()->getPosition();
  }
}

float bullet::GetRotation(){ return this->body->getBody()->getRotation(); }

std::string bullet::Class(){
  return "bullet";
}
