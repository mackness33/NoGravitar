#include "text.hpp"

//------------CONSTRUCTORS------------
text::text() : entity<sf::Text>::entity() {}
text::text(const sf::Font &f, const std::string &s) : entity<sf::Text>::entity(f, s) {}
//template <class T> text<T>::text(std::size_t vertexCount, std::vector<sf::Vector2f*> vertexPosition, sf::PrimitiveType type) : entity<T>::entity(vertexCount, vertexPosition, type){}      //VertexArray

/*template <class T> text<T>::text(sf::RenderWindow* w){
  window = w;
  body = new sf::CircleShape();
  body->setRadius(10);
  body->setFillColor(sf::Color::Red);
  //boundBox = new sf::FloatRect(0, 0, 0, 0);        //for testing use
  boundBox = new sf::FloatRect(body->getLocalBounds());        //for testing use
  bound.setSize(sf::Vector2f(boundBox->width, boundBox->height));
  bound.setOrigin(body.getOrigin());
  bound.setPosition(body.getPosition());
  bound.setRotation(body.getRotation());
  bound.setScale(body.getScale());
}*/


text::~text(){
  std::cout << "DELETING TEXT" << std::endl;
}


std::string text::GetString (){ this->body->getString(); }

void text::SetFont (const sf::Font &f){ this->body->setFont(f); }
void text::SetStyle (sf::Uint32	s) { this->body->setStyle(s); }
void text::SetString (const std::string &s) { this->body->setString(s); }
void text::SetFillColor (const sf::Color &c) { this->body->setFillColor(c); }
void text::SetOutlineColor (const sf::Color &c) { this->body->setOutlineColor(c); }
void text::SetCharacterSize (unsigned int s) { this->body->setCharacterSize(s); }
void text::SetOutlineThickness (float t) { this->body->setOutlineThickness(t); }

std::string text::Class(){
  return "text";
}
