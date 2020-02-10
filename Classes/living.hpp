#ifndef LIVING_H
#define LIVING_H

#include<iostream>

class living{
  protected:
    int life;

  public:
    //---------------CONSTRUCTORS---------------
    living(int lifes = 5);

    //---------------DESTRUCTORS---------------
    ~living();

    //---------------GETS---------------
    bool isAlive();
    //---------------SETS---------------

    //---------------METHODS---------------
    void rip();

    //return the class of the object
    virtual std::string Class();
};

#endif
