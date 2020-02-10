#include "points.hpp"

//---------------CONSTRUCTORS---------------
points::points(std::string f, unsigned int ip, sf::Vector2f p) : label(f, std::to_string(ip), p), totalPoint(ip) {}

points::~points(){
  std::cout << "DELETING POINTS" << std::endl;
}


//---------------GETS---------------
unsigned int points::getPoints(){ return totalPoint; }

//---------------METHODS---------------
void points::deathBunker(){ body->SetString(std::to_string(totalPoint += 250)); }
void points::deathPlanet(){ body->SetString(std::to_string(totalPoint += 2000)); }
void points::reset(){ body->SetString(std::to_string(totalPoint = 0)); }

std::string points::Class(){
  return "points";
}
