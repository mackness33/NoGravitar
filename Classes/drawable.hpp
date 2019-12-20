#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "movable.hpp"
#include "entity.hpp"
#include "shape.hpp"

class drawable{
  public:
    drawable();

    virtual ~drawable();

    //----------GETS----------
    //ugly solution, but it's the only thing that can be done
    //Templates can't also be virtual!
    template <typename T> essence<T>* getEssence();
    template <typename T> movable<T>* getMovable();
    template <typename T> entity<T>* getEntity();
    template <typename T> shape<T>* getLine();
    template <typename T> T* getDrawable();
    virtual sf::FloatRect GetLocalBounds();
    virtual sf::FloatRect GetGlobalBounds();

    //----------METHODS------------
    virtual void Draw (sf::RenderWindow* window) = 0;
    virtual void Update ();
    virtual sf::Vector2f left();
    virtual sf::Vector2f right();
    virtual sf::Vector2f top();
    virtual sf::Vector2f bottom();

    virtual std::string Class();

};

#include "drawable.tpp"

#endif // DRAWABLE_H
