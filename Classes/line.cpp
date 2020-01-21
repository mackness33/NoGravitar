#include "line.hpp"

//---------------CONSTRUCTORS---------------
line::line(sf::Vector2f pnt1, sf::Vector2f pnt2){
  a = new sf::Vector2f(pnt1);
  b = new sf::Vector2f(pnt2);

  this->setup();
  //std::cout << "coffx: " << width << std::endl;
  //std::cout << "coffy: " << height << std::endl;
  //std::cout << "offset: " << offset << std::endl;
  //std::cout << "Q: " << Q << std::endl;
  //std::cout << "slope: " << slope << std::endl;
  //coefficient = new sf::Vector3f(height, width, offset);
  //coefficients = new sf::Vector2f(slope, Q);

  //int min_ordinate = b->y;
  //if(a->y < b->y)
    //min_ordinate = a->y;


  //std::cout << "NOT ERROR "  << std::endl;

  //area = new sf::FloatRect(sf::Vector2f(a->x, min_ordinate), sf::Vector2f(width, height));


}

line::~line(){
  std::cout << "DELETING LINE" << std::endl;

  a = nullptr, b = nullptr;
}


//---------------GETS---------------ù
//TODO:
float line::getWidth() { return width; }
double line::getSlope() { return slope; }
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

  setup();
}

void line::setB(sf::Vector2f pnt) {
  *b = pnt;

  setup();
}

void line::setptrA(sf::Vector2f* pnt) {
  a = pnt;

  setup();
}

void line::setptrB(sf::Vector2f* pnt) {
  delete b;
  b = pnt;

  setup();
}



//---------------METHODS---------------
void line::setup(){
  width = b->x - a->x;
  height = b->y - a->y;            //cause we're on the third quadrant

  if(width != 0)
    slope = height / width;
  else
    slope = -999999999;
  //float offset = (a->y - a->x) * slope;
  //float Q = a->y - (a->x * slope);


  height = abs(height);
  width = abs(width);
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
  int orn1 = orientation(*a, *b, p);
  int orn2 = orientation(*a, *b, q);
  int orn3 = orientation(p, q, *a);
  int orn4 = orientation(p, q, *b);

  // General case
  if (orn1 != orn2 && orn3 != orn4)
      return true;

  // Special Cases
  // a, b and p are colinear and p lies on segment ab
  if (orn1 == 0 && onSegment(*a, p, *b)) return true;

  // a, b and q are colinear and q lies on segment ab
  if (orn2 == 0 && onSegment(*a, q, *b)) return true;

  // p, q and a are colinear and a lies on segment pq
  if (orn3 == 0 && onSegment(p, *a, q)) return true;

   // p, q and b are colinear and b lies on segment pq
  if (orn4 == 0 && onSegment(p, *b, q)) return true;

  return false; // Doesn't fall in any of the above cases
}


void line::swap(){
  sf::Vector2f *temp = a;
  a = b;
  b = temp;
}

std::string line::Class(){
  return "line";
}
