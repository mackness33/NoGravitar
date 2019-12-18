#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <exception>
#include <vector>
#include "essence.hpp"

template <class T> class entity : public essence<T>{
  protected:
    void setBoundery();

  public:
    //TODO: add all the constructors of sf::Shape sf::Sprite .. etc
    //----------CONSTRUCTORS----------
    entity();
    entity(T* b);
    entity(sf::Texture* image);                                                                                       //Sprite
    entity(float radius, std::size_t pointCount = 30);                                                                //CircleShape
    entity(sf::Vector2f size, sf::Vector2f position = sf::Vector2f(0, 0), sf::Texture* image = nullptr);              //RectangleShape


    ~entity();

    //----------GETS----------

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
    virtual std::string Class();
};

#include "entity.tpp"
#endif // ENTITY_H
