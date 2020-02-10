#include "header.hpp"
#include "game.hpp"

//------------CONSTRUCTORS------------
header::header(sf::RenderWindow* w, sf::Vector2f s, sf::Vector2f p, sf::Texture* i) : viewer(w, s, p , i){
  // Setting title text
  //TODO: set for text's direct methods for modifiers of strings
  title = new label("AeroviasBrasil", "NOGRAVITAR");
  title->getText()->SetCharacterSize(30);
  title->getText()->SetStyle(sf::Text::Bold);
  title->getText()->SetFillColor(sf::Color::Green);
  title->getText()->SetPosition(sf::Vector2f((s.x - title->GetLocalBounds().width)/2, 0));


  // Setting point text
  score = new points("AeroviasBrasil", 0);
  score->getText()->SetCharacterSize(30);
  score->getText()->SetStyle(sf::Text::Regular);
  score->getText()->SetFillColor(sf::Color::Green);
  score->getText()->SetPosition(sf::Vector2f((s.x - score->GetLocalBounds().width)/2, (s.y - score->GetLocalBounds().height)/2));


  bestScore = new label("AeroviasBrasil", std::to_string(game::bestScore));
  bestScore->getText()->SetCharacterSize(30);
  bestScore->getText()->SetStyle(sf::Text::Bold);
  bestScore->getText()->SetFillColor(sf::Color::Green);
  bestScore->getText()->SetPosition(sf::Vector2f((s.x - bestScore->GetLocalBounds().width)/2 + 50, (s.y - bestScore->GetLocalBounds().height)/2));
}

header::~header(){
  std::cout << "DELETING HEADER" << std::endl;
}

//----------GETS----------
points* header::getPoints(){ return this->score;}
//label header::getTitle(){ return *(this->title);}
//const sf::Font* header::getFont(){ return font;}

//----------SETS----------
unsigned int header::getBest(){ return 300;}//(bestScore->getString().compare(score->getString()) >= 0) ? std::stoi(bestScore->getString()) : std::stoi(score->getString()); }
//void header::setTitle(sf::Text t){ this->title = t;}
//void header::setFont(sf::Font* f){ *(this->font) = *f;}

//----------METHODS----------

void header::Draw (){
  viewer::Draw();
  bestScore->Draw(window);
  score->Draw(window);
  title->Draw(window);
}

std::string header::Class(){
  return "header";
}
