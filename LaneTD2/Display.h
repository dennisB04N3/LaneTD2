#pragma once

#include"SFML/Graphics.hpp"

class Display
{
private:

	sf::RenderWindow window;
	sf::View view;

	float viewSpeed;

public:

	Display();

	void init();
	void moveView(char key, float deltaTime);

	inline sf::RenderWindow* getWindow() { return &this->window; }

};