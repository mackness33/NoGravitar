#ifndef BUNKER_H
#define BUNKER_H

#include "bullet.hpp"
#include "entity.hpp"
#include "essence.hpp"
#include "line.hpp"
#include "living.hpp"
#include "playground.hpp"
#include "shooter.hpp"

class bunker : public drawable, public shooter, public living{
  private:
    entity<sf::RectangleShape>* body;
    playground *Playground;
    sf::Texture* image;
    float totalTime;
    int BulletsxShooting;

  protected:
    //inizialization of the body features
    void inizialization(line l);

  public:
    //----------CONSTRUCTORS----------
    bunker(playground* Playground, line Line, bool type = false);

    ~bunker();

    //----------GETS----------
    entity<sf::RectangleShape>* getEntity();
    sf::RectangleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();

    //----------METHODS----------
    //draws the object's body
    void Draw (sf::RenderWindow* window);

    //update of the object's data for each time that it is draw
    void Update();

    //this function makes the shooter shoot its own bullet
    void shoot();

    //return the class of the object
    virtual std::string Class();
};

#endif
