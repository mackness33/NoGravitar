#ifndef HEADER_H
#define HEADER_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "essence.hpp"
#include "entity.hpp"
#include "label.hpp"
#include "fuelLabel.hpp"
#include "information.hpp"
#include "points.hpp"
#include "viewer.hpp"

class viewer;

class header : public viewer{
  private:
    fuelLabel *FuelLabel;
    label *lblFuelLabel;
    points *score;
    label *lblScore;
    points *bestScore;
    label *lblBestScore;
    label *title;

  public:
    //----------CONSTRUCTORS----------
    header(sf::RenderWindow *window, sf::Vector2f size = information::HEADER_DEFAULT_SIZE, sf::Vector2f position = information::HEADER_DEFAULT_POSITION, sf::Texture* image = nullptr);
    ~header();

    //----------GETS----------
    points* getPoints();
    fuelLabel* getFuels();
    unsigned int getBest();

    //---------------METHODS---------------
    //Draw the objects
    void Draw();
    //return the class of the object
    virtual std::string Class();
};

#endif
