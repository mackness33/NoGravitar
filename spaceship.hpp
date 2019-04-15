//SPACESHIP
//Class that handle everything that concerne a spaceship
#define PI 3.14159265

class spaceship : public sf::Text/*, public sf::Transformable*/{
private:
  float spatial_Versor;                   //used for constant movement
  float rotation_Versor;                  //used for constant rotation

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

  //GETS
  float getSpatialVersor(){ return this->spatial_Versor;}
  float getRotationVersor(){ return this->rotation_Versor;}

  //SETS
  void setSpatialVersor(float sv) { this->spatial_Versor = sv;}
  void setRotationVersor(float rv) { this->rotation_Versor = rv;}

  //METHODS
  //It let the spaceship move or rotate based on the key pressed
  void movement(sf::Keyboard::Key k){
    switch (k) {
      case sf::Keyboard::Left : {                 //LEFT
        this->rotate(-3);
      };break;

      case sf::Keyboard::Right : {                //RIGHT
        this->rotate(3);
      };break;

      case sf::Keyboard::Up : {                   //UP
        this->move(cos(this->getRotation() * PI / 180.0) * (10), sin(this->getRotation() * PI / 180.0) * (10));
      };break;

      case sf::Keyboard::Down : {                 //DOWN
        this->move(cos(this->getRotation() * PI / 180.0) * -10, sin(this->getRotation() * PI / 180.0) * -10);
      };break;

      default: std::cout << "Not a movementCommand" << std::endl;
    }
  }

};
