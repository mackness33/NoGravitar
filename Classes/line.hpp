#ifndef LINE_H
#define LINE_H


#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <experimental/filesystem>
#include <cmath>
#include <vector>

//the line go from left to right.
//A.x will always be < over B.x

class line{
  protected:
    sf::Vector2f *a, *b;
    float width, height;
    long double slope;

  protected:
    virtual void setup();

  public:
    //---------------CONSTRUCTORS---------------
    line(sf::Vector2f point1 = sf::Vector2f(0, 0), sf::Vector2f point2 = sf::Vector2f(0, 0));

    //---------------DESTRUCTORS---------------
    ~line();

    //---------------GETS---------------
    float getWidth();
    long double getSlope();
    float getHeight();
    sf::Vector2f getA();
    sf::Vector2f getB();
    sf::Vector2f* getptrA();
    sf::Vector2f* getptrB();

    //---------------SETS---------------
    void setA(sf::Vector2f pnt);
    void setB(sf::Vector2f pnt);
    void setptrA(sf::Vector2f* pnt);
    void setptrB(sf::Vector2f* pnt);
    //void getWidth();

    //---------------METHODS---------------
    void swap();

    //return the class of the object
    //sf::Vector2f intersect(line Line);
    //bool intersect(sf::Vector2f point);
    bool doIntersect(line* Line);
    bool onSegment(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r);
    int orientation(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r);
    sf::Vector2f intersection(line l);

    virtual std::string Class();
};

#endif
