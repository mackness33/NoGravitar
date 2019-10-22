//HEADER
//Class that handle everything that concerne the top of the window
#include "bullet.hpp"
/*

*/
#define PI 3.14159265

//CONSTRUCTORS
bullet::bullet(){
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
  speed = s;
  direction = d * PI / 180.0f;
  totalTime = 0;

  this->build();
  body.setPosition(p);
}

bullet::~bullet(){}


//GETS
sf::CircleShape bullet::getBody() { return body; }

//SETS

//---------------METHODS---------------

//DRAW
void bullet::Draw (sf::RenderWindow* window){
  //window->draw(bound);
  window->draw(body);
}

void bullet::Update(){
  //distance++;
  //body.setOrigin(body.getPosition() + sf::Vector2f(5, 6));
  //body.setPosition(body.getPosition() + sf::Vector2f(1, 1));

  totalTime += settings::deltaTime;

  if(totalTime >= settings::switchTime){
    totalTime -= settings::switchTime;
    body.move(cos(direction) * speed, sin(direction) * speed);
    std::cout << "Position x:" << body.getPosition().x << std::endl;
    std::cout << "Position y:" << body.getPosition().y << std::endl;
    //std::cout << "switchTime:" << settings::switchTime << std::endl;
  }

  std::cout << "totalTime:" << totalTime << std::endl;
  //std::cout << "deltaTime:" << settings::deltaTime << std::endl;
}

void bullet::build(){
  body.setRadius(10);
  body.setFillColor(sf::Color::Red);
}
