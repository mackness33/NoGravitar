#ifndef SHOOTER_H
#define SHOOTER_H


#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <exception>
#include <list>
#include "bullet.hpp"
#include "utility.hpp"
#include "information.hpp"

class bullet;

class shooter{
  protected:
    std::list <bullet*> bullets;

  public:
    shooter();

    virtual ~shooter();

    //----------GETS----------


    //----------METHODS------------
    virtual void deleteBullet(bullet* bullet);
    virtual void deleteBullets();
    virtual void shoot() = 0;

    virtual std::string Class();

};

//#include "shooter.tpp"

#endif // SHOOTER_H
