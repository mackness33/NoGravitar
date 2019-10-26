#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
//how to include an external class
#include "object_test.hpp"

int main(){
    sf::RenderWindow window(sf::VideoMode(900, 800), "My object");
    sf::View view;

    // Load an image file from a file
    //sf::Image background;
    //if (!background.loadFromFile("universe.png"))
        //return -1;
    // Create a 20x20 image filled with black color
    //sf::Image image;
    //image.create(20, 20, sf::Color::Black);


    //how to create an object
    sf::CircleShape circle;
    circle.setRadius(100);
    circle.setOutlineColor(sf::Color::Red);
    circle.setOutlineThickness(5);
    //circle.setPosition(100, 200);

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(100, 50));
    rectangle.setOutlineColor(sf::Color::Green);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(10, 20);

    // Declare and load a texture
    sf::Texture texture;
    texture.loadFromFile("img/universe.png", sf::IntRect(0,0,900,800));

    std::cout << "Texture width: " << texture.getSize().x << std::endl;
    std::cout << "Texture height: " << texture.getSize().y << std::endl;

    // Create a sprite
    sf::Sprite sprite;
    sprite.setTexture(texture);
    //sprite.setTextureRect(sf::IntRect(300, 300, 500, 300));
    sprite.setColor(sf::Color(255, 255, 0, 200));
    sprite.setPosition(100, 25);
    // Draw it

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Initialize the view to a rectangle located at (100, 100) and with a size of 400x200
        // Rotate it by 45 degrees
        //view.rotate(45);
        // Set its target viewport to be half of the window
        //view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
        sf::FloatRect viewBounding(-10, -10, 500, 500);
        view.reset(viewBounding);
        sf::RectangleShape viewBoundingBox(sf::Vector2f(viewBounding.width, viewBounding.height));
        window.draw(viewBoundingBox);
        // Apply it
        window.setView(view);
        // Render stuff
        window.draw(circle);
        // Set the default view back
        window.setView(window.getDefaultView());
        // Render stuff not affected by the view
        window.draw(rectangle);
        window.draw(circle);

        window.draw(sprite);

        window.display();
    }

    return 0;
}
