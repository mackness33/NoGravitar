#ifndef PLANETOBJ_H
#define PLANETOBJ_H

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
    bool isDead();
    planetView* getPlanetView();
    //planetView* isDead();

    //----------SETS----------
    void setLife(bool l);
    void setPlanetView(planetView* newView);

    //----------METHODS----------
    void Draw (sf::RenderWindow* window);
    bool spawnIntersects(drawable* obj);

    void build();

    virtual std::string Class();
};

#endif
