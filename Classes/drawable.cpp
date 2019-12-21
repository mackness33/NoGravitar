#include "drawable.hpp"

//------------CONSTRUCTORS------------
drawable::drawable(){
}

//------------DESTRUCTORS------------
drawable::~drawable(){
  std::cout << "DELETING DRAWABLE" << std::endl;
}

//------------GETS------------
sf::FloatRect drawable::GetLocalBounds(){ return sf::FloatRect(0, 0, 0, 0); }
sf::FloatRect drawable::GetGlobalBounds(){ return sf::FloatRect(0, 0, 0, 0); }


//------------METHODS------------


std::string drawable::Class(){
  return "drawable";
}

void drawable::Update(){}
