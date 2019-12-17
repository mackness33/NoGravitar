#include "viewer.hpp"

//------------CONSTRUCTORS------------
viewer::viewer(sf::RenderWindow* w, sf::Vector2f s, sf::Vector2f p, sf::Texture* i){
  window = w;
  sf::Vector2f default_size = sf::Vector2f(w->getSize().x - 6, (w->getSize().y * 9/10) - 6);   //with the -6 I can see the bounderies
  sf::Vector2f default_position = sf::Vector2f(3, w->getSize().y/10 + 3);
  if(s == sf::Vector2f(-1, -1) && p == sf::Vector2f(-1, -1)){
    background = new entity<sf::RectangleShape>(default_size, default_position);
    std::cout << "size x:" << w->getSize().x << std::endl;
    std::cout << "size y:" << w->getSize().y << std::endl;
    std::cout << "pos win x:" << w->getSize().x/2 << std::endl;
    std::cout << "pos win y:" << w->getSize().y/2 + w->getSize().y/10 << std::endl;
  }
  else
    background = new entity<sf::RectangleShape>(s, p);

  if(!i)
    background->getBody()->setTexture(i);

  background->getBound()->setOutlineColor(sf::Color::Green);
  background->getBound()->setFillColor(sf::Color::Black);
}

viewer::~viewer(){
  std::cout << "DELETING VIEWER" << std::endl;
}


//------------GETS------------
entity<sf::RectangleShape>* viewer::getEntity() { return background; }
sf::RectangleShape* viewer::getDrawable() { return background->getBody(); }
sf::FloatRect viewer::GetLocalBounds() { return background->getBody()->getLocalBounds(); }
sf::FloatRect viewer::GetGlobalBounds() { return background->getBody()->getGlobalBounds(); }
//sf::Texture* viewer::getBackground(){ return background; }


//------------SETS------------
//TODO: finish texture
void viewer::setBackground(sf::Texture* texture){}


//------------METHODS------------
void viewer::Draw (){
  background->DrawTest(window);
}

std::string viewer::Class(){
  return "viewer";
}

void viewer::Draw (sf::RenderWindow* window){}
