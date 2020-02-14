#ifndef GAME_H
#define GAME_H

#include <vector>
#include "gameplay.hpp"
#include "menu.hpp"

class gameplay;
class menu;

class game{
  protected:
    sf::RenderWindow *Window;
    scene *mainScene;
    gameplay *Gameplay;
    menu *Menu;

  public:
    static unsigned int bestScore;

  public:
    //----------CONSTRUCTORS----------
    game(sf::RenderWindow* window);
    ~game();

    //----------SETS----------
    void setMainScene(std::string name);

    //----------METHODS----------
    //inizialize the game
    void inizialize ();

    //start the game
    void start ();

    //restart the game
    void restart ();


    virtual std::string Class();

};

#endif
