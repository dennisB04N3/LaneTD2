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
	sf::RectangleShape map_borders;
	sf::Vector2f mapPosition;
	int gridSize;
	int rows;
	int columns;

	//different buttons or booleans for event-handling
	bool place_startNode_onClick;
	bool place_endNode_onClick;
	bool button_pressed;
	sf::RectangleShape button_resetNodes;
	sf::RectangleShape tile_selector;
	bool left_mouse_button_pressed;
	bool right_mouse_button_pressed;

	//following just for testing, must later be erased
	//Text for Mouse position
	sf::Font font;
	sf::Text text_MP;

	void update();
	void pre_event_update();

public:
	Game();
	~Game();

	void start();
};

