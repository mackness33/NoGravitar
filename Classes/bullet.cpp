//HEADER
//Class that handle everything that concerne the top of the window
#include "bullet.hpp"
/*

*/
#define PI 3.14159265

//CONSTRUCTORS
bullet::bullet(){
  body = new movable<sf::CircleShape>();

  speed = 12;
  direction = 0 * PI / 180.0f;
  totalTime = 0;
  this->build();
  /**boundingBox = body.getLocalBounds();        //for testing use
  bound.setSize(sf::Vector2f(boundingBox->width, boundingBox->height));
  bound.setOrigin(body.getOrigin());
  bound.setPosition(body.getPosition());*/
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
movable<sf::CircleShape>* bullet::getBody() { return body; }

//SETS

//---------------METHODS---------------

//DRAW
void bullet::Draw (sf::RenderWindow* window){
  body->Draw(window);
}

void bullet::Update(){
  //distance++;
  //body.setOrigin(body.getPosition() + sf::Vector2f(5, 6));
  //body.setPosition(body.getPosition() + sf::Vector2f(1, 1));

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
}
