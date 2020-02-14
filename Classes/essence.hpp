#ifndef ESSENCE_H
#define ESSENCE_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

//this class is the essence of the every drawable object
//at first it was created for testing porposes
template <class T> class essence{
  protected:
    sf::RectangleShape bound;       //FOR TESTING ONLY
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

    //----------METHODS------------
    void Draw (sf::RenderWindow* window);
    void DrawTest (sf::RenderWindow* window);

    virtual std::string Class();
};

#include "essence.tpp"
#endif // ENTITY_H
