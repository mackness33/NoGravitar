#include "game.hpp"

viewer game::*Playground = nullptr;

//CONSTRUCTORS
game::game(sf::RenderWindow* wnd){
  Window = wnd;

  information::inizialize(Window->getSize());

  Player = new spaceship(nullptr);
  Header = new header(Window);
  //Settings = new information(Window);
  Galaxy = new galaxy(Window, Player, 20, this);
  Playground = Galaxy;
  Player->setPlayground(Galaxy);

  information::DELTA_TIME = 10.0f;
}

game::~game(){
  std::cout << "DELETING GAME" << std::endl;

  if(!!Player)
    delete Player;

  if(!!Galaxy)
    delete Galaxy;

  if(!!Header)
    delete Header;

  if(!!Settings)
    delete Settings;

  if(!!Playground)
    delete Playground;

  Window = nullptr;
  Player = nullptr;
  Header = nullptr;
  Settings = nullptr;
  Galaxy = nullptr;
  Playground = nullptr;

}


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
          eventHandler::keyPressedHandler(Player, event);
        }

        //WINDOWCLOSED
        case sf::Event::Closed :{
          eventHandler::windowClosedHandler(event, *Window);
        };break;

        default :
          break;
      }

    }

    collisionHandler::checkOutOfBounds(Player, Playground);

    //module keys
    translation.isUsed(sf::Keyboard::Up, sf::Keyboard::Down);   //which key has been pressed
    if(translation.getTransformation())                         //if pressed make a transformation of the object
      Player->movement(translation.getKey()/*, &spaceshipBoundingBox*/);


    //direction keys
    rotation.isUsed(sf::Keyboard::Right, sf::Keyboard::Left);   //which key has been pressed
    if(rotation.getTransformation())                            //if pressed make a transformation of the object
      Player->movement(rotation.getKey()/*, &spaceshipBoundingBox*/);

    //game::Playground->checkCollision();

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

void game::setMainViewer(viewer* newViewer){
  Playground = newViewer;
}

std::string game::Class(){
  return "game";
}
