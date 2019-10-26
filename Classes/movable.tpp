//MOVABLE

//------------CONSTRUCTORS------------
template <class T> movable<T>::movable(T* b) : entity<T>::entity(b) {}

template <class T> movable<T>::movable() : entity<T>::entity() {}

/*template <class T> movable<T>::movable(sf::RenderWindow* w){
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

template <class T> movable<T>::movable(float radius, std::size_t pointCount) : entity<T>::entity(radius, pointCount) {}

template <class T> movable<T>::movable(sf::Texture* texture) : entity<T>::entity(texture) {}

template <class T> void movable<T>::Move (float offsetX, float offsetY){
  entity<T>::body->move(offsetX, offsetY);
  entity<T>::bound.move(offsetX, offsetY);
}

template <class T> void movable<T>::Move (const sf::Vector2f &offset){
  entity<T>::body->move(offset);
  entity<T>::bound.move(offset);
}

template <class T> void movable<T>::Rotate (float angle){
  entity<T>::body->rotate(angle);
  entity<T>::bound.rotate(angle);
}

template <class T> void movable<T>::Scale (float factorY, float factorX){
  entity<T>::body->move(factorX, factorY);
  entity<T>::bound.move(factorX, factorY);
}

template <class T> void movable<T>::Scale (const sf::Vector2f &factor){
  entity<T>::body->move(factor);
  entity<T>::bound.move(factor);
}
