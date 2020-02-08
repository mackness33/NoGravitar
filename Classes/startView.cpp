#include "startView.hpp"

//------------CONSTRUCTORS------------
startView::startView(sf::RenderWindow* w/*, sf::Texture* i*/) : viewer(w), selectedIndex(0){
  this->inizializeSelecters();
  selectors[selectedIndex]->select(true);
}

startView::~startView(){
  std::cout << "DELETING STARTVIEW" << std::endl;

  // TODO: utility::deleteList(selectors);

  selectors.clear();
}


//------------GETS------------
std::string startView::getValue(){ return selectors[selectedIndex]->getValue(); }

//------------SETS------------

//------------METHODS------------
void startView::Draw (){
  viewer::Draw();
  for (auto d = selectors.begin(); d != selectors.end(); d++){
    if(!!*d){
      //(*d)->Update();
      (*d)->Draw(this->window);
    }
  }
  //this->DrawList(selectors);
}

void startView::inizializeSelecters(){
  sf::Vector2u s = window->getSize();

  selectionLabel *sl = new selectionLabel("AeroviasBrasil", "Gameplay", "Start", sf::Color::Blue, sf::Color::Red);
  sl->getText()->SetCharacterSize(30);
  sl->getText()->SetStyle(sf::Text::Regular);
  sl->getText()->SetPosition(sf::Vector2f((s.x - sl->GetLocalBounds().width)/2, (s.y - sl->GetLocalBounds().height)/2));


  selectionLabel *hs = new selectionLabel("AeroviasBrasil", "Settings", "Holy shit", sf::Color::Green, sf::Color::Red);
  hs->getText()->SetCharacterSize(30);
  hs->getText()->SetStyle(sf::Text::Regular);
  hs->getText()->SetPosition(sf::Vector2f((s.x - sl->GetLocalBounds().width)/2, 400));


  selectionLabel *fu = new selectionLabel("AeroviasBrasil", "Restart", "Fuck up", sf::Color::Yellow, sf::Color::Red);
  fu->getText()->SetCharacterSize(30);
  fu->getText()->SetStyle(sf::Text::Regular);
  fu->getText()->SetPosition(sf::Vector2f((s.x - sl->GetLocalBounds().width)/2, 300));

  selectors.push_back(sl);
  selectors.push_back(hs);
  selectors.push_back(fu);
}

void startView::DrawList (std::list<drawable*> objs){
  for (std::list<drawable*>::iterator d = objs.begin(); d != objs.end(); d++){
    if(!!*d){
      //(*d)->Update();
      (*d)->Draw(this->window);
    }
  }
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
