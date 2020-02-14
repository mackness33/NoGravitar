#ifndef PLANETOBJ_H
#define PLANETOBJ_H

#include "entity.hpp"
#include "essence.hpp"
#include "drawable.hpp"
#include "planetView.hpp"

class planetView;

class planetObj : public drawable{
  private:
    entity<sf::CircleShape>* body;
    planetView* view;

  public:
    //----------CONSTRUCTORS----------
    planetObj(float radius = information::PLANET_DEFAULT_RADIUS, sf::Vector2f position = sf::Vector2f(0, 0));

    ~planetObj();

    //----------GETS----------
    entity<sf::CircleShape>* getEntity();
    sf::CircleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();
    planetView* getPlanetView();

    //----------SETS----------
    void setLife(bool l);
    void setPlanetView(planetView* newView);

    //----------METHODS----------
    bool isDead();                              //if dead return true otherwise false
    //Draw the objects
    void Draw (sf::RenderWindow* window);
    bool spawnIntersects(drawable* obj);        //return if the object in input is at the right distance from this planet

    void build();

    //return the class of the object
    virtual std::string Class();
};

#endif
