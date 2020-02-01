#include "galaxy.hpp"

//----------CONSTRUCTORS----------
galaxy::galaxy(sf::RenderWindow* win, spaceship* spc, unsigned int numPlanets, game* actGame) : playground(win), Player(spc), currentGame(actGame){
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
      playground::addEnemy(pln);
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

  bool intersection = false, changeViewer = false;
  planetObj *planet = nullptr;

  for (auto ally = allies.begin(); ally != allies.end();){
    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++, intersection = false){
      if(!!*ally && !!*enemy){
        if((*enemy)->intersects(*ally)){
          collision(&ally, &enemy, &changeViewer);
          std::cout << "COLLISION!!" << std::endl;
          intersection = true;
        }
      }
      if(changeViewer) {break;}
    }

    if(changeViewer) {break;}

    if(!intersection) {ally++;}
  }
}


void galaxy::collision(std::_List_iterator<drawable*>* a, std::_List_iterator<drawable*>* e, bool* cv){
  std::string allyClass = (**a)->Class();
  std::cout << "In Collision" << std::endl;

  switch(allyClass[0]){
    case 'b': { this->collisionBullet(&*a, &*e); }; break;
    case 's': { this->collisionSpaceship(&*a, &*e, cv); }; break;
    default: std::cout << allyClass << "in Allies" << std::endl;
  }
}

void galaxy::collisionBullet(std::_List_iterator<drawable*>* blt, std::_List_iterator<drawable*>* e){
  std::cout << "In CollisionBullet" << std::endl;
  Player->deleteBullet(static_cast<bullet*>(**blt));
  *blt = allies.erase(*blt);

  std::string enemyClass = (**e)->Class();

  switch(enemyClass[0]){
    case 'b': {
      std::cout << "deleting a enemy bullet from Bullet" << std::endl;
    }; break;

    case 'p': {
      std::cout << "Bounce in Planet" << std::endl;
    }; break;

    default: std::cout << enemyClass << "in Enemies" << std::endl;
  }
}

void galaxy::collisionSpaceship(std::_List_iterator<drawable*>* spc, std::_List_iterator<drawable*>* e, bool* cv){
  std::cout << "In CollisionSpaceship" << std::endl;
  std::string enemyClass = (**e)->Class();

  switch(enemyClass[0]){
    case 'b': {
      std::cout << "deleting a enemy bullet from Spaceship" << std::endl;
    }; break;

    case 'p': {
      Player->deleteBullets();     //delete all the bullets
      allies.clear();

      allies.push_front(Player);

      planetObj *planet = static_cast<planetObj*> (**e);
      Player->setPlayground(planet->getPlanetView());
      Player->getEntity()->SetPosition(sf::Vector2f(100, 200));
      currentGame->setMainViewer(planet->getPlanetView());

      *cv = true;

      std::cout << "Bounce in Ground from Spaceship" << std::endl;
    }; break;

    default: std::cout << enemyClass << "in Enemies" << std::endl;
  }
}

void galaxy::delPlanet(planetObj *planet){
  Player->getEntity()->SetPosition(planet->getEntity()->GetPosition());

  enemies.remove(static_cast<drawable*>(planet));
  delete planet;
  planet = nullptr;
}


std::string galaxy::Class(){
  return "galaxy";
}
