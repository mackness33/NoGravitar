#ifndef LIVING_H
#define LIVING_H

#include<iostream>

class living{
  protected:
    int life;

  public:
    //---------------CONSTRUCTORS---------------
    living(int lifes = 2);

    //---------------DESTRUCTORS---------------
    ~living();

    //---------------METHODS---------------
    bool isAlive();                           //return true if lifes > 0 otherwise false
    void rip();                               //losing a life

    //return the class of the object
    virtual std::string Class();
};

#endif
