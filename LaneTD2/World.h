#pragma once
#include"SFML/Graphics.hpp"
#include"Tile.h"
#include"Node.h"
#include"Grid.h"
#include"Pathfinder.h"
#include<map>

class World
{
private:
	std::map<int, std::map<int, Node*>> node_map;
	std::map<int, std::map<int, Tile*>> tile_map;
	Pathfinder* pathfinder;

	Grid* grid;
	sf::Vector2f mapPosition;
	int gridSize;
	int rows;
	int columns;

	void init_Maps();
	void build_neighbour_nodes();
	
public:
	World(sf::Vector2f mapPosition, int gridSize, int rows, int columns);
	~World();

	void click(const sf::Vector2u& MPGrid);
	void draw(sf::RenderTarget& target);
	void place_startNode(sf::Vector2u coordinates);
	void place_endNode(sf::Vector2u coordinates);
	void place_wall(sf::Vector2u coordinates);

	inline void start_pathfinder() { pathfinder->start(); }
	void reset_pathfinder();
};

