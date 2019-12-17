//------------CONSTRUCTORS------------
template <class T> entity<T>::entity(){}

template <class T> entity<T>::entity(T* b){
  this->body = new T(b);
  this->setBoundery();
}

template <class T> entity<T>::entity(float r, std::size_t pc){
  this->body = new sf::CircleShape(r, pc);
  this->setBoundery();
}

template <class T> entity<T>::entity(sf::Texture* i){
  this->body = new sf::Sprite(*i);
  this->setBoundery();
}

template <class T> entity<T>::entity(sf::Vector2f s, sf::Vector2f p, sf::Texture* i){
  this->body = new sf::RectangleShape(s);
  this->SetPosition(p);

  if(!i)
    this->body->setFillColor(sf::Color::Black);

  this->setBoundery();
}

/*template <class T> entity<T>::entity(std::size_t vc, std::vector<sf::Vector2f*> vp, sf::PrimitiveType t){
  body = new sf::VertexArray(t, vc);

  for (int i = 0; i = vp.size(); i++){
    body->append(new sf::Vertex((vp[i])&, sf::Color::Green));
  }

  this->setBoundery();
}*/



template <class T> entity<T>::~entity(){
  std::cout << "DELETING ENTITY" << std::endl;
  delete this->body;
  this->body = nullptr;
}


//------------GETS------------


//------------SETS------------
template <class T> void entity<T>::setBody(T* b){
  this->body = b;

  this->setBoundery();
}

//TODO: Add checks for VertexArray and VertexBuffer
template <class T> void entity<T>::setBoundery(){
  sf::FloatRect *boundBox = new sf::FloatRect(0, 0, 0, 0);
  if (!!this->body){
      boundBox = new sf::FloatRect(this->body->getLocalBounds());        //for testing use
  }

  this->bound.setFillColor(sf::Color::Black);
  this->bound.setOutlineColor(sf::Color::Red);
  this->bound.setOutlineThickness(3);
  this->bound.setSize(sf::Vector2f(boundBox->width, boundBox->height));
}

template <class T> void entity<T>::SetPosition(float x, float y){
  this->body->setPosition(x, y);
  this->bound.setPosition(x, y);
}

template <class T> void entity<T>::SetPosition(const sf::Vector2f &position){
  this->body->setPosition(position);
  this->bound.setPosition(position);
}

template <class T> void entity<T>::SetRotation(float angle){
  this->body->setRotation(angle);
  this->bound.setRotation(angle);
}

template <class T> void entity<T>::SetScale(float x, float y){
  this->body->setScale(x, y);
  this->bound.setScale(x, y);
}

template <class T> void entity<T>::SetScale(const sf::Vector2f &factor){
  this->body->setScale(factor);
  this->bound.setScale(factor);
}

template <class T> void entity<T>::SetOrigin(float x, float y){
  this->body->setOrigin(x, y);
  this->bound.setOrigin(x, y);
}

template <class T> void entity<T>::SetOrigin(const sf::Vector2f &origin){
  this->body->setOrigin(origin);
  this->bound.setOrigin(origin);
}


//------------METHODS------------
