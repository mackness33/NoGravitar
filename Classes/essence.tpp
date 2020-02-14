//------------CONSTRUCTORS------------
template <class T> essence<T>::essence() {}

template <class T> essence<T>::~essence(){
  if(!!body)
    delete body;

  body = nullptr;
}

//------------GETS------------
template <class T> T* essence<T>::getBody(){ return body; }
template <class T> sf::RectangleShape* essence<T>::getBound(){ return &bound; }


//------------SETS------------
template <class T> void essence<T>::setBoundery(){}


//------------METHODS------------
template <class T> void essence<T>::Draw (sf::RenderWindow* window){
  window->draw(*body);
}

template <class T> void essence<T>::DrawTest (sf::RenderWindow* window){
  window->draw(bound);
  window->draw(*body);
}

template <class T> std::string essence<T>::Class(){
  return "essence";
}
