//EVENTHANDLER
//Class that handle events

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
  static void keyPressedHandler (spaceship* s/*paceship*/){
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
    std::cout << "Position x:" << s->getBody().getPosition().x << std::endl;
    std::cout << "Position y:" << s->getBody().getPosition().y << std::endl;
    std::cout << "Rotation:" << s->getBody().getRotation() << std::endl;
    std::cout << "Sin :" << sin(s->getBody().getRotation() * PI / 180.0) << std::endl;
    std::cout << "Cos :" << cos(s->getBody().getRotation() * PI / 180.0) << std::endl;
    std::cout << "Sin ModuleUp:" << sin(s->getBody().getRotation() * PI / 180.0) * 10<< std::endl;
    std::cout << "Cos ModuleUp:" << cos(s->getBody().getRotation() * PI / 180.0) * 10<< std::endl;
    std::cout << "Sin ModuleDown:" << sin(s->getBody().getRotation() * PI / 180.0) * -10<< std::endl;
    std::cout << "Cos ModuleDown:" << cos(s->getBody().getRotation() * PI / 180.0) * -10<< std::endl;
    std::cout << "LeftOOB:" << s->getLeftOutOfBounds() << std::endl;
    std::cout << "TopOOB:" << s->getTopOutOfBounds() << std::endl;
    std::cout << "xOutOfBound:" << s->getXOutOfBounds() << std::endl;
    std::cout << "yOutOfBound:" << s->getYOutOfBounds() << std::endl;
  }

  //It handle Event::Closed
  //it close the window if pressed 'Q', 'ESC' or close button
  static void windowClosedHandler (sf::Event& e/*vent*/, sf::RenderWindow& w/*indow*/){
    // "close requested" event: we close the window
    if (e.type == sf::Event::Closed || (e.type == sf::Event::KeyPressed && (e.key.code == 16 || e.key.code == 36)))
      w.close();
  }
};
