#ifndef MOVABLE_H
#define MOVABLE_H

#include <vector>
#include "entity.hpp"

/*
  BUG: change body into sprites
*/

template <class T> class movable : public entity<T>{

  public:
    //----------CONSTRUCTORS----------
    //TODO: add all the constructors of sf::Shape sf::Sprite .. etc
    movable();
    movable(T* b);
    movable(sf::Texture* image);                                                                                       //Sprite
    movable(float radius, std::size_t pointCount = 30);                                                                //CircleShape
    movable(sf::Vector2f size, sf::Vector2f position = sf::Vector2f(0, 0), sf::Texture* image = nullptr);              //RectangleShape
    //movable(std::size_t vertexCount, std::vector<sf::Vector2f*> vertexPosition = {}, sf::PrimitiveType type = sf::LineStrip);      //VertexArray

    void 	Move (float offsetX, float offsetY);
    void 	Move (const sf::Vector2f &offset);

    void 	Rotate (float angle);

    void 	Scale (float factorX, float factorY);
    void 	Scale (const sf::Vector2f &factor);

    virtual std::string Class();
};

#include "movable.tpp"
#endif // MOVABLE_H
