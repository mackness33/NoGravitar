#include "galaxy.hpp"

//----------CONSTRUCTORS----------
galaxy::galaxy(sf::RenderWindow* win, spaceship* spc, unsigned int numPlanets, game* actGame) : playground(win), Player(spc), currentGame(actGame){
  planets = {};
  playground::addAlly(spc);
  bullets = Player->getBullets();
  this->inizializePlanets(numPlanets);
}

//----------GETS----------
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//----------SETS----------
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}


//----------METHODS----------

//CLEAN:
/*bool galaxy::checkPlanetPosition(std::list<sf::FloatRect>* posPlanets, sf::Vector2f pos){
  sf::FloatRect planetsIntersection, playerIntersection;
  sf::FloatRect newPlanetBound (pos, sf::Vector2f(300, 300));
  int i = 0;

  //if(Player->GetGlobalBounds().intersects(newPlanetBound, playerIntersection))
    //return false;

  for(std::list<sf::FloatRect>::iterator boundPlanet = posPlanets->begin(); boundPlanet != posPlanets->end(); boundPlanet++, i++){
    //std::cout << "newPlanetBound.contains(*boundPlanet, playerIntersection): " << newPlanetBound.contains(*boundPlanet, playerIntersection) << std::endl;
    //std::cout << "intersects: " << newPlanetBound.intersects(*boundPlanet, planetsIntersection) << std::endl;
    /*

    sf::FloatRect newPlanetBound (position, sf::Vector2f(200, 200));
    std::cout << "newPlanetBound.intersects(*boundPlanet, playerIntersection): " << playerBound.intersects(newPlanetBound, playerIntersection) << std::endl;
    std::cout << "right: " << playerIntersection.left + playerIntersection.width << std::endl;
    std::cout << "top: " << playerIntersection.top << std::endl;
    std::cout << "left: " << playerIntersection.left << std::endl;
    std::cout << "bottom: " << playerIntersection.top + playerIntersection.height << std::endl;


    if(i == 0){
      std::cout << "newPlanetBound.intersects(*boundPlanet, playerIntersection): " << newPlanetBound.intersects(*boundPlanet, playerIntersection) << std::endl;
      std::cout << "right: " << playerIntersection.left + playerIntersection.width << std::endl;
      std::cout << "top: " << playerIntersection.top << std::endl;
      std::cout << "left: " << playerIntersection.left << std::endl;
      std::cout << "bottom: " << playerIntersection.top + playerIntersection.height << std::endl;
    }

    if(newPlanetBound.intersects(*boundPlanet, planetsIntersection)){
      std::cout << std::endl << std::endl << std::endl << "INSIDE: " << std::endl << std::endl << std::endl << std::endl;
      return false;
    }
  }

  return true;
}
*/

bool galaxy::checkPlanetPosition(planetObj pln){
  for(auto obj = this->objects.begin(); obj != this->objects.end(); obj++)
    if(pln.spawnIntersects(*obj))
      return false;

  return true;
}


void galaxy::inizializePlanets(unsigned int numPlanets){
  sf::Vector2f plgBound = viewer::getDrawable()->getSize() - sf::Vector2f(100, 100);
  //std::list<sf::FloatRect> *posObjects = new std::list<sf::FloatRect>();
  //sf::FloatRect playerIntersection, playerBound = Player->GetGlobalBounds();
  planetObj *pln = nullptr;

  for (int i = 0; i < numPlanets; i++){
    sf::Vector2f position = utility::RandVector(plgBound.x - 20, plgBound.y - 20, 10, (window->getSize().y/10) + 10);
    //sf::Vector2f position = utility::RandVector(win->getSize().x, win->getSize().y);
    //std::cout << "pos x: " << position.x << std::endl;
    //std::cout << "pos y: " << position.y << std::endl;
    //std::cout << "size: " << posObjects->size() << std::endl;
    pln = new planetObj(utility::RandInt(20, 30), position);

    if(this->checkPlanetPosition(*pln)){
    //if(pln->intersects()){
      pln->setPlanetView(new planetView(window, Player, currentGame));
      //pln->getBody()->SetOrigin(pos);
      planets.push_front(pln);
      playground::addEnemy(pln);
      //posObjects->push_front(pln->GetGlobalBounds());
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
  bool cll = false, changeViewer = false;
  planetObj *planet = nullptr;
  //std::cout << "START!!" << std::endl;
  int i = 0;
  for (auto ally = allies.begin(); ally != allies.end(); changeViewer = false){
    //std::cout << "Ally: " << i << std::endl;
    bool collision_planets = false;
    int j = 0;
    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++, j++, cll = false){
      //std::cout << "Enemy: " << j << std::endl;
      if(!!*ally && !!*enemy){
        if((*enemy)->intersects(*ally)){
          collision(&ally, &enemy, &changeViewer);
          std::cout << "COLLISION!!" << std::endl;
          cll = true;
          //enemies.erase(enemy);
        }
      }

    }
      /*if(collision && collision_planets){
        auto pln = std::find(planets.begin(), planets.end(), *enemy);
        delete *pln;
        *pln = nullptr;
        enemy = enemies.erase(enemy);
        planets.erase(pln);
        collision_planets = false;
      }
      else{
        enemy++;
        j++;
      }
      //std::cout << "STILL WORKING!!" << std::endl;
    //std::cout << "ALLY FOR!!" << std::endl;
    if(collision){
      switch((*ally)->Class()[0]){
        case 'b':{
          Player->deleteBullet(static_cast<bullet*>(*ally));
          ally = allies.erase(*ally);
        };break;

        case 's': {
          Player->deleteBullets();     //delete all the bullets
          //delete all the bullets from allies
          allies.clear();
          playground::addAlly(Player);
          Player->setPlayground(planet->getPlanetView());
          changeViewer = true;
          currentGame->setMainViewer(planet->getPlanetView());
          Player->getEntity()->SetPosition(100, 200);
        }; break;

        default: std::cout << "There's a " << (*ally)->Class() << " in allies, why?";
      }

      collision = false;
    }*/

    if(!cll){
      ally++;
      i++;
    }

    if(changeViewer) {break;}
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

std::string galaxy::Class(){
  return "galaxy";
}
