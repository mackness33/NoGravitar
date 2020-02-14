#ifndef SELECTIONLABEL_H
#define SELECTIONLABEL_H

#include <string>
#include "drawable.hpp"
#include "entity.hpp"
#include "essence.hpp"
#include "label.hpp"
#include "text.hpp"

class selectionLabel : public label{
  protected:
    sf::Color primary;
    sf::Color secondary;
    int totalTime;
    bool isSelected;
    std::string value;

  protected:
    void Reset();                       //reset totalTime to 0. This way it stop blinking

  public:
    //---------------CONSTRUCTORS---------------
    selectionLabel(std::string font = "CafeBrewery", const std::string &val = "", const std::string &string = "", sf::Color color1 = sf::Color::White, sf::Color color2 = sf::Color::Red, sf::Vector2f position = sf::Vector2f(0, 0));

    //---------------DESTRUCTORS---------------
    ~selectionLabel();

    //---------------GETS---------------
    std::string getValue();

    //---------------METHODS---------------
    void Draw (sf::RenderWindow* window);


    //update of the object's data for each time that it is draw
    void Update();

    void select(bool is);                 //decide whethere this label is selected or not

    //return the class of the object
    virtual std::string Class();
};

#endif
