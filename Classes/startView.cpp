#include "startView.hpp"

//------------CONSTRUCTORS------------
startView::startView(sf::RenderWindow* w/*, sf::Texture* i*/) : viewer(w){
  this->inizializeSelecters();
}

startView::~startView(){
  std::cout << "DELETING STARTVIEW" << std::endl;

  utility::deleteList(selectors);

  selectors.clear();
}


//------------GETS------------

//------------SETS------------

//------------METHODS------------
void startView::Draw (){
  viewer::Draw();
  for (std::list<selectionLabel*>::iterator d = selectors.begin(); d != selectors.end(); d++){
    if(!!*d){
      //(*d)->Update();
      (*d)->Draw(this->window);
    }
  }
  //this->DrawList(selectors);
}

void startView::inizializeSelecters(){
  sf::Vector2u s = window->getSize();
  
  selectionLabel *sl = new selectionLabel("AeroviasBrasil", "Suck it", sf::Color::Blue, sf::Color::Red);
  sl->getText()->SetCharacterSize(30);
  sl->getText()->SetStyle(sf::Text::Regular);
  sl->getText()->SetPosition(sf::Vector2f((s.x - sl->GetLocalBounds().width)/2, (s.y - sl->GetLocalBounds().height)/2));


  selectionLabel *hs = new selectionLabel("AeroviasBrasil", "Holy shit", sf::Color::Green, sf::Color::Red);
  hs->getText()->SetCharacterSize(30);
  hs->getText()->SetStyle(sf::Text::Regular);
  hs->getText()->SetPosition(sf::Vector2f((s.x - sl->GetLocalBounds().width)/2, 400));


  selectionLabel *fu = new selectionLabel("AeroviasBrasil", "Fuck up", sf::Color::Yellow, sf::Color::Red);
  fu->getText()->SetCharacterSize(30);
  fu->getText()->SetStyle(sf::Text::Regular);
  fu->getText()->SetPosition(sf::Vector2f((s.x - sl->GetLocalBounds().width)/2, 300));
  fu->select(true);

  selectors.push_front(sl);
  selectors.push_front(hs);
  selectors.push_front(fu);
}

void startView::DrawList (std::list<drawable*> objs){
  for (std::list<drawable*>::iterator d = objs.begin(); d != objs.end(); d++){
    if(!!*d){
      //(*d)->Update();
      (*d)->Draw(this->window);
    }
  }
}


std::string startView::Class(){
  return "startView";
}
