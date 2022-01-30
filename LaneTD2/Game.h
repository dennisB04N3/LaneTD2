#pragma once

#include"Display.h"
#include"World.h"

#include"SFML/Graphics.hpp"

#include<iostream>

class Game
{
private:

	int WINDOW_WIDTH, WINDOW_HEIGHT;

	Display* display;
	World* world;
	sf::Clock clock;
	sf::RenderWindow* window;

	//Mouse position
	sf::Vector2i MPWindow;
	sf::Vector2f MPView;
	sf::Vector2u MPGrid;


	//structure data for world
	sf::Vector2f mapPosition;
	int gridSize;
	int rows;
	int columns;

	void update();
	void updateMP();

	//following just for testing, must later be erased
	//Text for Mouse position
	sf::Font font;
	sf::Text text_MP;
	bool pathfinder_ran;

public:
	Game();
	~Game();

	void start();
};

