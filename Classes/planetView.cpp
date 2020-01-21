#include "planetView.hpp"

//----------CONSTRUCTORS----------
planetView::planetView(sf::RenderWindow* win, spaceship* spc, game* actGame) : playground(win){
  currentGame = actGame;

  Player = spc;
  playground::addAlly(spc);
  Player->getMovable()->SetPosition(100, 200);

  sf::Vector2f plgBound = viewer::getDrawable()->getSize() - sf::Vector2f(100, 100);
  Ground = new ground(information::MENU_DEFAULT_SIZE.x, information::MENU_DEFAULT_SIZE.y);

  std::vector<line*> lines = Ground->getLines();

  bunkers = new bunker(*lines[0]);

  playground::addEnemy(Ground);
  playground::addEnemy(bunkers);
}

//----------GETS----------
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//----------SETS----------
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}

//----------METHODS---------------
//TODO: Need to delete the object at the end of all the cicles!
//TODO: consider to delete in a good way the mo'fucking pointers
void planetView::checkCollision (){
  bool cll = false, changeViewer = false;
  //std::cout << "START!!" << std::endl;
  int i = 0;
  for (auto ally = allies.begin(); ally != allies.end(); changeViewer = false){
    //std::cout << "Ally: " << i << std::endl;
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

//TODO: first need to check enemies, than allies
void planetView::collision(std::_List_iterator<drawable*>* a, std::_List_iterator<drawable*>* e, bool* cv){
  std::string allyClass = (**a)->Class();
  std::cout << "In Collision checkin up " << allyClass << std::endl;

  switch(allyClass[0]){
    case 'b': { this->collisionBullet(&*a, &*e); }; break;
    case 's': { this->collisionSpaceship(&*a, &*e, cv); }; break;
    default: std::cout << allyClass << "in Allies" << std::endl;
  }
}

void planetView::collisionBullet(std::_List_iterator<drawable*>* blt, std::_List_iterator<drawable*>* e){

  std::string enemyClass = (**e)->Class();
  std::string bulletClass = (**blt)->Class();
  std::cout << "In CollisionBullet checkin up " << enemyClass << std::endl;
  std::cout << "In CollisionBullet checkin up " << bulletClass << std::endl;


  sf::Vector2f left = utility::left(**blt);
  sf::Vector2f right = utility::right(**blt);
  sf::Vector2f top = utility::top(**blt);
  sf::Vector2f bottom = utility::bottom(**blt);

  Player->deleteBullet(static_cast<bullet*>(**blt));
  *blt = allies.erase(*blt);

  switch(enemyClass[0]){
    case 'b': {
      std::cout << "deleting a bunker from Bullet" << std::endl;
    }; break;

    case 'p': {
      std::cout << "Bounce in Planet" << std::endl;
    }; break;

    case 'g': {
      std::cout << "COLLISION WITH GROUND" << std::endl;
    }; break;

    default: std::cout << enemyClass << "in Enemies" << std::endl;
  }
}

void planetView::collisionSpaceship(std::_List_iterator<drawable*>* spc, std::_List_iterator<drawable*>* e, bool* cv){
  std::cout << "In CollisionSpaceship" << std::endl;
  std::string enemyClass = (**e)->Class();

  switch(enemyClass[0]){
    case 'b': {
      std::cout << "deleting a enemy bullet from Spaceship" << std::endl;
    }; break;

    case 'p': {
      //Player->deleteBullets();     //delete all the bullets
      allies.clear();

      planetObj *planet = static_cast<planetObj*> (**e);
      Player->setPlayground(planet->getPlanetView());
      currentGame->setMainViewer(planet->getPlanetView());

      *cv = true;

      std::cout << "Bounce in Ground from Spaceship" << std::endl;
    }; break;

    default: std::cout << enemyClass << "in Enemies" << std::endl;
  }
}

std::string planetView::Class(){
  return "planetView";
}
