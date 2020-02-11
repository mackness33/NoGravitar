#include "gameplay.hpp"

//CONSTRUCTORS
gameplay::gameplay(sf::RenderWindow* wnd, game* g) : scene(wnd), Game(g) {
  Player = new spaceship(nullptr);
  Header = new header(Window);
  //Playground = new playground(Window);
  //Settings = new information(Window);
  Galaxy = new galaxy(Window, Player, 20, this);
  //StartView = new startView(Window);
  this->Viewer = Galaxy;
  Player->setPlayground(Galaxy);

  Points = Header->getPoints();
}

gameplay::~gameplay(){
  std::cout << "DELETING GAMEPLAY" << std::endl;

  if(!!Player)
    delete Player;

  if(!!Galaxy)
    delete Galaxy;

  if(!!Header)
    delete Header;

  //if(!!Settings)
    //delete Settings;

  //if(!!Viewer)
    //delete Viewer;

  Window = nullptr;
  Player = nullptr;
  Header = nullptr;
  //Settings = nullptr;
  Galaxy = nullptr;
  //Viewer = nullptr;

}


//GETS
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//SETS
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->background = b;}


//---------------METHODS---------------

void gameplay::eventHandler(const sf::Event &event){
  switch (event.type) {
    //KEYRELEASED
    case sf::Event::KeyReleased :{
      eventHandler::keyReleasedHandler(event, &translation, &rotation);
    };break;

    //KEYPRESSED
    case sf::Event::KeyPressed :{
      this->keyPressedHandler(event);
    }

    //WINDOWCLOSED
    case sf::Event::Closed :{
      eventHandler::windowClosedHandler(event, *Window);
    };break;

    default :
      break;
  }
}

void gameplay::restart(){
  std::cout << "Boh vediamo! " << std::endl;
  game::bestScore = Header->getBest();
  std::cout << "Magari! " << std::endl;
  Game->restart();
}
void gameplay::deathBunker(){ Points->deathBunker(); }      //can be optimazed with friend keyword on points for Galaxy
void gameplay::deathPlanet(){ Points->deathPlanet(); }      //can be optimazed with friend keyword on points for PlanetView
void gameplay::keyReleasedHandler(const sf::Event &e){}

void gameplay::keyPressedHandler(const sf::Event &e){
  std::cout << "the key pressed is: " << e.key.code << std::endl;
  switch (e.key.code) {
    case sf::Keyboard::S : {
      Player->shoot();
    };break;

    /*case sf::Keyboard::Y : {
      //(static_cast<planetView*>(Playground))->restart();
    };break;
*/
    case sf::Keyboard::X : {
      std::cout << "Hi, I am X: " << std::endl;
      // std::cout << "CLASS: " << Playground->Class() << std::endl;
      std::cout << "CLASS: " << !!Playground << std::endl;
      //Playground->restart();
      (Player->getPlayground())->restart();
    }

    default: {}

  }
    //default: std::cout << "the key pressed is: " << e.key.code << std::endl;
  /*
  std::cout << "the key pressed is: " << event.key.code << std::endl;
  std::cout << "control:" << event.key.control << std::endl;
  std::cout << "alt:" << event.key.alt << std::endl;
  std::cout << "shift:" << event.key.shift << std::endl;
  std::cout << "system:" << event.key.system << std::endl;
  */
}

//DRAW
void gameplay::Draw (){

  collisionHandler::checkOutOfBounds(Player, this->Viewer);

  //module keys
  translation.isUsed(sf::Keyboard::Up, sf::Keyboard::Down);   //which key has been pressed
  if(translation.getTransformation())                         //if pressed make a transformation of the object
    Player->movement(translation.getKey()/*, &spaceshipBoundingBox*/);


  //direction keys
  rotation.isUsed(sf::Keyboard::Right, sf::Keyboard::Left);   //which key has been pressed
  if(rotation.getTransformation())                            //if pressed make a transformation of the object
    Player->movement(rotation.getKey()/*, &spaceshipBoundingBox*/);

  //gameplay::Viewer->checkCollision();

  Header->Draw();
  scene::Draw();
}

void gameplay::setMainViewer(viewer* newViewer){
  this->Viewer = newViewer;
}

std::string gameplay::Class(){
  return "gameplay";
}
