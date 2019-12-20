#include "ground.hpp"

//---------------METHODS---------------
//TODO: selection of the SECT is more difficult, need to know exacly where's the points
//      Probably using a binary search
//BUG: You can't check only the bottom, if movable or if the object has been rotated we need to check the most bottom point
template <typename T> bool ground::intersects (drawable* obj){
  sf::FloatRect objBound = obj->GetGlobalBounds();
  line *ptr = new line(sf::Vector2f(objBound.left, objBound.top + objBound.height));
  int sectLeft = objBound.left / length, sectRight = ptr->getA() / length;

  //TODO: Implementation "intersection line-line and line-point"
  if(sectLeft != sectRight){

    lines[sectLeft].intersects()
    //TODO: Need to check also between the Left and Left + Width
    intersection(sf::Vector2f(objBound.top + objBound.height, objBound.left), lines[sectLeft], monotony);
  }

  //if(!intersection)
    //intersectionPoint(sf::Vector2f(objBound.top + objBound.height, objBound.left + objBound.width), lines[sectRight], monotony);

  return false;
}
