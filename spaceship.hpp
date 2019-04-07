#include <iostream>

class spaceship : public sf::Text{
public:

  //CONSTRUCTORS
  spaceship(sf::Text* t, sf::Font* f) : sf::Text(*t){
    this->setFont(*f);
    this->setString("Spacestrip");
  }

  spaceship(sf::Font* f) : sf::Text(){
    this->setFont(*f);

    this->setString("Spaceship");

    // set the character size
    this->setCharacterSize(30); // in pixels, not points!

    // set the color
    this->setFillColor(sf::Color::Green);

    // set the text style
    this->setStyle(sf::Text::Bold | sf::Text::Underlined);
  }

  //METHODS
  void movement(sf::Keyboard::Key* k){
    float shift = 10;

    switch (*k) {
      case sf::Keyboard::Left : { this->move(-shift, 0); };break;           //LEFT
      case sf::Keyboard::Right : { this->move(shift, 0); };break;           //RIGHT
      case sf::Keyboard::Up : { this->move(0, -shift); };break;             //UP
      case sf::Keyboard::Down : { this->move(0, shift); };break;            //DOWN
      default: std::cout << "Not a movementCommand" << std::endl;
    }
  }
};
