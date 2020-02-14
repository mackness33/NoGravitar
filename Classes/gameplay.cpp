#include "gameplay.hpp"

//CONSTRUCTORS
gameplay::gameplay(sf::RenderWindow* wnd, game* g) : scene(wnd), Game(g), galaxies(std::vector<galaxy*>()){
  Player = new spaceship(nullptr);
  Header = new header(Window);

  for(int i = 0; i < information::GALAXY_DEFAULT_QUANTITY; i++)
    galaxies.push_back(new galaxy(Window, Player, i, this));

  //set the actual viewer to the first galaxy
  activeGalaxy = galaxies.begin();
  this->Viewer = *activeGalaxy;

  Player->setPlayground(*activeGalaxy);
  Player->setTractorPosition();       //need to set the tractor position here, otherwise the tractor will be shift a bit to the right of the spaceship

  //get the game information from the header
  Points = Header->getPoints();
  FuelLabel = Header->getFuels();
}

gameplay::~gameplay(){
  if(!!Player)
    delete Player;

  utility::deleteVector(galaxies);

  if(!!Header)
    delete Header;

  Window = nullptr;
  Player = nullptr;
  Header = nullptr;
  FuelLabel = nullptr;
  Points = nullptr;
  *activeGalaxy = nullptr;
}

//---------------SETS---------------
void gameplay::setMainViewer(viewer* newViewer){ this->Viewer = newViewer; }

//---------------METHODS---------------
void gameplay::deathBunker(){ Points->deathBunker(); }
void gameplay::deathPlanet(){ Points->deathPlanet(); }
void gameplay::addFuel(int fuels){ FuelLabel->addFuel(fuels); }

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
  game::bestScore = Header->getBest();
  Game->restart();
}

void gameplay::next(){
  if(std::distance(activeGalaxy, galaxies.end()) > 1){
    this->Viewer = *(++activeGalaxy);
    this->Player->SetPosition(information::PLAYER_DEFAULT_POSITION);
    this->Player->setPlayground(*activeGalaxy);
  }
}

void gameplay::prev(){
  if(activeGalaxy != galaxies.begin()){
    this->Viewer = *(--activeGalaxy);
    this->Player->SetPosition(information::PLAYER_DEFAULT_POSITION);
    this->Player->setPlayground(*activeGalaxy);
  }
}

void gameplay::keyReleasedHandler(const sf::Event &e){
  switch (e.key.code) {
    case sf::Keyboard::Left : { }                                                             //LEFT
    case sf::Keyboard::Right : { Player->setRotation(false); };break;                         //RIGHT
    case sf::Keyboard::Up : { }                                                               //UP
    case sf::Keyboard::Down : { Player->setTranslation(false); };break;                       //DOWN
    case sf::Keyboard::Z : { information::TRACTORBEAM_IS_ACTIVE = false; };break;             //Z
    default: ;
  }
}

//arrows keys are not present because they are handle directly by the spaceship
void gameplay::keyPressedHandler(const sf::Event &e){
  switch (e.key.code) {
    case sf::Keyboard::Space : { Player->shoot(); };break;                                    //SPACE

    case sf::Keyboard::Z : { information::TRACTORBEAM_IS_ACTIVE = true; };break;              //Z

    default: ;
  }
}

//if every galaxy is conquer than return true else false
bool gameplay::Win (){
  for(auto glx = galaxies.begin(); glx != galaxies.end(); glx++)
    if(!(*glx)->isConquer())
      return false;

  return true;
}

void gameplay::Draw (){
  if(FuelLabel->getFuels() <= 1 || this->Win())             // check whether there's still fuel
    this->restart();
  else{
    Header->Draw();
    scene::Draw();
  }
}


std::string gameplay::Class(){
  return "gameplay";
}
