//------------CONSTRUCTORS------------
template <class T> shape<T>::shape() : essence<T>::essence() {}
template <class T> shape<T>::shape(int vc, std::vector<line*> vp, sf::PrimitiveType t){
  sf::VertexArray *ptr = new sf::VertexArray(sf::LineStrip, vc);
  this->body = new sf::VertexArray(sf::LineStrip, vc);
  ptr = this->body;
  //std::cout << "vp size: " << vp.size();

  line *temp = vp[0];

  for (int i = 0; i < vp.size(); i++){
    temp = vp[i];
    //std::cout << "Position x" << i << ": " << temp->getA().x << std::endl;
    //std::cout << "Position y" << i << ": " << temp->getA().y << std::endl;
    (*ptr)[i].position = temp->getA();
    (*ptr)[i].color = sf::Color::Green;
  }

  int lastpos = vp.size();
  (*ptr)[lastpos].position = temp->getB();
  //std::cout << "Position x" << lastpos << ": " << temp->getB().x << std::endl;
  //std::cout << "Position y" << lastpos << ": " << temp->getB().y << std::endl;
  //std::cout << "Class: " << this->body->getVertexCount() << std::endl;
  /*sf::Vertex *vtx = (this->body)[0];
  vtx->position = sf::Vector2f(200, 200);
  *vtx = (this->body)[1];
  vtx->position = sf::Vector2f(300, 300);
  *vtx = (this->body)[2];
  vtx->position = sf::Vector2f(400, 800);
*/
  //sf::Vertex *vtx = (this->body)[0];
  //*(this->body) = *ptr;
  //this->isVA = true;
  //this->setBoundery();
}

template <class T> shape<T>::~shape(){
  std::cout << "DELETING SHAPE" << std::endl;
}

template <class T> void shape<T>::setBoundery(){}

template <class T> std::string shape<T>::Class(){
  return "shape";
}
