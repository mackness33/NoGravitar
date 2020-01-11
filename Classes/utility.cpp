#include "utility.hpp"

float utility::deltaTime ; // You MUST declare it in a CPP
float utility::switchTime ; // You MUST declare it in a CPP

//----------CONSTRUCTORS----------
//probably I don't need it
utility::utility(){

}

//----------GETS----------
//sf::Sprite getBackground(){ return this->background;}

//----------SETS----------
//void setTexture(sf::Texture t){ this->background.setTexture(t);}

//----------METHODS----------
float utility::toRadiant(float deg){ return deg * PI / 180.0f; }
float utility::toDegrees(float rad){ return rad * 180.0f / PI; }
int utility::Proportion(int a, int b, int c){ return c * b / a; }
int utility::RandInt(int x, int y){ return rand() % x + y; }
float utility::RandFloat(int x, float y){ return rand() % x + y; }
sf::Vector2f utility::RandVector(int x, int y, int offsetX, int offsetY){ return sf::Vector2f(rand() % x + offsetX, rand() % y + offsetY); }

sf::Vector2f utility::left(drawable *obj){
  sf::FloatRect glbBound = obj->GetGlobalBounds();
  sf::FloatRect lclBound = obj->GetLocalBounds();
  float param = 2 * (((int)obj->GetRotation()) % 90) - 90;
  float x = glbBound.left;
  float y = glbBound.top + (glbBound.height / 2) - (lclBound.height / 2) * sin(param * PI / 180);

  return sf::Vector2f(x, y);
}

sf::Vector2f utility::right(drawable* obj){
  sf::FloatRect glbBound = obj->GetGlobalBounds();
  sf::FloatRect lclBound = obj->GetLocalBounds();
  float param = 2 * (((int)obj->GetRotation()) % 90) - 90;
  float x = glbBound.left + glbBound.width;
  float y = glbBound.top + (glbBound.height / 2) - (lclBound.height / 2) * -sin(param * PI / 180);
  return sf::Vector2f(x, y);
}

sf::Vector2f utility::top(drawable* obj){
  sf::FloatRect glbBound = obj->GetGlobalBounds();
  sf::FloatRect lclBound = obj->GetLocalBounds();
  float param = 2 * (((int)obj->GetRotation()) % 90) - 90;
  float x = glbBound.left + (glbBound.width / 2) - (lclBound.width / 2) * -sin(param * PI / 180);
  float y = glbBound.top;

  return sf::Vector2f(x, y);
}

sf::Vector2f utility::bottom(drawable* obj){
  sf::FloatRect glbBound = obj->GetGlobalBounds();
  sf::FloatRect lclBound = obj->GetLocalBounds();
  //std::cout << "width: " << lclBound.width << std::endl;
  //std::cout << "sin rot: " << sin(2 * obj->GetRotation()) << std::endl;
  //std::cout << "adder: " << (glbBound.width - lclBound.width * sin(2 * obj->GetRotation())) / 2 << std::endl;
  //std::cout << "diagonal: " << (glbBound.width + glbBound.height) << std::endl;
  float param = 2 * (((int)obj->GetRotation()) % 90) - 90;
  float x = glbBound.left + (glbBound.width / 2) - (lclBound.width / 2) * sin(param * PI / 180);
  float y = glbBound.top + glbBound.height;

  return sf::Vector2f(x, y);
}
