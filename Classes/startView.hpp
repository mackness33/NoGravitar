#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <vector>
#include "viewer.hpp"
#include "selectionLabel.hpp"
#include "bullet.hpp"

class startView : public viewer{
  protected:
    std::vector<selectionLabel*> selectors;
    int selectedIndex;
    std::string *value;

  protected:
    void DrawList (std::list<drawable*> objects);

  public:
    //---------------CONSTRUCTORS---------------
    startView(sf::RenderWindow *window/*, sf::Texture* image = nullptr*/);

    ~startView();

    //---------------GETS---------------
    //virtual void getObjectsBounds (std::list<drawable*> objects, std::list<sf::FloatRect>* objectsBounds);
    std::string getValue();

    //---------------METHODS---------------
    virtual void Draw();
    void inizializeSelecters ();
    void selectNext ();
    void selectPrev ();

    virtual std::string Class();
};

#endif
