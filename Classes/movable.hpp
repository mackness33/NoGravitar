#ifndef MOVABLE_H
#define MOVABLE_H

#include <list>
#include "entity.hpp"

/*
  BUG: change body into sprites
*/

template <class T> class movable : public entity<T>{

  public:
    //----------CONSTRUCTORS----------
    //TODO: add all the constructors of sf::Shape sf::Sprite .. etc
    movable(T* b);

    movable();

    //CircleShape
    movable(float radius, std::size_t pointCount = 30);

    //Sprite
    movable(sf::Texture* texture);

    void 	Move (float offsetX, float offsetY);
    void 	Move (const sf::Vector2f &offset);

    void 	Rotate (float angle);

    void 	Scale (float factorX, float factorY);
    void 	Scale (const sf::Vector2f &factor);

};

#include "movable.tpp"
#endif // MOVABLE_H
