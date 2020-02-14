#include "header.hpp"
#include "game.hpp"

//------------CONSTRUCTORS------------
header::header(sf::RenderWindow* w, sf::Vector2f s, sf::Vector2f p, sf::Texture* i) : viewer(w, s, p , i){
  // Setting title text
  title = new label("AeroviasBrasil", "NOGRAVITAR");
  title->getText()->SetCharacterSize(30);
  title->getText()->SetStyle(sf::Text::Bold);
  title->getText()->SetFillColor(sf::Color::Green);
  title->getText()->SetPosition(sf::Vector2f((s.x - title->GetLocalBounds().width)/2, 0));


  // Setting label Score text
  lblScore = new label("AeroviasBrasil", "SCORE");
  lblScore->getText()->SetCharacterSize(20);
  lblScore->getText()->SetStyle(sf::Text::Regular);
  lblScore->getText()->SetFillColor(sf::Color::Green);
  lblScore->getText()->SetPosition(sf::Vector2f((s.x - lblScore->GetLocalBounds().width)/3, (s.y - lblScore->GetLocalBounds().height)/2 + 10));

  // Setting Score text
  score = new points("AeroviasBrasil", 0);
  score->getText()->SetCharacterSize(25);
  score->getText()->SetStyle(sf::Text::Regular);
  score->getText()->SetFillColor(sf::Color::Green);
  score->getText()->SetPosition(sf::Vector2f((s.x - score->GetLocalBounds().width)/2, (s.y - score->GetLocalBounds().height)/2 + 10));


  // Setting label Fuel text
  lblFuelLabel = new label("AeroviasBrasil", "FUEL");
  lblFuelLabel->getText()->SetCharacterSize(20);
  lblFuelLabel->getText()->SetStyle(sf::Text::Regular);
  lblFuelLabel->getText()->SetFillColor(sf::Color::Green);
  lblFuelLabel->getText()->SetPosition(sf::Vector2f((s.x/3 * 2), 0));

  // Setting Fuel text
  FuelLabel = new fuelLabel("AeroviasBrasil");
  FuelLabel->getText()->SetCharacterSize(25);
  FuelLabel->getText()->SetStyle(sf::Text::Bold);
  FuelLabel->getText()->SetFillColor(sf::Color::Green);
  FuelLabel->getText()->SetPosition(sf::Vector2f(s.x - 100, 0));


  // Setting label Bestscore text
  lblBestScore = new label("AeroviasBrasil", "BEST SCORE");
  lblBestScore->getText()->SetCharacterSize(20);
  lblBestScore->getText()->SetStyle(sf::Text::Regular);
  lblBestScore->getText()->SetFillColor(sf::Color::Green);
  lblBestScore->getText()->SetPosition(sf::Vector2f((s.x/3 * 2), (s.y - lblBestScore->GetLocalBounds().height)/2 + 10));

  // Setting Bestscore text
  bestScore = new points("AeroviasBrasil", game::bestScore);
  bestScore->getText()->SetCharacterSize(25);
  bestScore->getText()->SetStyle(sf::Text::Bold);
  bestScore->getText()->SetFillColor(sf::Color::Green);
  bestScore->getText()->SetPosition(sf::Vector2f(s.x - 100, (s.y - bestScore->GetLocalBounds().height)/2 + 10));
}

header::~header() {}

//----------GETS----------
points* header::getPoints(){ return this->score;}
fuelLabel* header::getFuels(){ return this->FuelLabel;}

//----------SETS----------
//return the Max between the actual score and the best
unsigned int header::getBest(){ return ((bestScore->getPoints() >= score->getPoints()) ? bestScore->getPoints() : score->getPoints()); }

//----------METHODS----------

void header::Draw (){
  viewer::Draw();
  bestScore->Draw(window);
  lblBestScore->Draw(window);
  score->Draw(window);
  lblScore->Draw(window);
  title->Draw(window);
  FuelLabel->Draw(window);
  lblFuelLabel->Draw(window);
}

std::string header::Class(){
  return "header";
}
