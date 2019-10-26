//UNIVERSE
//Class that handle everything that concerne the top of the window

/*

*/
//#include "entity.hpp"
#define PI 3.14159265

//------------CONSTRUCTORS------------
template <class T> entity<T>::entity(T* b){
  if(!!b){
    body = new T();
    boundBox = new sf::FloatRect(body->getLocalBounds());        //for testing use
    bound.setSize(sf::Vector2f(boundBox->width, boundBox->height));
  }
  else
    this->setBody(b);

  //this->setBody(new T());
}

template <class T> entity<T>::entity(){
  body = new T();
  boundBox = new sf::FloatRect(body->getLocalBounds());        //for testing use
  bound.setSize(sf::Vector2f(boundBox->width, boundBox->height));
}

/*template <class T> entity<T>::entity(sf::RenderWindow* w){
  window = w;
  body = new sf::CircleShape();
  body->setRadius(10);
  body->setFillColor(sf::Color::Red);
  //boundBox = new sf::FloatRect(0, 0, 0, 0);        //for testing use
  boundBox = new sf::FloatRect(body->getLocalBounds());        //for testing use
  bound.setSize(sf::Vector2f(boundBox->width, boundBox->height));
  /*bound.setOrigin(body.getOrigin());
  bound.setPosition(body.getPosition());
  bound.setRotation(body.getRotation());
  bound.setScale(body.getScale());
}*/

template <class T> entity<T>::entity(float radius, std::size_t pointCount){
  body = new sf::CircleShape(radius);
  //boundBox = new sf::FloatRect(0, 0, 0, 0);        //for testing use

  boundBox = new sf::FloatRect(body->getLocalBounds());        //for testing use

  bound.setSize(sf::Vector2f(boundBox->width, boundBox->height));
  bound.setOrigin(body->getOrigin());
  bound.setPosition(body->getPosition());
  bound.setRotation(body->getRotation());
  bound.setScale(body->getScale());
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

template <class T> void entity<T>::Draw (sf::RenderWindow* window){
  window->draw(body);
}

template <class T> void entity<T>::DrawTest (sf::RenderWindow* window){
  window->draw(bound);
  window->draw(*body);
}
