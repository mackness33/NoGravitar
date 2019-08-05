#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
//how to include an external class
#include "Classes/object_test.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 800), "My object");

    //how to create an object
    object Obj = new object();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        //how to draw the object
        window.draw(Obj);

        window.display();
    }

    return 0;
}
