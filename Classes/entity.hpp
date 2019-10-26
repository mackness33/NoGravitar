//SPACESHIP
//Class that handle everything that concerne a spaceship

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <list>

/*
  BUG: change body into sprites
*/
#define PI 3.14159265

template <class T> class entity{
  private:
    //void draw(sf::RenderTarget& target, sf::RenderStates states = RenderStates::Default) const;

  protected:
    sf::RenderWindow* window;
    sf::FloatRect *boundBox;
    sf::RectangleShape bound;       //FOR TESTING ONLY
    T *body;

  public:
    //TODO: add all the constructors of sf::Shape sf::Sprite .. etc
    //----------CONSTRUCTORS----------
    entity(sf::RenderWindow* w, T* b);

    entity(sf::RenderWindow* w);

    //----------GETS----------
    T* getBody();
    //*sf::FloatRect getBoundBox();
    //*sf::RectangleShape getBound();

    //----------SETS----------
    void setBody(T *b);
    //TODO: void setBody(T b);

    void 	SetPosition (float x, float y);
    void 	SetPosition (const sf::Vector2f &position);

    void 	SetRotation (float angle);

    void 	SetScale (float factorX, float factorY);
    void 	SetScale (const sf::Vector2f &factors);

    void 	SetOrigin (float x, float y);
    void 	SetOrigin (const sf::Vector2f &origin);

    //----------METHODS------------
    void Draw ();
    void DrawTest ();

    void 	Move (float offsetX, float offsetY);
    void 	Move (const sf::Vector2f &offset);

    void 	Rotate (float angle);

    void 	Scale (float factorX, float factorY);
    void 	Scale (const sf::Vector2f &factor);

};
