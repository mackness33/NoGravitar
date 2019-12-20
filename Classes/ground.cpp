#include "ground.hpp"

//---------------CONSTRUCTORS---------------
ground::ground(float w, float h, sf::Color c){
  int sectionY = h * (settings::MAX_GROUND_HEIGHT - settings::MIN_GROUND_HEIGHT);
  sf::Vector2f *lastPoint = nullptr, *actualPoint = nullptr;
  line *L = nullptr;

  numVertex = utility::RandInt(10, 5);
  offsetY = settings::MIN_GROUND_HEIGHT;
  length = w / numVertex;

  lastPoint = new sf::Vector2f(0, (h - utility::RandFloat(sectionY, offsetY)));

  std::cout << "NUMVERTEX" << numVertex << ": " << numVertex << std::endl;

  for(int i = 1, lastPos = 0; i < numVertex-1; i++, lastPos += length, *lastPoint = *actualPoint){
    actualPoint = new sf::Vector2f(utility::RandInt(length, lastPos), h - utility::RandFloat(sectionY, offsetY));

    L = new line(*lastPoint, *actualPoint);

    if(i > 1)
      L->setptrA(lines.back()->getptrB());

    lines.push_back(L);
  }

  actualPoint = new sf::Vector2f(w, (h - utility::RandFloat(sectionY, offsetY)));
  L = new line(*lastPoint, *actualPoint);
  L->setptrA(lines.back()->getptrB());
  lines.push_back(L);

  body = new shape<sf::VertexArray>(numVertex, lines);
  //std::cout << "FORGING GROUND" << std::endl;
}

ground::~ground(){
  std::cout << "DELETING GROUND" << std::endl;

  delete body;
  body = nullptr;
}


//---------------GETS---------------
shape<sf::VertexArray>* ground::getLine() { return body; }
sf::VertexArray* ground::getDrawable() { return body->getBody(); }
sf::FloatRect ground::GetGlobalBounds() { return body->getBody()->getBounds(); }

//---------------SETS---------------



//---------------METHODS---------------
bool ground::getMonotony(int sect){
  //sf::Vector2f* A = lines[sect].getA();
  //sf::Vector2f* B = lines[sect].getB();

  //if(A.y <= B.y)
    //return true;
  return false;
}

bool ground::intersectionPoint(sf::Vector2f* pnt, line* sect, bool monotony){

  //if(monotony)
}

void ground::Draw (sf::RenderWindow* window){
  body->Draw(window);
}

std::string ground::Class(){
  return "ground";
}
