#ifndef BUNKER_H
#define BUNKER_H

#include "shooter.hpp"
#include "bullet.hpp"
#include "line.hpp"
#include "playground.hpp"

class bunker : public drawable, public shooter{
  private:
    entity<sf::RectangleShape>* body;
    std::list <bullet*> bullets;
    playground *Playground;
    sf::Texture* image;
    float totalTime;

  public:
    //----------CONSTRUCTORS----------
    bunker(playground* Playground, line Line);

    ~bunker();

    //----------GETS----------
    entity<sf::RectangleShape>* getEntity();
    sf::RectangleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();

    //----------SETS----------

    //----------METHODS----------
    void Draw (sf::RenderWindow* window);

    void build();

    //update of the object's data for each time that it is draw
    void Update();

    void shoot();

    virtual std::string Class();
};

#endif
