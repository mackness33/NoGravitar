#include "playground.hpp"
#include "bullet.hpp"

//------------CONSTRUCTORS------------
playground::playground(sf::RenderWindow* w, sf::Vector2f s, sf::Vector2f p, sf::Texture* i) : viewer(w, s, p , i), endGame(false){
  allies = std::list<drawable*>();
  enemies = std::list<drawable*>();
  neutrals = std::list<drawable*>();

}

playground::~playground(){
  allies.clear();
  enemies.clear();
  neutrals.clear();
}

//------------METHODS------------
void playground::restart(){}

//it's different from the drawable one because it only has to understand whether the input object hits one of the sides
bool playground::intersects(drawable* obj){
  sf::FloatRect objGlobalBound = obj->GetGlobalBounds();
  sf::FloatRect plgGlobalBound = this->GetGlobalBounds();

  if(plgGlobalBound.left >= objGlobalBound.left || plgGlobalBound.left + plgGlobalBound.width <= objGlobalBound.left + objGlobalBound.width || plgGlobalBound.top >= objGlobalBound.top || plgGlobalBound.top + plgGlobalBound.height <= objGlobalBound.top + objGlobalBound.height)
    return true;

  return false;
}

void playground::Draw (){
  this->checkCollision();

  if(!endGame){
    viewer::Draw();
    this->DrawList(allies);
    this->DrawList(enemies);
    this->DrawList(neutrals);
  }

}

//Draw a list of objects
void playground::DrawList (std::list<drawable*> objs){
  for (std::list<drawable*>::iterator d = objs.begin(); d != objs.end(); d++){
    if(!!*d){
      (*d)->Update();
      (*d)->Draw(this->window);
    }
  }
}

void playground::addAlly (drawable* ally){ allies.push_front(ally); }
void playground::addEnemy (drawable* enemy){ enemies.push_front(enemy); }
void playground::addNeutral (drawable* neutral){ neutrals.push_front(neutral); }

void playground::next(){}
void playground::prev(){}
void playground::back(){}

//collision handling only for bullets because viewers like galaxy don't need more
void playground::collision(std::_List_iterator<drawable*>* obj, bool ally){
  std::string objectClass = (**obj)->Class();

  switch(objectClass[0]){
    case 'b': {
      bullet *blt = static_cast<bullet*>(**obj);
      shooter *parent = blt->getShooter();
      parent->deleteBullet(blt);

      if(ally)
        *obj = allies.erase(*obj);
      else
        *obj = enemies.erase(*obj);

    }; break;

    default: ;
  }
}


//basic check collision between enemies and allies
void playground::checkCollision (){
  for (auto ally = allies.begin(); ally != allies.end(); ally++)
    if(!!*ally)
      if(this->intersects(*ally) && (*ally)->Class().compare("spaceship") != 0)
        collision(&ally, true);

  for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++)
    if(!!*enemy)
      if(this->intersects(*enemy))
        this->collision(&enemy, false);
}

std::string playground::Class(){
  return "playground";
}
