#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "movable.hpp"
#include "entity.hpp"
#include "shape.hpp"
#include "information.hpp"

class drawable{
  protected:
    float width, height;
    float diagonal;

  protected:

  public:
    drawable();

    virtual ~drawable();

    //----------GETS----------
    //ugly solution, but it's the only thing that can be done
    //Templates can't also be virtual!
    //the porpose of these functions return the body of the object
    template <typename T> essence<T>* getEssence();
    template <typename T> movable<T>* getMovable();
    template <typename T> entity<T>* getEntity();
    template <typename T> shape<T>* getShape();
    template <typename T> T* getDrawable();
    virtual sf::FloatRect GetLocalBounds();
    virtual sf::FloatRect GetGlobalBounds();
    virtual float GetRotation();
    float GetDiagonal();


    //----------METHODS------------
    //the method should draw the object and everything regarding in it
    virtual void Draw (sf::RenderWindow* window) = 0;

    //if necessary it updates the object.
    virtual void Update ();

    //handle of the intersection of the object and the one in input
    virtual bool intersects(drawable* obj);

    //return the class of the object
    virtual std::string Class();
};

#include "drawable.tpp"

#endif // DRAWABLE_H
