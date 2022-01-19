#pragma once
#include"SFML/Graphics.hpp"
#include"Tile.h"
#include<iostream>
class Node
{
	// what does it need?
	//X - position 
	//X - shape for visualisation
	//  - cost-matrix for cost calculation (map or vector)?
	//  -->how to get the right value?
	//  - neighboring Nodes for Pathfinder (map or vector)?
	//  -->how to "walk"?
	//  - g-, f- and h-cost
	//  -->how to evaluate?
private:
	std::vector<std::tuple<Node*, int>> neighbours;

	sf::CircleShape shape;
	sf::Vector2f position;
	Tile* tile;

public:

	Node(float posX, float posY);
	~Node() {};

	void click();
	void initNeighbours(std::map<int, std::map<int, Node*>>* nodeMap, const int rows, const int columns, const int posX, const int posY);

	sf::CircleShape& getShape() { return shape; }
	sf::RectangleShape& getTileShape() { return tile->getShape(); }
	void setTile(Tile* _tile) { tile = _tile; }

};

