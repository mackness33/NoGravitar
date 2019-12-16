//------------CONSTRUCTORS------------
template <class T> line<T>::line(int vc, std::vector<sf::Vector2f*> vp, sf::PrimitiveType t){
  this->body = new sf::VertexArray(t, vc);

  for (int i = 0; i = vp.size(); i++){
    sf::Vector2f temp = *vp[i];
    this->body->append(temp);
  }

  this->isVA = true;
  setBoundery();
}

template <class T> void line<T>::setBoundery(){
  sf::FloatRect *boundBox = new sf::FloatRect(0, 0, 0, 0);
  if (!!this->body){
      boundBox = new sf::FloatRect(this->body->getBounds());        //for testing use
  }

  this->bound.setFillColor(sf::Color::Black);
  this->bound.setOutlineColor(sf::Color::Red);
  this->bound.setOutlineThickness(3);
  this->bound.setSize(sf::Vector2f(boundBox->width, boundBox->height));
}
