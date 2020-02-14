#ifndef MENU_H
#define MENU_H

#include "scene.hpp"
#include "game.hpp"
#include "startView.hpp"

class game;

class menu : public scene{
  protected:
    game *Game;
    startView *view;

  protected:
    //event handlers
    void keyPressedHandler(const sf::Event &event);

  public:
    //----------CONSTRUCTORS----------
    menu(sf::RenderWindow* window, game* g);
    ~menu();

    //----------METHODS----------
    //main (general) event handler
    void eventHandler(const sf::Event &event);
    //return the class of the object
    virtual std::string Class();

};

#endif
