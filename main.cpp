#include<iostream>
#include <SFML/Window.hpp>

int main (void){
// Create a window with the same pixel depth as the desktop
//std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
sf::Window window(sf::VideoMode(desktop.height, desktop.width, desktop.bitsPerPixel), "NoGravitar");

  // run the program as long as the window is open
  while (window.isOpen()){
      // check all the window's events that were triggered since the last iteration of the loop
      sf::Event event;
      while (window.pollEvent(event)){

        // if the event is a keypressed show me what type is it
        if (event.type == sf::Event::KeyPressed){
              std::cout << "the key pressed is: " << event.key.code << std::endl;
              std::cout << "control:" << event.key.control << std::endl;
              std::cout << "alt:" << event.key.alt << std::endl;
              std::cout << "shift:" << event.key.shift << std::endl;
              std::cout << "system:" << event.key.system << std::endl;
        }
          // "close requested" event: we close the window
          if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && (event.key.code == 16 || event.key.code == 36)))
              window.close();
      }
  }

  return 0;
}
