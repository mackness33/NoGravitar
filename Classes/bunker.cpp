#include "bunker.hpp"

//----------CONSTRUCTORS----------
bunker::bunker(playground* plg, line l, bool triple) : Playground(plg), living(1), BulletsxShooting(2){
  image = information::getImage("bunker2");
  body = new movable<sf::RectangleShape>(sf::Vector2f(50, 50), sf::Vector2f(400, 400), image);

  long double angle = utility::toDegrees(l.getSlope());
  float maxX = l.getA().x;
  float maxY = std::min(l.getA().y, l.getB().y);

  bullets = {};
  totalTime = 0;

  if(triple)
    BulletsxShooting++;

  sf::FloatRect bounds = this->GetLocalBounds();

  body->SetOrigin(bounds.width/2, bounds.height/2);
  body->SetRotation(-angle);
  body->SetPosition(sf::Vector2f((maxX + l.getWidth()/2) - ((bounds.width/2) * sin(l.getSlope())), (maxY + l.getHeight()/2) - ((bounds.height/2) * cos(l.getSlope()))));
  //body->SetPosition(lines[0]->intersection(line(utility::left(bunkers), utility::bottom(bunkers))));
}



bunker::~bunker(){
  std::cout << "DELETING BUNKER" << std::endl;
  if(!!body)
    delete body;

  body = nullptr;
  Playground = nullptr;
  image = nullptr;

  this->deleteBullets();
}


//----------GETS----------
entity<sf::RectangleShape>* bunker::getEntity() { return body; }
sf::RectangleShape* bunker::getDrawable() { return body->getBody(); }
sf::FloatRect bunker::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect bunker::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }

//----------SETS----------

//----------METHODS----------
// bool bunker::isAlive (){ return life; }
// void bunker::rip (){ life = false;}

void bunker::Draw (sf::RenderWindow* window){
  body->DrawTest(window);
}

//TODO: randomize the color of the planets
void bunker::build(){
  //body->getBody()->setColor(sf::Color::White);
}

void bunker::Update(){
  totalTime += information::DELTA_TIME;

  if(totalTime >= information::SHOOTER_SWITCH_TIME){
    totalTime -= information::SHOOTER_SWITCH_TIME;
    this->shoot();
  }
}

void bunker::shoot(){
  // sf::FloatRect bounds = this->GetLocalBounds();
  // sf::Vector2f origin = this->GetPosition();
  // sf::Vector2f origin = body->getBody()->getPosition() - sf::Vector2f((this->GetLocalBounds().width * -sin(this->GetRotation())) / 2, (this->GetLocalBounds().height * cos(this->GetRotation())) / 2);

  int range = 160/BulletsxShooting;
  bullet *bul = nullptr;
  for(int i = 0, angle = 160; i < BulletsxShooting; i++, angle -= range){
    bul = new bullet(this, information::BULLET_DEFAULT_SPEED, utility::RandFloat(range, this->getDrawable()->getRotation() - angle), body->GetPosition());// sf::Vector2f(bounds);
    bullets.push_front(bul);
    Playground->addEnemy(bul);
  }

  // bullet *bul2 = new bullet(this, information::BULLET_DEFAULT_SPEED, utility::RandFloat(60, this->getDrawable()->getRotation() - 90), body->GetPosition());
  // bullets.push_front(bul2);
  //
  // Playground->addEnemy(bul2);
}

std::string bunker::Class(){
  return "bunker";
}
