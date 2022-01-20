#pragma once
#include"SFML/Graphics.hpp"
#include"Tile.h"
#include"Node.h"
#include"Grid.h"

#include<map>

class World
{
private:
	//Tile and its Nodes as map of maps
	std::map<int, std::map<int, Node*>> nodeMap;
	std::map<int, std::map<int, Tile*>> tileMap;

	Grid* grid;

	sf::Vector2f mapPosition;
	int gridSize;
	int rows;
	int columns;

	void initMaps();
	/*method to initialize the neighbours of every node in nodeMap
	method directs to method in nodes, which than builds up its neighbours
	with the given data.
	nodeMap - nodemap to get the right neighbors
	rows, columns, posX, posY - variables for boundary calculation with the actual coordintes of calling node*/
	void buildNeighbourNodes();
	
public:

	World(sf::Vector2f mapPosition, int gridSize, int rows, int columns);
	~World();

	void click(const sf::Vector2u& MPGrid);

	void draw(sf::RenderTarget& target);
};

//TODO: 
// -build node_neighborhoods

