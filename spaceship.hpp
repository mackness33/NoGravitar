#define PI 3.14159265


class spaceship : public sf::Text{
private:
  float spatial_Versor;
  float rotation_Versor;
  sf::Transformable myTransform;

public:

  //CONSTRUCTORS
  spaceship(sf::Text* t, sf::Font* f, float sv, float rv) : sf::Text(*t){
    this->setFont(*f);
    this->setString("Spacestrip");
    spatial_Versor = sv;
    rotation_Versor = rv;
  }

  spaceship(sf::Text* t, sf::Font* f) : sf::Text(*t){
    this->setFont(*f);
    this->setString("Spacestrip");
    spatial_Versor = 0;
    rotation_Versor = 0;
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

    spatial_Versor = 0;
    rotation_Versor = 0;
  }

  //SETS

  //METHODS
  void movement(sf::Keyboard::Key* k){
    switch (*k) {
      case sf::Keyboard::Left : {
        this->rotate(1);
      };break;           //LEFT

      case sf::Keyboard::Right : {
        this->rotate(-1);
      };break;           //RIGHT

      case sf::Keyboard::Up : {
        this->move(cos(this->getRotation() * PI / 180.0) * (10), sin(this->getRotation() * PI / 180.0) * (10));
      };break;             //UP

      case sf::Keyboard::Down : {
        this->move(cos(this->getRotation() * PI / 180.0) * -10, sin(this->getRotation() * PI / 180.0) * -10);
      };break;            //DOWN

      default: std::cout << "Not a movementCommand" << std::endl;
    }
  }

};
