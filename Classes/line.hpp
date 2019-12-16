#ifndef LINE_H
#define LINE_H

#include "entity.hpp"

template <class T> class line : public entity<T>{
  public:
    line(int vertexCount, std::vector<sf::Vector2f*> vertexPosition, sf::PrimitiveType type = sf::LineStrip);      //VertexArray

    void setBoundery();
};

#include "line.tpp"
#endif // LINE_H
