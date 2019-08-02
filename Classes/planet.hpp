
class planet : public sf::Vertex{

  public:
    //CONSTRUCTORS
    planet(sf::Vertex* s) : sf::Vertex(*s){

    }

    planet(sf::Vertex* s) : sf::Vertex(*s){

    }

    //METHODS

    void build (){
      sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
      sf::RenderWindow Window(sf::VideoMode(desktop.height, desktop.width, desktop.bitsPerPixel), "NoGravitar");

      sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(0.f, ((desktop.height)/2.f))),
        sf::Vertex(sf::Vector2f((desktop.width)/1.f, (desktop.height)/2.f))
      }
    }
};
