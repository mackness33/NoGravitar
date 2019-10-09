//HEADER
//Class that handle everything that concerne the top of the window

/*

*/
#include "header.hpp"

#define PI 3.14159265

//CONSTRUCTORS
header::header(sf::RenderWindow* win){
  window = win;

  // Declare and load a font
  if(!font.loadFromFile("Fonts/Aerovias_Brasil/AeroviasBrasilNF.ttf")){
    std::cout << "Error in load of Aerovias Brasil font" << std::endl;

    if(!font.loadFromFile("Fonts/Cafe_Brewery/cafeandbrewery.ttf")){
      std::cout << "Error in load of Cafe Brewery font" << std::endl;
    }
  }

  // Setting bounding box
  size = new sf::Vector2f(win->getSize().x, win->getSize().y/10);
  position = new sf::Vector2f(0, 0);
  boundingBox = new sf::FloatRect(*position, *size);
  bound.setPosition(*position);
  bound.setSize(*size);
  bound.setFillColor(sf::Color(255, 255, 000));


  // Setting point text
  points.setFont(font);
  points.setString("0");
  points.setCharacterSize(30);
  points.setStyle(sf::Text::Regular);
  points.setFillColor(sf::Color::White);
  points.setPosition((size->x-title.getLocalBounds().width)/2, (size->y-title.getLocalBounds().height)/2);


  // Setting title text
  title.setFont(font);
  title.setString("NOGRAVITAR");
  title.setCharacterSize(30);
  title.setStyle(sf::Text::Bold);
  title.setFillColor(sf::Color::White);
  title.setPosition((size->x-title.getLocalBounds().width)/2, 0);
}

/*spaceship(const spaceship& S){
this->spatial_Versor = S.getSpatialVersor();
  this->rotation_Versor = S.getRotationVersor();

  this->build();
}*/

//GETS
sf::Text header::getPoints(){ return this->points;}
sf::Text header::getTitle(){ return this->title;}
sf::Font header::getFont(){ return font;}

//SETS
void header::setPoints(sf::Text p){ this->points = p;}
void header::setTitle(sf::Text t){ this->title = t;}
void header::setFont(sf::Font f){ this->font = f;}

//---------------METHODS---------------

//DRAW
void header::Draw (/*sf::RenderWindow* window*/){
  window->draw(bound);
  window->draw(points);
  window->draw(title);
}
