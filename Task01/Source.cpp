#include <SFML/Graphics.hpp>
#include <iostream>
#include "Flower.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "SFML works!");

    Flower flower(&window);

    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        flower.draw();
        window.display();
    }
}