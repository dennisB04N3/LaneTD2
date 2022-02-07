#pragma once

#include"SFML/Graphics.hpp"
#include<iostream>

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
	inline void set_window_to_view() { window.setView(view); }
	inline void set_window_to_default() { window.setView(window.getDefaultView()); }
};