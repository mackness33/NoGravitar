//SPACESHIP
//Class that handle everything that concerne a spaceship

/*
  BUG: change body into sprites
*/
#define PI 3.14159265
#include "spaceship.hpp"

//CONSTRUCTORS
spaceship::spaceship(){
  xOutOfBound = false;
  yOutOfBound = false;
  topOOB = false;
  leftOOB = false;

  spatial_Versor = 10;
  rotation_Versor = 3;

  //b = NULL;
  bullets = {};

  image->loadFromFile("img/spaceship.png");
  body = new movable<sf::Sprite>(image);

  //this->build();
}

spaceship::spaceship(sf::Texture* img){
  xOutOfBound = false;
  yOutOfBound = false;
  topOOB = false;
  leftOOB = false;

  spatial_Versor = 10;
  rotation_Versor = 3;

  //b = NULL;
  bullets = {};

  image = img;
  image->loadFromFile("img/spaceship.png");

  body = new movable<sf::Sprite>(image);
  body->SetScale(0.25f, 0.25f);
  body->SetPosition(80.f, 70.f);


  //this->build();
}

/*spaceship(const spaceship& S){
  spatial_Versor = S.getSpatialVersor();
  rotation_Versor = S.getRotationVersor();

  build();
}*/

//GETS
bool spaceship::getXOutOfBounds(){ return xOutOfBound;}
bool spaceship::getYOutOfBounds(){ return yOutOfBound;}
bool spaceship::getLeftOutOfBounds(){ return leftOOB;}
bool spaceship::getTopOutOfBounds(){ return topOOB;}
float spaceship::getSpatialVersor(){ return spatial_Versor;}
float spaceship::getRotationVersor(){ return rotation_Versor;}
sf::Sprite* spaceship::getBody(){ return body->getBody();}

//SETS
void spaceship::setXOutOfBounds(bool x){ xOutOfBound = x;}
void spaceship::setYOutOfBounds(bool y){ yOutOfBound = y;}
void spaceship::setLeftOutOfBounds(bool l){ leftOOB = l;}
void spaceship::setTopOutOfBounds(bool t){ topOOB = t;}
void spaceship::setSpatialVersor(float sv) { spatial_Versor = sv;}
void spaceship::setRotationVersor(float rv) { rotation_Versor = rv;}
//void spaceship::setBody(sf::Sprite* b) { body = b;}

//---------------METHODS--------------------

//MOVEMENT
//It let the spaceship move or rotate based on the key pressed
void spaceship::movement(sf::Keyboard::Key k){
  switch (k) {
    case sf::Keyboard::Left : {                 //LEFT
      body->Rotate(-rotation_Versor);
    };break;

    case sf::Keyboard::Right : {                //RIGHT
      body->Rotate(rotation_Versor);
    };break;

    case sf::Keyboard::Up : {                   //UP
      fly(spatial_Versor);
    };break;

    case sf::Keyboard::Down : {                 //DOWN
      fly(-spatial_Versor);
    };break;

    default: std::cout << "Not a movementCommand" << std::endl;
  }
}

//for testing use
void spaceship::movement(sf::Keyboard::Key k, sf::RectangleShape *Bound){
  switch (k) {
    case sf::Keyboard::Left : {                 //LEFT
      body->Rotate(-rotation_Versor);
      Bound->rotate(-rotation_Versor);
    };break;

    case sf::Keyboard::Right : {                //RIGHT
      body->Rotate(rotation_Versor);
      Bound->rotate(rotation_Versor);
    };break;

    case sf::Keyboard::Up : {                   //UP
      fly(spatial_Versor, Bound);
    };break;

    case sf::Keyboard::Down : {                 //DOWN
      fly(-spatial_Versor, Bound);
    };break;

    default: std::cout << "Not a movementCommand" << std::endl;
  }
}

//for testing use
void spaceship::fly(float module, sf::RectangleShape *Bound){
  float direction = body->getBody()->getRotation() * PI / 180.0;
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

  body->Move(cos_module, sin_module);
  Bound->move(cos_module, sin_module);
}


//FLY
//It handle spaceship translation in the window
void spaceship::fly(float module){
  float direction = body->getBody()->getRotation() * PI / 180.0;
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

  body->Move(cos_module, sin_module);
}


//OPPOSITE_DIRECTION
//It understand if the spaceship want o go OutOfBOunds
bool spaceship::opposite_direction(bool side, float direction){
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

void spaceship::Draw (sf::RenderWindow* window){
  /*for (bullet b : bullets) {
    b.Update();
    b.Draw(window);
    std::cout << "bullet printed" << '\n';
  }*/
  //std::cout << !!b << std::endl;
  //bullet *b ;//= (* bullet) bullets.front();
  /*if(!bullets.empty()){
    bullet *bul;
    bul = &(bullets.front());
    //b = bul;
    bul->Update();
    bul->Draw(window);
  }*/

  //std::cout << "bullets size(): " << bullets.size() <<  '\n';

  //for (bullet bul : bullets) {
  bullet *bul;
  //bullet b = bullets.begin();
  int i = 0;

  std::list<bullet*>::iterator b = bullets.begin();
  //while( i != bullets.size()){
  for (/*std::list<bullet*>::iterator */b = bullets.begin(); b != bullets.end(); b++){
    //std::cout << "position i: " << i << std::endl;
    bul = *b;
    //std::cout << "Does the bullet exist: " << !!bul << std::endl;
    if(!!bul){
      //std::cout << "real location of " << i << "^ bullet: " << bul << std::endl;
      bul->Update();
      bul->Draw(window);
    }//break;

    //if(!!(b+1))
      //b++;
    //next(b, i);
  }
  //std::cout << "bullets size: " << bullets.size() << std::endl;


  /*for (vector<int>::iterator b = bullets.cbegin(); b != bullets.cend(); b++){
    *bul = *b;
    bul->Update();
    bul->Draw(window);
  }
  /*while(i < bullets.size()){
    std::cout << "bullet id: " << ++i << std::endl;
  	b++;
  }
  /*for (int i = 0; i < bullets.size(); i++) {
    //if(bul != NULL){
    //}
    bul = &(bullets.front());
    //b = bul;
    bul->Update();
    bul->Draw(window);
  }*/

  body->Draw(window);
}

//BUILD
//It build up the spaceship shape
/*void spaceship::build (){
  //creo quattro punti per la spezzata chiusa dell'astronave
  body->setPointCount(4);

  body->setPoint(2, sf::Vector2f(30.f, 0.f));
  body.setPoint(1, sf::Vector2f(0.f, 40.f));
  body.setPoint(3, sf::Vector2f(60.f, 40.f));
  body.setPoint(0, sf::Vector2f(30.f, 20.f));

  //creo il contorno della navicella colorata
  body.setOutlineThickness(2.f);
  body.setOutlineColor(sf::Color(000, 255, 000));
  body.setOrigin(30.f, 20.f);
  body.setPosition(80.f, 70.f);
  body.setScale(0.5f, 0.5f);

  //body.rotate(90);
}*/

void spaceship::Shoot(){

  bullet *bul = new bullet(spatial_Versor * 1.5f, body->getBody()->getRotation(), body->getBody()->getPosition());
  //std::cout << "real location c: " << bul << std::endl;
  bullets.push_back(bul);
}
