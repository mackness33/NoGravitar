#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "viewer.hpp"

class scene {
  protected:
    sf::RenderWindow *Window;
    viewer *Viewer;
    bool isActive;

  protected:

  public:
    //----------CONSTRUCTORS----------
    scene(sf::RenderWindow* window);
    ~scene();

    //----------METHODS----------
    void windowClosedHandler (const sf::Event& event);

    //main (general) event handler
    virtual void eventHandler(const sf::Event &event);
    virtual void Draw ();                               //basic draw for a scene

    virtual std::string Class();

};

#endif
