#include "drawable.hpp"

//------------CONSTRUCTORS------------
drawable::drawable(){
  sf::FloatRect boundBox = GetLocalBounds();

  width =  boundBox.width;
  height =  boundBox.height;
  diagonal = width * height;
}

//------------DESTRUCTORS------------
drawable::~drawable(){
  std::cout << "DELETING DRAWABLE" << std::endl;
}

//------------GETS------------
sf::FloatRect drawable::GetLocalBounds(){ return sf::FloatRect(0, 0, 0, 0); }
sf::FloatRect drawable::GetGlobalBounds(){ return sf::FloatRect(0, 0, 0, 0); }


//------------METHODS------------
bool drawable::intersects(drawable* obj){ return this->GetGlobalBounds().intersects(obj->GetGlobalBounds()); }

float drawable::GetRotation(){ return -1; }
float drawable::GetDiagonal(){ return diagonal; }

std::string drawable::Class(){
  return "drawable";
}

void drawable::Update(){}
