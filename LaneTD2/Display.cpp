#include "Display.h"

Display::Display()
{
	this->init();
	viewSpeed = 2000.f;
}


void Display::init()
{
	//for later: configuration file?(menu point: options) ->google
	window.create(sf::VideoMode(1920, 1080), "Lane TD");
	view.setSize(1920.f, 1080.f);
	view.setCenter(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
	window.setView(view);
}

void Display::moveView(char key, float deltaTime)
{
	switch (key)
	{
	case 'W':
		this->view.move(0.f, -viewSpeed * deltaTime);
		break;
	case 'S':
		this->view.move(0.f, viewSpeed * deltaTime);
		break;
	default:
		break;
	}
}