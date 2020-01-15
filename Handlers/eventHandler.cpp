#include "eventHandler.hpp"

void eventHandler::keyReleasedHandler (sf::Event& e/*vent*/, keyVector* t/*ranslation*/, keyVector* r/*otation*/){
  switch (e.key.code) {
    case sf::Keyboard::Left : { }                                      //LEFT
    case sf::Keyboard::Right : { r->setTransformation(false); };break;            //RIGHT
    case sf::Keyboard::Up : { }                                        //UP
    case sf::Keyboard::Down : { t->setTransformation(false); };break;            //DOWN
    default: break;
  }
}

//It handle KeyEvent::KeyPressed
//It gives information bout transformation of the spaceship
void eventHandler::keyPressedHandler (spaceship* S/*paceship*/, sf:: Event& e){
  switch (e.key.code) {                                             //LEFT
    case sf::Keyboard::S : {
      S->shoot();
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

//It handle Event::Closed
//it close the window if pressed 'Q', 'ESC' or close button
void eventHandler::windowClosedHandler (sf::Event& e/*vent*/, sf::RenderWindow& w/*indow*/){
  // "close requested" event: we close the window
  if (e.type == sf::Event::Closed || (e.type == sf::Event::KeyPressed && (e.key.code == 16 || e.key.code == 36)))
    w.close();
}
