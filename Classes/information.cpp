#include "information.hpp"

sf::Vector2u information::WINDOW_SIZE; // You MUST declare it in a CPP
sf::Vector2f information::MENU_DEFAULT_SIZE = sf::Vector2f(0, 0); // You MUST declare it in a CPP
sf::Vector2f information::MENU_DEFAULT_POSITION = sf::Vector2f(0, 0); // You MUST declare it in a CPP
sf::Vector2f information::HEADER_DEFAULT_SIZE = sf::Vector2f(0, 0); // You MUST declare it in a CPP
sf::Vector2f information::HEADER_DEFAULT_POSITION = sf::Vector2f(0, 0); // You MUST declare it in a CPP
sf::Vector2f information::PLAYGROUND_DEFAULT_SIZE = sf::Vector2f(0, 0); // You MUST declare it in a CPP
sf::Vector2f information::PLAYGROUND_DEFAULT_POSITION = sf::Vector2f(0, 0); // You MUST declare it in a CPP
sf::Vector2f information::PLAYER_DEFAULT_POSITION = sf::Vector2f(80.f, 70.f); // You MUST declare it in a CPP
float information::SPACESHIP_DEFAULT_ANGULAR_SPEED = 3; // You MUST declare it in a CPP
float information::SPACESHIP_DEFAULT_SPEED = 10; // You MUST declare it in a CPP
float information::PLANET_DEFAULT_RADIUS = 50; // You MUST declare it in a CPP
float information::BULLET_DEFAULT_RADIUS = 10; // You MUST declare it in a CPP
float information::BULLET_DEFAULT_SPEED = 0; // You MUST declare it in a CPP
//float information::BULLET_DEFAULT_DIRECTION = 0; // You MUST declare it in a CPP

const float information::MAX_GROUND_HEIGHT = 0.4;             //30%
const float information::MIN_GROUND_HEIGHT = 0.1;             //30%

//------------METHODS------------
const void information::inizialize(sf::Vector2u ws){
  std::cout << "HOLA" << std::endl;
  WINDOW_SIZE = ws;

  MENU_DEFAULT_SIZE = sf::Vector2f(WINDOW_SIZE.x, WINDOW_SIZE.y);   //with the -6 I can see the bounderies
  MENU_DEFAULT_POSITION = sf::Vector2f(0, 0);

  HEADER_DEFAULT_SIZE = sf::Vector2f(WINDOW_SIZE.x, WINDOW_SIZE.y/10);

  PLAYGROUND_DEFAULT_SIZE = sf::Vector2f(WINDOW_SIZE.x - 6, (WINDOW_SIZE.y * 9/10) - 6);   //with the -6 I can see the bounderies
  PLAYGROUND_DEFAULT_POSITION = sf::Vector2f(3, WINDOW_SIZE.y/10 + 3);

  //TODO: SPACESHIP_DEFAULT_POSITION = sf::Vector2f(80.f, 70.f);

  //TODO: BULLET_DEFAULT_RADIUS = 5;
  BULLET_DEFAULT_SPEED = SPACESHIP_DEFAULT_SPEED * 1.25;

  std::cout << "AGIAN" << std::endl;
}

std::string information::Class(){
  return "information";
}