#include "selectionLabel.hpp"
#include "utility.hpp"

//---------------CONSTRUCTORS---------------
selectionLabel::selectionLabel(std::string f, const std::string &v, const std::string &s, sf::Color c1, sf::Color c2, sf::Vector2f p) : label(f, s, p), value(v), primary(c1), secondary(c2), totalTime(0), isSelected(false) {
  this->getText()->SetFillColor(secondary);
}

selectionLabel::~selectionLabel(){}


//---------------GETS---------------
std::string selectionLabel::getValue(){ return value; }

//---------------METHODS---------------
void selectionLabel::Reset(){ totalTime = 0; }

//change the bool and make the label blink if selected
void selectionLabel::select(bool is){
  isSelected = is;
  this->Reset();

  if(isSelected)
    this->getText()->SetFillColor(primary);
  else
    this->getText()->SetFillColor(secondary);
}

//makes the label change color at the same time
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

std::string selectionLabel::Class(){
  return "selectionLabel";
}
