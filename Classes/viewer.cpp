#include "viewer.hpp"

//------------CONSTRUCTORS------------
viewer::viewer(sf::RenderWindow* w, sf::Vector2f s, sf::Vector2f p, sf::Texture* i) : window(w){
  background = new entity<sf::RectangleShape>(s, p);

  if(!i)
    background->getBody()->setTexture(i);

  background->getBound()->setOutlineColor(sf::Color::Green);
  background->getBound()->setFillColor(sf::Color::Black);
}

viewer::viewer() {}

viewer::~viewer() {}


//------------GETS------------
entity<sf::RectangleShape>* viewer::getEntity() { return background; }
sf::RectangleShape* viewer::getDrawable() { return background->getBody(); }
sf::FloatRect viewer::GetLocalBounds() { return background->getBody()->getLocalBounds(); }
sf::FloatRect viewer::GetGlobalBounds() { return background->getBody()->getGlobalBounds(); }

//------------METHODS------------
void viewer::Draw (){ background->Draw(window); }

std::string viewer::Class(){
  return "viewer";
}

void viewer::Draw (sf::RenderWindow* window){}
