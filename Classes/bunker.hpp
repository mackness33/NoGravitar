#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class bunker{
  //if there are properties you must set and get them!!!
  private:
    sf::ConvexShape body;

  public:
    //CONSTRUCTORS
    bunker();

    void Disegna(sf::RenderWindow* window);
    void build ();
};
