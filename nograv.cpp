//export NG="/home/mack/University/Programmazione/NoGravitar"
#include <iostream>
#include <thread>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Classes/game.hpp"
#include "Classes/gameplay.hpp"
#include "Classes/menu.hpp"
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
  window.setFramerateLimit(20);
  window.setKeyRepeatEnabled(false);

  //settings::loadImages();
  information::inizialize(window.getSize());

  srand (time(NULL));

  // gameplay *currentGame = new gameplay(&window);
  menu *currentGame = new menu(&window);

  currentGame->start();

  return 0;
}
