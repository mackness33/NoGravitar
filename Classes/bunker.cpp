#include "bunker.hpp"

//----------CONSTRUCTORS----------
bunker::bunker(playground* plg, line l) : Playground(plg){
  image = information::getImage("bunker");
  body = new movable<sf::RectangleShape>(sf::Vector2f(50, 50), sf::Vector2f(400, 400), image);

  long double angle = utility::toDegrees(l.getSlope());
  float maxX = l.getA().x;
  float maxY = std::min(l.getA().y, l.getB().y);

  bullets = {};
  totalTime = 0;

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
  sf::Vector2f origin = body->getBody()->getPosition() - sf::Vector2f((this->GetLocalBounds().width * -sin(this->GetRotation())) / 2, (this->GetLocalBounds().height * cos(this->GetRotation())) / 2);
  bullet *bul1 = new bullet(this, information::BULLET_DEFAULT_SPEED, this->getDrawable()->getRotation() - 60, origin);
  bullets.push_front(bul1);

  bullet *bul2 = new bullet(this, information::BULLET_DEFAULT_SPEED, this->getDrawable()->getRotation() - 120, origin);
  bullets.push_front(bul2);

  Playground->addEnemy(bul1);
  Playground->addEnemy(bul2);
}

std::string bunker::Class(){
  return "bunker";
}
