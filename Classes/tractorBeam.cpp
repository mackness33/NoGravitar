#include "tractorBeam.hpp"

//---------------CONSTRUCTORS---------------
//TODO: checks on the line to check on
tractorBeam::tractorBeam(sf::Vector2f p, sf::Vector2f s){
  image = information::getImage("tractorbeam");
  body = new movable<sf::RectangleShape>(s, p, image);
}

tractorBeam::~tractorBeam(){
  std::cout << "DELETING TRACTORBEAM" << std::endl;

  if(!!body)
    delete body;

  body = nullptr;
}


//---------------GETS---------------
essence<sf::RectangleShape>* tractorBeam::getEssence() { return static_cast<essence<sf::RectangleShape>*>(body); }
entity<sf::RectangleShape>* tractorBeam::getEntity() { return static_cast<entity<sf::RectangleShape>*>(body); }
movable<sf::RectangleShape>* tractorBeam::getMovable() { return body; }
sf::RectangleShape* tractorBeam::getDrawable() { return body->getBody(); }
sf::FloatRect tractorBeam::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect tractorBeam::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }

//---------------SETS---------------



//---------------METHODS---------------
void tractorBeam::Draw (sf::RenderWindow* window){
  // body->DrawTest(window);
  body->Draw(window);
}

std::string tractorBeam::Class(){ return "tractorBeam"; }
