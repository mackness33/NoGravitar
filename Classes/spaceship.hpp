//SPACESHIP
//Class that handle everything that concerne a spaceship

/*
  ISSUE:
    -> nella costruzione immagine ruotata di 90°
*/
#define PI 3.14159265

class spaceship : public sf::ConvexShape/*, public sf::Transformable*/{
private:
  bool xOutOfBound;                   //XOutOfBounds
  bool yOutOfBound;                   //YOutOfBounds
  float spatial_Versor;
  float rotation_Versor;

public:
  //CONSTRUCTORS
  spaceship(sf::ConvexShape* s, float sv, float rv, bool x/*ottomOutOfBounds*/, bool y/*ightOutOfBounds*/) : sf::ConvexShape(*s){
    this->xOutOfBound = x;
    this->yOutOfBound = y;

    this->spatial_Versor = sv;
    this->rotation_Versor = rv;
  }

  spaceship(sf::ConvexShape* s, float sv, float rv) : sf::ConvexShape(*s){
    this->xOutOfBound = false;
    this->yOutOfBound = false;

    this->spatial_Versor = sv;
    this->rotation_Versor = rv;
  }

  spaceship(float sv, float rv, bool x/*ottomOutOfBounds*/, bool y/*ightOutOfBounds*/){
    this->xOutOfBound = x;
    this->yOutOfBound = y;

    this->spatial_Versor = sv;
    this->rotation_Versor = rv;

    this->build();
  }

  spaceship(sf::ConvexShape* s) : sf::ConvexShape(*s){
    this->xOutOfBound = false;
    this->yOutOfBound = false;

    this->spatial_Versor = 10;
    this->rotation_Versor = 3;
  }

  spaceship(float sv, float rv){
    this->xOutOfBound = false;
    this->yOutOfBound = false;

    this->spatial_Versor = sv;
    this->rotation_Versor = rv;

    this->build();
  }

  spaceship(bool x/*OutOfBounds*/, bool y/*ightOutOfBounds*/){
    this->xOutOfBound = x;
    this->yOutOfBound = y;

    this->spatial_Versor = 10;
    this->rotation_Versor = 3;

    this->build();
  }

  spaceship(){
    this->xOutOfBound = false;
    this->yOutOfBound = false;

    this->spatial_Versor = 10;
    this->rotation_Versor = 3;

    this->build();
  }

  /*spaceship(const spaceship& S){
    this->spatial_Versor = S.getSpatialVersor();
    this->rotation_Versor = S.getRotationVersor();

    this->build();
  }*/

  //GETS
  bool getXOutOfBounds(){ return this->xOutOfBound;}
  bool getYOutOfBounds(){ return this->yOutOfBound;}
  float getSpatialVersor(){ return this->spatial_Versor;}
  float getRotationVersor(){ return this->rotation_Versor;}

  //SETS
  void setXOutOfBounds(bool x){ this->xOutOfBound = x;}
  void setYOutOfBounds(bool y){ this->yOutOfBound = y;}
  void setSpatialVersor(float sv) { this->spatial_Versor = sv;}
  void setRotationVersor(float rv) { this->rotation_Versor = rv;}

  //METHODS
  //It let the spaceship move or rotate based on the key pressed
  void movement(sf::Keyboard::Key k, sf::RectangleShape *Bound){
    switch (k) {
      case sf::Keyboard::Left : {                 //LEFT
        this->rotate(-this->rotation_Versor);
        Bound->rotate(-this->rotation_Versor);
      };break;

      case sf::Keyboard::Right : {                //RIGHT
        this->rotate(this->rotation_Versor);
        Bound->rotate(this->rotation_Versor);
      };break;

      case sf::Keyboard::Up : {                   //UP
        std::cout << "x origin: " << this->getOrigin().x << "y origin: " << this->getOrigin().y << std::endl;
        if(xOutOfBound || yOutOfBound){
          std::cout << "OutOfBounds!!!" << std::endl;
          if(xOutOfBound && yOutOfBound){
            this->move(0, 0);
            Bound->move(0, 0);
          }else if(xOutOfBound){
            this->move(0, sin(this->getRotation() * PI / 180.0) * this->spatial_Versor);
            Bound->move(0, sin(this->getRotation() * PI / 180.0) * this->spatial_Versor);
          }else{
            this->move(cos(this->getRotation() * PI / 180.0) * this->spatial_Versor, 0);
            Bound->move(cos(this->getRotation() * PI / 180.0) * this->spatial_Versor, 0);
          }
        }
        else{
          this->move(cos(this->getRotation() * PI / 180.0) * this->spatial_Versor, sin(this->getRotation() * PI / 180.0) * this->spatial_Versor);
          Bound->move(cos(this->getRotation() * PI / 180.0) * this->spatial_Versor, sin(this->getRotation() * PI / 180.0) * this->spatial_Versor);
        }
      };break;

      case sf::Keyboard::Down : {                 //DOWN
        std::cout << "x origin: " << this->getOrigin().x << "y origin: " << this->getOrigin().y << std::endl;

        if(xOutOfBound || yOutOfBound){
          std::cout << "OutOfBounds!!!" << std::endl;
          if(xOutOfBound && yOutOfBound){
            this->move(0, 0);
            Bound->move(0, 0);
          }else if(xOutOfBound){
            this->move(0, sin(this->getRotation() * PI / 180.0) * -this->spatial_Versor);
            Bound->move(0, sin(this->getRotation() * PI / 180.0) * -this->spatial_Versor);
          }else{
            this->move(cos(this->getRotation() * PI / 180.0) * -this->spatial_Versor, 0);
            Bound->move(cos(this->getRotation() * PI / 180.0) * -this->spatial_Versor, 0);
          }
        }
        else{
          this->move(cos(this->getRotation() * PI / 180.0) * -this->spatial_Versor, sin(this->getRotation() * PI / 180.0) * -this->spatial_Versor);
          Bound->move(cos(this->getRotation() * PI / 180.0) * -this->spatial_Versor, sin(this->getRotation() * PI / 180.0) * -this->spatial_Versor);
        }
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
    this->setOrigin(30.f, 20.f);
    this->setPosition(80.f, 70.f);
    this->rotate(90);
  }
};
