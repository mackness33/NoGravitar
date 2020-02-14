#include "shooter.hpp"
#include "utility.hpp"

//------------CONSTRUCTORS------------
shooter::shooter(){}

//------------DESTRUCTORS------------
shooter::~shooter(){ this->deleteBullets(); }

//------------METHODS------------
void shooter::deleteBullet(bullet* b){
  bullets.remove(b);
  delete b;
  b = nullptr;
}

void shooter::deleteBullets(){ utility::deleteList(bullets); }

void shooter::shoot(){}

std::string shooter::Class(){
  return "shooter";
}
