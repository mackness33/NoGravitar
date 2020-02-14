#include "galaxy.hpp"

//----------CONSTRUCTORS----------
galaxy::galaxy(sf::RenderWindow* win, spaceship* spc, unsigned int galaxyLevel, gameplay* actGame) : playground(win), Player(spc), Gameplay(actGame), conquer(false), level(galaxyLevel){
  planets = {};
  //Player->getEntity()->SetPosition(sf::Vector2f(300, 300));
  playground::addAlly(spc);
  this->inizializePlanets();
}

galaxy::~galaxy(){
  std::cout << "DELETING GALAXY" << std::endl;

  utility::deleteList(planets);

  Player = nullptr;
  Gameplay = nullptr;
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


void galaxy::inizializePlanets(){
  sf::Vector2f plgBound = viewer::getDrawable()->getSize() - sf::Vector2f(100, 100);
  planetObj *pln = nullptr;

  for (int i = 0; i < information::GALAXY_DEFAULT_PLANETS; i++){
    sf::Vector2f position = utility::RandVector(plgBound.x - 20, plgBound.y - 20, 10, (window->getSize().y/10) + 10);
    pln = new planetObj(utility::RandInt(20, 30), position);

    if(this->checkPlanetPosition(pln)){
      pln->setPlanetView(new planetView(window, Player, Gameplay, this, pln));
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
int galaxy::getLevel (){ return level; }
void galaxy::checkCollision (){
  playground::checkCollision();

  int i = 0;
  for (auto neutral = neutrals.begin(); neutral != neutrals.end(); neutral++){
    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++){
      if(!!*neutral && !!*enemy){
        if ((*neutral)->intersects(*enemy)){
          collision(&neutral, &enemy);
          std::cout << "COLLISION NEUTRAL in GALAXY!!" << std::endl;
          std::cout << "Enemies Tho'!!" << std::endl;
        }
      }
    }

    std::cout << "planet num: " << i << std::endl;
    for (auto ally = allies.begin(); ally != allies.end(); ally++, i++){
      std::cout << "Class: " << (*ally)->Class() << std::endl;
      if(!!*neutral && !!*ally){
        if ((*neutral)->intersects(*ally)){

          collision(&neutral, &ally);
          std::cout << "COLLISION NEUTRAL in GALAXY!!" << std::endl;
          std::cout << " Tho'!!" << std::endl;
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
      Player->SetPosition(information::PLAYER_DEFAULT_POSITION);
      std::cout << "Does it exists? " << !!(planet->getPlanetView()) << std::endl;
      if(!!(planet->getPlanetView()))
        Gameplay->setMainViewer(planet->getPlanetView());

      *obj = allies.end();
     }; break;
    default: std::cout << allyClass << "in Allies" << std::endl;
  }
}

bool galaxy::isConquer() { return conquer; }
void galaxy::delPlanet(planetObj *planet){
  sf::Vector2f position = planet->getEntity()->GetPosition();
  sf::FloatRect bounds = planet->GetLocalBounds();

  Player->SetPosition(position - sf::Vector2f(bounds.width/2, bounds.height/2));

  neutrals.remove(static_cast<drawable*>(planet));
  planets.remove(planet);
  delete planet;
  planet = nullptr;

  Gameplay->deathPlanet();
  if(planets.size() == 0){
    conquer = true;
    Gameplay->next();
  }
  else
    Player->setPlayground(this);
}

void galaxy::next(){ Gameplay->next(); }
void galaxy::prev(){ Gameplay->prev(); }

std::string galaxy::Class(){
  return "galaxy";
}
