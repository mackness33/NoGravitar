//EVENTHANDLER
//Class that handle events

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "collisionHandler.hpp"
#include "../Classes/keyVector.hpp"

class eventHandler{
  public:
    //It handle KeyEvent::KeyReleased.
    //It stops the movement
    static void keyReleasedHandler (sf::Event& e/*vent*/, keyVector* t/*ranslation*/, keyVector* r/*otation*/){
      switch (e.key.code) {
        case sf::Keyboard::Left : { }                                      //LEFT
        case sf::Keyboard::Right : { r->setTransformation(false); };break;            //RIGHT
        case sf::Keyboard::Up : { }                                        //UP
        case sf::Keyboard::Down : { t->setTransformation(false); };break;            //DOWN
        default:
          break;
      }
    }

    //It handle KeyEvent::KeyPressed
    //It gives information bout transformation of the spaceship
    static void keyPressedHandler (spaceship* S/*paceship*/, sf:: Event& e){
      switch (e.key.code) {                                             //LEFT
        case sf::Keyboard::Space : {
          S->Shoot();
        };break;

        default: std::cout << "the key pressed is: " << e.key.code << std::endl;
      }

      /*
      std::cout << "the key pressed is: " << event.key.code << std::endl;
      std::cout << "control:" << event.key.control << std::endl;
      std::cout << "alt:" << event.key.alt << std::endl;
      std::cout << "shift:" << event.key.shift << std::endl;
      std::cout << "system:" << event.key.system << std::endl;

      t.move(10.f, 50.f);
      s1->move(50.f, 10.f);
      //SETTEXT(text);
      std::cout << "Position x:" << t.getPosition().x << std::endl;
      std::cout << "Position y:" << t.getPosition().y << std::endl;
      std::cout << "Position x:" << s1->getPosition().x << std::endl;
      std::cout << "Position y:" << s1->getPosition().y << std::endl;
      */
      std::cout << "Position x:" << S->getBody().getPosition().x << std::endl;
      std::cout << "Position y:" << S->getBody().getPosition().y << std::endl;
      std::cout << "Rotation:" << S->getBody().getRotation() << std::endl;
      std::cout << "Sin :" << sin(S->getBody().getRotation() * PI / 180.0) << std::endl;
      std::cout << "Cos :" << cos(S->getBody().getRotation() * PI / 180.0) << std::endl;
      std::cout << "Sin ModuleUp:" << sin(S->getBody().getRotation() * PI / 180.0) * 10<< std::endl;
      std::cout << "Cos ModuleUp:" << cos(S->getBody().getRotation() * PI / 180.0) * 10<< std::endl;
      std::cout << "Sin ModuleDown:" << sin(S->getBody().getRotation() * PI / 180.0) * -10<< std::endl;
      std::cout << "Cos ModuleDown:" << cos(S->getBody().getRotation() * PI / 180.0) * -10<< std::endl;
      std::cout << "LeftOOB:" << S->getLeftOutOfBounds() << std::endl;
      std::cout << "TopOOB:" << S->getTopOutOfBounds() << std::endl;
      std::cout << "xOutOfBound:" << S->getXOutOfBounds() << std::endl;
      std::cout << "yOutOfBound:" << S->getYOutOfBounds() << std::endl;
    }

    //It handle Event::Closed
    //it close the window if pressed 'Q', 'ESC' or close button
    static void windowClosedHandler (sf::Event& e/*vent*/, sf::RenderWindow& w/*indow*/){
      // "close requested" event: we close the window
      if (e.type == sf::Event::Closed || (e.type == sf::Event::KeyPressed && (e.key.code == 16 || e.key.code == 36)))
        w.close();
    }

};
