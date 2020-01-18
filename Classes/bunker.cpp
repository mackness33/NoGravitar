#include "bunker.hpp"

//----------CONSTRUCTORS----------
bunker::bunker(/*playground* plg, sf::Texture* img,*/sf::Vector2f p){
  bullets = {};

  image = information::getImage("bunker");
  body = new movable<sf::Sprite>(image);
  sf::FloatRect bounds = this->GetLocalBounds();

  body->getBody()->setColor(sf::Color::White);

  body->SetScale(0.25f, 0.25f);
  body->SetPosition(p);
  body->SetOrigin(bounds.width/2, bounds.height/2);
}

bunker::~bunker(){
  std::cout << "DELETING BUNKER" << std::endl;

  bullets.clear();
}


//----------GETS----------
entity<sf::Sprite>* bunker::getEntity() { return body; }
sf::Sprite* bunker::getDrawable() { return body->getBody(); }
sf::FloatRect bunker::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect bunker::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }

//----------SETS----------

//----------METHODS----------
void bunker::Draw (sf::RenderWindow* window){
  body->DrawTest(window);
}

//TODO: randomize the color of the planets
void bunker::build(){
  body->getBody()->setColor(sf::Color::White);
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
