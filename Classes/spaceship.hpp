#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <list>
#include <string>
#include "bullet.hpp"
#include "playground.hpp"
#include "shooter.hpp"
#include "living.hpp"
#include "tractorBeam.hpp"
#include "keyVector.hpp"

class spaceship : public drawable, public shooter, public living{
  private:
    bool xOutOfBound;                   //XOutOfBounds
    bool yOutOfBound;                   //YOutOfBounds
    bool leftOOB;                   //leftOutOfBounds
    bool topOOB;                   //topOutOfBounds
    bool attract;
    float speed;
    float angular_speed;
    movable<sf::RectangleShape>* body;
    tractorBeam *TractorBeam;
    sf::Texture *image;
    playground *Playground;
    keyVector rotation;
    keyVector translation;
//    keyVector attraction;

  protected:
    //It build up the spaceship shape
    void build ();

    void Move(sf::Vector2f pos);
    //It understands if the spaceship wants to go OutOfBOunds
    bool opposite_direction(bool side, float direction);

    virtual float GetRotation();

  public:
    //----------CONSTRUCTORS----------
    spaceship(playground* Playground, float spd = information::SPACESHIP_DEFAULT_SPEED, float dir = information::SPACESHIP_DEFAULT_ANGULAR_SPEED);
    //spaceship(const spaceship& Player);
    ~spaceship();

    //----------GETS----------
    bool getXOutOfBounds();
    bool getYOutOfBounds();
    bool getLeftOutOfBounds();
    bool getTopOutOfBounds();
    float getSpatialVersor();
    float getRotationVersor();
    movable<sf::RectangleShape>* getMovable();
    entity<sf::RectangleShape>* getEntity();
    sf::RectangleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();
    std::list<bullet*>* getBullets();
    playground* getPlayground();
    tractorBeam* getTractorBeam();

    //----------SETS----------
    void setXOutOfBounds(bool x);
    void setYOutOfBounds(bool y);
    void setLeftOutOfBounds(bool left);
    void setTopOutOfBounds(bool top);
    void setSpatialVersor(float spatialVersor);
    void setRotationVersor(float rotationVersor);
    void setBody(sf::RectangleShape* body);
    void setPlayground(playground* Playground);
    void setRotation(bool rotation);
    void setTranslation(bool traslation);
    void setAttraction(bool attraction);
    bool isAttracting();
    //TODO: setTexture(sf::Texture* t);

    //----------METHODS------------
    //It lets the spaceship moves or rotates based on the key pressed
    void movement(sf::Keyboard::Key k);
    void setTractorPosition();

    void SetPosition(sf::Vector2f pos);

    //It handles spaceship's translation in the window
    void fly(float module);

    void Draw (sf::RenderWindow* window);

    void shoot();
    void pull();

    virtual std::string Class();
};

#endif
