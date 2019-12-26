#include <iostream>
#include <string>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Classes/ground.hpp"
#include "Classes/bullet.hpp"
//how to include an external class
//#include "object_test.hpp"

//template class object_test<sf::CircleShape>;

int main(){
    sf::RenderWindow window(sf::VideoMode(900, 713), "My entity");
    ground *G = new ground(window.getSize().x, window.getSize().y);
    bullet *B = new bullet(0, 0, sf::Vector2f(500, 500));
    //sf::RectangleShape *rect = new sf::RectangleShape(sf::Vector2f(100, 100));
    //rect->setPosition();
    //how to create an object
    //sf::Texture spaceshipImage;
    //spaceshipImage.loadFromFile("img/spaceship.png", sf::IntRect(0, 0, 0, 0));
    //spaceshipImage.setSmooth(true);
    //viewer *cs = new viewer(&window, &spaceshipImage);

    //cs->getBackground()->SetPosition(cs->getBackground()->getBody()->getLocalBounds().width, cs->getBackground()->getBody()->getLocalBounds().height);
    //std::cout << "width: " << cs->getBackground()->getBody()->getLocalBounds().width << std::endl;
    //std::cout << "height: " << cs->getBackground()->getBody()->getLocalBounds().height << std::endl;

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        //how to draw the object
        G->Draw(&window);
        B->Draw(&window);
        //window.draw(*rect);

        std::cout << "Intersection? " << G->intersects(B) << std::endl;

        window.display();
    }
    return 0;
}
