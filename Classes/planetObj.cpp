#include "planetObj.hpp"

//----------CONSTRUCTORS----------
planetObj::planetObj(float r, sf::Vector2f p){
  body = new entity<sf::CircleShape>(r);
  view = nullptr;

  body->SetPosition(p);
}

planetObj::~planetObj(){
  std::cout << "DELETING PLANETOBJ" << std::endl;


  std::cout << "!view: " << !view << std::endl;
  std::cout << "!!view: " << !!view << std::endl;
  if(!!view){
    std::cout << "View does existed!!!" << std::endl;
    delete view;
  }
  view = nullptr;

  std::cout << "!body: " << !body << std::endl;
  std::cout << "!!body: " << !!body << std::endl;
  if(!!body){
    std::cout << "Body does existed!!!" << std::endl;
    delete body;
  }
  body = nullptr;
}


//----------GETS----------
entity<sf::CircleShape>* planetObj::getEntity() { return body; }
sf::CircleShape* planetObj::getDrawable() { return body->getBody(); }
sf::FloatRect planetObj::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect planetObj::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }
planetView* planetObj::getPlanetView() { return view; }

//----------SETS----------
void planetObj::setPlanetView(planetView* newView){ view = newView; }

//----------METHODS----------
void planetObj::Draw (sf::RenderWindow* window){
  body->DrawTest(window);
}

bool planetObj::spawnIntersects(drawable* obj){
  sf::FloatRect bounds = obj->GetGlobalBounds();
  sf::FloatRect spawningBounds (sf::Vector2f(bounds.left - 20, bounds.top - 20), sf::Vector2f(bounds.width + 40, bounds.height + 40));

  return spawningBounds.intersects(this->GetGlobalBounds());
}

//TODO: randomize the color of the planets
void planetObj::build(){
  body->getBody()->setFillColor(sf::Color::White);
}

std::string planetObj::Class(){
  return "planetObj";
}
