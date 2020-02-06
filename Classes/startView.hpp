#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <list>
#include "viewer.hpp"
#include "selectionLabel.hpp"
#include "bullet.hpp"

class startView : public viewer{
  protected:
    std::list<selectionLabel*> selectors;

  protected:
    void DrawList (std::list<drawable*> objects);

  public:
    //---------------CONSTRUCTORS---------------
    startView(sf::RenderWindow *window/*, sf::Texture* image = nullptr*/);

    ~startView();

    //---------------GETS---------------
    //virtual void getObjectsBounds (std::list<drawable*> objects, std::list<sf::FloatRect>* objectsBounds);

    //---------------METHODS---------------
    virtual void Draw();
    void inizializeSelecters ();

    virtual std::string Class();
};

#endif
