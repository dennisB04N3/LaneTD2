#pragma once
#include"SFML/Graphics.hpp"

#include<map>

class World
{
private:
	//Tile and its Nodes as map of maps
	//std::map<int, std::map<int, Node*>> nodeMap;
	//std::map<int, std::map<int, Tile*>> tileMap;

	sf::Vector2f mapPosition;
	int gridSize;
	int rows;
	int columns;

	void initMaps();

public:

	World(sf::Vector2f mapPosition, int gridSize, int rows, int columns);
	~World();

	void draw(sf::RenderTarget& target);
};

//TODO: 
// -constructor
// -init maps
// -build node_neighborhoods
// -draw function
// -Grid (class)

