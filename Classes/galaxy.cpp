#include "galaxy.hpp"
#include "utility.hpp"
#include "planetView.hpp"

//----------CONSTRUCTORS----------
galaxy::galaxy(sf::RenderWindow* win, spaceship* spc, unsigned int galaxyLevel, gameplay* actGame) : playground(win), Player(spc), Gameplay(actGame), conquer(false), level(galaxyLevel), planets(std::list<planetObj*>()){
  playground::addAlly(spc);
  this->inizializationPlanets();
}

galaxy::~galaxy(){
  utility::deleteList(planets);

  Player = nullptr;
  Gameplay = nullptr;
}


//----------GETS----------
int galaxy::getLevel (){ return level; }


//----------METHODS----------
bool galaxy::checkPlanetPosition(planetObj* pln){
  bool intersection = true;

  //checkin position for each type of object
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


void galaxy::inizializationPlanets(){
  sf::Vector2f plgBound = viewer::getDrawable()->getSize() - sf::Vector2f(100, 100);
  planetObj *pln = nullptr;

  for (int i = 0; i < information::GALAXY_DEFAULT_PLANETS; i++){
    sf::Vector2f position = utility::RandVector(plgBound.x - 20, plgBound.y - 20, 10, (window->getSize().y/10) + 10);
    pln = new planetObj(utility::RandInt(20, 30), position);

    //if the position is OK create the view add to the neutrals else delete it and create another one
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


void galaxy::checkCollision (){
  this->endGame = false;                        //necessary because sometimes it changed to true not letting the object being draw
  playground::checkCollision();

  //check the neutrals collision
  for (auto neutral = neutrals.begin(); neutral != neutrals.end(); neutral++){

    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++)
      if(!!*neutral && !!*enemy)
        if ((*neutral)->intersects(*enemy))
          collision(&neutral, &enemy);

    for (auto ally = allies.begin(); ally != allies.end(); ally++)
      if(!!*neutral && !!*ally)
        if ((*neutral)->intersects(*ally))
          collision(&neutral, &ally);

  }
}

//collision handling of neutral vs ally/enemy
//it has its own method since the consequences comes only for the ally/enemy
void galaxy::collision(std::_List_iterator<drawable*>* ntl, std::_List_iterator<drawable*>* obj){
  std::string objectClass = (**obj)->Class();
  switch(objectClass[0]){
    case 'b': {                                               //handling bullets case
      bullet *blt = static_cast<bullet*>(**obj);
      shooter *parent = blt->getShooter();
      parent->deleteBullet(blt);
      *obj = allies.erase(*obj);
    }; break;

    case 's': {                                               //handling spaceship case
      Player->deleteBullets();                                //delete all the bullets
      allies.clear();

      allies.push_front(Player);

      //entering in the planets
      planetObj *planet = static_cast<planetObj*> (**ntl);
      Player->setPlayground(planet->getPlanetView());
      Player->SetPosition(information::PLAYER_DEFAULT_POSITION);
      Gameplay->setMainViewer(planet->getPlanetView());

      *obj = allies.end();
     }; break;

    default: ;
  }
}

bool galaxy::isConquer() { return conquer; }

void galaxy::delPlanet(planetObj *planet){
  sf::Vector2f position = planet->getEntity()->GetPosition();
  sf::FloatRect bounds = planet->GetLocalBounds();

  Player->SetPosition(position - sf::Vector2f(bounds.width/2, bounds.height/2));

  //delete of the conquer planet
  neutrals.remove(static_cast<drawable*>(planet));
  planets.remove(planet);
  delete planet;
  planet = nullptr;

  Gameplay->deathPlanet();            //adding points to the game

  //go to the next galaxy if conqueerd
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
