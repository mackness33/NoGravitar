//SPACESHIP
//Class that handle everything that concerne a spaceship

/*
  ISSUE:
    -> nella costruzione immagine ruotata di 90°
*/
#define PI 3.14159265

class backView{
  private:
    sf::View body;

  public:
    //CONSTRUCTORS
    backView(){
      // Initialize the view to a rectangle located at (100, 100) and with a size of 400x200
      view.reset(sf::FloatRect(100, 100, 400, 200));
      // Rotate it by 45 degrees
      view.rotate(45);
      // Set its target viewport to be half of the window
      view.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));
      // Apply it
      window.setView(view);
      // Render stuff
      window.draw(someSprite);
      // Set the default view back
      window.setView(window.getDefaultView());
      // Render stuff not affected by the view
      window.draw(someText);
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
    sf::ConvexShape getBody(){ return this->body;}

    //SETS
    void setXOutOfBounds(bool x){ this->xOutOfBound = x;}
    void setYOutOfBounds(bool y){ this->yOutOfBound = y;}
    void setLeftOutOfBounds(bool l){ this->leftOOB = l;}
    void setTopOutOfBounds(bool t){ this->topOOB = t;}
    void setSpatialVersor(float sv) { this->spatial_Versor = sv;}
    void setRotationVersor(float rv) { this->rotation_Versor = rv;}
    void setBody(sf::ConvexShape b) { this->body = b;}

    //METHODS

    //MOVEMENT
    //It let the spaceship move or rotate based on the key pressed
    void movement(sf::Keyboard::Key k){
      switch (k) {
        case sf::Keyboard::Left : {                 //LEFT
          this->body.rotate(-this->rotation_Versor);
        };break;

        case sf::Keyboard::Right : {                //RIGHT
          this->body.rotate(this->rotation_Versor);
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
          this->body.rotate(-this->rotation_Versor);
          Bound->rotate(-this->rotation_Versor);
        };break;

        case sf::Keyboard::Right : {                //RIGHT
          this->body.rotate(this->rotation_Versor);
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
      float direction = this->body.getRotation() * PI / 180.0;
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

      this->body.move(cos_module, sin_module);
      Bound->move(cos_module, sin_module);
    }


    //FLY
    //It handle spaceship translation in the window
    void fly(float module){
      float direction = this->body.getRotation() * PI / 180.0;
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

      this->body.move(cos_module, sin_module);
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

    void Draw (sf::RenderWindow* window){
      window->draw(body);
    }

    //BUILD
    //It build up the spaceship shape
    void build (){
      //creo quattro punti per la spezzata chiusa dell'astronave
      this->body.setPointCount(4);

      this->body.setPoint(2, sf::Vector2f(30.f, 0.f));
      this->body.setPoint(1, sf::Vector2f(0.f, 40.f));
      this->body.setPoint(3, sf::Vector2f(60.f, 40.f));
      this->body.setPoint(0, sf::Vector2f(30.f, 20.f));

      //creo il contorno della navicella colorata
      this->body.setOutlineThickness(2.f);
      this->body.setOutlineColor(sf::Color(000, 255, 000));
      this->body.setOrigin(30.f, 20.f);
      this->body.setPosition(80.f, 70.f);
      this->body.rotate(90);
    }
};
