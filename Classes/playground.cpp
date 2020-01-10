#include "playground.hpp"

//------------CONSTRUCTORS------------
playground::playground(sf::RenderWindow* w, sf::Vector2f s, sf::Vector2f p, sf::Texture* i) : viewer(w, s, p , i){
  allies = std::list<drawable*>();
  enemies = std::list<drawable*>();
}

playground::~playground(){
  std::cout << "DELETING PLAYGROUND" << std::endl;
}


//------------GETS------------
void playground::getObjectsBounds (std::list<drawable*> objs, std::list<sf::FloatRect>* objsBounds){
  for (std::list<drawable*>::iterator d = objs.begin(); d != objs.end(); d++)
    objsBounds->push_front((*d)->GetGlobalBounds());
}

//------------SETS------------

//------------METHODS------------
void playground::Draw (){
  this->checkCollision();

  viewer::Draw();
  this->DrawList(allies);
  this->DrawList(enemies);
}

void playground::DrawList (std::list<drawable*> objs){
  for (std::list<drawable*>::iterator d = objs.begin(); d != objs.end(); d++){
    if(!!*d){
      (*d)->Update();
      (*d)->Draw(this->window);
    }
  }
}

void playground::addAlly (drawable* ally){
  allies.push_front(ally);
  objects.push_front(ally);
  std::cout << "Allies size: " << allies.size()  << std::endl;
}

void playground::addEnemy (drawable* enemy){
  enemies.push_front(enemy);
  objects.push_front(enemy);
  std::cout << "Enemies size: " << enemies.size() << std::endl;
}

std::string playground::Class(){
  return "playground";
}


void playground::checkCollision (){}
