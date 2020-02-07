#include "menu.hpp"

//CONSTRUCTORS
menu::menu(sf::RenderWindow* wnd) : scene(wnd){
  view = new startView(Window);
  Viewer = view;
}

menu::~menu(){
  std::cout << "DELETING SCENE" << std::endl;

  if(!!view)
    delete view;

  view = nullptr;
  //Window = nullptr;
}


//GETS
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//SETS
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}


//---------------METHODS---------------

void menu::start (){
  // run the program as long as the window is open
  while (Window->isOpen()){
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;

    while (Window->pollEvent(event))
      this->eventHandler(event);

    Window->clear();

    Viewer->Draw();

    // end the current frame
    Window->display();

  }
}

void menu::eventHandler(const sf::Event &event){
  switch (event.type) {
    //KEYRELEASED
    //case sf::Event::KeyReleased :{
      //eventHandler::keyReleasedHandler(event);
    //};break;

    //KEYPRESSED
    case sf::Event::KeyPressed :{
      this->keyPressedHandler(event);
    }

    //WINDOWCLOSED
    case sf::Event::Closed :{
      eventHandler::windowClosedHandler(event, *Window);
    };break;

    default :
      break;
  }
}

void menu::keyPressedHandler(const sf::Event &e){
  switch (e.key.code) {                                             //LEFT
    case sf::Keyboard::Up : {
      view->selectNext();
      std::cout << "the key pressed is: " << e.key.code << std::endl;
    };break;

    case sf::Keyboard::Down : {
      view->selectPrev();
      std::cout << "the key pressed is: " << e.key.code << std::endl;
    };break;
    //default: std::cout << "the key pressed is: " << e.key.code << std::endl;
  }

  /*
  std::cout << "the key pressed is: " << event.key.code << std::endl;
  std::cout << "control:" << event.key.control << std::endl;
  std::cout << "alt:" << event.key.alt << std::endl;
  std::cout << "shift:" << event.key.shift << std::endl;
  std::cout << "system:" << event.key.system << std::endl;
  */
}

// void eventHandler::keyReleasedHandler (const sf::Event& e){
//   switch (e.key.code) {
//     case sf::Keyboard::Left : { }                                      //LEFT
//     case sf::Keyboard::Right : { r->setTransformation(false); };break;            //RIGHT
//     case sf::Keyboard::Up : { }                                        //UP
//     case sf::Keyboard::Down : { t->setTransformation(false); };break;            //DOWN
//     default: break;
//   }
// }

//----------METHODS----------
std::string menu::Class(){
  return "menu";
}
