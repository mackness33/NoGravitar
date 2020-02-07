#include "gameplay.hpp"

//CONSTRUCTORS
gameplay::gameplay(sf::RenderWindow* wnd) : scene(wnd) {
  Player = new spaceship(nullptr);
  Header = new header(Window);
  //Settings = new information(Window);
  Galaxy = new galaxy(Window, Player, 20, this);
  StartView = new startView(Window);
  this->Viewer = StartView;
  Player->setPlayground(Galaxy);

  information::DELTA_TIME = 10.0f;
}

gameplay::~gameplay(){
  std::cout << "DELETING GAMEPLAY" << std::endl;

  if(!!Player)
    delete Player;

  if(!!Galaxy)
    delete Galaxy;

  if(!!Header)
    delete Header;

  //if(!!Settings)
    //delete Settings;

  //if(!!Viewer)
    //delete Viewer;

  Window = nullptr;
  Player = nullptr;
  Header = nullptr;
  //Settings = nullptr;
  Galaxy = nullptr;
  //Viewer = nullptr;

}


//GETS
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//SETS
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}


//---------------METHODS---------------

void gameplay::eventHandler(const sf::Event &event){
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

//DRAW
void gameplay::start (){
  // run the program as long as the window is open
  while (Window->isOpen()){
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;

    while (Window->pollEvent(event))
      this->eventHandler(event);

    collisionHandler::checkOutOfBounds(Player, this->Viewer);

    //module keys
    translation.isUsed(sf::Keyboard::Up, sf::Keyboard::Down);   //which key has been pressed
    if(translation.getTransformation())                         //if pressed make a transformation of the object
      Player->movement(translation.getKey()/*, &spaceshipBoundingBox*/);


    //direction keys
    rotation.isUsed(sf::Keyboard::Right, sf::Keyboard::Left);   //which key has been pressed
    if(rotation.getTransformation())                            //if pressed make a transformation of the object
      Player->movement(rotation.getKey()/*, &spaceshipBoundingBox*/);

    //gameplay::Viewer->checkCollision();

    Window->clear();

    this->draw();

    // end the current frame
    Window->display();

  }
}


void gameplay::draw (){
  Header->Draw();
  this->Viewer->Draw();
}

void gameplay::setMainViewer(viewer* newViewer){
  this->Viewer = newViewer;
}

std::string gameplay::Class(){
  return "gameplay";
}
