#include <SFML/Graphics.hpp>
#include "Flower.h"

Flower::Flower(sf::RenderWindow* targetWindow) {
    window = targetWindow;
    scaleFactor = 1.f;
    isGrowing = true;
}

void Flower::draw()
{

    if (animationClock.getElapsedTime().asMilliseconds() > 10) {
        if (isGrowing) {
            scaleFactor += 0.01f;
            if (scaleFactor >= 2.f) isGrowing = false;
        }
        else {
            scaleFactor -= 0.01f;
            if (scaleFactor <= 1.f) isGrowing = true;
        }
        animationClock.restart();
    }

    float centerX = 640.f;
    float centerY = 360.f;

    sf::RectangleShape stem(sf::Vector2f(10.f, 180.f));
    stem.setFillColor(sf::Color::Green);
    stem.setPosition(sf::Vector2f(centerX, centerY + 150.f));
    stem.setOrigin(sf::Vector2f(5.f, 100.f));
    stem.setScale(sf::Vector2f(scaleFactor, scaleFactor));
    window->draw(stem);



    sf::CircleShape center(30.f);
    center.setFillColor(sf::Color(255, 215, 0));
    center.setPosition(sf::Vector2f(centerX, centerY));
    center.setOrigin(sf::Vector2f(30.f, 30.f));
    center.setScale(sf::Vector2f(scaleFactor, scaleFactor));


    sf::CircleShape petal(40.f);
    petal.setFillColor(sf::Color::Blue);
    petal.setOrigin(sf::Vector2f(40.f, 40.f));


    //top, bottom, left, right
    petal.setPosition(sf::Vector2f(centerX, centerY - 50.f));
    petal.setScale(sf::Vector2f(scaleFactor, scaleFactor));
    window->draw(petal);

    petal.setPosition(sf::Vector2f(centerX, centerY + 50.f));
    petal.setScale(sf::Vector2f(scaleFactor, scaleFactor));
    window->draw(petal);

    petal.setPosition(sf::Vector2f(centerX - 50.f, centerY));
    petal.setScale(sf::Vector2f(scaleFactor, scaleFactor));
    window->draw(petal);

    petal.setPosition(sf::Vector2f(centerX + 50.f, centerY));
    petal.setScale(sf::Vector2f(scaleFactor, scaleFactor));
    window->draw(petal);


    window->draw(center);
}



