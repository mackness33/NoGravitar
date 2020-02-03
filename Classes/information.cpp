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
float information::DELTA_TIME = 10.0f; // You MUST declare it in a CPP
float information::SWITCH_TIME = 10.0f; // You MUST declare it in a CPP
float information::SHOOTER_SWITCH_TIME = 0.0f; // You MUST declare it in a CPP

const float information::MAX_GROUND_HEIGHT = 0.4;             //30%
const float information::MIN_GROUND_HEIGHT = 0.1;             //30%
std::vector<file<sf::Texture>*> information::images = {};             //30%
std::vector<file<sf::Font>*> information::fonts = {};             //30%

//------------METHODS------------
const void information::inizialize(sf::Vector2u ws){
  WINDOW_SIZE = ws;

  MENU_DEFAULT_SIZE = sf::Vector2f(WINDOW_SIZE.x, WINDOW_SIZE.y);   //with the -6 I can see the bounderies
  MENU_DEFAULT_POSITION = sf::Vector2f(0, 0);

  HEADER_DEFAULT_SIZE = sf::Vector2f(WINDOW_SIZE.x, WINDOW_SIZE.y/10);

  PLAYGROUND_DEFAULT_SIZE = sf::Vector2f(WINDOW_SIZE.x - 6, (WINDOW_SIZE.y * 9/10) - 6);   //with the -6 I can see the bounderies
  PLAYGROUND_DEFAULT_POSITION = sf::Vector2f(3, WINDOW_SIZE.y/10 + 3);

  //TODO: SPACESHIP_DEFAULT_POSITION = sf::Vector2f(80.f, 70.f);

  //TODO: BULLET_DEFAULT_RADIUS = 5;
  BULLET_DEFAULT_SPEED = SPACESHIP_DEFAULT_SPEED * 1.25;

  SHOOTER_SWITCH_TIME = SWITCH_TIME * 20;

  std::string path = std::experimental::filesystem::current_path();
  information::loadFiles<sf::Texture>(path + "/img", images);
  information::loadFiles<sf::Font>(path + "/font", fonts);
}

std::string information::filenameFromPath(std::string path){
  std::size_t posSlash = path.find_last_of("/\\");
  path = path.substr(posSlash+1);
  std::size_t posDot = path.find_first_of(".");

  return path.substr(0, posDot);
}

//FEAT: can be optimazed
sf::Texture* information::getImage(std::string n){
  for(auto img = images.begin(); img != images.end(); img++)
    if(n.compare((*img)->name) == 0)
      return (*img)->object;

  return nullptr;
}

sf::Font* information::getFont(std::string n){
  for(auto fnt = fonts.begin(); fnt != fonts.end(); fnt++)
    if(n.compare((*fnt)->name) == 0)
      return (*fnt)->object;

  return nullptr;
}

std::string information::Class(){
  return "information";
}
