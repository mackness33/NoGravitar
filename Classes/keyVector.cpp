#include "keyVector.hpp"

//----------CONSTRUCTORS----------
keyVector::keyVector(sf::Keyboard::Key k/*ey*/, bool t/*ransfomation*/){
  key = k;
  transformation = t;
}

keyVector::keyVector(){
  key = sf::Keyboard::Unknown;
  transformation = false;
}

//copy constructor
keyVector::keyVector(const keyVector& V){
  key = V.key;
  transformation = V.transformation;
}

//----------OPERATORS----------
keyVector& keyVector::operator= (const keyVector& V){
  key = V.key;
  transformation = V.transformation;

  return *this;
}

//----------GETS----------
sf::Keyboard::Key keyVector::getKey(){ return key;}
bool keyVector::getTransformation(){ return transformation; }

//----------SETS----------
void keyVector::setKey(sf::Keyboard::Key k) { key = k;}
void keyVector::setTransformation(bool t) { transformation = t;}

//----------METHODS----------
//the method understand which key has been pressed and sets the boolean for the smoothness of the trasformation
void keyVector::isUsed(sf::Keyboard::Key key1, sf::Keyboard::Key key2){
  if(sf::Keyboard::isKeyPressed(key1) || sf::Keyboard::isKeyPressed(key2)){
    transformation = true;

    if(sf::Keyboard::isKeyPressed(key1))
      key = key1;            //KEY1
    else
      key = key2;            //KEY2
  }
}

std::string keyVector::Class(){
  return "keyVector";
}
