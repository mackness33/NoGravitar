#ifndef TRACTORBEAM_H
#define TRACTORBEAM_H

#include "line.hpp"
#include "shape.hpp"
#include "utility.hpp"
#include "drawable.hpp"
#include "information.hpp"
#include <climits>

class tractorBeam : public drawable{
  protected:
    movable<sf::RectangleShape>* body;
    std::vector<line*> lines;

  protected:
  public:
    //---------------CONSTRUCTORS---------------
    tractorBeam(sf::Vector2f position = information::PLAYER_DEFAULT_POSITION, sf::Vector2f size = information::PLAYER_DEFAULT_SIZE + sf::Vector2f(30, 30));

    //---------------DESTRUCTORS---------------
    ~tractorBeam();

    //---------------GETS---------------
    entity<sf::RectangleShape>* getEntity();
    essence<sf::RectangleShape>* getEssence();
    movable<sf::RectangleShape>* getMovable();
    sf::RectangleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();

    //---------------SETS---------------

    //---------------METHODS---------------
    void Draw (sf::RenderWindow* window);

    //return the class of the object
    virtual std::string Class();
};

#endif
