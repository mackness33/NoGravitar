#include "ground.hpp"

//---------------CONSTRUCTORS---------------
ground::ground(int w, int h, sf::Color c){
  std::vector<sf::Vector2f*> vtxPosition = {};
  int numVertex = utility::RandInt(10, 5);
  int sectionY = h * (settings::MAX_GROUND_HEIGHT - settings::MIN_GROUND_HEIGHT);
  float offsetY = settings::MIN_GROUND_HEIGHT;
  float length = w / numVertex;

  std::cout << "NUMVERTEX" << numVertex << ": " << numVertex << std::endl;
  for(int i = 0, lastPos = 0; i < numVertex; i++, lastPos += length){
    float x = utility::RandInt(length, lastPos), y = h - utility::RandFloat(sectionY, offsetY);
    std::cout << "Position x" << i << ": " << x << std::endl;
    std::cout << "Position y" << i << ": " << y << std::endl;
    vtxPosition.push_back(new sf::Vector2f(x, y));
  }

  body = new line<sf::VertexArray>(numVertex, vtxPosition);
  std::cout << "Position ?" << std::endl;
}

ground::~ground(){
  std::cout << "DELETING GROUND" << std::endl;

  delete body;
  body = nullptr;
}


//---------------GETS---------------
line<sf::VertexArray>* ground::getLine() { return body; }
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
