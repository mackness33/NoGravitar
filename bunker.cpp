#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 800), "bunker");
    sf::ConvexShape convex;

    //creo quattro punti per la spezzata chiusa dell'astronave
    convex.setPointCount(6);

    convex.setPoint(0, sf::Vector2f(30.f, 0.f));
    convex.setPoint(1, sf::Vector2f(40.f, 0.f));
    convex.setPoint(2, sf::Vector2f(40.f, 10.f));
    convex.setPoint(3, sf::Vector2f(60.f, 30.f));
    convex.setPoint(4, sf::Vector2f(10.f, 30.f));
    convex.setPoint(5, sf::Vector2f(30.f, 10.f));

    convex.setFillColor(sf::Color(000, 032, 128));
    //creo il contorno della navicella colorata
    convex.setOutlineThickness(2.f);
    convex.setOutlineColor(sf::Color(000, 224, 224));

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
