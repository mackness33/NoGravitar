#ifndef BUNKER_H
#define BUNKER_H

#include "shooter.hpp"
#include "bullet.hpp"
#include "line.hpp"
#include "living.hpp"
#include "playground.hpp"

class bunker : public drawable, public shooter, public living{
  private:
    entity<sf::RectangleShape>* body;
    //std::list <bullet*> bullets;
    playground *Playground;
    sf::Texture* image;
    float totalTime;
    int BulletsxShooting;

  public:
    //----------CONSTRUCTORS----------
    bunker(playground* Playground, line Line, bool triple = false);

    ~bunker();

    //----------GETS----------
    entity<sf::RectangleShape>* getEntity();
    sf::RectangleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();

    //----------SETS----------

    //----------METHODS----------
    // bool isAlive();
    // void rip();

    void Draw (sf::RenderWindow* window);

    void build();

    //update of the object's data for each time that it is draw
    void Update();

    void shoot();

    virtual std::string Class();
};

#endif
