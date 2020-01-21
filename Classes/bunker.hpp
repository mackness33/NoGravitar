#ifndef BUNKER_H
#define BUNKER_H

#include "bullet.hpp"
#include "line.hpp"
#include "playground.hpp"

class bunker : public drawable{
  private:
    entity<sf::RectangleShape>* body;
    std::list <bullet*> bullets;
    //playground *Playground;
    sf::Texture* image;

  public:
    //----------CONSTRUCTORS----------
    bunker(/*playground* Playground, sf::Texture* image, */line Line);

    ~bunker();

    //----------GETS----------
    entity<sf::RectangleShape>* getEntity();
    sf::RectangleShape* getDrawable();
    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();

    //----------SETS----------

    //----------METHODS----------
    void Draw (sf::RenderWindow* window);

    void build();

    void shoot();
    void deleteBullet(bullet* b);

    virtual std::string Class();
};

#endif
