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

/*
Optimization:
  -> struct => bool trasformation, sf::Keyboard::Key k;   DONE
  -> eventHandler         DONE
*/

int main (void){
  // Create a window with the same pixel depth as the desktop
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  sf::RenderWindow window(sf::VideoMode(desktop.height, desktop.width, desktop.bitsPerPixel), "NoGravitar");

  //TODO: make a function that it makes it automaticaly
  window.setFramerateLimit(60);
  window.setKeyRepeatEnabled(false);

  //Create the spaceship
  spaceship *s2 = new spaceship();

  //classes to handle input commands in smooth trasformations of object
  keyVector rotation;
  keyVector translation;

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

    //module keys
    translation.isUsed(sf::Keyboard::Up, sf::Keyboard::Down);   //it return which key has been pressed
    if(translation.getTransformation())                         //if pressed make a transformation of the object
      s2->movement(translation.getKey());


    //direction keys
    rotation.isUsed(sf::Keyboard::Right, sf::Keyboard::Left);   //it return which key has been pressed
    if(rotation.getTransformation())                            //if pressed make a transformation of the object
      s2->movement(rotation.getKey());

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
