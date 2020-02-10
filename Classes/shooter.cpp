#include "shooter.hpp"

//------------CONSTRUCTORS------------
shooter::shooter(){}

//------------DESTRUCTORS------------
shooter::~shooter(){
  std::cout << "DELETING SHOOTER" << std::endl;

  this->deleteBullets();
}

//------------GETS------------


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
