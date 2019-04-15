#define PI 3.14159265


class spaceship : public sf::Text{
private:
  sf::Transformable myTransform;

public:

  //CONSTRUCTORS
  spaceship(sf::Text* t, sf::Font* f) : sf::Text(*t){
    this->setFont(*f);
    this->setString("Spacestrip");
  }

  spaceship(sf::Font* f) : sf::Text(){
    this->setFont(*f);

    this->setString("Spaceship");

    // set the character size
    this->setCharacterSize(30); // in pixels, not points!

    // set the color
    this->setFillColor(sf::Color::Green);

    // set the text style
    this->setStyle(sf::Text::Bold | sf::Text::Underlined);

  }

  //SETS

  //METHODS
  void SetPosition(float x, float y){
    myTransform.setPosition(x, y);
  }

  void Draw(sf::RenderTarget& target) const{
    target.draw(*this, myTransform.getTransform());
  }

  void Move(float x, float y){
    myTransform.move(x, y);
  }

  void Rotate(float g){
    myTransform.rotate(g);
  }

  const sf::Vector2f& GetPosition() const{
    return myTransform.getPosition();
  }

  void movement(sf::Keyboard::Key* k){
    float shift = 10;

    switch (*k) {
      case sf::Keyboard::Left : {
        this->rotate(1);
      };break;           //LEFT
      case sf::Keyboard::Right : {
        this->rotate(-1);
      };break;           //RIGHT
      case sf::Keyboard::Up : { this->move(cos(this->getRotation() * PI / 180.0) * (shift), sin(this->getRotation() * PI / 180.0) * (shift)); };break;             //UP
      case sf::Keyboard::Down : { this->move(cos(this->getRotation() * PI / 180.0) * -shift, sin(this->getRotation() * PI / 180.0) * -shift); };break;            //DOWN
      default: std::cout << "Not a movementCommand" << std::endl;
    }
  }

  /*sf::Keyboard::Key smooth_movement(bool* t, bool* r){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
      *t  = true;

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->movement(sf::Keyboard::Up);            //UP
      else
        this->movement(sf::Keyboard::Down);            //DOWN
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
      *r  = true;

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->movement(sf::Keyboard::Left);            //UP
      else
        this->movement(sf::Keyboard::Right);            //DOWN
    }

    return sf::Keyboard::Unknown;
  }*/


};
