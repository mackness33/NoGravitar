#include <iostream>
#include <string>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
//#include "Classes/ground.hpp"
#include "Classes/text.hpp"
//#include "Classes/bullet.hpp"
//how to include an external class
//#include "object_test.hpp"

//template class object_test<sf::CircleShape>;

int main(){
    sf::RenderWindow window(sf::VideoMode(900, 713), "My entity");
    std::string *s = new std::string("string");

    sf::Font font;
    if(!font.loadFromFile("font/CafeBrewery.ttf"))
      std::cout << "Fuck, there's some problem up in this bitch!" << std::endl;

    text T (font, *s);
    T.SetCharacterSize(30);
    T.SetStyle(sf::Text::Bold);
    T.SetFillColor(sf::Color::Red);
    //T.SetOutlineColor(sf::Color::Yellow);
    //T.SetOutlineThickness(1);
    T.SetPosition(sf::Vector2f(200, 300));

    text *title = new plainText("AeroviasBrasil", "NOGRAVITAR", sf::Vector2f((s.x - title->GetLocalBounds().width)/2, 0));
    title->getText()->SetCharacterSize(30);
    title->getText()->SetStyle(sf::Text::Bold);
    title->getText()->SetFillColor(sf::Color::Green);

    std::cout << "body pos x: " << T.GetPosition().x << std::endl;
    std::cout << "body pos y: " << T.GetPosition().y << std::endl;
    std::cout << "body size width: " << T.getBody()->getLocalBounds().width << std::endl;
    std::cout << "body size height: " << T.getBody()->getLocalBounds().height << std::endl;
    std::cout << "bound pos x: " << T.getBound()->getPosition().x << std::endl;
    std::cout << "bound pos y: " << T.getBound()->getPosition().y << std::endl;
    std::cout << "bound size width: " << T.getBound()->getLocalBounds().width << std::endl;
    std::cout << "bound size height: " << T.getBound()->getLocalBounds().height << std::endl;
    //sf::RectangleShape *rect = new sf::RectangleShape(sf::Vector2f(100, 100));
    //rect->setPosition();
    //how to create an object
    //sf::Texture spaceshipImage;
    //spaceshipImage.loadFromFile("img/spaceship.png", sf::IntRect(0, 0, 0, 0));
    //spaceshipImage.setSmooth(true);
    //viewer *cs = new viewer(&window, &spaceshipImage);
    //T.SetB();
    //cs->getBackground()->SetPosition(cs->getBackground()->getBody()->getLocalBounds().width, cs->getBackground()->getBody()->getLocalBounds().height);
    //std::cout << "width: " << cs->getBackground()->getBody()->getLocalBounds().width << std::endl;
    //std::cout << "height: " << cs->getBackground()->getBody()->getLocalBounds().height << std::endl;
    int i = 0;
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
          if (event.type == sf::Event::Closed)
              window.close();

        }

        window.clear();

        //how to draw the object
        T.DrawTest(&window);
        //B->Draw(&window);
        //window.draw(*rect);

        //std::cout << "Intersection? " << G->intersects(B) << std::endl;
        window.display();

        if(i > 60){
          T.SetFillColor(sf::Color::Green);
          if(i > 120){
            T.SetFillColor(sf::Color::Red);
            i = 0;
          }
        }

        i++;
        //std::cout << "i: " << i << std::endl;
    }
    return 0;
}
