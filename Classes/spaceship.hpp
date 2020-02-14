#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <list>
#include <string>
#include "bullet.hpp"
#include "entity.hpp"
#include "essence.hpp"
#include "keyVector.hpp"
#include "living.hpp"
#include "movable.hpp"
#include "playground.hpp"
#include "shooter.hpp"
#include "tractorBeam.hpp"

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
    void SetPosition(sf::Vector2f pos);

    //----------METHODS------------
    //It lets the spaceship moves or rotates based on the key pressed
    void movement(sf::Keyboard::Key k);

    //set the position of the tractor beam
    void setTractorPosition();

    bool isAttracting();                        //return true if the tractor beam is enable. false otherwise

    //It handles spaceship's translation in the window
    void fly(float module);

    //Draw the objects
    void Draw (sf::RenderWindow* window);

    //check the side of the spaceship and understand if is colliding with the playground
    void checkSide(sf::Vector2f spcSide, sf::Vector2f plgSide, bool *sizeOOB, bool *coordinatesOOB);
    void checkOutOfBounds();

    void shoot();       //shoots a bullet
    void pull();                  //disable the tractor beam

    virtual std::string Class();
};

#endif
