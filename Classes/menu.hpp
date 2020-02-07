#ifndef MENU_H
#define MENU_H

#include <vector>
#include "settings.hpp"
#include "scene.hpp"
#include "startView.hpp"
#include "../Handlers/eventHandler.hpp"

class menu : public scene{
  protected:
    startView *view;

  protected:
    void eventHandler(const sf::Event &event);
    void keyPressedHandler(const sf::Event &event);

  public:
    //----------CONSTRUCTORS----------
    menu(sf::RenderWindow* window);
    ~menu();

    //----------GETS----------
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //----------SETS----------
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //----------METHODS----------
    //friend void eventHandler::changePlaygroundHandler(); // Friend function
    virtual void start();
    virtual std::string Class();

};

#endif
