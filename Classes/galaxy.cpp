#include "galaxy.hpp"

//----------CONSTRUCTORS----------
galaxy::galaxy(sf::RenderWindow* win, spaceship* spc, unsigned int numPlanets, game* actGame) : playground(win){
  Player = spc;
  currentGame = actGame;
  playground::addAlly(spc);
  bullets = Player->getBullets();
  planets = {};
  std::list<sf::FloatRect> posPlanets = {};
  sf::Vector2f plgBound = viewer::getDrawable()->getSize() - sf::Vector2f(100, 100);

  for (int i = 0; i < numPlanets; i++){
    sf::Vector2f position = utility::RandVector(plgBound.x, plgBound.y, 0, win->getSize().y/10);
    //sf::Vector2f position = utility::RandVector(win->getSize().x, win->getSize().y);
    //std::cout << "pos x: " << position.x << std::endl;
    //std::cout << "pos y: " << position.y << std::endl;
    if(this->checkPlanetPosition(&posPlanets, position)){
      planetObj *pln = new planetObj(utility::Rand(20, 30), position);
      pln->setPlanetView(new planetView(window, Player, currentGame));
      //pln->getBody()->SetOrigin(pos);
      planets.push_front(pln);
      playground::addEnemy(pln);
      posPlanets.push_front(pln->GetGlobalBounds());
    }
    else
      i--;
  }
}

//----------GETS----------
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//----------SETS----------
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}


//----------METHODS----------
bool galaxy::checkPlanetPosition(std::list<sf::FloatRect>* posPlanets, sf::Vector2f pos){
  sf::FloatRect newPlanetBound (pos, sf::Vector2f(100, 100));
  sf::FloatRect planetsIntersection;
  int i = 0;

  for(std::list<sf::FloatRect>::iterator boundPlanet = posPlanets->begin(); boundPlanet != posPlanets->end(); boundPlanet++, i++){
      //std::cout << "intersects: " << newPlanetBound.intersects(*boundPlanet, planetsIntersection) << std::endl;
      if(newPlanetBound.intersects(*boundPlanet, planetsIntersection))
        return false;
  }

  return true;
}

//TODO: Need to delete the object at the end of all the cicles!
//TODO: consider to delete in a good way the mo'fucking pointers
void galaxy::checkCollision (){
  bool collision = false, changeViewer = false;
  planetObj *planet = nullptr;
  std::cout << "START!!" << std::endl;
  int i = 0;
  for (auto ally = allies.begin(); ally != allies.end();){
    std::cout << "Ally: " << i << std::endl;
    bool collision_planets = false;
    int j = 0;
    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++, j++){
      std::cout << "Enemy: " << j << std::endl;
      if(!!*ally && !!*enemy){
        if(collisionHandler::checkCollision(*ally, *enemy)){
          std::cout << "COLLISION!!" << std::endl;
          planet = static_cast<planetObj*>(*enemy);
          collision = true;
          collision_planets = true;
          //enemies.erase(enemy);
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
      }*/
      //std::cout << "STILL WORKING!!" << std::endl;
    }
    //std::cout << "ALLY FOR!!" << std::endl;
    if(collision){
      switch((*ally)->Class()[0]){
        case 'b':{
          Player->deleteBullet(static_cast<bullet*>(*ally));
          ally = allies.erase(ally);
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
    }
    else{
      ally++;
      i++;
    }

    if(changeViewer) {break;}
  }
}

//TODO: create a .tpp and convert collision in template <typename T> void galaxy::collision(T* obj, planetObj* planet){ return nullptr; }
void galaxy::collision(bullet* bullet, planetObj* planet){
  Player->deleteBullet(bullet);
}

void galaxy::collision(spaceship* spaceship, planetObj* planet){
  Player->deleteBullets();     //delete all the bullets
}
