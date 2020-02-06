#ifndef SELECTIONLABEL_H
#define SELECTIONLABEL_H

#include "entity.hpp"
#include "text.hpp"
#include "drawable.hpp"
#include "plainText.hpp"
#include "utility.hpp"

class selectionLabel : public plainText{
  protected:
    sf::Color primary;
    sf::Color secondary;
    int totalTime;
    bool isSelected;

  public:
    //---------------CONSTRUCTORS---------------
    selectionLabel(std::string font = "CafeBrewery", const std::string &string = "", sf::Color color1 = sf::Color::White, sf::Color color2 = sf::Color::Red, sf::Vector2f position = sf::Vector2f(0, 0));

    //---------------DESTRUCTORS---------------
    ~selectionLabel();

    //---------------GETS---------------
    //---------------SETS---------------

    //---------------METHODS---------------
    void Draw (sf::RenderWindow* window);

    //update of the object's data for each time that it is draw
    void Update();

    //build all the information of object's body
    void build();
    void select(bool is);

    //return the class of the object
    virtual std::string Class();
};

#endif
