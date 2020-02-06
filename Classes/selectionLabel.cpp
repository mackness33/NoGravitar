#include "selectionLabel.hpp"

//---------------CONSTRUCTORS---------------
selectionLabel::selectionLabel(std::string f, const std::string &s, sf::Color c1, sf::Color c2, sf::Vector2f p) : plainText(f, s, p), primary(c1), secondary(c2), totalTime(0), isSelected(false) {
  this->getText()->SetFillColor(primary);
}

selectionLabel::~selectionLabel(){
  std::cout << "DELETING SELECTIONLABEL" << std::endl;
}


//---------------GETS---------------

//---------------SETS---------------
void selectionLabel::select(bool is){ isSelected = is;}


//---------------METHODS---------------
void selectionLabel::Update(){
  totalTime += 1;

  if(totalTime >= 10){
    this->getText()->SetFillColor(secondary);

    if(totalTime >= 20)
      totalTime = 0;
  }
  else
    this->getText()->SetFillColor(primary);
}

void selectionLabel::Draw(sf::RenderWindow* window) {
  if(isSelected)
    this->Update();
  plainText::Draw(window);
}

void selectionLabel::build(){
  //body->getBody()->setFillColor(sf::Color::White);
  //body->getBody()->setSmooth(true);
}

std::string selectionLabel::Class(){
  return "selectionLabel";
}
