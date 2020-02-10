#include "playground.hpp"

//------------CONSTRUCTORS------------
playground::playground(sf::RenderWindow* w, sf::Vector2f s, sf::Vector2f p, sf::Texture* i) : viewer(w, s, p , i), endGame(false){
  allies = std::list<drawable*>();
  enemies = std::list<drawable*>();
  neutrals = std::list<drawable*>();
  objects = std::list<drawable*>();

  //this->addNeutral(this);
}

playground::~playground(){
  std::cout << "DELETING PLAYGROUND" << std::endl;

  allies.clear();
  enemies.clear();
  neutrals.clear();
  objects.clear();
}


//------------GETS------------
void playground::getObjectsBounds (std::list<drawable*> objs, std::list<sf::FloatRect>* objsBounds){
  for (std::list<drawable*>::iterator d = objs.begin(); d != objs.end(); d++)
    objsBounds->push_front((*d)->GetGlobalBounds());
}

//------------SETS------------

//------------METHODS------------
void playground::restart(){}
void playground::Hola(){ std::cout << "Hola " << std::endl;}

bool playground::intersects(drawable* obj){
  sf::FloatRect objGlobalBound = obj->GetGlobalBounds();
  sf::FloatRect plgGlobalBound = this->GetGlobalBounds();

  if(plgGlobalBound.left >= objGlobalBound.left || plgGlobalBound.left + plgGlobalBound.width <= objGlobalBound.left + objGlobalBound.width || plgGlobalBound.top >= objGlobalBound.top || plgGlobalBound.top + plgGlobalBound.height <= objGlobalBound.top + objGlobalBound.height)
    return true;

  return false;
}

// OPTIMIZATION
// bool drawable::checkSide(float diagonal){
//
// }

void playground::Draw (){
  this->checkCollision();

  if(!endGame){
    viewer::Draw();
    this->DrawList(allies);
    this->DrawList(enemies);
    this->DrawList(neutrals);
  }

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
  //objects.push_front(ally);
  std::cout << "Allies size: " << allies.size()  << std::endl;
  //std::cout << "Objects size: " << objects.size() << std::endl;
}

void playground::addEnemy (drawable* enemy){
  enemies.push_front(enemy);
  //objects.push_front(enemy);
  std::cout << "Enemies size: " << enemies.size() << std::endl;
  //std::cout << "Objects size: " << objects.size() << std::endl;
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

void playground::collision(std::_List_iterator<drawable*>* obj, bool ally){
  std::string objectClass = (**obj)->Class();
  std::cout << "In Collision checkin up " << objectClass << std::endl;

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
    //case 's': { this->collisionSpaceship(&*a, &*e, cv); }; break;
    default: std::cout << objectClass << "in Objects" << std::endl;
  }
}


void playground::checkCollision (){
  for (auto ally = allies.begin(); ally != allies.end(); ally++){
    if(!!*ally){
      if(this->intersects(*ally) && (*ally)->Class().compare("spaceship") != 0){
        collision(&ally, true);
        std::cout << "COLLISION with Playground!!" << std::endl;
      }
    }
  }

  for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++){
    if(!!*enemy){
      if(this->intersects(*enemy)){
        this->collision(&enemy, false);
        std::cout << "COLLISION with Playground!!" << std::endl;
      }
    }
  }
}
