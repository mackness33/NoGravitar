#include "text.hpp"

//------------CONSTRUCTORS------------
text::text() : entity<sf::Text>::entity() {}
text::text(const sf::Font &f, const std::string &s) : entity<sf::Text>::entity(f, s) {}


text::~text(){}


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
