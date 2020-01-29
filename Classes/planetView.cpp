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

  bunkers = std::list<bunker*>();

  inizializeBunker();

  playground::addNeutral(Ground);
}

planetView::~planetView(){
  std::cout << "DELETING PLANETVIEW" << std::endl;

  //delete Ground;
  //delete bunkers;
  utility::deleteList(bunkers);

  Player = nullptr;
  Ground = nullptr;
  Galaxy = nullptr;
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
void planetView::inizializeBunker(){
  std::vector<line*> lines = Ground->getLines();
  bool occupied[20];
  int numBunker = lines.size() - 3;
  int pos = 0;
  bunker *tempi = nullptr;

  for(int k = 0; k < lines.size(); k++)
    occupied[k] = false;

  for(int i = 0; i < numBunker;){
    pos = utility::RandInt(lines.size());

    if(!occupied[pos]){
      bunker *temp = new bunker(this, *lines[pos]);
      bunkers.push_front(temp);
      playground::addEnemy(temp);

      occupied[pos] = true;
      i++;
    }
  }

}

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
      if(changeViewer)
        break;
    }

    if(changeViewer)
      break;

    if(!intersection)
      ally++;
  }

  if(changeViewer)
    Galaxy->delPlanet(Planet);

  /*for (auto neutral = neutrals.begin(); neutral != neutrals.end();){
    for (auto object = objects.begin(); object != objects.end(); object++, intersection = false){
      if(!!*neutral && !!*object){
        if((*object)->intersects(*neutral)){
          //collision(&neutral, &object, &changeViewer);
          std::cout << "COLLISION!!" << std::endl;
          intersection = true;
        }
      }
      if(changeViewer)
        {break;}
    }

    if(changeViewer)
      {break;}

    if(!intersection)
      neutral++;
  }*/


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
        bunkers.remove(static_cast<bunker*>(**e));
        std::cout << "Here" << std::endl;
        *e = enemies.erase(*e);
        objects.remove(**e);

        if(bunkers.empty()){
          allies.remove(static_cast<drawable*>(Player));
          objects.remove(static_cast<drawable*>(Player));
          Player->setPlayground(Galaxy);
          currentGame->setMainViewer(Galaxy);

          std::cout << "this to?" << std::endl;

          *cv = true;
        }
        std::cout << "Bullet VS. Bunker" << std::endl;
      }
      else{
        //Player->deleteBullet(static_cast<bullet*>(**e));
        *e = enemies.erase(*e);
        objects.remove(**e);

        std::cout << "Bullet VS. Bullet" << std::endl;
      }

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
