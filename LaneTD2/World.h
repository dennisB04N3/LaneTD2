#pragma once
#include"SFML/Graphics.hpp"
#include"Tile.h"
#include"Node.h"
#include"Grid.h"
#include"Pathfinder.h"

#include<unordered_map>

class World
{
private:
	//Tile and its Nodes as map of maps
	std::map<int, std::map<int, Node*>> nodeMap;
	std::map<int, std::map<int, Tile*>> tileMap;
	Pathfinder* pathfinder;

	Grid* grid;

	sf::Vector2f mapPosition;
	int gridSize;
	int rows;
	int columns;

	void initMaps();

	void buildNeighbourNodes();
	
public:

	World(sf::Vector2f mapPosition, int gridSize, int rows, int columns);
	~World();

	void click(const sf::Vector2u& MPGrid);

	void draw(sf::RenderTarget& target);
	inline void start_pathfinding() { pathfinder->start(); }
};

//TODO: 
// -build node_neighborhoods

