#include "line.hpp"

//---------------CONSTRUCTORS---------------
line::line(sf::Vector2f pnt1, sf::Vector2f pnt2){
  a = new sf::Vector2f(pnt1);
  b = new sf::Vector2f(pnt2);

  width = b->x - a->x;
  height = b->y - a->y;            //cause we're on the third quadrant

  if(width != 0)
    slope = height / width;
  else
    slope = -999999999;
  float offset = (a->y - a->x) * slope;
  float Q = a->y - (a->x * slope);


  std::cout << "coffx: " << width << std::endl;
  std::cout << "coffy: " << height << std::endl;
  //std::cout << "offset: " << offset << std::endl;
  std::cout << "Q: " << Q << std::endl;
  std::cout << "slope: " << slope << std::endl;
  coefficient = new sf::Vector3f(height, width, offset);
  coefficients = new sf::Vector2f(slope, Q);

  int min_ordinate = b->y;
  if(a->y < b->y)
    min_ordinate = a->y;

  height = abs(height);

  std::cout << "NOT ERROR "  << std::endl;

  area = new sf::FloatRect(sf::Vector2f(a->x, min_ordinate), sf::Vector2f(width, height));


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
sf::Vector2f line::getCoefficients() { return *coefficients; }

//---------------SETS---------------
void line::setA(sf::Vector2f pnt) {
  *a = pnt;
  //width = abs(a->x - b->x);
  //height = abs(a->y - b->y);

  width = a->x - b->x;
  height = a->y - b->y;

  slope = height / width;
  coefficients->y = a->y - (a->x * slope);
  coefficients->x = slope;
}

void line::setptrA(sf::Vector2f* pnt) {
  a = pnt;
  //width = abs(a->x - b->x);
  //height = abs(a->y - b->y);

  width = a->x - b->x;
  height = a->y - b->y;
  slope = height / width;
  coefficients->y = a->y - (a->x * slope);
  coefficients->x = slope;
}

void line::setptrB(sf::Vector2f* pnt) {
  delete b;
  b = pnt;
  //width = abs(a->x - b->x);
  //height = abs(a->y - b->y);

  width = a->x - b->x;
  height = a->y - b->y;

  slope = height / width;
  coefficients->y = a->y - (a->x * slope);
  coefficients->x = slope;
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

//BUG: x and y are not right! Need to be fixed
sf::Vector2f line::intersect(line l){
  sf::Vector2f secondLine = l.getCoefficients();

  //line -> x0*x + y0*y = z0       |     sf::Vector3f(x0, y0, z0)
  if(this->slope != l.getSlope()){
    //float x = (coefficient->z * secondLine.y - secondLine.z * coefficient->y) / (coefficient->x * secondLine.y - secondLine.x * coefficient->y);
    float x = (secondLine.y - coefficients->y) / (coefficients->x - secondLine.x);
    //float y = (coefficient->x * secondLine.z - secondLine.x * coefficient->z) / (coefficient->x * secondLine.y - secondLine.x * coefficient->y);
    float y = (coefficients->x * x) + coefficients->y;

    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;

    if(x >= 0 && y >= 0 ){
      std::cout << "point intersection x: " << this->intersect(sf::Vector2f(x, y)) << std::endl;
      if(this->intersect(sf::Vector2f(x, y)))
        return sf::Vector2f(x, y);
    }

  }
  return sf::Vector2f(-1, -1);
}

bool line::intersect(sf::Vector2f pnt){
  if(pnt == *a || pnt == *b)
    return true;

  //float y = (pnt.y - a->y) / (b->y - a->y);
  float y = pnt.y;
  float x = slope * pnt.x + coefficients->y;


  std::cout << "area left: " << area->left << std::endl;
  std::cout << "area right: " << area->left + area->width << std::endl;
  std::cout << "area top: " << area->top << std::endl;
  std::cout << "area bottom: " << area->top + area->height << std::endl;


  std::cout << "point y: " << pnt.y << std::endl;
  std::cout << "point x: " << pnt.x << std::endl;
  std::cout << "contains point? " << area->contains(pnt) << std::endl;
  std::cout << "equal? " << (y==x) << std::endl;

  if(y == x && area->contains(pnt))
    return true;
  return false;
}

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool line::onSegment(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r)
{
  if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
    q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
   return true;

    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int line::orientation(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r)
{
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'ab'
// and 'pq' intersect.
bool line::doIntersect(line* l){
  sf::Vector2f p = l->getA(), q = l->getB();

  // Find the four orientations needed for general and
  // special cases
  int o1 = orientation(*a, *b, p);
  int o2 = orientation(*a, *b, q);
  int o3 = orientation(p, q, *a);
  int o4 = orientation(p, q, *b);

  // General case
  if (o1 != o2 && o3 != o4)
      return true;

  // Special Cases
  // a, b and p are colinear and p lies on segment ab
  if (o1 == 0 && onSegment(*a, p, *b)) return true;

  // a, b and q are colinear and q lies on segment ab
  if (o2 == 0 && onSegment(*a, q, *b)) return true;

  // p, q and a are colinear and a lies on segment pq
  if (o3 == 0 && onSegment(p, *a, q)) return true;

   // p, q and b are colinear and b lies on segment pq
  if (o4 == 0 && onSegment(p, *b, q)) return true;

  return false; // Doesn't fall in any of the above cases
}


void line::swap(){
  sf::Vector2f* temp = a;
  a = b;
  b = temp;
}

std::string line::Class(){
  return "line";
}
