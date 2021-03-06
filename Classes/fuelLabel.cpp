#include "fuelLabel.hpp"
#include "information.hpp"

//---------------CONSTRUCTORS---------------
fuelLabel::fuelLabel(std::string f, unsigned int ifuel, sf::Vector2f p) : label(f, std::to_string(ifuel), p), totalFuel(ifuel){}

fuelLabel::~fuelLabel() {}


//---------------GETS---------------
unsigned int fuelLabel::getFuels() { return totalFuel; }

//---------------METHODS---------------
void fuelLabel::Draw(sf::RenderWindow *window) { this->Update(); label::Draw(window); }
void fuelLabel::Update() { totalFuel = (!information::TRACTORBEAM_IS_ACTIVE) ? --totalFuel : (totalFuel - 20); this->setString(std::to_string(totalFuel)); }

void fuelLabel::addFuel(int value) { totalFuel += value; this->setString(std::to_string(totalFuel)); }
void fuelLabel::reset() { body->SetString(std::to_string(totalFuel = information::FUELS_DEFAULT_CAPACITY)); }

std::string fuelLabel::Class(){
  return "fuelLabel";
}
