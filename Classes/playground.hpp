#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <list>
#include "viewer.hpp"

class playground : public viewer{
  protected:
    std::list<drawable*> allies;
    std::list<drawable*> enemies;
    std::list<drawable*> objects;

  protected:
    void DrawList (std::list<drawable*> objects);

  public:
    //---------------CONSTRUCTORS---------------
    playground(sf::RenderWindow *window, sf::Vector2f size = information::PLAYGROUND_DEFAULT_SIZE, sf::Vector2f position = information::PLAYGROUND_DEFAULT_POSITION, sf::Texture* image = nullptr);

    ~playground();

    //---------------GETS---------------
    virtual void getObjectsBounds (std::list<drawable*> objects, std::list<sf::FloatRect>* objectsBounds);

    //---------------METHODS---------------
    virtual void Draw();

    virtual void addAlly (drawable* ally);
    virtual void addEnemy (drawable* enemy);


    virtual void checkCollision ();

    virtual std::string Class();
};

#endif
