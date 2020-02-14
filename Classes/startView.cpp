#include "startView.hpp"

//------------CONSTRUCTORS------------
startView::startView(sf::RenderWindow* w) : viewer(w), selectedIndex(0){
  sf::Vector2u s = window->getSize();

  title = new selectionLabel("AeroviasBrasil", "", "NOGRAVITAR", sf::Color::Green, sf::Color::Yellow);
  title->getText()->SetCharacterSize(150);
  title->getText()->SetStyle(sf::Text::Bold);
  title->getText()->SetFillColor(sf::Color::Red);
  title->getText()->SetPosition(sf::Vector2f((s.x - title->GetLocalBounds().width)/2, 50));
  title->select(true);

  this->inizializeSelecters();
  selectors[selectedIndex]->select(true);
}

startView::~startView(){ selectors.clear(); }


//------------GETS------------
std::string startView::getValue(){ return selectors[selectedIndex]->getValue(); }

//------------METHODS------------
void startView::Draw (){
  viewer::Draw();
  title->Draw(this->window);

  for (auto d = selectors.begin(); d != selectors.end(); d++)
    if(!!*d)
      (*d)->Draw(this->window);
}

void startView::inizializeSelecters(){
  sf::Vector2u s = window->getSize();

  selectionLabel *start = new selectionLabel("AeroviasBrasil", "Gameplay", "Start", sf::Color::Blue, sf::Color::Red);
  start->getText()->SetCharacterSize(30);
  start->getText()->SetStyle(sf::Text::Regular);
  start->getText()->SetPosition(sf::Vector2f((s.x - start->GetLocalBounds().width)/2, (s.y - start->GetLocalBounds().height)/2));

  selectors.push_back(start);
}

void startView::selectNext (){
  selectors[selectedIndex]->select(false);
  selectedIndex = ++selectedIndex % selectors.size();
  selectors[selectedIndex]->select(true);
}

void startView::selectPrev (){
  selectors[selectedIndex]->select(false);
  std::cout << "--selIndex" << std::abs(selectedIndex) << std::endl;
  selectedIndex = (selectedIndex <= 0)? (selectors.size() - 1) : --selectedIndex;
  selectors[selectedIndex]->select(true);
}


std::string startView::Class(){
  return "startView";
}
