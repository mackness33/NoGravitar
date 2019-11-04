//UNIVERSE
//Class that handle everything that concerne the top of the window

/*

*/
#include "drawable.hpp"
#define PI 3.14159265

//drawable::drawable(){}
drawable::~drawable(){
  std::cout << "DELETING DRAWABLE" << std::endl;
}

//------------GETS------------
sf::FloatRect drawable::GetLocalBounds(){ return sf::FloatRect(0, 0, 0, 0); }
sf::FloatRect drawable::GetGlobalBounds(){ return sf::FloatRect(0, 0, 0, 0); }


//------------METHODS------------
void drawable::Update(){}
std::string drawable::Class(){}
