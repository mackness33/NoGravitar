#ifndef LABEL_H
#define LABEL_H

#include "essence.hpp"
#include "entity.hpp"
#include "text.hpp"
#include "drawable.hpp"
#include "information.hpp"
#include "utility.hpp"

class label : public drawable{
  protected:
    text *body;
    sf::Font *font;

  public:
    //---------------CONSTRUCTORS---------------
    label(std::string font = "CafeBrewery", const std::string &string = "", sf::Vector2f position = sf::Vector2f(0, 0));

    //---------------DESTRUCTORS---------------
    ~label();

    //---------------GETS---------------
    int getInt();                       //return the string as a intager
    std::string getString();
    text* getText();
    sf::Text* getDrawable();
    entity<sf::Text>* getEntity();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();

    //---------------SETS---------------
    void setString (const std::string &s);

    //---------------METHODS---------------
    //Draw the objects
    void Draw (sf::RenderWindow* window);

    //return the class of the object
    virtual std::string Class();
};

#endif
