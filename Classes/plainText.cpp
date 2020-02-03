#include "plainText.hpp"

//---------------CONSTRUCTORS---------------
plainText::plainText(std::string f, const std::string &s, sf::Vector2f p){
  if(!(font = information::getFont(f)))
    std::cout << "Error in load of " << f << " font" << std::endl;

  body = new text(*font, s);
  totalTime = 0;

  body->SetPosition(p);
}

plainText::~plainText(){
  std::cout << "DELETING BULLET" << std::endl;

  if(!!body)
    delete body;

  if(!!font)
    delete font;

  body = nullptr;
  font = nullptr;
}


//---------------GETS---------------
text* plainText::getText() { return body; }
entity<sf::Text>* plainText::getEntity() { return static_cast<entity<sf::Text>*> (body); }
sf::Text* plainText::getDrawable() { return body->getBody(); }
sf::FloatRect plainText::GetLocalBounds() { return body->getBody()->getLocalBounds(); }
sf::FloatRect plainText::GetGlobalBounds() { return body->getBody()->getGlobalBounds(); }

//---------------SETS-------------font--



//---------------METHODS---------------

void plainText::Draw (sf::RenderWindow* window){
  body->Draw(window);
}

void plainText::Update(){
  totalTime += 1;

  if(totalTime >= information::SWITCH_TIME){
    totalTime -= information::SWITCH_TIME;
    //body->Move(cos(direction) * speed, sin(direction) * speed);
    //sf::Vector2f pos = body->getBody()->getPosition();
  }
}

void plainText::build(){
//  body->getBody()->setFillColor(sf::Color::White);
  //body->getBody()->setSmooth(true);
}

std::string plainText::Class(){
  return "plainText";
}
