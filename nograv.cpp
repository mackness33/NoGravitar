//export NG="/home/mack/University/Programmazione/NoGravitar"
#include <iostream>
#include <thread>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Classes/spaceship.hpp"
#include "Classes/keyVector.hpp"
#include "Handlers/eventHandler.hpp"
#include "Handlers/transformationHandler.hpp"
#include "Handlers/collisionHandler.hpp"

/*
Optimization:
  -> struct => bool trasformation, sf::Keyboard::Key k;   DONE
  -> eventHandler         DONE
*/

int main (void){
  // Display the list of all the video modes available for fullscreen
  std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
  /*for (std::size_t i = 0; i < modes.size(); ++i)
  {
      sf::VideoMode mode = modes[i];
      std::cout << "Mode #" << i << ": "
                << mode.width << "x" << mode.height << " - "
                << mode.bitsPerPixel << " bpp" << std::endl;
  }
  // Create a window with the same pixel depth as the desktop
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();*/
  // Create a window with the same pixel depth as the desktop
  //sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  //sf::RenderWindow window(sf::VideoMode(desktop.height, desktop.width, desktop.bitsPerPixel), "NoGravitar");
  sf::RenderWindow window(sf::VideoMode(modes[0].width, modes[0].height, modes[0].bitsPerPixel), "NoGravitar");

  //TODO: make a function that it makes it automaticaly
  window.setFramerateLimit(60);
  window.setKeyRepeatEnabled(false);

  //Create the spaceship
  spaceship *s2 = new spaceship();

  //classes to handle input commands in smooth trasformations of object
  keyVector rotation;
  keyVector translation;

  collisionHandler c;
  // run the program as long as the window is open
  while (window.isOpen()){
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;

    while (window.pollEvent(event)){

      switch (event.type) {
        //KEYRELEASED
        case sf::Event::KeyReleased :{
          eventHandler::keyReleasedHandler(event, &translation, &rotation);
        };break;

        //KEYPRESSED
        case sf::Event::KeyPressed :{
          eventHandler::keyPressedHandler(s2);
        }

        //WINDOWCLOSED
        case sf::Event::Closed :{
          eventHandler::windowClosedHandler(event, window);
        };break;

        default :
          break;
      }

    }

    //c.checkCollision(s2, &window);

    //module keys
    translation.isUsed(sf::Keyboard::Up, sf::Keyboard::Down);   //it return which key has been pressed
    if(translation.getTransformation())                         //if pressed make a transformation of the object
      s2->movement(translation.getKey());


    //direction keys
    rotation.isUsed(sf::Keyboard::Right, sf::Keyboard::Left);   //it return which key has been pressed
    if(rotation.getTransformation())                            //if pressed make a transformation of the object
      s2->movement(rotation.getKey());

    /*translation.isUsed(sf::Keyboard::Up, sf::Keyboard::Down);   //it return which key has been pressed
    rotation.isUsed(sf::Keyboard::Right, sf::Keyboard::Left);   //it return which key has been pressed

    if(translation.getTransformation() || rotation.getTransformation()){
      float direction = 0;
      float up = 0;
      float down = 0;

      if(sf::Keyboard::Up == translation.getKey()){
        up = cos(s2->getRotation() * PI / 180.0) * 10;
        down = sin(s2->getRotation() * PI / 180.0) * 10;
      }else{
        if(sf::Keyboard::Down == translation.getKey()){
          up = cos(s2->getRotation() * PI / 180.0) * -10;
          down = sin(s2->getRotation() * PI / 180.0) * -10;
        }
      }

      if(sf::Keyboard::Left == rotation.getKey())
        direction = 3;
      else{
        if(sf::Keyboard::Right == rotation.getKey()){
          direction = 3;
        }
      }

      sf::Vector2f module(up, down);
      sf::Transformable *t = dynamic_cast<sf::Transformable*>(s2);
      transformationHandler::movement(t, module, direction);
    }*/


    window.clear();

    //for now we write all here
    //TODO: create a function that draw everything
    // draw the object (spaceship for now)
    window.draw(*s2);

    // end the current frame
    window.display();

  }

  return 0;
}
