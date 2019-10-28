//SPACESHIP
//Class that handle everything that concerne a spaceship
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <list>

/*
  BUG: change body into sprites
*/
#define PI 3.14159265

template <class T> class entity{
  protected:
    sf::FloatRect *boundBox;
    sf::RectangleShape bound;       //FOR TESTING ONLY
    T *body;

  protected:
    void setBoundery();

  public:
    //TODO: add all the constructors of sf::Shape sf::Sprite .. etc
    //----------CONSTRUCTORS----------
    entity(T* b);

    entity();

    //CircleShape
    entity(float radius, std::size_t pointCount = 30);

    //Sprite
    entity(sf::Texture* image);

    entity(sf::Vector2f size, sf::Vector2f position = sf::Vector2f(0, 0), sf::Texture* image = nullptr);

    //----------GETS----------
    T* getBody();
    sf::RectangleShape* getBound();

    //----------SETS----------
    void setBody(T *b);

    void 	SetPosition (float x, float y);
    void 	SetPosition (const sf::Vector2f &position);

    void 	SetRotation (float angle);

    void 	SetScale (float factorX, float factorY);
    void 	SetScale (const sf::Vector2f &factor);

    void 	SetOrigin (float x, float y);
    void 	SetOrigin (const sf::Vector2f &origin);

    //----------METHODS------------
    void Draw (sf::RenderWindow* window);
    void DrawTest (sf::RenderWindow* window);
};

#include "entity.tpp"
#endif // ENTITY_H
