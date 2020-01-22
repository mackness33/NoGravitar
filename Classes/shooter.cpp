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
  auto bul = std::find(bullets.begin(), bullets.end(), b);

  delete *bul;
  *bul = nullptr;
  bullets.erase(bul);
}

void shooter::deleteBullets(){
  for (auto bul = bullets.begin(); bul != bullets.end(); ){
    if(!!*bul)
      delete *bul;

    *bul = nullptr;
    bul = bullets.erase(bul);
  }
}

void shooter::shoot(){}

std::string shooter::Class(){
  return "shooter";
}
