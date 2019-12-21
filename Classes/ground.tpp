#include "ground.hpp"

//---------------METHODS---------------
//TODO: selection of the SECT is more difficult, need to know exacly where's the points
//      Probably using a binary search
//BUG: You can't check only the bottom, if movable or if the object has been rotated we need to check the most bottom point
template <typename T> bool ground::intersects (drawable* obj){
  entity *objBody = static_cast<entity<T>>(obj.getEntity);
  sf::FloatRect objBound = obj->GetGlobalBounds();
  sf::Vector2f left = objBody->left();
  sf::Vector2f bottom = objBody->bottom();
  line *ptr = new line(left, bottom);
  int sectLeft = objBound.left / length, sectRight = ptr->getA() / length;

  //TODO: Implementation "intersection line-line and line-point"
  if(sectLeft != sectRight){

    lines[sectLeft].intersects(*ptr);

    ptr->swap();
    ptr->setA(objBody->right());
    lines[sectRight].intersects(*ptr);
    //TODO: Need to check also between the Left and Left + Width
    intersection(sf::Vector2f(objBound.top + objBound.height, objBound.left), lines[sectLeft]);
  }
  else{
    if(lines[sectLeft].getA().y >= lines[sectLeft].getB().y)
      lines[sectLeft].intersects(*ptr);
    else{
      ptr->swap();
      ptr->setA(objBody->right());
      lines[sectLeft].intersects(*ptr);
    }
  }
  return false;
}
