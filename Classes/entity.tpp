//------------CONSTRUCTORS------------
template <class T> entity<T>::entity(){}

template <class T> entity<T>::entity(T* b){
  body = new T(b);
  isVA = false;
  this->setBoundery();
}

template <class T> entity<T>::entity(float r, std::size_t pc){
  body = new sf::CircleShape(r, pc);
  isVA = false;
  this->setBoundery();
}

template <class T> entity<T>::entity(sf::Texture* i){
  body = new sf::Sprite(*i);
  isVA = false;
  this->setBoundery();
}

template <class T> entity<T>::entity(sf::Vector2f s, sf::Vector2f p, sf::Texture* i){
  body = new sf::RectangleShape(s);
  this->SetPosition(p);

  if(!i)
    body->setFillColor(sf::Color::Black);

  isVA = false;
  this->setBoundery();
}



template <class T> entity<T>::~entity(){
  std::cout << "DELETING ENTITY" << std::endl;
  delete body;
  body = nullptr;
}


//------------GETS------------
template <class T> T* entity<T>::getBody(){ return body; }
template <class T> sf::RectangleShape* entity<T>::getBound(){ return &bound; }
template <class T> bool entity<T>::isVertexArray(){ return isVA; }


//------------SETS------------
template <class T> void entity<T>::setBody(T* b){
  body = b;

  this->setBoundery();
}

//TODO: Add checks for VertexArray and VertexBuffer
template <class T> void entity<T>::setBoundery(){
  sf::FloatRect *boundBox = new sf::FloatRect(0, 0, 0, 0);
  if (!!body){
      boundBox = new sf::FloatRect(body->getLocalBounds());        //for testing use
  }

  bound.setFillColor(sf::Color::Black);
  bound.setOutlineColor(sf::Color::Red);
  bound.setOutlineThickness(3);
  bound.setSize(sf::Vector2f(boundBox->width, boundBox->height));
}

template <class T> void entity<T>::SetPosition(float x, float y){
  body->setPosition(x, y);
  bound.setPosition(x, y);
}

template <class T> void entity<T>::SetPosition(const sf::Vector2f &position){
  body->setPosition(position);
  bound.setPosition(position);
}

template <class T> void entity<T>::SetRotation(float angle){
  body->setRotation(angle);
  bound.setRotation(angle);
}

template <class T> void entity<T>::SetScale(float x, float y){
  body->setScale(x, y);
  bound.setScale(x, y);
}

template <class T> void entity<T>::SetScale(const sf::Vector2f &factor){
  body->setScale(factor);
  bound.setScale(factor);
}

template <class T> void entity<T>::SetOrigin(float x, float y){
  body->setOrigin(x, y);
  bound.setOrigin(x, y);
}

template <class T> void entity<T>::SetOrigin(const sf::Vector2f &origin){
  body->setOrigin(origin);
  bound.setOrigin(origin);
}


//------------METHODS------------
template <class T> void entity<T>::Draw (sf::RenderWindow* window){
  window->draw(*body);
}

template <class T> void entity<T>::DrawTest (sf::RenderWindow* window){
  window->draw(bound);
  window->draw(*body);
}
