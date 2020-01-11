#ifndef HEADER_H
#define HEADER_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "viewer.hpp"
#include "information.hpp"

class viewer;

class header : public viewer{
  private:
    sf::Text points;
    sf::Text title;
    sf::Font font;

  public:
    //----------CONSTRUCTORS----------
    header(sf::RenderWindow *window, sf::Vector2f size = information::HEADER_DEFAULT_SIZE, sf::Vector2f position = information::HEADER_DEFAULT_POSITION, sf::Texture* image = nullptr);

    //----------GETS----------
    sf::Text getPoints();
    sf::Text getTitle();
    sf::Font getFont();

    //----------SETS----------
    void setPoints(sf::Text p);
    void setTitle(sf::Text t);
    void setFont(sf::Font f);

    //---------------METHODS---------------
    void Draw();
    virtual std::string Class();
};

#endif
