//UNIVERSE
//Class that handle everything that concerne the top of the window

/*

*/
#include "entity.hpp"
#define PI 3.14159265

//------------CONSTRUCTORS------------
template <class T> entity<T>::entity(sf::RenderWindow* w, T* b){
  window = w;
  this->setBody(b);
}

template <class T> entity<T>::entity(sf::RenderWindow* w){
  window = w;
  body = new sf::CircleShape();
  boundBox = new sf::FloatRect(0, 0, 0, 0);        //for testing use
  bound.setSize(sf::Vector2f(boundBox->width, boundBox->height));
  /*bound.setOrigin(body.getOrigin());
  bound.setPosition(body.getPosition());
  bound.setRotation(body.getRotation());
  bound.setScale(body.getScale());*/
}


//------------GETS------------
template <class T> T* entity<T>::getBody(){ return body; }


//------------SETS------------
template <class T> void entity<T>::setBody(T* b){
  body = b;

  //TODO: Add checks for VertexArray and VertexBuffer

  if (!!body)
    boundBox = new sf::FloatRect(0, 0, 0, 0);        //for testing use
  else
    boundBox = new sf::FloatRect(body->getLocalBounds());        //for testing use


  bound.setSize(sf::Vector2f(boundBox->width, boundBox->height));
}

template <class T> void entity<T>::SetPosition(float x, float y){
  body->setPosition(x, y);
  bound.setPosition(x, y);
}

template <class T> void entity<T>::SetPosition(const sf::Vector2f &position){
  body->setPosition(position);
  bound.setPosition(position);
}

template <class T> void entity<T>::SetRotation(float angle){
  body->setRotation(angle);
  bound.setRotation(angle);
}

template <class T> void entity<T>::SetOrigin(float x, float y){
  body->setOrigin(x, y);
  bound.setOrigin(x, y);
}

template <class T> void entity<T>::SetOrigin(const sf::Vector2f &origin){
  body->setOrigin(origin);
  bound.setOrigin(origin);
}


//------------METHODS------------
/*template <class T> void entity::draw(sf::RenderTarget& target, sf::RenderStates states = RenderStates::Default) const{
  // You can draw other high-level objects
  target.draw(, states);
}*/

template <class T> void entity<T>::Draw (){
  window->draw(body);
}

template <class T> void entity<T>::DrawTest (){
  window->draw(body);
  window->draw(bound);
}

template <class T> void entity<T>::Move (float offsetX, float offsetY){
  body->move(offsetX, offsetY);
  bound.move(offsetX, offsetY);
}

template <class T> void entity<T>::Move (const sf::Vector2f &offset){
  body->move(offset);
  bound.move(offset);
}

template <class T> void entity<T>::Rotate (float angle){
  body->rotate(angle);
  bound.rotate(angle);
}

template <class T> void entity<T>::Scale (float factorY, float factorX){
  body->move(factorX, factorY);
  bound.move(factorX, factorY);
}

template <class T> void entity<T>::Scale (const sf::Vector2f &factor){
  body->move(factor);
  bound.move(factor);
}
