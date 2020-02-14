#ifndef GAME_H
#define GAME_H

#include "gameplay.hpp"
#include "menu.hpp"
#include "scene.hpp"

class gameplay;
class menu;

class game{
  protected:
    sf::RenderWindow *Window;
    scene *mainScene;
    gameplay *Gameplay;
    menu *Menu;

  public:
    static unsigned int bestScore;                    //I leave it static so that I don't need include the object through multiple classes just to changed it

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

    //return the class of the object
    virtual std::string Class();

};

#endif
