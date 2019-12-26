#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "movable.hpp"
#include "entity.hpp"
#include "shape.hpp"

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
    template <typename T> essence<T>* getEssence();
    template <typename T> movable<T>* getMovable();
    template <typename T> entity<T>* getEntity();
    template <typename T> shape<T>* getLine();
    template <typename T> T* getDrawable();
    virtual sf::FloatRect GetLocalBounds();
    virtual sf::FloatRect GetGlobalBounds();
    virtual float GetRotation();
    float GetDiagonal();


    //----------METHODS------------
    virtual void Draw (sf::RenderWindow* window) = 0;
    virtual void Update ();
    virtual bool intersects(drawable* obj);

    virtual std::string Class();

};

#include "drawable.tpp"

#endif // DRAWABLE_H
