#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <list>
#include "entity.hpp"
#include "essence.hpp"
#include "drawable.hpp"
#include "viewer.hpp"

class playground : public viewer{
  protected:
    std::list<drawable*> allies;
    std::list<drawable*> enemies;
    std::list<drawable*> neutrals;
    bool endGame;

  protected:
    void DrawList (std::list<drawable*> objects);     //draw of a list of objects

  public:
    //---------------CONSTRUCTORS---------------
    playground(sf::RenderWindow *window, sf::Vector2f size = information::PLAYGROUND_DEFAULT_SIZE, sf::Vector2f position = information::PLAYGROUND_DEFAULT_POSITION, sf::Texture* image = nullptr);

    ~playground();

    //---------------METHODS---------------
    virtual void restart();                     //restart of the view
    virtual void Draw();                        //draw of the object's
    virtual void next();                        //go to the next view
    virtual void prev();                        //go to the previous view
    virtual void back();                        //go back to the last view

    virtual void addAlly (drawable* ally);      //add a drawable to allies
    virtual void addEnemy (drawable* enemy);    //add a drawable to enemies
    virtual void addNeutral (drawable* neutral);//add a drawable to neutrals

    virtual bool intersects(drawable* obj);     //handle the intersection between the playground and the drawable in input
    virtual void checkCollision ();             //checks of collision between the various objects
    virtual void collision(std::_List_iterator<drawable*>* object, bool isAlly);    //handle of collision

    //return the class of the object
    virtual std::string Class();
};

#endif
