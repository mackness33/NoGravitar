#include "planetView.hpp"

//----------CONSTRUCTORS----------
planetView::planetView(sf::RenderWindow* win, spaceship* spc, game* actGame, galaxy* glx, planetObj* pln) : playground(win){
  currentGame = actGame;
  Galaxy = glx;
  Planet = pln;
  Player = spc;

  playground::addAlly(spc);
  Player->getMovable()->SetPosition(100, 200);

  sf::Vector2f plgBound = viewer::getDrawable()->getSize() - sf::Vector2f(100, 100);
  Ground = new ground(information::MENU_DEFAULT_SIZE.x, information::MENU_DEFAULT_SIZE.y);

  std::vector<line*> lines = Ground->getLines();

  bunkers = new bunker(this, *lines[0]);

  playground::addEnemy(Ground);
  playground::addEnemy(bunkers);
}

planetView::~planetView(){
  std::cout << "DELETING PLANETVIEW" << std::endl;

  //delete Ground;
  //delete bunkers;

  Player = nullptr;
  Ground = nullptr;
  Galaxy = nullptr;
  bunkers = nullptr;
  currentGame = nullptr;
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
//TODO: Need to delete the object at the end of all the cicles!
//TODO: consider to delete in a good way the mo'fucking pointers
void planetView::checkCollision (){
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

    if(changeViewer) {
      //Galaxy->delPlanet(Planet);
      break;
    }

    if(!intersection) {ally++;}
  }

  if(changeViewer) {
    Galaxy->delPlanet(Planet);
  }
}

//TODO: first need to check enemies, than allies
void planetView::collision(std::_List_iterator<drawable*>* a, std::_List_iterator<drawable*>* e, bool* cv){
  std::string allyClass = (**a)->Class();
  std::cout << "In Collision checkin up " << allyClass << std::endl;

  switch(allyClass[0]){
    case 'b': { this->collisionBullet(&*a, &*e, cv); }; break;
    case 's': { this->collisionSpaceship(&*a, &*e, cv); }; break;
    default: std::cout << allyClass << "in Allies" << std::endl;
  }
}

void planetView::collisionBullet(std::_List_iterator<drawable*>* blt, std::_List_iterator<drawable*>* e, bool* cv){

  std::string enemyClass = (**e)->Class();
  std::string bulletClass = (**blt)->Class();
  std::cout << "In CollisionBullet checkin up " << enemyClass << std::endl;
  std::cout << "In CollisionBullet checkin up " << bulletClass << std::endl;


  Player->deleteBullet(static_cast<bullet*>(**blt));
  *blt = allies.erase(*blt);
  objects.remove(**blt);

  switch(enemyClass[0]){
    case 'b': {
      if(enemyClass[2] == 'n'){
        allies.remove(static_cast<drawable*>(Player));
        objects.remove(static_cast<drawable*>(Player));
        Player->setPlayground(Galaxy);
        currentGame->setMainViewer(Galaxy);

        *cv = true;
      }

      std::cout << "Bounce in Ground from Spaceship" << std::endl;
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

      std::cout << "Bounce in Ground from Spaceship" << std::endl;
    }; break;

    default: std::cout << enemyClass << "in Enemies" << std::endl;
  }
}

std::string planetView::Class(){
  return "planetView";
}
