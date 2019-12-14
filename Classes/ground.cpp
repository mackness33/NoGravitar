#include "ground.hpp"

//---------------CONSTRUCTORS---------------
ground::ground(float w, float h){

  std::vector<sf::Vector2f*> vtxPosition = {};

  for(int)
  sf::Vector2f position;

  //body = new movable<sf::VertexArray>(5);
  this->build();
}

ground::~ground(){
  std::cout << "DELETING GROUND" << std::endl;

  delete body;
  body = nullptr;
}


//---------------GETS---------------
entity<sf::VertexArray>* ground::getEntity() { return static_cast<entity<sf::VertexArray>*> (body); }
sf::VertexArray* ground::getDrawable() { return body->getBody(); }
sf::FloatRect ground::GetBounds() { return body->getBody()->getBounds(); }
sf::FloatRect ground::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }

//---------------SETS---------------



//---------------METHODS---------------

void ground::Draw (sf::RenderWindow* window){
  body->DrawTest(window);
}

void ground::build(){
  body->getBody()->setFillColor(sf::Color::Green);
  //body->getBody()->setSmooth(true);
}

std::string ground::Class(){
  return "ground";
}
