#pragma once
#include <SFML/Graphics.hpp>

class Flower {
public:
	Flower(sf::RenderWindow* targetWindow);
	void draw();

private:
	//������� �� sfml ����
	sf::RenderWindow* window;

	sf::Clock animationClock;
	float scaleFactor;
	bool isGrowing;
};