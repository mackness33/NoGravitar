//SPACESHIP
//Class that handle everything that concerne a spaceship

/*
  BUG: change body into sprites
*/
#define PI 3.14159265
#include "spaceship.hpp"

//CONSTRUCTORS
spaceship::spaceship(){
  xOutOfBound = false;
  yOutOfBound = false;
  topOOB = false;
  leftOOB = false;

  spatial_Versor = 10;
  rotation_Versor = 3;

  this->build(body);
}

/*spaceship(const spaceship& S){
  spatial_Versor = S.getSpatialVersor();
  rotation_Versor = S.getRotationVersor();

  build();
}*/

//GETS
bool spaceship::getXOutOfBounds(){ return xOutOfBound;}
bool spaceship::getYOutOfBounds(){ return yOutOfBound;}
bool spaceship::getLeftOutOfBounds(){ return leftOOB;}
bool spaceship::getTopOutOfBounds(){ return topOOB;}
float spaceship::getSpatialVersor(){ return spatial_Versor;}
float spaceship::getRotationVersor(){ return rotation_Versor;}
sf::ConvexShape spaceship::getBody(){ return body;}

//SETS
void spaceship::setXOutOfBounds(bool x){ xOutOfBound = x;}
void spaceship::setYOutOfBounds(bool y){ yOutOfBound = y;}
void spaceship::setLeftOutOfBounds(bool l){ leftOOB = l;}
void spaceship::setTopOutOfBounds(bool t){ topOOB = t;}
void spaceship::setSpatialVersor(float sv) { spatial_Versor = sv;}
void spaceship::setRotationVersor(float rv) { rotation_Versor = rv;}
void spaceship::setBody(sf::ConvexShape b) { body = b;}

//---------------METHODS--------------------

//MOVEMENT
//It let the spaceship move or rotate based on the key pressed
void spaceship::movement(sf::Keyboard::Key k){
  switch (k) {
    case sf::Keyboard::Left : {                 //LEFT
      body.rotate(-rotation_Versor);
    };break;

    case sf::Keyboard::Right : {                //RIGHT
      body.rotate(rotation_Versor);
    };break;

    case sf::Keyboard::Up : {                   //UP
      fly(spatial_Versor);
    };break;

    case sf::Keyboard::Down : {                 //DOWN
      fly(-spatial_Versor);
    };break;

    default: std::cout << "Not a movementCommand" << std::endl;
  }
}

//for testing use
void spaceship::movement(sf::Keyboard::Key k, sf::RectangleShape *Bound){
  switch (k) {
    case sf::Keyboard::Left : {                 //LEFT
      body.rotate(-rotation_Versor);
      Bound->rotate(-rotation_Versor);
    };break;

    case sf::Keyboard::Right : {                //RIGHT
      body.rotate(rotation_Versor);
      Bound->rotate(rotation_Versor);
    };break;

    case sf::Keyboard::Up : {                   //UP
      fly(spatial_Versor, Bound);
    };break;

    case sf::Keyboard::Down : {                 //DOWN
      fly(-spatial_Versor, Bound);
    };break;

    default: std::cout << "Not a movementCommand" << std::endl;
  }
}

//for testing use
void spaceship::fly(float module, sf::RectangleShape *Bound){
  float direction = body.getRotation() * PI / 180.0;
  int sin_module = sin(direction) * module;
  int cos_module = cos(direction) * module;
  bool y_opp_dir = opposite_direction(topOOB,  sin(direction) * module);
  bool x_opp_dir = opposite_direction(leftOOB,  cos(direction) * module);

  if((yOutOfBound && !y_opp_dir)){
    sin_module = 0;
    std::cout << "YOutOfBounds!!!" << std::endl;
  }

  if((xOutOfBound && !x_opp_dir)){
    cos_module = 0;
    std::cout << "XOutOfBounds!!!" << std::endl;
  }

  body.move(cos_module, sin_module);
  Bound->move(cos_module, sin_module);
}


//FLY
//It handle spaceship translation in the window
void spaceship::fly(float module){
  float direction = body.getRotation() * PI / 180.0;
  int sin_module = sin(direction) * module;
  int cos_module = cos(direction) * module;
  bool y_opp_dir = opposite_direction(topOOB,  sin(direction) * module);
  bool x_opp_dir = opposite_direction(leftOOB,  cos(direction) * module);

  if((yOutOfBound && !y_opp_dir)){
    sin_module = 0;
    std::cout << "YOutOfBounds!!!" << std::endl;
  }

  if((xOutOfBound && !x_opp_dir)){
    cos_module = 0;
    std::cout << "XOutOfBounds!!!" << std::endl;
  }

  body.move(cos_module, sin_module);
}


//OPPOSITE_DIRECTION
//It understand if the spaceship want o go OutOfBOunds
bool spaceship::opposite_direction(bool side, float direction){
  if(side){
    if(direction >= 0)
      return true;
  }
  else{
    if(direction <= 0)
      return true;
  }

  return false;
}

void spaceship::Draw (sf::RenderWindow* window){
  window->draw(body);
}

//BUILD
//It build up the spaceship shape
void spaceship::build (sf::ConvexShape body){
  //creo quattro punti per la spezzata chiusa dell'astronave
  body.setPointCount(4);

  body.setPoint(2, sf::Vector2f(30.f, 0.f));
  body.setPoint(1, sf::Vector2f(0.f, 40.f));
  body.setPoint(3, sf::Vector2f(60.f, 40.f));
  body.setPoint(0, sf::Vector2f(30.f, 20.f));

  //creo il contorno della navicella colorata
  body.setOutlineThickness(2.f);
  body.setOutlineColor(sf::Color(000, 255, 000));
  body.setOrigin(30.f, 20.f);
  body.setPosition(80.f, 70.f);
  body.rotate(90);
}
