#ifndef SHAPE_H
#define SHAPE_H

#include "essence.hpp"
#include "line.hpp"

template <class T> class shape : public essence<T>{
  public:
    shape();
    shape(int vertexCount, std::vector<line*> vertexPosition, sf::PrimitiveType type = sf::LineStrip);      //VertexArray

    ~shape();

    void setBoundery();
    virtual std::string Class();
};

#include "shape.tpp"
#endif // LINE_H
