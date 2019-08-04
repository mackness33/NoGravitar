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
      if (!desktopBoundingBox.intersects(spaceshipBoundingBox, spaceshipBoundingBox)){
        /*std::cout << "Desktop Left: " << typeid(desktopBoundingBox.left).name() << std::endl;
        std::cout << "Desktop Right: " << desktopBoundingBox.left + desktopBoundingBox.width << std::endl;
        std::cout << "Desktop Top: " << desktopBoundingBox.top << std::endl;
        std::cout << "Desktop Buttom: " << desktopBoundingBox.top + desktopBoundingBox.height << std::endl;
        std::cout << "Spaceship Left: " << spaceshipBoundingBox.left << std::endl;
        std::cout << "Spaceship Right: " << spaceshipBoundingBox.left + spaceshipBoundingBox.width << std::endl;
        std::cout << "Spaceship Top: " << spaceshipBoundingBox.top << std::endl;
        std::cout << "Spaceship Buttom: " << spaceshipBoundingBox.top + spaceshipBoundingBox.height << std::endl;
        */
        //std::cout << "OutOfBounds!!!" << std::endl;
      }

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
