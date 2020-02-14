#ifndef TEXT_H
#define TEXT_H

#include <vector>
#include "entity.hpp"
#include "essence.hpp"

class text : public entity<sf::Text>{

  public:
    //----------CONSTRUCTORS----------
    text();
    text(const sf::Font &font, const std::string &string);                //Text

    ~text();

    //----------GETS----------
    std::string GetString ();

    //----------SETS----------
    void SetB ();
    void SetFont (const sf::Font &f);
    void SetStyle (sf::Uint32	style);
    void SetString (const std::string &f);
    void SetFillColor (const sf::Color &color);
    void SetOutlineColor (const sf::Color &color);
    void SetCharacterSize (unsigned int size);
    void SetOutlineThickness (float thickness);

    //----------METHODS----------
    //return the class of the object
    virtual std::string Class();
};

#endif // text_H
