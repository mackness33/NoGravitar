#include "ground.hpp"

//---------------METHODS---------------
//TODO:selection of the SECT is more difficult, need to know exacly where's the points
//      Probably using a binary search
template <typename T> bool ground::intersects (drawable* obj){
  sf::FloatRect objBound = ((obj->getEssence())<T>)->getBounds();
  int sectLeft = objBound.left / length, sectRight = (objBound.left + objBound.width) / length;
  //if(sectLeft != sectRight){

  //}


}
