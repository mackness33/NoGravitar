#ifndef GROUND_H
#define GROUND_H

#include "line.hpp"
#include "shape.hpp"
#include "utility.hpp"
#include "drawable.hpp"
#include "settings.hpp"

class ground : public drawable{
  protected:
    float length;
    float offsetY;
    int numVertex;
    shape<sf::VertexArray>* body;
    std::vector<line*> lines;

  protected:
    bool getMonotony(int section);          //if f(x(A)) < f(x(B))  -> crescente (true)     ELSE -> decrescente(false)

  public:
    //---------------CONSTRUCTORS---------------
    ground(float width, float height, sf::Color color = sf::Color::Green);

    //---------------DESTRUCTORS---------------
    ~ground();

    //---------------GETS---------------
    essence<sf::VertexArray>* getEssence();
    shape<sf::VertexArray>* getLine();
    sf::VertexArray* getDrawable();
    sf::FloatRect GetGlobalBounds();

    //---------------SETS---------------

    //---------------METHODS---------------
    void Draw (sf::RenderWindow* window);

    virtual bool intersects(drawable* object);
    template <typename T> bool intersects(drawable* object);

    //return the class of the object
    virtual std::string Class();
};

#include "ground.tpp"
#endif
