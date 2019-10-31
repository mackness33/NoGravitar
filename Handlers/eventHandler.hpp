//EVENTHANDLER
//Class that handle events

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Classes/galaxy.hpp"

class eventHandler{
  public:
    //It handle KeyEvent::KeyReleased.
    //It stops the movement
    static void keyReleasedHandler (sf::Event& e/*vent*/, keyVector* t/*ranslation*/, keyVector* r/*otation*/);
    //It handle KeyEvent::KeyPressed
    //It gives information bout transformation of the spaceship
    static void keyPressedHandler (spaceship* S/*paceship*/, sf:: Event& e);

    //It handle Event::Closed
    //it close the window if pressed 'Q', 'ESC' or close button
    static void windowClosedHandler (sf::Event& e/*vent*/, sf::RenderWindow& w/*indow*/);

};
