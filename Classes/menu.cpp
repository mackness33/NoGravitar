#include "menu.hpp"

//---------------CONSTRUCTORS---------------
menu::menu(sf::RenderWindow* wnd, game* g) : scene(wnd), Game(g){
  view = new startView(Window);
  this->Viewer = view;
}

menu::~menu(){
  if(!!view)
    delete view;

  view = nullptr;
}

//---------------METHODS---------------
void menu::eventHandler(const sf::Event &event){
  switch (event.type) {
    //KEYPRESSED
    case sf::Event::KeyPressed :{
      this->keyPressedHandler(event);
    }

    //WINDOWCLOSED
    case sf::Event::Closed :{
      this->windowClosedHandler(event);
    };break;

    default :
      break;
  }
}

void menu::keyPressedHandler(const sf::Event &e){
  switch (e.key.code) {                                             //LEFT
    case sf::Keyboard::Up : {
      view->selectNext();
    };break;

    case sf::Keyboard::Down : {
      view->selectPrev();
    };break;

    case sf::Keyboard::Return : {
      //switch to understand in which view to go next. The value is the name of the next Scene or View to go next
      switch((view->getValue())[0]){
        case 'G': Game->setMainScene("gameplay"); break;
        default: {}
      }
    };break;
    default: ;
  }
}

//----------METHODS----------
std::string menu::Class(){
  return "menu";
}
