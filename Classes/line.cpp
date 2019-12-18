#include "line.hpp"

//---------------CONSTRUCTORS---------------
line::line(sf::Vector2f pnt1, sf::Vector2f pnt2){
  a = new sf::Vector2f(pnt1);
  b = new sf::Vector2f(pnt2);

  width = abs(a->x - b->x);
  height = abs(a->y - b->y);
}

line::~line(){
  std::cout << "DELETING LINE" << std::endl;

  a = nullptr, b = nullptr;
}


//---------------GETS---------------
float line::getWidth() { return width; }
float line::getHeight() { return height; }
sf::Vector2f line::getA() { return *a; }
sf::Vector2f line::getB() { return *b; }
sf::Vector2f* line::getptrA() { return a; }
sf::Vector2f* line::getptrB() { return b; }

//---------------SETS---------------
void line::setptrA(sf::Vector2f* pnt) {
  delete a;
  a = pnt;
  width = abs(a->x - b->x);
  height = abs(a->y - b->y);
}

void line::setptrB(sf::Vector2f* pnt) {
  a = pnt;
  width = abs(a->x - b->x);
  height = abs(a->y - b->y);
}



//---------------METHODS---------------

std::string line::Class(){
  return "line";
}
