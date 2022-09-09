//#include<iostream>
//#include <SFML/Window.hpp>
//#include<SFML/Graphics.hpp>
//#include<SFML/System.hpp>
//
//using namespace sf;
//
//int main()
//{
//    RenderWindow window(VideoMode(800, 600), "Moving Circle", Style::Default);
//    window.setFramerateLimit(60);
//
//    CircleShape circle(50.f);
//    circle.setFillColor(Color::White);
//
//    while (window.isOpen())
//    {
//
//        Event event;
//        while (window.pollEvent(event))
//        {
//
//            if (event.type == Event::Closed)
//                window.close();
//        }
//
//
//        circle.move(3.f, 0.f);
//
//        //draw
//        window.clear(Color::Green);
//        //draw something
//        window.draw(circle);
//
//        window.display();
//
//    }
//    return 0;
//}
