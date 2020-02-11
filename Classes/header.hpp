#ifndef HEADER_H
#define HEADER_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "label.hpp"
#include "points.hpp"
#include "viewer.hpp"
#include "information.hpp"

class viewer;

class header : public viewer{
  private:
    points* score;
    points* bestScore;
    label* title;

  public:
    //----------CONSTRUCTORS----------
    header(sf::RenderWindow *window, sf::Vector2f size = information::HEADER_DEFAULT_SIZE, sf::Vector2f position = information::HEADER_DEFAULT_POSITION, sf::Texture* image = nullptr);
    ~header();

    //----------GETS----------
    points* getPoints();
    unsigned int getBest();
    //sf::Text getTitle();
    //const sf::Font* getFont();

    //----------SETS----------
    //void setTitle(sf::Text text);
    //void setFont(sf::Font* font);

    //---------------METHODS---------------
    void Draw();
    virtual std::string Class();
};

#endif
