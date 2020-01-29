#include "playground.hpp"

//------------CONSTRUCTORS------------
playground::playground(sf::RenderWindow* w, sf::Vector2f s, sf::Vector2f p, sf::Texture* i) : viewer(w, s, p , i){
  allies = std::list<drawable*>();
  enemies = std::list<drawable*>();
  neutrals = std::list<drawable*>();
  objects = std::list<drawable*>();

  //this->addNeutral(this);
}

playground::~playground(){
  std::cout << "DELETING PLAYGROUND" << std::endl;

  utility::deleteList(allies);
  utility::deleteList(enemies);
  utility::deleteList(neutrals);

  objects.clear();
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
  this->DrawList(neutrals);
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
  std::cout << "Objects size: " << objects.size() << std::endl;
}

void playground::addEnemy (drawable* enemy){
  enemies.push_front(enemy);
  objects.push_front(enemy);
  std::cout << "Enemies size: " << enemies.size() << std::endl;
  std::cout << "Objects size: " << objects.size() << std::endl;
}

void playground::addNeutral (drawable* neutral){
  neutrals.push_front(neutral);
  //objects.push_front(neutral);
  std::cout << "neutrals size: " << neutrals.size() << std::endl;
  //std::cout << "Objects size: " << objects.size() << std::endl;
}

void playground::delObjects (){
  utility::deleteList(allies);
  utility::deleteList(enemies);
  utility::deleteList(neutrals);

  objects.clear();
}


std::string playground::Class(){
  return "playground";
}


void playground::checkCollision (){}
