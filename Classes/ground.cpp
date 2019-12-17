#include "ground.hpp"

//---------------CONSTRUCTORS---------------
ground::ground(float w, float h){
  this->body = new VertexArray(sf::LineStrip, 0);
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

std::string ground::Class(){
  return "ground";
}
