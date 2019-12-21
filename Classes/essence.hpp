#ifndef ESSENCE_H
#define ESSENCE_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <exception>
#include <vector>

template <class T> class essence{
  protected:
    sf::RectangleShape bound;       //FOR TESTING ONLY
    float diagonal;
    T *body;

  protected:
    virtual void setBoundery();

  public:
    //----------CONSTRUCTORS----------
    essence();
    ~essence();


    //----------GETS----------
    T* getBody();
    sf::RectangleShape* getBound();
    virtual float getDiagonal();

    //----------SETS----------

    //----------METHODS------------
    void Draw (sf::RenderWindow* window);
    void DrawTest (sf::RenderWindow* window);

    virtual std::string Class();
};

#include "essence.tpp"
#endif // ENTITY_H
