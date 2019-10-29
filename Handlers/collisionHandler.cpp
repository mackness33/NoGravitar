//COLLISIONHANDLER
//Class that handle collision

/*

*/
#include "collisionHandler.hpp"

//-------------METHODS------------
//It let the spaceship move or rotate based on the key pressed
void collisionHandler::checkOutOfBounds(spaceship *spc, viewer* plg){
  // get the bounding box of the entity
  sf::FloatRect bbSpaceship = spc->getBody()->getGlobalBounds();     //bb => BoundBox
  sf::FloatRect bbPlayground = plg->getBackground()->getBody()->getGlobalBounds();

  // check collision with another box (like the bounding box of another entity)
  bbPlayground.intersects(bbSpaceship, bbSpaceship);

  //TODO: make methods to organize checkOutOfBounds spaceship
  //Y OUT OF BOUNDS
  if(checkSide(bbSpaceship.top + bbSpaceship.height, bbPlayground.top + bbPlayground.height) || checkSide(bbSpaceship.top, bbPlayground.top)){
    spc->setYOutOfBounds(true);

    if(checkSide(bbSpaceship.top, bbPlayground.top))
      spc->setTopOutOfBounds(true);
    else
      spc->setTopOutOfBounds(false);

  }
  else
    spc->setYOutOfBounds(false);

  //X OUT OF BOUNDS
  if(checkSide(bbSpaceship.left + bbSpaceship.width, bbPlayground.left + bbPlayground.width) || checkSide(bbSpaceship.left, bbPlayground.left)){
    spc->setXOutOfBounds(true);

    if(checkSide(bbSpaceship.left, bbPlayground.left))
      spc->setLeftOutOfBounds(true);
    else
      spc->setLeftOutOfBounds(false);

  }
  else
    spc->setXOutOfBounds(false);

}

bool collisionHandler::checkSide(float side1, float side2){
  if(side1 == side2)
    return true;

  return false;
}
