//UNIVERSE
//Class that handle everything that concerne the top of the window

/*

*/
#include "galaxy.hpp"
#define PI 3.14159265

//CONSTRUCTORS
galaxy::galaxy(sf::RenderWindow* win, spaceship* spc, unsigned int numPlanets) : viewer(win){
  S = spc;

  // Setting bounding box
  sf::Vector2f playground = this->getDrawable()->getSize() - sf::Vector2f(100, 100);
  std::cout << "rand x: " << playground.x << std::endl;
  std::cout << "rand y: " << playground.y << std::endl;

  planets = {};

  std::list<sf::FloatRect> posPlanets = {};

  for (int i = 0; i < 20; i++){
    sf::Vector2f position = utility::RandVector(playground.x, playground.y, 0, win->getSize().y/10);
    //sf::Vector2f position = utility::RandVector(win->getSize().x, win->getSize().y);
    std::cout << "pos x: " << position.x << std::endl;
    std::cout << "pos y: " << position.y << std::endl;
    if(this->checkPlanetPosition(&posPlanets, position)){
      planetObj *pln = new planetObj(utility::Rand(20, 30), position);
      //pln->getBody()->SetOrigin(pos);
      planets.push_front(pln);
      posPlanets.push_front(pln->GetGlobalBounds());
    }
    else{
      std::cout << "INTERSECTS!" << std::endl;
      i--;
    }
  }

  /*
  //texture.create((unsigned int)size->x, (unsigned int)size->y);
  if(!texture.loadFromFile("img/galaxy.png"))
    std::cout << "Error in load images" << std::endl;
  else
    std::cout << "PERFECT!" << std::endl;

  background.setTexture(texture);
  //background.setTextureRect(sf::IntRect(300, 300, 500, 300));
  background.setColor(sf::Color::Blue);
  background.setPosition(*position);
  //background.scale(200, 200);
  //sprite.setSize(0, 0);
  */
}

//GETS
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//SETS
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}


//---------------METHODS---------------


//DRAW
void galaxy::Draw (/*sf::RenderWindow* window*/){
  viewer::Draw();
  S->Draw(window);
  this->DrawPlanets();
  //window->draw(background);
}

bool galaxy::checkPlanetPosition(std::list<sf::FloatRect>* posPlanets, sf::Vector2f pos){
  sf::FloatRect newPlanetBound (pos, sf::Vector2f(100, 100));
  sf::FloatRect planetsIntersection;
  int i = 0;

  for(std::list<sf::FloatRect>::iterator boundPlanet = posPlanets->begin(); boundPlanet != posPlanets->end(); boundPlanet++, i++){
      std::cout << "intersects: " << newPlanetBound.intersects(*boundPlanet, planetsIntersection) << std::endl;
      if(planetsIntersection != sf::FloatRect(0,0,0,0))
        return false;
  }

  return true;
}

void galaxy::DrawPlanets (/*sf::RenderWindow* window*/){
  planetObj *pln;
  for (std::list<planetObj*>::iterator p = planets.begin(); p != planets.end(); p++){
    //std::cout << "position i: " << i << std::endl;
    pln = *p;
    //std::cout << "Does the bullet exist: " << !!bul << std::endl;
    if(!!pln){
      //std::cout << "real location of " << i << "^ bullet: " << bul << std::endl;
      pln->Draw(window);
    }
  }
}


void galaxy::checkCollision (){}

//
