//OBJECT
//A prototype of a class
//#include "object_test.hpp"

template <class T> object_test<T>::object_test(sf::RenderWindow* w){
  body = new entity<sf::CircleShape>(w);
  this->property = 0;
}

//if there's no property, you don't need get and set!!!
//GETS
template <class T> int object_test<T>::getFroperty(){ return this->property;}

//SETS
template <class T> void object_test<T>::setFroperty(int p) { this->property = p;}

  //METHODS
  //build the shape of the object
  /*void build (){
    //you mostly have to write your code here!
    //creo quattro punti per la spezzata chiusa dell'astronave
    this->setPointCount(4);

    this->setPoint(0, sf::Vector2f(0.f, 0.f));
    this->setPoint(1, sf::Vector2f(0.f, 20.f));
    this->setPoint(2, sf::Vector2f(20.f, 20.f));
    this->setPoint(3, sf::Vector2f(20.f, 0.f));

    //creo il contorno della navicella colorata
    this->setOutlineThickness(2.f);
    this->setOutlineColor(sf::Color(000, 255, 000));
    this->setOrigin(10.f, 10.f);
    this->setPosition(80.f, 70.f);
    this->rotate(90);
  }*/
template <class T> void object_test<T>::Draw (){
  body->DrawTest();
}
