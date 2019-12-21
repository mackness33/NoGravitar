//------------CONSTRUCTORS------------
template <class T> essence<T>::essence() { diagonal = -1; }

template <class T> essence<T>::~essence(){
  std::cout << "DELETING ESSENCE" << std::endl;
  delete body;
  body = nullptr;
}


//------------GETS------------
template <class T> T* essence<T>::getBody(){ return body; }
template <class T> sf::RectangleShape* essence<T>::getBound(){ return &bound; }
template <class T> float essence<T>::getDiagonal(){ return diagonal; }


//------------SETS------------
//TODO: Add checks for VertexArray and VertexBuffer
template <class T> void essence<T>::setBoundery(){}


//------------METHODS------------
template <class T> void essence<T>::Draw (sf::RenderWindow* window){
  window->draw(*body);
}

template <class T> void essence<T>::DrawTest (sf::RenderWindow* window){
  window->draw(bound);
  window->draw(*body);
  sf::RectangleShape bound;       //FOR TESTING ONLY

}

template <class T> std::string essence<T>::Class(){
  return "essence";
}
