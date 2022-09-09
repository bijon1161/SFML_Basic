#include<iostream>
#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "My window", Style::Default);
    window.setFramerateLimit(60);

    CircleShape circle(50.f);
    // circle.setFillColor(Color::Red);

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
                window.close();
        }


        circle.move(0.3f, 0.f);

        //draw
        window.clear(Color::Red);
        //draw something
        window.draw(circle);

        window.display();

    }
    return 0;
}
