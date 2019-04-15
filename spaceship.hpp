//SPACESHIP
//Class that handle everything that concerne a spaceship
#define PI 3.14159265

class spaceship : public sf::ConvexShape/*, public sf::Transformable*/{
private:
  float spatial_Versor;                   //used for constant movement
  float rotation_Versor;                  //used for constant rotation

public:
  //CONSTRUCTORS
  spaceship(sf::ConvexShape* s, float sv, float rv) : sf::ConvexShape(*s){
    this->spatial_Versor = sv;
    this->rotation_Versor = rv;
  }

  spaceship(float sv, float rv){
    this->spatial_Versor = sv;
    this->rotation_Versor = rv;

    this->build();
  }

  spaceship(sf::ConvexShape* s) : sf::ConvexShape(*s){
    this->spatial_Versor = 3;
    this->rotation_Versor = 6;
  }

  spaceship(){
    this->spatial_Versor = 3;
    this->rotation_Versor = 6;

    this->build();
  }

  /*spaceship(const spaceship& S){
    this->spatial_Versor = S.getSpatialVersor();
    this->rotation_Versor = S.getRotationVersor();

    this->build();
  }*/

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

  //It build up the spaceship shape
  void build (){
    //creo quattro punti per la spezzata chiusa dell'astronave
    this->setPointCount(4);

    this->setPoint(2, sf::Vector2f(30.f, 0.f));
    this->setPoint(1, sf::Vector2f(0.f, 40.f));
    this->setPoint(3, sf::Vector2f(60.f, 40.f));
    this->setPoint(0, sf::Vector2f(30.f, 20.f));

    //creo il contorno della navicella colorata
    this->setOutlineThickness(2.f);
    this->setOutlineColor(sf::Color(000, 255, 000));
    this->rotate(90);
  }
};
