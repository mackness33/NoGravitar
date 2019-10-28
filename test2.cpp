#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
//how to include an external class
#include "object_test.hpp"

//template class object_test<sf::CircleShape>;

int main(){
    sf::RenderWindow window(sf::VideoMode(900, 713), "My entity");

    std::cout << "window x: " << window.getSize().x << std::endl;
    std::cout << "window y: " << window.getSize().y << std::endl;
    //how to create an object
    sf::Texture spaceshipImage;
    spaceshipImage.loadFromFile("img/spaceship.png", sf::IntRect(0, 0, 0, 0));
    spaceshipImage.setSmooth(true);
    viewer *cs = new viewer(&window, &spaceshipImage);

    cs->getBackground()->SetPosition(cs->getBackground()->getBody()->getLocalBounds().width, cs->getBackground()->getBody()->getLocalBounds().height);
    std::cout << "width: " << cs->getBackground()->getBody()->getLocalBounds().width << std::endl;
    std::cout << "height: " << cs->getBackground()->getBody()->getLocalBounds().height << std::endl;

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        //how to draw the object
        cs->Draw();

        window.display();
    }

    return 0;
}
