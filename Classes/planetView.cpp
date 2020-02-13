#include "planetView.hpp"

//----------CONSTRUCTORS----------
planetView::planetView(sf::RenderWindow* win, spaceship* spc, gameplay* actGame, galaxy* glx, planetObj* pln) : playground(win), restartViewer(false), changeViewer(false){
  Gameplay = actGame;
  Galaxy = glx;
  Planet = pln;
  Player = spc;

  playground::addAlly(spc);
  Player->SetPosition(information::PLAYER_DEFAULT_POSITION);

  sf::Vector2f plgBound = viewer::getDrawable()->getSize() - sf::Vector2f(100, 100);
  Ground = new ground(information::MENU_DEFAULT_SIZE.x, information::MENU_DEFAULT_SIZE.y);

  bunkers = std::list<bunker*>();
  fuels = std::list<fuel*>();

  inizializeBunker();

  playground::addNeutral(Ground);
}

planetView::~planetView(){
  std::cout << "DELETING PLANETVIEW" << std::endl;

  //delete Ground;
  //delete bunkers;
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
//----------GETS----------
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//----------SETS----------
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}

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
  bunker *temp = new bunker(this, *lines[2]);
  bunkers.push_front(temp);
  playground::addEnemy(temp);

  // bool occupied[20];
  // //TODO
  // int numBunker = lines.size() - 3;
  // int numFuel = 2;
  // int pos = 0;
  // bunker *tempBunker = nullptr;
  // fuel *tempFuel = nullptr;
  //
  // for(int k = 0; k < lines.size(); k++)
  //   occupied[k] = false;
  //
  // for(int i = 0; i < numBunker;){
  //   pos = utility::RandInt(lines.size());
  //
  //   if(!occupied[pos]){
  //     tempBunker = new bunker(this, *lines[pos]);
  //     bunkers.push_front(tempBunker);
  //     playground::addEnemy(tempBunker);
  //
  //     occupied[pos] = true;
  //     i++;
  //   }
  // }
  //
  // for(int i = 0; i < numFuel;){
  //   pos = utility::RandInt(lines.size());
  //
  //   if(!occupied[pos]){
  //     tempFuel = new fuel(*lines[pos]);
  //     fuels.push_front(tempFuel);
  //     playground::addAlly(tempFuel);
  //
  //     occupied[pos] = true;
  //     i++;
  //   }
  // }

}

//TODO: Need to delete the object at the end of all the cicles!
//TODO: consider to delete in a good way the mo'fucking pointers
void planetView::checkCollision (){
  playground::checkCollision();
  changeViewer = false, restartViewer = false;

  for (auto ally = allies.begin(); ally != allies.end(); ally++){
    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++){
      if(!!*ally && !!*enemy){
        if((*ally)->intersects(*enemy)){
          collision(&ally, &enemy);
          std::cout << "COLLISION!!" << std::endl;
        }
      }

      if(changeViewer && !endGame){
        Galaxy->delPlanet(Planet);
        return;
      }

      if(endGame || restartViewer)
        return;
    }
  }

  for (auto neutral = neutrals.begin(); neutral != neutrals.end(); neutral++){
    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++){
      if(!!*neutral && !!*enemy){
        if ((*neutral)->intersects(*enemy) && (*enemy)->Class().compare("bunker") != 0){
          collision(&enemy, false);
          std::cout << "COLLISION NEUTRAL in planetView!!" << std::endl;
        }
      }

    }

    for (auto ally = allies.begin(); ally != allies.end(); ally++){
      if(!!*neutral && !!*ally){
        if ((*neutral)->intersects(*ally) && (*ally)->Class().compare("fuel") != 0){
          collision(&ally, true);
          std::cout << "COLLISION NEUTRAL in PLANETVIEW!!" << std::endl;
        }

        if(endGame || restartViewer)
          return;
      }
    }
  }

  if(information::TRACTORBEAM_IS_ACTIVE){
    tractorBeam *trb = Player->getTractorBeam();

    for(auto f = fuels.begin(); f != fuels.end(); f++){
      if((*f)->intersects(trb)){
        allies.remove(static_cast<drawable*>(*f));
        f = fuels.erase(f);
        Gameplay->addFuel();
      }
    }
  }
}

void planetView::collision(std::_List_iterator<drawable*>* obj, bool isAlly){
  std::string objectClass = (**obj)->Class();
  std::cout << "In Collision checkin up " << objectClass << std::endl;

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

    default: std::cout << objectClass << "in Objects" << std::endl;
  }
}

//TODO: first need to check enemies, than allies
void planetView::collision(std::_List_iterator<drawable*>* a, std::_List_iterator<drawable*>* e){
  std::string allyClass = (**a)->Class();
  std::cout << "In Collision checkin up " << allyClass << std::endl;

  switch(allyClass[0]){
    case 'b': { this->collisionBullet(&*a, &*e); }; break;
    case 's': { this->collisionSpaceship(&*a, &*e); }; break;
    default: std::cout << allyClass << "in Allies" << std::endl;
  }
}

void planetView::collisionBullet(std::_List_iterator<drawable*>* blt, std::_List_iterator<drawable*>* e){

  std::string enemyClass = (**e)->Class();
  std::string bulletClass = (**blt)->Class();
  std::cout << "In CollisionBullet checkin up " << enemyClass << std::endl;
  std::cout << "In CollisionBullet checkin up " << bulletClass << std::endl;


  Player->deleteBullet(static_cast<bullet*>(**blt));
  *blt = allies.erase(*blt);

  switch(enemyClass[0]){
    case 'b': {
      if(enemyClass[2] == 'n'){
        bunker *bnk = static_cast<bunker*>(**e);
        bnk->rip();
        bunkers.remove(bnk);
        *e = enemies.erase(*e);
        Gameplay->deathBunker();

        if(bunkers.empty()){
          allies.remove(static_cast<drawable*>(Player));
          Player->setPlayground(Galaxy);
          Gameplay->setMainViewer(Galaxy);

          this->changeViewer = true;
        }
      }
      else{
        bullet *bll = static_cast<bullet*>(**e);
        shooter *parent = bll->getShooter();
        parent->deleteBullet(bll);
        *e = enemies.erase(*e);
      }

    }; break;

    default: std::cout << enemyClass << "in Enemies" << std::endl;
  }
}

void planetView::collisionSpaceship(std::_List_iterator<drawable*>* spc, std::_List_iterator<drawable*>* e){
  std::cout << "In CollisionSpaceship" << std::endl;
  std::string enemyClass = (**e)->Class();
  std::cout << "In CollisionSpaceship checkin up " << enemyClass << std::endl;

  if(enemyClass.compare("bunker") == 0){
    bunker *bnk = static_cast<bunker*>(**e);
    bnk->rip();
    bunkers.remove(bnk);
    *e = enemies.erase(*e);
    Gameplay->deathBunker();

    if(bunkers.empty()){
      allies.remove(static_cast<drawable*>(Player));
      Player->setPlayground(Galaxy);
      Gameplay->setMainViewer(Galaxy);

      this->changeViewer = true;
    }
    std::cout << "Spaceship VS. Bunker" << std::endl;
  }

  Player->rip();
  if(!Player->isAlive()){
    Gameplay->restart();
    this->endGame = true;
  }else{
    this->restart();
    restartViewer = true;
  }
}

std::string planetView::Class(){
  return "planetView";
}
