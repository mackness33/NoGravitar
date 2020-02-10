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
    
  protected:

  public:
    //----------CONSTRUCTORS----------
    game(sf::RenderWindow* window);
    ~game();

    //----------GETS----------
    //----------SETS----------
    void setMainScene(std::string name);

    //----------METHODS----------
    void inizialize ();
    void start ();
    void restart ();

    //friend void eventHandler::changePlaygroundHandler(); // Friend function
    virtual std::string Class();

};

#endif
