//SPACESHIP
//Class that handle everything that concerne a spaceship
#ifndef OBJECT_INFO_H
#define OBJECT_INFO_H

#include <iostream>
#include <string>

/*
  BUG: change body into sprites
*/
#define PI 3.14159265

class object_info{
  public:
    //----------METHODS------------
    virtual std::String Class() = 0;

};

#endif // OBJECT_INFO_H
