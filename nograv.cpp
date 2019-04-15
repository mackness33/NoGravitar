//export NG="/home/mack/University/Programmazione/NoGravitar"
#include <iostream>
#include <thread>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "spaceship.hpp"

#define PI 3.14159265


void inizializeText(sf::Text* t, sf::Font* f);

int main (void){
  // Create a window with the same pixel depth as the desktop
  //std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  sf::RenderWindow window(sf::VideoMode(desktop.height, desktop.width, desktop.bitsPerPixel), "NoGravitar");

  window.setFramerateLimit(60);

  sf::Text t;
  sf::Font f;
  //sf::Transform translation;
  //sf::Transform rotatation;
  inizializeText(&t, &f);

  spaceship *s1 = new spaceship(&t, &f);
  spaceship *s2 = new spaceship(&f);
  bool rotation = false;
  bool translation = false;
  sf::Keyboard::Key module = sf::Keyboard::Unknown;
  sf::Keyboard::Key direction = sf::Keyboard::Unknown;
  window.setKeyRepeatEnabled(false);

  // run the program as long as the window is open
  while (window.isOpen()){
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    //thread thread(&spaceship::smooth_movement, s2, &e);


    while (window.pollEvent(event)){

      switch (event.type) {

        case sf::Event::KeyReleased :{
          switch (event.key.code) {
            case sf::Keyboard::Left : { }                                      //LEFT
            case sf::Keyboard::Right : { rotation = false; };break;            //RIGHT
            case sf::Keyboard::Up : { }                                        //UP
            case sf::Keyboard::Down : { translation = false; };break;            //DOWN
            default:
              break;
          }
        };break;

        case sf::Event::KeyPressed :{
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

        case sf::Event::Closed :{
          // "close requested" event: we close the window
          if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && (event.key.code == 16 || event.key.code == 36)))
            window.close();
        };break;

        default :
          break;
      }


      // if the event is a keypressed show me what type is it
      /*if (event.type == sf::Event::KeyPressed && event.key.code != sf::Keyboard::Unknown){
        pressed = true;
        key = event.key.code;
      }

      if (event.type == sf::Event::KeyReleased)
      pressed = false;

      while(pressed){
        s2->movement(&key);
      }


      if (event.type == sf::Event::KeyPressed){
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
        std::cout << "Position x:" << s2->getPosition().x << std::endl;
        std::cout << "Position y:" << s2->getPosition().y << std::endl;
      }

      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && (event.key.code == 16 || event.key.code == 36)))
        window.close();*/

    }



    /*if(!translate)
      translation.translate(0, 0);


    if(!rotate)
      rotatation.rotate(0);
    */
    // clear the window with black color

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
      translation  = true;

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        module = sf::Keyboard::Up;            //UP
      else
        module = sf::Keyboard::Down;            //DOWN
    }

    if(translation)
      s2->movement(&module);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
      rotation  = true;

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction = sf::Keyboard::Left;            //LEFT
      else
        direction = sf::Keyboard::Right;            //RIGHT
    }

    if(rotation)
      s2->movement(&direction);

    window.clear();

    // draw everything here...
    window.draw(t);
    window.draw(*s1);

    s2->Draw(window);

    /*
    if(pressed){
      if(rotate)
        window.draw(*s2, translation);
      else
        window.draw(*s2, rotatation);
    }
    else
      window.draw(*s2);
    */
    // end the current frame
    window.display();

  }

  return 0;
}

void inizializeText(sf::Text* t, sf::Font* f){
  //sf::Font font;
  f->loadFromFile("Fonts/York_Whiteletter/yorkwhiteletter.ttf");

  //sf::Text *t;
  t->setFont(*f);

  t->setString("Hello world");

  // set the character size
  t->setCharacterSize(24); // in pixels, not points!

  // set the color
  t->setFillColor(sf::Color::Red);

  // set the text style
  t->setStyle(sf::Text::Bold | sf::Text::Underlined);
}
