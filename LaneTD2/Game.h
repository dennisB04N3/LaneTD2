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

	//different buttons or booleans for event-handling such as:
	//	-when does the click mean the start or end node have to be placed
	//	-when to start the pathfinder
	bool place_startNode_onClick;
	bool place_endNode_onClick;
	sf::RectangleShape button_resetNodes;
	bool button_pressed;

	//following just for testing, must later be erased
	//Text for Mouse position
	sf::Font font;
	sf::Text text_MP;

public:
	Game();
	~Game();

	void start();
};

