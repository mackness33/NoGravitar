#ifndef SHOOTER_H
#define SHOOTER_H


#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <exception>
#include <list>
#include "bullet.hpp"
class bullet;

class shooter{
  protected:
    std::list <bullet*> bullets;

  public:
    shooter();

    virtual ~shooter();

    //----------METHODS------------
    virtual void deleteBullet(bullet* bullet);            //deletes a bullet
    virtual void deleteBullets();                         //delets all the bullets
    virtual void shoot() = 0;

    virtual std::string Class();

};

#endif // SHOOTER_H
