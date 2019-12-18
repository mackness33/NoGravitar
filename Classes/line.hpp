#ifndef LINE_H
#define LINE_H

#include "settings.hpp"
#include "utility.hpp"

class line{
  protected:
    sf::Vector2f *a, *b;
    float width, height;

  public:
    //---------------CONSTRUCTORS---------------
    line(sf::Vector2f point1 = sf::Vector2f(0, 0), sf::Vector2f point2 = sf::Vector2f(0, 0));

    //---------------DESTRUCTORS---------------
    ~line();

    //---------------GETS---------------
    float getWidth();
    float getHeight();
    sf::Vector2f getA();
    sf::Vector2f getB();
    sf::Vector2f* getptrA();
    sf::Vector2f* getptrB();
    //---------------SETS---------------
    void setptrA(sf::Vector2f* pnt);
    void setptrB(sf::Vector2f* pnt);
    //void getWidth();

    //---------------METHODS---------------

    //return the class of the object
    virtual std::string Class();
};

#endif
