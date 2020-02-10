#include "galaxy.hpp"

//----------CONSTRUCTORS----------
galaxy::galaxy(sf::RenderWindow* win, spaceship* spc, unsigned int numPlanets, gameplay* actGame) : playground(win), Player(spc), currentGame(actGame){
  planets = {};
  //Player->getEntity()->SetPosition(sf::Vector2f(300, 300));
  playground::addAlly(spc);
  this->inizializePlanets(numPlanets);
}

galaxy::~galaxy(){
  std::cout << "DELETING GALAXY" << std::endl;

  utility::deleteList(planets);

  Player = nullptr;
  currentGame = nullptr;
}


//----------GETS----------
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//----------SETS----------
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}


//----------METHODS----------
bool galaxy::checkPlanetPosition(planetObj* pln){
  bool intersection = true;

  for(auto obj = this->enemies.begin(); obj != this->enemies.end(); obj++)
    if(pln->spawnIntersects(*obj))
      return false;

  for(auto obj = this->allies.begin(); obj != this->allies.end(); obj++)
    if(pln->spawnIntersects(*obj))
      return false;

  for(auto obj = this->neutrals.begin(); obj != this->neutrals.end(); obj++)
    if(pln->spawnIntersects(*obj))
      return false;

  return true;
}


void galaxy::inizializePlanets(unsigned int numPlanets){
  sf::Vector2f plgBound = viewer::getDrawable()->getSize() - sf::Vector2f(100, 100);
  planetObj *pln = nullptr;

  for (int i = 0; i < numPlanets; i++){
    sf::Vector2f position = utility::RandVector(plgBound.x - 20, plgBound.y - 20, 10, (window->getSize().y/10) + 10);
    pln = new planetObj(utility::RandInt(20, 30), position);

    if(this->checkPlanetPosition(pln)){
      pln->setPlanetView(new planetView(window, Player, currentGame, this, pln));
      planets.push_front(pln);
      playground::addNeutral(pln);
    }
    else{
      delete pln;
      pln = nullptr;
      i--;
    }
  }
}

//TODO: Need to delete the object at the end of all the cicles!
//TODO: consider to delete in a good way the mo'fucking pointers
void galaxy::checkCollision (){
  playground::checkCollision();

  for (auto neutral = neutrals.begin(); neutral != neutrals.end(); neutral++){
    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++){
      if(!!*neutral && !!*enemy){
        if ((*neutral)->intersects(*enemy)){
          collision(&neutral, &enemy);
          std::cout << "COLLISION NEUTRAL in GALAXY!!" << std::endl;
        }
      }
    }

    for (auto ally = allies.begin(); ally != allies.end(); ally++){
      if(!!*neutral && !!*ally){
        if ((*neutral)->intersects(*ally)){
          collision(&neutral, &ally);
          std::cout << "COLLISION NEUTRAL in GALAXY!!" << std::endl;
        }
      }
    }
  }

}


void galaxy::collision(std::_List_iterator<drawable*>* ntl, std::_List_iterator<drawable*>* obj){
  std::string allyClass = (**obj)->Class();
  std::cout << "In Collision" << std::endl;

  switch(allyClass[0]){
    case 'b': {
      bullet *blt = static_cast<bullet*>(**obj);
      shooter *parent = blt->getShooter();
      parent->deleteBullet(blt);
      *obj = allies.erase(*obj);

      /* FEAT: adding spaceship's enemies
      if(isAlly)
        *obj = allies.erase(*obj);
      else
        *obj = enemies.erase(*obj);
      */
    }; break;
    case 's': {
      Player->deleteBullets();     //delete all the bullets
      allies.clear();

      allies.push_front(Player);

      planetObj *planet = static_cast<planetObj*> (**ntl);
      Player->setPlayground(planet->getPlanetView());
      Player->getEntity()->SetPosition(sf::Vector2f(100, 200));
      currentGame->setMainViewer(planet->getPlanetView());

      *obj = allies.end();
     }; break;
    default: std::cout << allyClass << "in Allies" << std::endl;
  }
}

void galaxy::delPlanet(planetObj *planet){
  Player->getEntity()->SetPosition(planet->getEntity()->GetPosition());

  neutrals.remove(static_cast<drawable*>(planet));
  planets.remove(planet);
  delete planet;
  planet = nullptr;
}


std::string galaxy::Class(){
  return "galaxy";
}
