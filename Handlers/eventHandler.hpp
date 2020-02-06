#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "../Classes/spaceship.hpp"
#include "../Classes/keyVector.hpp"


class eventHandler{
  public:
    //It handle KeyEvent::KeyReleased.
    //It stops the movement
    static void keyReleasedHandler (const sf::Event& event, keyVector* translation, keyVector* rotation);

    //It handle KeyEvent::KeyPressed
    //It gives information bout transformation of the spaceship
    static void keyPressedHandler (spaceship* Spaceship, const sf:: Event& event);

    //It handle Event::Closed
    //it close the window if pressed 'Q', 'ESC' or close button
    static void windowClosedHandler (const sf::Event& event, sf::RenderWindow& window);

};

#endif
