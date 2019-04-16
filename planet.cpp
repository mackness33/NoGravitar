#include <SFML/Graphics.hpp>
int main()
{

  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  sf::RenderWindow Window(sf::VideoMode(desktop.height, desktop.width, desktop.bitsPerPixel), "NoGravitar");




// disegno la linea del pianeta con la dimensione dello schermo
//si trova esattamente a metà della window per ora
    sf::Vertex line[] =
{
    sf::Vertex(sf::Vector2f(0.f, ((desktop.height)/2.f))),
    sf::Vertex(sf::Vector2f((desktop.width)/1.f, (desktop.height)/2.f))
};



    while (Window.isOpen())
    {
        sf::Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window.close();
        }

        Window.clear();
        Window.draw(line, 2, sf::Lines);
        Window.display();
    }

    return 0;
}
