#include "ground.hpp"

//---------------METHODS---------------
//TODO: selection of the SECT is more difficult, need to know exacly where's the points
//      Probably using a binary search
//BUG: You can't check only the bottom, if movable or if the object has been rotated we need to check the most bottom point
template <typename T> bool ground::intersects (drawable* obj){
  return false;
}
