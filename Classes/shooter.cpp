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
//  auto blt = std::find(bullets.begin(), bullets.end(), b);
  bullets.remove(b);
  delete b;
  b = nullptr;

  std::cout << "bullets: ?!!" << this->bullets.size() << std::endl;
}

void shooter::deleteBullets(){ utility::deleteList(bullets); }

void shooter::shoot(){}

std::string shooter::Class(){
  return "shooter";
}
