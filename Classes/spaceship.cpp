#define PI 3.14159265
#include "spaceship.hpp"

//----------CONSTRUCTORS----------
spaceship::spaceship(playground* plg, float spd, float dir) : xOutOfBound(false), yOutOfBound(false), topOOB(false), leftOOB(false), speed(spd), angular_speed(dir), image(information::getImage("spaceship")), Playground(plg), tb(false){
  body = new movable<sf::RectangleShape>(information::PLAYER_DEFAULT_SIZE, information::PLAYER_DEFAULT_POSITION, image);
  //body->SetScale(0.25f, 0.25f);
  sf::FloatRect bounds = this->GetLocalBounds();
  body->SetOrigin(bounds.width/2, bounds.height/2);
  TractorBeam = new tractorBeam();
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
movable<sf::RectangleShape>* spaceship::getMovable() { return body; }
entity<sf::RectangleShape>* spaceship::getEntity() { return static_cast<entity<sf::RectangleShape>*> (body); }
sf::RectangleShape* spaceship::getDrawable() { return body->getBody(); }
sf::FloatRect spaceship::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect spaceship::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }
std::list<bullet*>* spaceship::getBullets() { return &bullets; }
playground* spaceship::getPlayground() { return Playground; }
tractorBeam* spaceship::getTractorBeam(){ return TractorBeam;}
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

  this->Move(sf::Vector2f(cos_module, sin_module));
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
  if(tb)
    TractorBeam->Draw(window);
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
void spaceship::setTractorPosition(){
  sf::Vector2f p = body->GetPosition();
  TractorBeam->getEntity()->SetPosition(sf::Vector2f(p.x - (information::TRACTORBEAM_DEFAULT_SIZE.x - information::PLAYER_DEFAULT_SIZE.x)/2, p.y));
}

// void spaceship::attractFuels(std::list){
//   for(auto f = fuels.begin(); f != f.end(); i++)
//     if(f->intersects(trb))
//       currentGame->deathBunker();
// }

void spaceship::Move(sf::Vector2f pos){
  body->Move(pos);
  TractorBeam->getMovable()->Move(pos);
}

void spaceship::SetPosition(sf::Vector2f pos){
  body->SetPosition(pos);
  TractorBeam->getMovable()->SetPosition(sf::Vector2f(pos.x - (information::TRACTORBEAM_DEFAULT_SIZE.x - information::PLAYER_DEFAULT_SIZE.x)/2, pos.y));
}

void spaceship::shoot(){
  bullet *bul = new bullet(this, information::BULLET_DEFAULT_SPEED, this->getDrawable()->getRotation(), body->getBody()->getPosition());
  bullets.push_front(bul);

  Playground->addAlly(bul);
}

void spaceship::attract(){ tb = !tb; }

std::string spaceship::Class(){
  return "spaceship";
}
