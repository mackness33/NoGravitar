#include <iostream>
#include <thread>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "spaceship.hpp"

void inizializeText(sf::Text* t, sf::Font* f);

int main (void){
  // Create a window with the same pixel depth as the desktop
  //std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  sf::RenderWindow window(sf::VideoMode(desktop.height, desktop.width, desktop.bitsPerPixel), "NoGravitar");

  window.setFramerateLimit(60);

  sf::Text t;
  sf::Font f;
  inizializeText(&t, &f);

  spaceship *s1 = new spaceship(&t, &f);
  spaceship *s2 = new spaceship(&f);

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
          s2->movement(&event.key.code);
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
          window.close();

      }



      // clear the window with black color
      window.clear();

      // draw everything here...
      window.draw(t);
      window.draw(*s1);
      window.draw(*s2);

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
