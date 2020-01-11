#include "header.hpp"

//------------CONSTRUCTORS------------
header::header(sf::RenderWindow* w, sf::Vector2f s, sf::Vector2f p, sf::Texture* i) : viewer(w, s, p , i){
  // Declare and load a font
  if(!font.loadFromFile("Fonts/Aerovias_Brasil/AeroviasBrasilNF.ttf")){
    std::cout << "Error in load of Aerovias Brasil font" << std::endl;

    if(!font.loadFromFile("Fonts/Cafe_Brewery/cafeandbrewery.ttf")){
      std::cout << "Error in load of Cafe Brewery font" << std::endl;
    }
  }

  // Setting title text
  title.setFont(font);
  title.setString("NOGRAVITAR");
  title.setCharacterSize(30);
  title.setStyle(sf::Text::Bold);
  title.setFillColor(sf::Color::Green);
  title.setPosition((s.x - title.getLocalBounds().width)/2, 0);


  // Setting point text
  points.setFont(font);
  points.setString("0");
  points.setCharacterSize(30);
  points.setStyle(sf::Text::Regular);
  points.setFillColor(sf::Color::Green);
  points.setPosition((s.x - points.getLocalBounds().width)/2, (s.y - points.getLocalBounds().height)/2);
}

//----------GETS----------
sf::Text header::getPoints(){ return this->points;}
sf::Text header::getTitle(){ return this->title;}
sf::Font header::getFont(){ return font;}

//----------SETS----------
void header::setPoints(sf::Text p){ this->points = p;}
void header::setTitle(sf::Text t){ this->title = t;}
void header::setFont(sf::Font f){ this->font = f;}

//----------METHODS----------

void header::Draw (){
  viewer::Draw();
  this->window->draw(points);
  this->window->draw(title);
}

std::string header::Class(){
  return "header";
}
