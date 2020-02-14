#ifndef SHAPE_H
#define SHAPE_H

#include "essence.hpp"
#include "line.hpp"

template <class T> class shape : public essence<T>{
  public:
    //---------------CONSTRUCTORS---------------
    shape();
    shape(int vertexCount, std::vector<line*> vertexPosition, sf::PrimitiveType type = sf::LineStrip);      //VertexArray

    ~shape();

    //---------------METHODS---------------
    //return the class of the object
    virtual std::string Class();
};

#include "shape.tpp"
#endif // LINE_H
