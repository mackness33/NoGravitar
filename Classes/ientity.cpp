//UNIVERSE
//Class that handle everything that concerne the top of the window

/*

*/
#include "ientity.hpp"
#define PI 3.14159265

//------------CONSTRUCTORS------------
ientity::ientity(sf::RenderWindow* w, sf::Transformable* b){
  window = w;
  this->setBody(b);
}

ientity::ientity(sf::RenderWindow* w){
  window = w;
  bodyDraw = NULL;
}

//------------SETS------------
void ientity::setBody(sf::Transformable *b){
  //*bodyDraw = *b;
  *bodyMove = *b;
  bodyDraw = (sf::Shape*)bodyMove;

  //TODO: Add checks for VertexArray and VertexBuffer

  if (!!bodyMove)
    boundBox = new sf::FloatRect(0, 0, 0, 0);        //for testing use
  else
    boundBox = new sf::FloatRect(((sf::Shape*)bodyMove)->getLocalBounds());        //for testing use


  bound.setSize(sf::Vector2f(boundBox->width, boundBox->height));
}


//------------METHODS------------
void ientity::Draw (sf::RenderWindow* window){
  window->draw(bodyDraw);
}
