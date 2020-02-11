#include "label.hpp"

//---------------CONSTRUCTORS---------------
label::label(std::string f, const std::string &s, sf::Vector2f p){
  if(!(font = information::getFont(f)))
    std::cout << "Error in load of " << f << " font" << std::endl;

  body = new text(*font, s);

  body->SetPosition(p);
}

label::~label(){
  std::cout << "DELETING LABEL" << std::endl;

  if(!!body)
    delete body;

  if(!!font)
    delete font;

  body = nullptr;
  font = nullptr;
}


//---------------GETS---------------
std::string label::getString() { return body->GetString(); }
int label::getInt() { return std::stoi(body->GetString()); }
text* label::getText() { return body; }
entity<sf::Text>* label::getEntity() { return static_cast<entity<sf::Text>*> (body); }
sf::Text* label::getDrawable() { return body->getBody(); }
sf::FloatRect label::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect label::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }

//---------------SETS---------------
void label::setString (const std::string &s){
  body->SetString(s);
}


//---------------METHODS---------------

void label::Draw (sf::RenderWindow* window){
  body->Draw(window);
}

void label::build(){
//  body->getBody()->setFillColor(sf::Color::White);
  //body->getBody()->setSmooth(true);
}

std::string label::Class(){
  return "label";
}
