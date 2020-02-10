#include "living.hpp"

//---------------CONSTRUCTORS---------------
living::living(int l) : life(l) {}

living::~living(){
  std::cout << "DELETING LIVING" << std::endl;
}


//---------------GETS---------------
bool living::isAlive(){ return (life > 0) ? true : false; }

//---------------METHODS---------------
void living::rip(){ life--; }

std::string living::Class(){
  return "living";
}
