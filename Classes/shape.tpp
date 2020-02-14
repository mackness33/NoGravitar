//------------CONSTRUCTORS------------
template <class T> shape<T>::shape() : essence<T>::essence() {}
template <class T> shape<T>::shape(int vc, std::vector<line*> vp, sf::PrimitiveType t){
  sf::VertexArray *ptr = new sf::VertexArray(sf::LineStrip, vc);
  this->body = new sf::VertexArray(sf::LineStrip, vc);
  line *temp = vp[0];
  int lastpos = vp.size();

  ptr = this->body;

  //set colors and Vertex of the object
  for (int i = 0; i < vp.size(); i++){
    temp = vp[i];
    (*ptr)[i].position = temp->getA();
    (*ptr)[i].color = sf::Color::Green;
  }

  (*ptr)[lastpos].position = temp->getB();
}

template <class T> shape<T>::~shape(){}

template <class T> std::string shape<T>::Class(){
  return "shape";
}
