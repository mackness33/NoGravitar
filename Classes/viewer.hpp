#ifndef VIEWER_H
#define VIEWER_H

#include "drawable.hpp"
#include "information.hpp"

class viewer : public drawable{
  protected:
    entity<sf::RectangleShape> *background;
    sf::RenderWindow *window;

  public:
    //----------CONSTRUCTORS----------
    viewer(sf::RenderWindow *window, sf::Vector2f size = information::MENU_DEFAULT_SIZE, sf::Vector2f position = information::MENU_DEFAULT_POSITION, sf::Texture* image = nullptr);
    viewer();

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

    virtual std::string Class();
};

#endif // VIEWER_H
