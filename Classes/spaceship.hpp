#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <list>
#include <string>
#include "bullet.hpp"
#include "playground.hpp"

class spaceship : public drawable{
  private:
    bool xOutOfBound;                   //XOutOfBounds
    bool yOutOfBound;                   //YOutOfBounds
    bool leftOOB;                   //leftOutOfBounds
    bool topOOB;                   //topOutOfBounds
    float spatial_Versor;
    float rotation_Versor;
    movable<sf::Sprite>* body;
    sf::Texture* image;
    std::list <bullet*> bullets;
    playground *Playground;

  protected:
    //BUILD
    //It build up the spaceship shape
    void build ();

  public:
    //----------CONSTRUCTORS----------
    spaceship(playground* Playground);
    spaceship(playground* Playground, sf::Texture* image);
    //spaceship(const spaceship& Player);
    ~spaceship();

    //----------GETS----------
    bool getXOutOfBounds();
    bool getYOutOfBounds();
    bool getLeftOutOfBounds();
    bool getTopOutOfBounds();
    float getSpatialVersor();
    float getRotationVersor();
    movable<sf::Sprite>* getMovable();
    entity<sf::Sprite>* getEntity();
    sf::Sprite* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();
    std::list<bullet*>* getBullets();

    //----------SETS----------
    void setXOutOfBounds(bool x);
    void setYOutOfBounds(bool y);
    void setLeftOutOfBounds(bool left);
    void setTopOutOfBounds(bool top);
    void setSpatialVersor(float spatialVersor);
    void setRotationVersor(float rotationVersor);
    void setBody(sf::Sprite* body);
    void setPlayground(playground* Playground);
    //TODO: setTexture(sf::Texture* t);

    //----------DELETES----------
    void deleteBullet(bullet* bullet);
    void deleteBullets();

    //----------METHODS------------
    //It let the spaceship move or rotate based on the key pressed
    void movement(sf::Keyboard::Key k);

    //It handle spaceship translation in the window
    void fly(float module);

    //It understand if the spaceship want o go OutOfBOunds
    bool opposite_direction(bool side, float direction);

    void Draw (sf::RenderWindow* window);

    void Shoot();

    std::string Class();
};

#endif
