#include "selectionLabel.hpp"

//---------------CONSTRUCTORS---------------
selectionLabel::selectionLabel(std::string f, const std::string &v, const std::string &s, sf::Color c1, sf::Color c2, sf::Vector2f p) : label(f, s, p), value(v), primary(c1), secondary(c2), totalTime(0), isSelected(false) {
  this->getText()->SetFillColor(secondary);
}

selectionLabel::~selectionLabel(){
  std::cout << "DELETING SELECTIONLABEL" << std::endl;
}


//---------------GETS---------------
std::string selectionLabel::getValue(){ return value; }

//---------------SETS---------------
void selectionLabel::select(bool is){
  isSelected = is;
  this->Reset();

  if(isSelected)
    this->getText()->SetFillColor(primary);
  else
    this->getText()->SetFillColor(secondary);
}


//---------------METHODS---------------
void selectionLabel::Reset(){ totalTime = 0; }

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
  label::Draw(window);
}

void selectionLabel::build(){
  //body->getBody()->setFillColor(sf::Color::White);
  //body->getBody()->setSmooth(true);
}

std::string selectionLabel::Class(){
  return "selectionLabel";
}
