#include "gameplay.hpp"

//CONSTRUCTORS
gameplay::gameplay(sf::RenderWindow* wnd, game* g) : scene(wnd), Game(g) {
  Player = new spaceship(nullptr);
  Header = new header(Window);
  std::cout << "Brust" << std::endl;
  //Playground = new playground(Window);
  //Settings = new information(Window);
  galaxies = {};
  for(int i = 0; i < information::GALAXY_DEFAULT_QUANTITY; i++)
    galaxies.push_back(new galaxy(Window, Player, 20, this));

  activeGalaxy = galaxies.begin();
  // Galaxy = new galaxy(Window, Player, 20, this);
  //StartView = new startView(Window);
  this->Viewer = *activeGalaxy;

  Player->setPlayground(*activeGalaxy);
  Player->setTractorPosition();

  Points = Header->getPoints();
  FuelLabel = Header->getFuels();
}

gameplay::~gameplay(){
  std::cout << "DELETING GAMEPLAY" << std::endl;

  if(!!Player)
    delete Player;

  utility::deleteVector(galaxies);

  //if(!!actualGalaxy)
    //delete Galaxy;

  if(!!Header)
    delete Header;

  //if(!!Settings)
    //delete Settings;

  //if(!!Viewer)
    //delete Viewer;

  Window = nullptr;
  Player = nullptr;
  Header = nullptr;
  *activeGalaxy = nullptr;
  // Viewer = nullptr;
  // Settings = nullptr;

}


//GETS
//sf::Texture getTexture(){ return this->background.getTexture();}
//sf::Sprite getBackground(){ return this->background;}

//SETS
//void setTexture(sf::Texture t){ this->background.setTexture(t);}
//void setBackground(sf::Sprite b){ this->bacckground = b;}


//---------------METHODS---------------

void gameplay::eventHandler(const sf::Event &event){
  switch (event.type) {
    //KEYRELEASED
    case sf::Event::KeyReleased :{
      this->keyReleasedHandler(event);
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

void gameplay::next(){
  std::cout << "Boh vediamo! " << std::distance(activeGalaxy, galaxies.end()) << std::endl;
  if(std::distance(activeGalaxy, galaxies.end()) > 1){
    this->Viewer = *(++activeGalaxy);
    this->Player->SetPosition(information::PLAYER_DEFAULT_POSITION);
    this->Player->setPlayground(*activeGalaxy);
  }
  // std::cout << "Hola: " << std::distance(galaxies.begin(), activeGalaxy) << std::endl;
}

void gameplay::prev(){
  std::cout << " Holy! " << std::endl;
  if(activeGalaxy != galaxies.begin()){
    this->Viewer = *(--activeGalaxy);
    this->Player->SetPosition(information::PLAYER_DEFAULT_POSITION);
    this->Player->setPlayground(*activeGalaxy);
  }
}

void gameplay::deathBunker(){ Points->deathBunker(); }      //can be optimazed with friend keyword on points for Galaxy
void gameplay::deathPlanet(){ Points->deathPlanet(); }      //can be optimazed with friend keyword on points for PlanetView
void gameplay::addFuel(){ FuelLabel->addFuel(); }      //can be optimazed with friend keyword on points for PlanetView

void gameplay::keyReleasedHandler(const sf::Event &e){
  switch (e.key.code) {
    case sf::Keyboard::Left : { }                                      //LEFT
    case sf::Keyboard::Right : { Player->setRotation(false); };break;            //RIGHT
    case sf::Keyboard::Up : { }                                        //UP
    case sf::Keyboard::Down : { Player->setTranslation(false); };break;            //DOWN
    case sf::Keyboard::Z : { information::TRACTORBEAM_IS_ACTIVE = false; };break;            //DOWN
    default: break;
  }
}

void gameplay::keyPressedHandler(const sf::Event &e){
  std::cout << "the key pressed is: " << e.key.code << std::endl;
  switch (e.key.code) {
    case sf::Keyboard::Space : {
      Player->shoot();
    };break;

    case sf::Keyboard::Z : {
      information::TRACTORBEAM_IS_ACTIVE = true;
    };break;

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

// void gameplay::Win (){
//   if(FuelLabel->getFuels() <= 50)
//     this->restart();
//   else{
//     Header->Draw();
//     scene::Draw();
//   }
// }

//DRAW
void gameplay::Draw (){
  if(FuelLabel->getFuels() <= 50)
    this->restart();
  else{
    Header->Draw();
    scene::Draw();
  }
}

void gameplay::setMainViewer(viewer* newViewer){
  this->Viewer = newViewer;
}

std::string gameplay::Class(){
  return "gameplay";
}
