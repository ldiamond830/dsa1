// PE5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    //creates the window to draw in
    RenderWindow window(sf::VideoMode(800, 600), "My window");
    
    //creates a circle
    CircleShape circle(100);
    circle.setFillColor(Color(100, 250, 50));

    //creates an octagon
    CircleShape octagon(50, 8);
    octagon.setFillColor(Color(100, 0, 5));
    octagon.setPosition(500, 100);

    //creates a rectangle
    RectangleShape rectangle(Vector2f(200, 100));
    rectangle.setPosition(100, 500);
    rectangle.setFillColor(Color(0, 255, 255));

    //taken from https://www.sfml-dev.org/tutorials/2.4/graphics-draw.php
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(circle);
        window.draw(octagon);
        window.draw(rectangle);

        // end the current frame
        window.display();
    }


    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
