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
  bool leftOOB;                   //leftOutOfBounds
  bool topOOB;                   //topOutOfBounds
  float spatial_Versor;
  float rotation_Versor;

public:
  //CONSTRUCTORS
  spaceship(sf::ConvexShape* s, float sv, float rv, bool x/*OutOfBounds*/, bool y/*OutOfBounds*/, bool t/*opOutOfBounds*/, bool l/*eftOutOfBounds*/) : sf::ConvexShape(*s){
    this->xOutOfBound = x;
    this->yOutOfBound = y;
    this->topOOB = t;
    this->leftOOB = l;

    this->spatial_Versor = sv;
    this->rotation_Versor = rv;
  }

  spaceship(sf::ConvexShape* s, float sv, float rv) : sf::ConvexShape(*s){
    this->xOutOfBound = false;
    this->yOutOfBound = false;
    this->topOOB = false;
    this->leftOOB = false;

    this->spatial_Versor = sv;
    this->rotation_Versor = rv;
  }

  spaceship(float sv, float rv, bool x/*OutOfBounds*/, bool y/*OutOfBounds*/, bool t/*opOutOfBounds*/, bool l/*eftOutOfBounds*/){
    this->xOutOfBound = x;
    this->yOutOfBound = y;
    this->topOOB = t;
    this->leftOOB = l;

    this->spatial_Versor = sv;
    this->rotation_Versor = rv;

    this->build();
  }

  spaceship(sf::ConvexShape* s) : sf::ConvexShape(*s){
    this->xOutOfBound = false;
    this->yOutOfBound = false;
    this->topOOB = false;
    this->leftOOB = false;

    this->spatial_Versor = 10;
    this->rotation_Versor = 3;
  }

  spaceship(float sv, float rv){
    this->xOutOfBound = false;
    this->yOutOfBound = false;
    this->topOOB = false;
    this->leftOOB = false;

    this->spatial_Versor = sv;
    this->rotation_Versor = rv;

    this->build();
  }

  spaceship(bool x/*OutOfBounds*/, bool y/*OutOfBounds*/, bool t/*opOutOfBounds*/, bool l/*eftOutOfBounds*/){
    this->xOutOfBound = x;
    this->yOutOfBound = y;
    this->topOOB = t;
    this->leftOOB = l;

    this->spatial_Versor = 10;
    this->rotation_Versor = 3;

    this->build();
  }

  spaceship(){
    this->xOutOfBound = false;
    this->yOutOfBound = false;
    this->topOOB = false;
    this->leftOOB = false;

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
  bool getLeftOutOfBounds(){ return this->leftOOB;}
  bool getTopOutOfBounds(){ return this->topOOB;}
  float getSpatialVersor(){ return this->spatial_Versor;}
  float getRotationVersor(){ return this->rotation_Versor;}

  //SETS
  void setXOutOfBounds(bool x){ this->xOutOfBound = x;}
  void setYOutOfBounds(bool y){ this->yOutOfBound = y;}
  void setLeftOutOfBounds(bool l){ this->leftOOB = l;}
  void setTopOutOfBounds(bool t){ this->topOOB = t;}
  void setSpatialVersor(float sv) { this->spatial_Versor = sv;}
  void setRotationVersor(float rv) { this->rotation_Versor = rv;}

  //METHODS

  //MOVEMENT
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
        fly(this->spatial_Versor);
      };break;

      case sf::Keyboard::Down : {                 //DOWN
        fly(-this->spatial_Versor);
      };break;

      default: std::cout << "Not a movementCommand" << std::endl;
    }
  }

  //for testing use
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
        fly(this->spatial_Versor, Bound);
      };break;

      case sf::Keyboard::Down : {                 //DOWN
        fly(-this->spatial_Versor, Bound);
      };break;

      default: std::cout << "Not a movementCommand" << std::endl;
    }
  }

  //for testing use
  void fly(float module, sf::RectangleShape *Bound){
    float direction = this->getRotation() * PI / 180.0;
    int sin_module = sin(direction) * module;
    int cos_module = cos(direction) * module;
    bool y_opp_dir = opposite_direction(topOOB,  sin(direction) * module);
    bool x_opp_dir = opposite_direction(leftOOB,  cos(direction) * module);

    if((yOutOfBound && !y_opp_dir)){
      sin_module = 0;
      std::cout << "YOutOfBounds!!!" << std::endl;
    }

    if((xOutOfBound && !x_opp_dir)){
      cos_module = 0;
      std::cout << "XOutOfBounds!!!" << std::endl;
    }

    this->move(cos_module, sin_module);
    Bound->move(cos_module, sin_module);
  }


  //FLY
  //It handle spaceship translation in the window
  void fly(float module){
    float direction = this->getRotation() * PI / 180.0;
    int sin_module = sin(direction) * module;
    int cos_module = cos(direction) * module;
    bool y_opp_dir = opposite_direction(topOOB,  sin(direction) * module);
    bool x_opp_dir = opposite_direction(leftOOB,  cos(direction) * module);

    if((yOutOfBound && !y_opp_dir)){
      sin_module = 0;
      std::cout << "YOutOfBounds!!!" << std::endl;
    }

    if((xOutOfBound && !x_opp_dir)){
      cos_module = 0;
      std::cout << "XOutOfBounds!!!" << std::endl;
    }

    this->move(cos_module, sin_module);
  }


  //OPPOSITE_DIRECTION
  //It understand if the spaceship want o go OutOfBOunds
  bool opposite_direction(bool side, float direction){
    if(side){
      if(direction >= 0)
        return true;
    }
    else{
      if(direction <= 0)
        return true;
    }

    return false;
  }

  //BUILD
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
