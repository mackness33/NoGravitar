#include "fuel.hpp"

//---------------CONSTRUCTORS---------------
//TODO: checks on the line to check on
fuel::fuel(line l){
  image = information::getImage("fuel3");
  body = new movable<sf::RectangleShape>(information::FUEL_DEFAULT_SIZE, sf::Vector2f(-1, -1), image);

  long double angle = utility::toDegrees(l.getSlope());
  float maxX = l.getA().x;
  float maxY = std::min(l.getA().y, l.getB().y);

  sf::FloatRect bounds = this->GetLocalBounds();

  body->SetOrigin(bounds.width/2, bounds.height/2);
  body->SetRotation(-angle);
  body->SetPosition(sf::Vector2f((maxX + l.getWidth()/2) - ((bounds.width/2) * sin(l.getSlope())), (maxY + l.getHeight()/2) - ((bounds.height/2) * cos(l.getSlope()))));
  //body->SetPosition(lines[0]->intersection(line(utility::left(bunkers), utility::bottom(bunkers))));
}

fuel::~fuel(){
  std::cout << "DELETING FUEL" << std::endl;

  if(!!body)
    delete body;

  body = nullptr;
}


//---------------GETS---------------
essence<sf::RectangleShape>* fuel::getEssence() { return static_cast<essence<sf::RectangleShape>*>(body); }
entity<sf::RectangleShape>* fuel::getEntity() { return static_cast<entity<sf::RectangleShape>*>(body); }
sf::RectangleShape* fuel::getDrawable() { return body->getBody(); }
sf::FloatRect fuel::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect fuel::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }

//---------------SETS---------------



//---------------METHODS---------------
void fuel::Draw (sf::RenderWindow* window){
  // body->Draw(window);
  body->DrawTest(window);
}

std::string fuel::Class(){ return "fuel"; }
