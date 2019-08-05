//SPACESHIP
//Class that handle everything that concerne a spaceship

/*
  ISSUE:
    -> nella costruzione immagine ruotata di 90°
*/

class collisionHandler{
  public:
    //METHODS
    //It let the spaceship move or rotate based on the key pressed
    void checkOutOfBounds(spaceship *S, sf::VideoMode *desktop){
      // get the bounding box of the entity
      sf::FloatRect spaceshipBoundingBox = S->getGlobalBounds();
      sf::FloatRect desktopBoundingBox(0, 0, desktop->width, desktop->height);
      
      // check collision with another box (like the bounding box of another entity)
      desktopBoundingBox.intersects(spaceshipBoundingBox, spaceshipBoundingBox);

      //Y OUT OF BOUNDS
      if(checkSide(spaceshipBoundingBox.top + spaceshipBoundingBox.height, desktopBoundingBox.top + desktopBoundingBox.height) || checkSide(spaceshipBoundingBox.top, desktopBoundingBox.top)){
        S->setYOutOfBounds(true);

        if(checkSide(spaceshipBoundingBox.top, desktopBoundingBox.top))
          S->setTopOutOfBounds(true);
        else
          S->setTopOutOfBounds(false);

      }else
        S->setYOutOfBounds(false);

      //X OUT OF BOUNDS
      if(checkSide(spaceshipBoundingBox.left + spaceshipBoundingBox.width, desktopBoundingBox.left + desktopBoundingBox.width) || checkSide(spaceshipBoundingBox.left, desktopBoundingBox.left)){
        S->setXOutOfBounds(true);

        if(checkSide(spaceshipBoundingBox.left, desktopBoundingBox.left))
          S->setLeftOutOfBounds(true);
        else
          S->setLeftOutOfBounds(false);

      }else
        S->setXOutOfBounds(false);

    }

    bool checkSide(float side1, float side2){
      if(side1 == side2)
        return true;

      return false;
    }
};