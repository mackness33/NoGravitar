//export NG="/home/mack/University/Programmazione/NoGravitar"
#include <iostream>
#include <thread>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Classes/header.hpp"
#include "Classes/universe.hpp"
#include "Handlers/eventHandler.hpp"

/*
Optimization:
  -> struct => bool trasformation, sf::Keyboard::Key k;   DONE
  -> eventHandler         DONE
*/

int main (void){
  // Display the list of all the video modes available for fullscreen
  std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
  int mod_num = 1;
  // Create a window with the same pixel depth as the desktop
  sf::RenderWindow window(sf::VideoMode(modes[mod_num].width, modes[mod_num].height, modes[mod_num].bitsPerPixel), "NoGravitar");

  //TODO: make a function that it makes it automaticaly
  window.setFramerateLimit(60);
  window.setKeyRepeatEnabled(false);

  header *Header = new header(&window);
  universe *Universe = new universe(&window);

  //Create the spaceship
  spaceship *s2 = new spaceship();
  /*sf::FloatRect spaceshipBound = s2->getLocalBounds();        //for testing use
  sf::RectangleShape spaceshipBoundingBox(sf::Vector2f(spaceshipBound.width, spaceshipBound.height));
  spaceshipBoundingBox.setOrigin(30.f, 20.f);
  spaceshipBoundingBox.setPosition(80.f, 70.f);*/

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

    c.checkOutOfBounds(s2, &modes[mod_num]);

    //module keys
    translation.isUsed(sf::Keyboard::Up, sf::Keyboard::Down);   //it return which key has been pressed
    if(translation.getTransformation())                         //if pressed make a transformation of the object
    s2->movement(translation.getKey()/*, &spaceshipBoundingBox*/);


    //direction keys
    rotation.isUsed(sf::Keyboard::Right, sf::Keyboard::Left);   //it return which key has been pressed
    if(rotation.getTransformation())                            //if pressed make a transformation of the object
    s2->movement(rotation.getKey()/*, &spaceshipBoundingBox*/);


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
      }.

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

    //for now we write all here.
    //TODO: create a function that draw everything
    // draw the object (spaceship for now)
    //window.draw(spaceshipBoundingBox);
    Header->Draw();
    Universe->Draw();
    s2->Draw(&window);

    // end the current frame
    window.display();

  }

  return 0;
}
