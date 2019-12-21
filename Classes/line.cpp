#include "line.hpp"

//---------------CONSTRUCTORS---------------
line::line(sf::Vector2f pnt1, sf::Vector2f pnt2){
  a = new sf::Vector2f(pnt1);
  b = new sf::Vector2f(pnt2);

  width = abs(a->x - b->x);
  height = a->y - b->y;

  slope = width / height;
  float offset = (a->y - a->x) * slope;

  std::cout << "coffx: " << width << std::endl;
  std::cout << "coffy: " << height << std::endl;
  std::cout << "offset: " << offset << std::endl;
  coefficient = new sf::Vector3f(height, width, offset);

  int max_ordinate = b->y;
  if(a->y > b->y)
    max_ordinate = a->y;

  area = new sf::FloatRect(sf::Vector2f(a->x, max_ordinate), sf::Vector2f(width, height));

  height = abs(height);
}

line::~line(){
  std::cout << "DELETING LINE" << std::endl;

  a = nullptr, b = nullptr;
}


//---------------GETS---------------
float line::getWidth() { return width; }
float line::getSlope() { return slope; }
float line::getHeight() { return height; }
sf::Vector2f line::getA() { return *a; }
sf::Vector2f line::getB() { return *b; }
sf::Vector2f* line::getptrA() { return a; }
sf::Vector2f* line::getptrB() { return b; }
sf::Vector3f line::getCoefficient() { return *coefficient; }

//---------------SETS---------------
void line::setA(sf::Vector2f pnt) {
  *a = pnt;
  width = abs(a->x - b->x);
  height = abs(a->y - b->y);
}

void line::setptrA(sf::Vector2f* pnt) {
  a = pnt;
  width = abs(a->x - b->x);
  height = abs(a->y - b->y);
}

void line::setptrB(sf::Vector2f* pnt) {
  delete b;
  b = pnt;
  width = abs(a->x - b->x);
  height = abs(a->y - b->y);
}



//---------------METHODS---------------
/*
A(a1x + b1y = c1),	B(a2x + b2y = c2)
y = mx + q
q =
m = y/x - q
xs = (c1b2 - c2b1) / (a1b2 - a2b1), ys = (a1c2 - a2c1) / i(a1b2 - a2b1)
S(xs, ys)

checks to be done:
	-> a1b2 - a2b1 != 0
*/

sf::Vector2f line::intersect(line l){
  sf::Vector3f secondLine = l.getCoefficient();

  //line -> x0*x + y0*y = z0       |     sf::Vector3f(x0, y0, z0)
  if(this->slope != l.getSlope()){
    float x = (coefficient->x * secondLine.y - secondLine.x * coefficient->y) / (coefficient->z * secondLine.y - secondLine.z * coefficient->y);
    float y = (coefficient->x * secondLine.y - secondLine.x * coefficient->y) / (coefficient->x * secondLine.z - secondLine.x * coefficient->z);

    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;

    if(x >= 0 && y >= 0 )
      if(this->intersect(sf::Vector2f(x, y)))
        return sf::Vector2f(x, y);

  }
  return sf::Vector2f(-1, -1);
}

bool line::intersect(sf::Vector2f pnt){
  if(pnt == *a || pnt == *b)
    return true;

  float y = (pnt.y - a->y) / (b->y - a->y);
  float x = (pnt.x - a->x) / (b->x - a->x);

  std::cout << "area left: " << area->left << std::endl;
  std::cout << "area right: " << area->left + area->width << std::endl;
  std::cout << "area top: " << area->top << std::endl;
  std::cout << "area bottom: " << area->top + area->height << std::endl;
  std::cout << "contains point? " << area->contains(pnt) << std::endl;
  std::cout << "equal? " << (y==x) << std::endl;
  if(y == x && area->contains(pnt))
    return true;
  return false;
}


void line::swap(){
  sf::Vector2f* temp = a;
  a = b;
  b = temp;
}

std::string line::Class(){
  return "line";
}
