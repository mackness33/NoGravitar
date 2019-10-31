//UNIVERSE
//Class that handle everything that concerne the top of the window

/*

*/
#include "game.hpp"
#define PI 3.14159265

//CONSTRUCTORS
game::game(sf::RenderWindow* wnd){
  spaceshipImage.setSmooth(true);

  Window = wnd;

  Spaceship = new spaceship(nullptr, &spaceshipImage);
  Header = new header(Window);
  Settings = new settings(Window);
  Galaxy = new galaxy(Window, Spaceship, 5);
  Spaceship->setPlayground(Galaxy);
  Playground = Galaxy;

  settings::deltaTime = 10.0f;
  settings::switchTime = 10.0f;
}

  /*
  //texture.create((unsigned int)size->x, (unsigned int)size->y);
  if(!texture.loadFromFile("img/game.png"))
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


//GETS
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//SETS
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}


//---------------METHODS---------------


//DRAW
void game::start (){
  // run the program as long as the window is open
  while (Window->isOpen()){
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;

    while (Window->pollEvent(event)){

      switch (event.type) {
        //KEYRELEASED
        case sf::Event::KeyReleased :{
          eventHandler::keyReleasedHandler(event, &translation, &rotation);
        };break;

        //KEYPRESSED
        case sf::Event::KeyPressed :{
          eventHandler::keyPressedHandler(Spaceship, event);
        }

        //WINDOWCLOSED
        case sf::Event::Closed :{
          eventHandler::windowClosedHandler(event, *Window);
        };break;

        default :
          break;
      }

    }

    collisionHandler::checkOutOfBounds(Spaceship, Playground);

    //module keys
    translation.isUsed(sf::Keyboard::Up, sf::Keyboard::Down);   //which key has been pressed
    if(translation.getTransformation())                         //if pressed make a transformation of the object
      Spaceship->movement(translation.getKey()/*, &spaceshipBoundingBox*/);


    //direction keys
    rotation.isUsed(sf::Keyboard::Right, sf::Keyboard::Left);   //which key has been pressed
    if(rotation.getTransformation())                            //if pressed make a transformation of the object
      Spaceship->movement(rotation.getKey()/*, &spaceshipBoundingBox*/);

    Playground->checkCollision();

    Window->clear();

    this->draw();

    // end the current frame
    Window->display();

  }
}

void game::draw (){
  Header->Draw();
  Playground->Draw();
}
