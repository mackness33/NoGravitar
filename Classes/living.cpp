#include "living.hpp"

//---------------CONSTRUCTORS---------------
living::living(int l) : life(l) {}

living::~living() {}

//---------------METHODS---------------
bool living::isAlive(){ return (life > 0) ? true : false; }
void living::rip(){ life--; }

std::string living::Class(){
  return "living";
}
