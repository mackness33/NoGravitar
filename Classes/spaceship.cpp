//SPACESHIP
//Class that handle everything that concerne a spaceship

/*
  BUG: change body into sprites
*/
#define PI 3.14159265
#include "spaceship.hpp"

//CONSTRUCTORS
spaceship::spaceship(viewer* plg){
  xOutOfBound = false;
  yOutOfBound = false;
  topOOB = false;
  leftOOB = false;

  spatial_Versor = 10;
  rotation_Versor = 3;

  //b = NULL;
  bullets = {};

  image->loadFromFile("img/spaceship.png");
  body = new movable<sf::Sprite>(image);

  //this->build();
}

spaceship::spaceship(viewer* plg, sf::Texture* img){
  xOutOfBound = false;
  yOutOfBound = false;
  topOOB = false;
  leftOOB = false;

  spatial_Versor = 10;
  rotation_Versor = 3;

  //b = NULL;
  bullets = {};

  image = img;
  image->loadFromFile("img/spaceship.png");

  body = new movable<sf::Sprite>(image);
  body->SetScale(0.25f, 0.25f);
  body->SetPosition(80.f, 70.f);
  sf::FloatRect bounds = this->GetLocalBounds();
  body->SetOrigin(bounds.width/2, bounds.height/2);

  playground = plg;
  //this->build();
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
movable<sf::Sprite>* spaceship::getMovable() { return body; }
entity<sf::Sprite>* spaceship::getEntity() { return static_cast<entity<sf::Sprite>*> (body); }
sf::Sprite* spaceship::getDrawable() { return body->getBody(); }
sf::FloatRect spaceship::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect spaceship::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }
//TODO: set texture to let the user change the spaceship image


//SETS
void spaceship::setXOutOfBounds(bool x){ xOutOfBound = x;}
void spaceship::setYOutOfBounds(bool y){ yOutOfBound = y;}
void spaceship::setLeftOutOfBounds(bool l){ leftOOB = l;}
void spaceship::setTopOutOfBounds(bool t){ topOOB = t;}
void spaceship::setSpatialVersor(float sv) { spatial_Versor = sv;}
void spaceship::setRotationVersor(float rv) { rotation_Versor = rv;}
void spaceship::setPlayground(viewer* pg) { playground = pg;}
//void spaceship::setBody(sf::Sprite* b) { body = b;}

//---------------METHODS--------------------

//MOVEMENT
//It let the spaceship move or rotate based on the key pressed
void spaceship::movement(sf::Keyboard::Key k){
  switch (k) {
    case sf::Keyboard::Left : {                 //LEFT
      body->Rotate(-rotation_Versor);
    };break;

    case sf::Keyboard::Right : {                //RIGHT
      body->Rotate(rotation_Versor);
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

//FLY
//It handle spaceship translation in the window
void spaceship::fly(float module){
  float direction = this->getDrawable()->getRotation() * PI / 180.0;
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

  body->Move(cos_module, sin_module);
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
  bullet *bul;
  for (std::list<bullet*>::iterator b = bullets.begin(); b != bullets.end(); b++){
    //std::cout << "position i: " << i << std::endl;
    bul = *b;
    //std::cout << "Does the bullet exist: " << !!bul << std::endl;
    if(!!bul){
      //std::cout << "real location of " << i << "^ bullet: " << bul << std::endl;
      bul->Update();
      bul->Draw(window);
    }
  }

  body->DrawTest(window);
}

//BUILD
//It build up the spaceship shape
/*void spaceship::build (){
  //creo quattro punti per la spezzata chiusa dell'astronave
  body->setPointCount(4);

  body->setPoint(2, sf::Vector2f(30.f, 0.f));
  body.setPoint(1, sf::Vector2f(0.f, 40.f));
  body.setPoint(3, sf::Vector2f(60.f, 40.f));
  body.setPoint(0, sf::Vector2f(30.f, 20.f));

  //creo il contorno della navicella colorata
  body.setOutlineThickness(2.f);
  body.setOutlineColor(sf::Color(000, 255, 000));
  body.setOrigin(30.f, 20.f);
  body.setPosition(80.f, 70.f);
  body.setScale(0.5f, 0.5f);

  //body.rotate(90);
}*/

void spaceship::Shoot(){

  bullet *bul = new bullet(spatial_Versor * 1.5f, this->getDrawable()->getRotation(), body->getBody()->getPosition());
  //std::cout << "real location c: " << bul << std::endl;
  playground->addAlly(bul);
  bullets.push_back(bul);
}
