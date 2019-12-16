#include "ground.hpp"

//---------------CONSTRUCTORS---------------
ground::ground(float w, float h, sf::Color c){
  std::vector<sf::Vector2f*> vtxPosition = {};
  int numVertex = utility::Rand(10, 5);
  int sectionY = h * (settings::MAX_GROUND_HEIGHT - settings::MIN_GROUND_HEIGHT);
  int offsetY = settings::MIN_GROUND_HEIGHT;
  int length = w / numVertex;

  for(int i = 0, lastPos = 0; i < numVertex; i++, lastPos += length){
    int x = utility::Rand(length, lastPos), y = utility::Rand(sectionY, offsetY);
    std::cout << "Position x" << i << ": " << x << std::endl;
    std::cout << "Position y" << i << ": " << y << std::endl;
    vtxPosition.push_back(new sf::Vector2f(x, y));
  }

  body = new line<sf::VertexArray>(numVertex, vtxPosition);
}

ground::~ground(){
  std::cout << "DELETING GROUND" << std::endl;

  delete body;
  body = nullptr;
}


//---------------GETS---------------
line<sf::VertexArray>* ground::getLine() { return line<sf::VertexArray>* (body); }
entity<sf::VertexArray>* ground::getEntity() { return static_cast<entity<sf::VertexArray>*> (body); }
sf::VertexArray* ground::getDrawable() { return body->getBody(); }
sf::FloatRect ground::GetGlobalBounds() { return body->getBody()->getBounds(); }

//---------------SETS---------------



//---------------METHODS---------------

void ground::Draw (sf::RenderWindow* window){
  body->DrawTest(window);
}

std::string ground::Class(){
  return "ground";
}
