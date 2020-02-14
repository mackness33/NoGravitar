#include "line.hpp"

//---------------CONSTRUCTORS---------------
line::line(sf::Vector2f pnt1, sf::Vector2f pnt2){
  a = new sf::Vector2f(pnt1);
  b = new sf::Vector2f(pnt2);

  this->setup();
}

line::~line(){ a = nullptr, b = nullptr; }


//---------------GETS---------------
float line::getWidth() { return width; }
long double line::getSlope() { return slope; }
float line::getHeight() { return height; }
sf::Vector2f line::getA() { return *a; }
sf::Vector2f line::getB() { return *b; }
sf::Vector2f* line::getptrA() { return a; }
sf::Vector2f* line::getptrB() { return b; }

//---------------SETS---------------
void line::setA(sf::Vector2f pnt) { *a = pnt; setup(); }

void line::setB(sf::Vector2f pnt) {*b = pnt; setup(); }

void line::setptrA(sf::Vector2f* pnt) {a = pnt; setup(); }

void line::setptrB(sf::Vector2f* pnt) { delete b; b = pnt; setup(); }



//---------------METHODS---------------
void line::setup(){
  long double w = (long double)(b->x - a->x);
  long double h = (long double)-(b->y - a->y);            //cause we're on the forth quadrant

  if(w != 0)
    slope =  h / w;
  else
    slope = -999999999999999999;

  height = abs(h);
  width = abs(w);
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
