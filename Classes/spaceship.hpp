//SPACESHIP
//Class that handle everything that concerne a spaceship

/*
  ISSUE:
    -> nella costruzione immagine ruotata di 90°
*/
#define PI 3.14159265

class spaceship : public sf::ConvexShape/*, public sf::Transformable*/{
private:
  bool bottomOOB;                   //BottomOutOfBounds
  bool leftOOB;                   //LeftOutOfBounds
  bool topOOB;                   //TopOutOfBounds
  bool rightOOB;                   //RightOutOfBounds
  float spatial_Versor;
  float rotation_Versor;

public:
  //CONSTRUCTORS
  spaceship(sf::ConvexShape* s, float sv, float rv, bool b/*ottomOutOfBounds*/, bool l/*eftOutOfBounds*/, bool t/*opOutOfBounds*/, bool r/*ightOutOfBounds*/) : sf::ConvexShape(*s){
    this->bottomOOB = b;
    this->leftOOB = l;
    this->topOOB = t;
    this->rightOOB = r;

    this->spatial_Versor = sv;
    this->rotation_Versor = rv;
  }

  spaceship(sf::ConvexShape* s, float sv, float rv) : sf::ConvexShape(*s){
    this->bottomOOB = false;
    this->leftOOB = false;
    this->topOOB = false;
    this->rightOOB = false;

    this->spatial_Versor = sv;
    this->rotation_Versor = rv;
  }

  spaceship(float sv, float rv, bool b/*ottomOutOfBounds*/, bool l/*eftOutOfBounds*/, bool t/*opOutOfBounds*/, bool r/*ightOutOfBounds*/){
    this->bottomOOB = b;
    this->leftOOB = l;
    this->topOOB = t;
    this->rightOOB = r;

    this->spatial_Versor = sv;
    this->rotation_Versor = rv;

    this->build();
  }

  spaceship(sf::ConvexShape* s) : sf::ConvexShape(*s){
    this->bottomOOB = false;
    this->leftOOB = false;
    this->topOOB = false;
    this->rightOOB = false;

    this->spatial_Versor = 10;
    this->rotation_Versor = 3;
  }

  spaceship(float sv, float rv){
    this->bottomOOB = false;
    this->leftOOB = false;
    this->topOOB = false;
    this->rightOOB = false;

    this->spatial_Versor = sv;
    this->rotation_Versor = rv;

    this->build();
  }

  spaceship(bool b/*ottomOutOfBounds*/, bool l/*eftOutOfBounds*/, bool t/*opOutOfBounds*/, bool r/*ightOutOfBounds*/){
    this->bottomOOB = b;
    this->leftOOB = l;
    this->topOOB = t;
    this->rightOOB = r;

    this->spatial_Versor = 10;
    this->rotation_Versor = 3;

    this->build();
  }

  spaceship(){
    this->bottomOOB = false;
    this->leftOOB = false;
    this->topOOB = false;
    this->rightOOB = false;

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
  bool getBottomOutOfBounds(){ return this->bottomOOB;}
  bool getLeftOutOfBounds(){ return this->leftOOB;}
  bool getTopOutOfBounds(){ return this->topOOB;}
  bool getRightOutOfBounds(){ return this->rightOOB;}
  float getSpatialVersor(){ return this->spatial_Versor;}
  float getRotationVersor(){ return this->rotation_Versor;}

  //SETS
  void setBottomOutOfBounds(bool b){ this->bottomOOB = b;}
  void setLeftOutOfBounds(bool l){ this->leftOOB = l;}
  void setTopOutOfBounds(bool t){ this->topOOB = t;}
  void setRightOutOfBounds(bool r){ this->rightOOB = r;}
  void setSpatialVersor(float sv) { this->spatial_Versor = sv;}
  void setRotationVersor(float rv) { this->rotation_Versor = rv;}

  //METHODS
  //It let the spaceship move or rotate based on the key pressed
  void movement(sf::Keyboard::Key k){
    switch (k) {
      case sf::Keyboard::Left : {                 //LEFT
        this->rotate(-this->rotation_Versor);
      };break;

      case sf::Keyboard::Right : {                //RIGHT
        this->rotate(this->rotation_Versor);
      };break;

      case sf::Keyboard::Up : {                   //UP
        this->move(cos(this->getRotation() * PI / 180.0) * this->spatial_Versor, sin(this->getRotation() * PI / 180.0) * this->spatial_Versor);
      };break;

      case sf::Keyboard::Down : {                 //DOWN
        this->move(cos(this->getRotation() * PI / 180.0) * -this->spatial_Versor, sin(this->getRotation() * PI / 180.0) * -this->spatial_Versor);
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
