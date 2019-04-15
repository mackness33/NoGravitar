#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 800), "la mia astronave!");
    sf::ConvexShape convex;

    //creo quattro punti per la spezzata chiusa dell'astronave
    convex.setPointCount(4);

    convex.setPoint(2, sf::Vector2f(30.f, 0.f));
    convex.setPoint(1, sf::Vector2f(0.f, 40.f));
    convex.setPoint(3, sf::Vector2f(60.f, 40.f));
    convex.setPoint(0, sf::Vector2f(30.f, 20.f));

    //creo il contorno della navicella colorata
    convex.setOutlineThickness(2.f);
    convex.setOutlineColor(sf::Color(000, 255, 000));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(convex);
        window.display();
    }

    return 0;
}
