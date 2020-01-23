#include "shooter.hpp"

//------------CONSTRUCTORS------------
shooter::shooter(){}

//------------DESTRUCTORS------------
shooter::~shooter(){
  std::cout << "DELETING SHOOTER" << std::endl;
}

//------------GETS------------


//------------METHODS------------
void shooter::deleteBullet(bullet* b){
  delete b;
  b = nullptr;
  bullets.remove(b);
}

void shooter::deleteBullets(){ utility::deleteList(bullets); }

void shooter::shoot(){}

std::string shooter::Class(){
  return "shooter";
}
