#ifndef UTILITY_H
#define UTILITY_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <math.h>
#include "drawable.hpp"


class drawable;

class utility{
  public:
    static float toRadiant(float degrees);
    static long double toDegrees(long double radiant);
    static int Proportion(int a, int b, int c = 100);
    static int RandInt(int x, int y = 0);
    static float RandFloat(int x, float y = 0);
    static sf::Vector2f RandVector(int x, int y, int offsetX = 0, int offsetY = 0);
    template <typename T> static void deleteList(std::list<T*>& objects);
    template <typename T> static void deleteVector(std::vector<T*>& objects);

    //they return the farthest side point of the objects
    static sf::Vector2f left(drawable* obj);
    static sf::Vector2f right(drawable* obj);
    static sf::Vector2f top(drawable* obj);
    static sf::Vector2f bottom(drawable* obj);
};

#include "utility.tpp"

#endif
