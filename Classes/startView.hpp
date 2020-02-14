#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <vector>
#include "viewer.hpp"
#include "selectionLabel.hpp"
#include "bullet.hpp"

class startView : public viewer{
  protected:
    std::vector<selectionLabel*> selectors;
    selectionLabel *title;
    std::string *value;
    int selectedIndex;

  public:
    //---------------CONSTRUCTORS---------------
    startView(sf::RenderWindow *window);

    ~startView();

    //---------------GETS---------------
    std::string getValue();

    //---------------METHODS---------------
    virtual void Draw();
    void inizializeSelecters ();                                //it inizialize the selecters
    void selectNext ();                                         //select the next label
    void selectPrev ();                                         //select the previous label

    virtual std::string Class();
};

#endif
