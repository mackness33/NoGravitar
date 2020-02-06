#include "scene.hpp"

viewer scene::*Playground = nullptr;

//CONSTRUCTORS
scene::scene(sf::RenderWindow* wnd) : Window(wnd), isActive(false), Viewer(nullptr){}

scene::~scene(){
  std::cout << "DELETING SCENE" << std::endl;

  if(!!viewer)
    delete viewer;

  viewer = nullptr;
  Window = nullptr;
}


//GETS
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//SETS
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}


//---------------METHODS---------------

void scene::eventHandler(const sf::Event &event){
  switch (event.type) {
    //KEYRELEASED
    case sf::Event::KeyReleased :{
      eventHandler::keyReleasedHandler(event);
    };break;

    //KEYPRESSED
    case sf::Event::KeyPressed :{
      eventHandler::keyPressedHandler(event);
    }

    //WINDOWCLOSED
    case sf::Event::Closed :{
      eventHandler::windowClosedHandler(event, *Window);
    };break;

    default :
      break;
  }
}

//----------METHODS----------
void scene::stop (){ isActive = false; }

void scene::swap (scene* next){
  this->stop();
  next->start();
}

//DRAW
void scene::start (){
  this->isActive = true;
  // run the program as long as the window is open
  while (this->isActive){
    if(!isActive)
      break;
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;

    while (Window->waitEvent(event)){
      this->eventHandler(event);
    }

    Window->clear();
    this->draw();
    Window->display();

  }
}

void scene::setMainViewer(viewer* newViewer){
  Playground = newViewer;
}

std::string scene::Class(){
  return "scene";
}
