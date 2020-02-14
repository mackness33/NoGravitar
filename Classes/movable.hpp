#ifndef MOVABLE_H
#define MOVABLE_H

#include <vector>
#include "essence.hpp"
#include "entity.hpp"

template <class T> class movable : public entity<T>{

  public:
    //----------CONSTRUCTORS----------
    movable();
    movable(T* b);
    movable(sf::Texture* image);                                                                                       //Sprite
    movable(float radius, std::size_t pointCount = 30);                                                                //CircleShape
    movable(sf::Vector2f size, sf::Vector2f position = sf::Vector2f(0, 0), sf::Texture* image = nullptr);              //RectangleShape

    ~movable();

    //----------METHODS----------
    void Move (float offsetX, float offsetY);
    void Move (const sf::Vector2f &offset);

    void Rotate (float angle);

    void Scale (float factorX, float factorY);
    void Scale (const sf::Vector2f &factor);

    //return the class of the object
    virtual std::string Class();
};

#include "movable.tpp"
#endif // MOVABLE_H
