//------------CONSTRUCTORS------------
template <class T> movable<T>::movable() : entity<T>::entity() {}
template <class T> movable<T>::movable(T* b) : entity<T>::entity(b) {}
template <class T> movable<T>::movable(float r, std::size_t pc) : entity<T>::entity(r, pc){}                                       //Sprite
template <class T> movable<T>::movable(sf::Texture* i) : entity<T>::entity(i){}                                                    //CircleShape
template <class T> movable<T>::movable(sf::Vector2f s, sf::Vector2f p, sf::Texture* i) : entity<T>::entity(s, p, i){}              //RectangleShape

template <class T> movable<T>::~movable(){}

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

template <class T> std::string movable<T>::Class(){
  return "movable";
}
