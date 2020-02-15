#include "bunker.hpp"
#include "information.hpp"
#include "utility.hpp"

//----------CONSTRUCTORS----------
bunker::bunker(playground* plg, line l, bool type) : Playground(plg), living(information::BUNKER_DEFAULT_LIFES), BulletsxShooting(information::BUNKER_DEFAULT_BULLETSXSHOOTING), image(information::getImage("bunker")), totalTime(0){
  if(type){                                       //type is a bool to understand the type of the bunker
    image = information::getImage("bunker2");
    BulletsxShooting++;     //number of bullets to shoot
  }

  body = new movable<sf::RectangleShape>(information::BUNKER_DEFAULT_SIZE, sf::Vector2f(-1, -1), image);

  this->inizialization(l);
}



bunker::~bunker(){
  if(!!body)
    delete body;

  body = nullptr;
  Playground = nullptr;
  image = nullptr;
}


//----------GETS----------
entity<sf::RectangleShape>* bunker::getEntity() { return body; }
sf::RectangleShape* bunker::getDrawable() { return body->getBody(); }
sf::FloatRect bunker::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect bunker::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }

//----------METHODS----------
void bunker::Draw (sf::RenderWindow* window){
  body->Draw(window);
}

//delta and switch time help to calculate the time between the shootes
void bunker::Update(){
  totalTime += information::DELTA_TIME;

  if(totalTime >= information::SHOOTER_SWITCH_TIME){
    totalTime -= information::SHOOTER_SWITCH_TIME;
    this->shoot();
  }
}


// setPosition() : it calculates the angle of the linw in which he is over
// basically it gets the position of the center of the line, then it calculates the angle of the line with sin(slope_of_line)
// than it shift the object a bit to let it stay OVER it, and not ON it
void bunker::inizialization(line l){
  float maxX = l.getA().x;
  float maxY = std::min(l.getA().y, l.getB().y);
  sf::FloatRect bounds = this->GetLocalBounds();

  body->SetOrigin(bounds.width/2, bounds.height/2);
  body->SetRotation(-utility::toDegrees(l.getSlope()));
  body->SetPosition(sf::Vector2f((maxX + l.getWidth()/2) - ((bounds.width/2) * sin(l.getSlope())), (maxY + l.getHeight()/2) - ((bounds.height/2) * cos(l.getSlope()))));
}


void bunker::shoot(){
  int range = 160/BulletsxShooting;     //max angle of bullets direction
  bullet *bul = nullptr;

  for(int i = 0, angle = 160; i < BulletsxShooting; i++, angle -= range){
    bul = new bullet(this, information::BULLET_DEFAULT_SPEED, utility::RandFloat(range, this->getDrawable()->getRotation() - angle), body->GetPosition(), sf::Color::Red);// sf::Vector2f(bounds);
    bullets.push_front(bul);
    Playground->addEnemy(bul);
  }
}

std::string bunker::Class(){
  return "bunker";
}
