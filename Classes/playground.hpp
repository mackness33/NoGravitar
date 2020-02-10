#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <list>
#include "viewer.hpp"
#include "bullet.hpp"

class playground : public viewer{
  protected:
    std::list<drawable*> allies;
    std::list<drawable*> enemies;
    std::list<drawable*> neutrals;
    std::list<drawable*> objects;
    bool endGame;

  protected:
    void DrawList (std::list<drawable*> objects);

  public:
    //---------------CONSTRUCTORS---------------
    playground(sf::RenderWindow *window, sf::Vector2f size = information::PLAYGROUND_DEFAULT_SIZE, sf::Vector2f position = information::PLAYGROUND_DEFAULT_POSITION, sf::Texture* image = nullptr);

    ~playground();

    //---------------GETS---------------
    virtual void getObjectsBounds (std::list<drawable*> objects, std::list<sf::FloatRect>* objectsBounds);

    //---------------METHODS---------------
    virtual void restart();
    virtual void Hola();
    virtual void Draw();

    virtual void delObjects ();
    virtual void addAlly (drawable* ally);
    virtual void addEnemy (drawable* enemy);
    virtual void addNeutral (drawable* neutral);

    virtual bool intersects(drawable* obj);
    virtual void checkCollision ();
    virtual void collision(std::_List_iterator<drawable*>* object, bool isAlly);

    virtual std::string Class();
};

#endif
