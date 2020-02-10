#ifndef TEXT_H
#define TEXT_H

#include <vector>
#include "entity.hpp"

/*
  BUG: change body into sprites
*/

class text : public entity<sf::Text>{

  public:
    //----------CONSTRUCTORS----------
    //TODO: add all the constructors of sf::Shape sf::Sprite .. etc
    text();
    text(const sf::Font &font, const std::string &string);                //Text

    ~text();

    //----------METHODS----------
    std::string GetString ();
    void SetB ();
    void SetFont (const sf::Font &f);
    void SetStyle (sf::Uint32	style);
    void SetString (const std::string &f);
    void SetFillColor (const sf::Color &color);
    void SetOutlineColor (const sf::Color &color);
    void SetCharacterSize (unsigned int size);
    void SetOutlineThickness (float thickness);

    virtual std::string Class();
};

//#include "text.tpp"
#endif // text_H
