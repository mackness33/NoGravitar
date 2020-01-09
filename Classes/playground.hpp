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
    playground(sf::RenderWindow *window, sf::Vector2f size = sf::Vector2f(-1, -1), sf::Vector2f position = sf::Vector2f(-1, -1), sf::Texture* image = nullptr);

    ~playground();

    //---------------GETS---------------
    virtual std::list<sf::FloatRect>* getObjectsBounds (std::list<drawable*> objects);

    //---------------METHODS---------------
    virtual void Draw();

    virtual void addAlly (drawable* ally);
    virtual void addEnemy (drawable* enemy);


    virtual void checkCollision ();

    virtual std::string Class();
};

#endif
