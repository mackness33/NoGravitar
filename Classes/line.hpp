#ifndef LINE_H
#define LINE_H

#include "settings.hpp"
#include "utility.hpp"

//the line go from left to right.
//A.x will always be < over B.x

class line{
  protected:
    sf::Vector2f *a, *b;
    float width, height;
    float slope;//, offset;
    sf::FloatRect* area;
    sf::Vector3f *coefficient;

  public:
    //---------------CONSTRUCTORS---------------
    line(sf::Vector2f point1 = sf::Vector2f(0, 0), sf::Vector2f point2 = sf::Vector2f(0, 0));

    //---------------DESTRUCTORS---------------
    ~line();

    //---------------GETS---------------
    float getWidth();
    float getSlope();
    float getHeight();
    sf::Vector2f getA();
    sf::Vector2f getB();
    sf::Vector2f* getptrA();
    sf::Vector2f* getptrB();
    sf::Vector3f getCoefficient();

    //---------------SETS---------------
    void setptrA(sf::Vector2f* pnt);
    void setptrB(sf::Vector2f* pnt);
    //void getWidth();

    //---------------METHODS---------------

    //return the class of the object
    sf::Vector2f intersection(line Line);
    bool intersection(sf::Vector2f point);

    virtual std::string Class();
};

#endif
