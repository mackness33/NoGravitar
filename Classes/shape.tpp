//------------CONSTRUCTORS------------
template <class T> shape<T>::shape() : essence<T>::essence() {}
template <class T> shape<T>::shape(int vc, std::vector<line*> vp, sf::PrimitiveType t){
  sf::VertexArray *ptr = new sf::VertexArray(sf::LineStrip, vc);
  this->body = new sf::VertexArray(sf::LineStrip, vc);
  ptr = this->body;
  std::cout << "vp size: " << vp.size();

  line *temp = vp[0];

  for (int i = 0; i < vp.size(); i++){
    temp = vp[i];
    std::cout << "Position x" << i << ": " << temp->getA().x << std::endl;
    std::cout << "Position y" << i << ": " << temp->getA().y << std::endl;
    (*ptr)[i].position = temp->getA();
    (*ptr)[i].color = sf::Color::Green;
  }

  std::cout << "STACCO" << std::endl;
  int lastpos = vp.size();
  (*ptr)[lastpos].position = temp->getB();
  std::cout << "Position x" << lastpos << ": " << temp->getB().x << std::endl;
  std::cout << "Position y" << lastpos << ": " << temp->getB().y << std::endl;
  std::cout << "Class: " << this->body->getVertexCount() << std::endl;
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

template <class T> void shape<T>::setBoundery(){
  sf::FloatRect *boundBox = new sf::FloatRect(0, 0, 0, 0);
  if (!!(this->body)){
      boundBox = new sf::FloatRect(this->body->getBounds());        //for testing use
  }

  std::cout << "Position top: " << boundBox->top << std::endl;
  std::cout << "Position bottom: " << boundBox->top + boundBox->height << std::endl;
  std::cout << "Position left: " << boundBox->left << std::endl;
  std::cout << "Position right: " << boundBox->left + boundBox->width << std::endl;
  this->bound.setFillColor(sf::Color::Black);
  this->bound.setOutlineColor(sf::Color::Red);
  this->bound.setOutlineThickness(3);
  this->bound.setSize(sf::Vector2f(boundBox->width, boundBox->height));
}

template <class T> std::string shape<T>::Class(){
  return "shape";
}
