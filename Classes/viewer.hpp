#ifndef VIEWER_H
#define VIEWER_H

#include <list>
#include "drawable.hpp"

class viewer : public drawable{
  protected:
    entity<sf::RectangleShape> *background;
    sf::RenderWindow *window;
    std::list<drawable*> allies;
    std::list<drawable*> enemies;

  public:
    //----------CONSTRUCTORS----------
    viewer(sf::RenderWindow *window, sf::Vector2f size = sf::Vector2f(-1, -1), sf::Vector2f position = sf::Vector2f(-1, -1), sf::Texture* image = nullptr);

    virtual ~viewer();

    //----------GETS----------
    entity<sf::RectangleShape>* getEntity();
    sf::RectangleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();

    //----------SETS----------
    void setBackground(sf::Texture* texture);

    //----------METHODS------------
    void Draw (sf::RenderWindow* window);
    virtual void Draw ();

    virtual void addAlly (drawable* ally);
    virtual void addEnemy (drawable* enemy);

    virtual void checkCollision ();
    std::string Class();
};

#endif // VIEWER_H
