#include "bunker.hpp"

//----------CONSTRUCTORS----------
bunker::bunker(playground* plg, line l, bool triple) : Playground(plg), living(1), BulletsxShooting(2), image(information::getImage("bunker")), totalTime(0){
  if(triple){
    image = information::getImage("bunker2");
    BulletsxShooting++;
  }

  body = new movable<sf::RectangleShape>(sf::Vector2f(50, 50), sf::Vector2f(400, 400), image);

  float maxX = l.getA().x;
  float maxY = std::min(l.getA().y, l.getB().y);

  sf::FloatRect bounds = this->GetLocalBounds();

  body->SetOrigin(bounds.width/2, bounds.height/2);
  body->SetRotation(-utility::toDegrees(l.getSlope()));
  body->SetPosition(sf::Vector2f((maxX + l.getWidth()/2) - ((bounds.width/2) * sin(l.getSlope())), (maxY + l.getHeight()/2) - ((bounds.height/2) * cos(l.getSlope()))));
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
  body->DrawTest(window);
}

void bunker::Update(){
  totalTime += information::DELTA_TIME;

  if(totalTime >= information::SHOOTER_SWITCH_TIME){
    totalTime -= information::SHOOTER_SWITCH_TIME;
    this->shoot();
  }
}

void bunker::shoot(){
  int range = 160/BulletsxShooting;
  bullet *bul = nullptr;

  for(int i = 0, angle = 160; i < BulletsxShooting; i++, angle -= range){
    bul = new bullet(this, information::BULLET_DEFAULT_SPEED, utility::RandFloat(range, this->getDrawable()->getRotation() - angle), body->GetPosition());// sf::Vector2f(bounds);
    bullets.push_front(bul);
    Playground->addEnemy(bul);
  }
}

std::string bunker::Class(){
  return "bunker";
}
