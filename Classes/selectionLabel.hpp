#ifndef SELECTIONLABEL_H
#define SELECTIONLABEL_H

#include <string>
#include "entity.hpp"
#include "text.hpp"
#include "drawable.hpp"
#include "label.hpp"
#include "utility.hpp"

class selectionLabel : public label{
  protected:
    sf::Color primary;
    sf::Color secondary;
    int totalTime;
    bool isSelected;
    std::string value;

  protected:
    void Reset();

  public:
    //---------------CONSTRUCTORS---------------
    selectionLabel(std::string font = "CafeBrewery", const std::string &val = "", const std::string &string = "", sf::Color color1 = sf::Color::White, sf::Color color2 = sf::Color::Red, sf::Vector2f position = sf::Vector2f(0, 0));

    //---------------DESTRUCTORS---------------
    ~selectionLabel();

    //---------------GETS---------------
    std::string getValue();

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
