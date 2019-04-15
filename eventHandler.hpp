#include "spaceship.hpp"

class eventHandler{
public:
  static void keyReleasedHandler (sf::Event::Event& e, bool* t, bool* r){
    switch (event.key.code) {
      case sf::Keyboard::Left : { }                                      //LEFT
      case sf::Keyboard::Right : { *r/*otation*/ = false; };break;            //RIGHT
      case sf::Keyboard::Up : { }                                        //UP
      case sf::Keyboard::Down : { *t/*ranslation*/ = false; };break;            //DOWN
      default:
        break;
    }
  }

  static void keyPressedHandler (){
    /*pressed = true;

    switch (event.key.code) {                                             //LEFT
      case sf::Keyboard::Left : {
        s2->Rotate(s2->getRotationVersor());
      };break;

      case sf::Keyboard::Right : {                                        //RIGHT
        s2->Rotate(-s2->getRotationVersor());
      };break;

      case sf::Keyboard::Up : {                                           //UP
        s2->Move(s2->getSpatialVersor(), 0);
      };break;

      case sf::Keyboard::Down : {                                         //DOWN
        s2->Move(-s2->getSpatialVersor(), 0);
      };break;

      default:{
        std::cout << "the key pressed is: " << event.key.code << std::endl;
        pressed = false;
      }
    }

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
    std::cout << "Position y:" << s1->getPosition().y << std::endl;*/
    std::cout << "Position x:" << s2->GetPosition().x << std::endl;
    std::cout << "Position y:" << s2->GetPosition().y << std::endl;
    std::cout << "Rotation:" << s2->getRotation() << std::endl;
    std::cout << "Sin :" << sin(s2->getRotation() * PI / 180.0) << std::endl;
    std::cout << "Cos :" << cos(s2->getRotation() * PI / 180.0) << std::endl;
  }

  static void windowClosedHandler (sf::Event::Event& e, sf::RenderTarget& target){
    // "close requested" event: we close the window
    if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && (event.key.code == 16 || event.key.code == 36)))
      target.close();
  }
}
