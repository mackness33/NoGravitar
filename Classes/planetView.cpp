#include "planetView.hpp"

//----------CONSTRUCTORS----------
planetView::planetView(sf::RenderWindow* win, spaceship* spc, gameplay* actGame, galaxy* glx, planetObj* pln) :
            playground(win), restartViewer(false), changeViewer(false), Galaxy(glx), Gameplay(actGame), Planet(pln), Player(spc), bunkers(std::list<bunker*>()), fuels(std::list<fuel*>()){

  sf::Vector2f plgBound = viewer::getDrawable()->getSize() - sf::Vector2f(100, 100);
  Ground = new ground(information::MENU_DEFAULT_SIZE.x, information::MENU_DEFAULT_SIZE.y);

  inizializeBunker();

  playground::addAlly(spc);
  playground::addNeutral(Ground);
}

planetView::~planetView(){
  if(!!Ground)
    delete Ground;

  utility::deleteList(bunkers);

  Ground = nullptr;
  Player = nullptr;
  Galaxy = nullptr;
  Gameplay = nullptr;
  Planet = nullptr;
  image = nullptr;
}

//----------METHODS---------------
void planetView::restart(){
  Player->SetPosition(information::PLAYER_DEFAULT_POSITION);

  enemies.clear();
  for(auto bnk = bunkers.begin(); bnk != bunkers.end(); bnk++){
    if(!!(*bnk)){
      (*bnk)->deleteBullets();
      enemies.push_front(*bnk);
    }
  }
}

void planetView::inizializeBunker(){
  std::vector<line*> lines = Ground->getLines();
  bool occupied[20];                              //its needed to check which lines are already occupy
  int numBunker = utility::RandInt(2,1);
  int numFuel = 1;
  int pos = 0;
  int level = Galaxy->getLevel();
  bunker *tempBunker = nullptr;
  fuel *tempFuel = nullptr;

  //setting all the bool to false
  for(int k = 0; k < lines.size(); k++)
    occupied[k] = false;

  //create bunkers and put it on top of a line
  for(int i = 0; i < numBunker;){
    pos = utility::RandInt(lines.size());

    if(!occupied[pos]){
      tempBunker = new bunker(this, *lines[pos], !!(utility::RandInt(500) % 2));
      bunkers.push_front(tempBunker);
      playground::addEnemy(tempBunker);

      occupied[pos] = true;
      i++;
    }
  }

  //Same with fuels
  for(int i = 0; i < numFuel;){
    pos = utility::RandInt(lines.size());

    if(!occupied[pos]){
      tempFuel = new fuel(*lines[pos], !!(utility::RandInt(500) % 4));
      fuels.push_front(tempFuel);
      playground::addAlly(tempFuel);

      occupied[pos] = true;
      i++;
    }
  }

}

void planetView::checkCollision (){
  playground::checkCollision();
  changeViewer = false, restartViewer = false, this->endGame = false;

  for (auto ally = allies.begin(); ally != allies.end(); ally++){
    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++){
      if(!!*ally && !!*enemy)
        if((*ally)->intersects(*enemy))
          collision(&ally, &enemy);

      if(changeViewer && !endGame)
        Galaxy->delPlanet(Planet);

      if(endGame || restartViewer || changeViewer)
        return;
    }
  }

  for (auto neutral = neutrals.begin(); neutral != neutrals.end(); neutral++){
    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++)
      if(!!*neutral && !!*enemy  && (*enemy)->Class().compare("bunker") != 0)
        if ((*neutral)->intersects(*enemy))
          collision(&enemy, false);

    for (auto ally = allies.begin(); ally != allies.end(); ally++){
      if(!!*neutral && !!*ally && (*ally)->Class().compare("fuel") != 0){
        if ((*neutral)->intersects(*ally))
          collision(&ally, true);

        if(endGame || restartViewer)
          return;
      }
    }
  }

  //if tractor beam is enable check whether it hits a fuel
  if(information::TRACTORBEAM_IS_ACTIVE){
    tractorBeam *trb = Player->getTractorBeam();

    for(auto f = fuels.begin(); f != fuels.end(); f++){
      if((*f)->intersects(trb)){
        Gameplay->addFuel((*f)->getValue());
        allies.remove(static_cast<drawable*>(*f));
        f = fuels.erase(f);
      }
    }
  }
}

void planetView::collision(std::_List_iterator<drawable*>* obj, bool isAlly){
  std::string objectClass = (**obj)->Class();

  switch(objectClass[0]){
    case 'b': {
      bullet *blt = static_cast<bullet*>(**obj);
      shooter *parent = blt->getShooter();
      parent->deleteBullet(blt);

      if(isAlly)
        *obj = allies.erase(*obj);
      else
        *obj = enemies.erase(*obj);
    }; break;

    case 's': {
      Player->rip();

      if(!Player->isAlive()){
        Gameplay->restart();
        this->endGame = true;
      }
      else{
        this->restart();
        restartViewer = true;
      }
    }; break;

    default: ;
  }
}

void planetView::collision(std::_List_iterator<drawable*>* a, std::_List_iterator<drawable*>* e){
  std::string allyClass = (**a)->Class();

  //based on the type of the ally handle the collision
  switch(allyClass[0]){
    case 'b': { this->collisionBullet(&*a, &*e); }; break;
    case 's': { this->collisionSpaceship(&*a, &*e); }; break;
    default: ;
  }
}

void planetView::collisionBullet(std::_List_iterator<drawable*>* blt, std::_List_iterator<drawable*>* e){
  std::string enemyClass = (**e)->Class();
  std::string bulletClass = (**blt)->Class();

  //deleting bullet
  Player->deleteBullet(static_cast<bullet*>(**blt));
  *blt = allies.erase(*blt);

  switch(enemyClass[0]){
    case 'b': {
      if(enemyClass[2] == 'n'){                             //if the enemy is a buNker else is a bullet
        //deleting bunker
        bunker *bnk = static_cast<bunker*>(**e);
        bnk->rip();
        bunkers.remove(bnk);
        *e = enemies.erase(*e);
        Gameplay->deathBunker();

        //changing the Viewer in case all the bunkers died
        if(bunkers.empty()){
          allies.remove(static_cast<drawable*>(Player));
          Player->setPlayground(Galaxy);
          Gameplay->setMainViewer(Galaxy);

          this->changeViewer = true;
        }
      }
      else{                                                 //is a bullet
        //simply deleting the bullet
        bullet *bll = static_cast<bullet*>(**e);
        shooter *parent = bll->getShooter();
        parent->deleteBullet(bll);
        *e = enemies.erase(*e);
      }

    }; break;

    default: ;
  }
}

void planetView::collisionSpaceship(std::_List_iterator<drawable*>* spc, std::_List_iterator<drawable*>* e){
  std::string enemyClass = (**e)->Class();

  if(enemyClass.compare("bunker") == 0){
    //deleting the bunker
    bunker *bnk = static_cast<bunker*>(**e);
    bnk->rip();
    bunkers.remove(bnk);
    *e = enemies.erase(*e);
    Gameplay->deathBunker();

    //go back to Galaxy if all the bunkers are dead
    if(bunkers.empty()){
      allies.remove(static_cast<drawable*>(Player));
      Player->setPlayground(Galaxy);
      Gameplay->setMainViewer(Galaxy);

      this->changeViewer = true;
    }
  }

  Player->rip();                          //player losing a life

  //restarting the game if spaceship has lost all his lifes else restarting only the view
  if(!Player->isAlive()){
    Gameplay->restart();
    this->endGame = true;
  }else{
    this->restart();
    restartViewer = true;
  }
}

void planetView::back(){
  Player->SetPosition(information::PLAYER_DEFAULT_POSITION);
  Player->setPlayground(Galaxy);
  Gameplay->setMainViewer(Galaxy);

  this->changeViewer = true;
  this->restart();
}

std::string planetView::Class(){
  return "planetView";
}
