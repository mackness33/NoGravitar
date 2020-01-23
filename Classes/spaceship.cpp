#define PI 3.14159265
#include "spaceship.hpp"

//----------CONSTRUCTORS----------
spaceship::spaceship(playground* plg, float spd, float dir){
  xOutOfBound = false;
  yOutOfBound = false;
  topOOB = false;
  leftOOB = false;

  speed = spd;
  angular_speed = dir;

  bullets = {};

  image = information::getImage("spaceship");

  body = new movable<sf::Sprite>(image);
  body->SetScale(0.25f, 0.25f);
  body->SetPosition(information::PLAYER_DEFAULT_POSITION);
  sf::FloatRect bounds = this->GetLocalBounds();
  body->SetOrigin(bounds.width/2, bounds.height/2);

  Playground = plg;
  //this->build();
}


spaceship::~spaceship(){
  std::cout << "DELETING SPACESHIP" << std::endl;

  if(!!body)
    delete body;

  image = nullptr;
  body = nullptr;
  Playground = nullptr;
}


//----------GETS----------
bool spaceship::getXOutOfBounds(){ return xOutOfBound;}
bool spaceship::getYOutOfBounds(){ return yOutOfBound;}
bool spaceship::getLeftOutOfBounds(){ return leftOOB;}
bool spaceship::getTopOutOfBounds(){ return topOOB;}
float spaceship::getSpatialVersor(){ return speed;}
float spaceship::getRotationVersor(){ return angular_speed;}
movable<sf::Sprite>* spaceship::getMovable() { return body; }
entity<sf::Sprite>* spaceship::getEntity() { return static_cast<entity<sf::Sprite>*> (body); }
sf::Sprite* spaceship::getDrawable() { return body->getBody(); }
sf::FloatRect spaceship::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect spaceship::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }
std::list<bullet*>* spaceship::getBullets() { return &bullets; }
//TODO: set texture to let the user change the spaceship image


//----------SETS----------
void spaceship::setXOutOfBounds(bool x){ xOutOfBound = x;}
void spaceship::setYOutOfBounds(bool y){ yOutOfBound = y;}
void spaceship::setLeftOutOfBounds(bool l){ leftOOB = l;}
void spaceship::setTopOutOfBounds(bool t){ topOOB = t;}
void spaceship::setSpatialVersor(float sv) { speed = sv;}
void spaceship::setRotationVersor(float rv) { angular_speed = rv;}
void spaceship::setPlayground(playground* pg) { Playground = pg;}
//void spaceship::setBody(sf::Sprite* b) { body = b;}

//----------METHODS----------
//MOVEMENT
//It lets the spaceship moves or rotates based on the key pressed
void spaceship::movement(sf::Keyboard::Key k){
  switch (k) {
    case sf::Keyboard::Left : {                 //LEFT
      body->Rotate(-angular_speed);
    };break;

    case sf::Keyboard::Right : {                //RIGHT
      body->Rotate(angular_speed);
    };break;

    case sf::Keyboard::Up : {                   //UP
      fly(speed);
    };break;

    case sf::Keyboard::Down : {                 //DOWN
      fly(-speed);
    };break;

    default: std::cout << "Not a movementCommand" << std::endl;
  }
}

//FLY
//It handles spaceship's translation in the window
void spaceship::fly(float module){
  float angle = this->getDrawable()->getRotation() * PI / 180.0;
  int sin_module = sin(angle) * module;
  int cos_module = cos(angle) * module;
  bool y_opp_dir = opposite_direction(topOOB,  sin(angle) * module);
  bool x_opp_dir = opposite_direction(leftOOB,  cos(angle) * module);

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
bool spaceship::opposite_direction(bool side, float angle){
  if(side){
    if(angle >= 0)
      return true;
  }
  else{
    if(angle <= 0)
      return true;
  }

  return false;
}

void spaceship::Draw (sf::RenderWindow* window){
  /*bullet *bul;
  for (std::list<bullet*>::iterator b = bullets.begin(); b != bullets.end(); b++){
    //std::cout << "position i: " << i << std::endl;
    bul = *b;
    //std::cout << "Does the bullet exist: " << !!bul << std::endl;
    if(!!bul){
      //std::cout << "real location of " << i << "^ bullet: " << bul << std::endl;
      bul->Update();
      bul->Draw(window);
    }
  }*/

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

float spaceship::GetRotation(){ return this->body->getBody()->getRotation(); }


void spaceship::shoot(){
  bullet *bul = new bullet(information::BULLET_DEFAULT_SPEED, this->getDrawable()->getRotation(), body->getBody()->getPosition());
  bullets.push_front(bul);

  Playground->addAlly(bul);
}

std::string spaceship::Class(){
  return "spaceship";
}
