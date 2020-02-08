#include "header.hpp"

//------------CONSTRUCTORS------------
header::header(sf::RenderWindow* w, sf::Vector2f s, sf::Vector2f p, sf::Texture* i) : viewer(w, s, p , i){
  // Setting title text
  //TODO: set for text's direct methods for modifiers of strings
  std::cout << "wassup fack" << std::endl;
  title = new plainText("AeroviasBrasil", "NOGRAVITAR");
  title->getText()->SetCharacterSize(30);
  title->getText()->SetStyle(sf::Text::Bold);
  title->getText()->SetFillColor(sf::Color::Green);
  title->getText()->SetPosition(sf::Vector2f((s.x - title->GetLocalBounds().width)/2, 0));


  // Setting point text
  points = new plainText("AeroviasBrasil", "0");
  points->getText()->SetCharacterSize(30);
  points->getText()->SetStyle(sf::Text::Regular);
  points->getText()->SetFillColor(sf::Color::Green);
  points->getText()->SetPosition(sf::Vector2f((s.x - points->GetLocalBounds().width)/2, (s.y - points->GetLocalBounds().height)/2));
}

header::~header(){
  std::cout << "DELETING HEADER" << std::endl;
}

//----------GETS----------
//plainText header::getPoints(){ return *(this->points);}
//plainText header::getTitle(){ return *(this->title);}
//const sf::Font* header::getFont(){ return font;}

//----------SETS----------
//void header::setPoints(sf::Text p){ this->points = p;}
//void header::setTitle(sf::Text t){ this->title = t;}
//void header::setFont(sf::Font* f){ *(this->font) = *f;}

//----------METHODS----------

void header::Draw (){
  viewer::Draw();
  points->Draw(window);
  title->Draw(window);
}

std::string header::Class(){
  return "header";
}
