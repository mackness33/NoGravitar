#include "bunker.hpp"

//----------CONSTRUCTORS----------
bunker::bunker(/*playground* plg, sf::Texture* img,*/line l){
  image = information::getImage("bunker");
  body = new movable<sf::RectangleShape>(sf::Vector2f(50, 50), sf::Vector2f(400, 400), image);

  long double angle = utility::toDegrees(l.getSlope());
  float maxX = l.getA().x;
  float maxY = std::min(l.getA().y, l.getB().y);

  bullets = {};

  sf::FloatRect bounds = this->GetLocalBounds();

  body->SetOrigin(bounds.width/2, bounds.height/2);
  body->SetRotation(-angle);
  body->SetPosition(sf::Vector2f((maxX + l.getWidth()/2) - ((bounds.width/2) * sin(l.getSlope())), (maxY + l.getHeight()/2) - ((bounds.height/2) * cos(l.getSlope()))));
  //body->SetPosition(lines[0]->intersection(line(utility::left(bunkers), utility::bottom(bunkers))));
}



bunker::~bunker(){
  std::cout << "DELETING BUNKER" << std::endl;

  bullets.clear();
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

void bunker::deleteBullet(bullet* b){
  auto bul = std::find(bullets.begin(), bullets.end(), b);
  delete *bul;
  *bul = nullptr;
  bullets.erase(bul);
}

void bunker::shoot(){
  bullet *bul = new bullet(information::BULLET_DEFAULT_SPEED, this->getDrawable()->getRotation(), body->getBody()->getPosition());
  //std::cout << "real location c: " << bul << std::endl;
  //Playground->addEnemy(bul);
  bullets.push_front(bul);
}

std::string bunker::Class(){
  return "bunker";
}
