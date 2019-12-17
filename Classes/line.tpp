//------------CONSTRUCTORS------------
template <class T> line<T>::line() : essence<T>::essence() {}
template <class T> line<T>::line(int vc, std::vector<sf::Vector2f*> vp, sf::PrimitiveType t){
  sf::VertexArray *ptr = new sf::VertexArray(sf::LineStrip, vc);
  sf::Vector2f *temp;
  std::cout << "vp size: " << vp.size();
  for (int i = 0; i < vp.size(); i++){
    temp = vp[i];
    (*ptr)[i].position = *temp;
    (*ptr)[i].color = sf::Color::Green;
  }

  /*sf::Vertex *vtx = (this->body)[0];
  vtx->position = sf::Vector2f(200, 200);
  *vtx = (this->body)[1];
  vtx->position = sf::Vector2f(300, 300);
  *vtx = (this->body)[2];
  vtx->position = sf::Vector2f(400, 800);
*/
  //sf::Vertex *vtx = (this->body)[0];

  this->body = ptr;
  std::cout << "Position END" << std::endl;
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
  //this->isVA = true;
  //this->setBoundery();
}

template <class T> void line<T>::setBoundery(){
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
