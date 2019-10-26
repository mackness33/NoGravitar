#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
//how to include an external class
#include "object_test.hpp"

//template class object_test<sf::CircleShape>;

int main(){
    sf::RenderWindow window(sf::VideoMode(900, 800), "My entity");

    //how to create an object
    object_test<sf::CircleShape> *cs = new object_test<sf::CircleShape>(&window);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        //how to draw the object
        cs->Draw(&window);

        window.display();
    }

    return 0;
}
