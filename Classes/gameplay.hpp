#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <vector>
#include "game.hpp"
#include "fuelLabel.hpp"
#include "galaxy.hpp"
#include "header.hpp"
#include "keyVector.hpp"
#include "points.hpp"
#include "scene.hpp"
#include "spaceship.hpp"
#include "startView.hpp"

class game;
class galaxy;

class gameplay : public scene{
  protected:
    game *Game;
    spaceship *Player;
    header *Header;
    std::vector<galaxy*> galaxies;
    points *Points;
    fuelLabel *FuelLabel;
    std::vector<galaxy*>::iterator activeGalaxy;

  protected:
    //event handlers
    void keyPressedHandler(const sf::Event &event);
    void keyReleasedHandler(const sf::Event &event);

  public:
    //----------CONSTRUCTORS----------
    gameplay(sf::RenderWindow* window, game* g);

    ~gameplay();

    //----------SETS----------
    void setMainViewer(viewer* newViewer);

    //----------METHODS----------
    //main (general) event handler
    void eventHandler(const sf::Event &event);

    //restart of the game
    void restart();

    //add points for the death of a bunker
    void deathBunker();

    //add points for the conquer of a planet
    void deathPlanet();

    //add fuel to the spaaceship
    void addFuel(int fuels);

    void next();                      //go to the next galaxy
    void prev();                      //go to the previous galaxy

    bool Win();                       //checks wheter the player won
    void Draw ();                     //Draw the objects

    //return the class of the object
    virtual std::string Class();

};

#endif
