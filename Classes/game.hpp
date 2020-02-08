#ifndef GAME_H
#define GAME_H

#include <vector>
#include "gameplay.hpp"
#include "menu.hpp"
#include "scene.hpp"

class game{
  protected:
    sf::RenderWindow *Window;
    scene *mainScene;
    gameplay *Gameplay;
    menu *Menu;

  protected:

  public:
    //----------CONSTRUCTORS----------
    game(sf::RenderWindow* window);
    ~game();

    //----------GETS----------
    //----------SETS----------
    void setMainScene(std::string name);

    //----------METHODS----------
    void start ();

    //friend void eventHandler::changePlaygroundHandler(); // Friend function
    virtual std::string Class();

};

#endif
