#pragma once
#include"SFML/Graphics.hpp"
#include"Tile.h"
#include<iostream>
#include<unordered_map>
class Node
{
	// what does it need?
	//X - position 
	//X - shape for visualisation
	//X  - cost-matrix for cost calculation (map or vector)?
	//  -->how to get the right value?
	//X  - neighboring Nodes for Pathfinder (map or vector)?
	//  -->how to "walk"?
	//  - g-, f- and h-cost
	//  -->how to evaluate?
private:
	//std::vector<std::tuple<Node*, int>> neighbours;
	std::unordered_map<Node*, int> neighbours;
	Node* parent;

	sf::CircleShape shape;
	sf::Vector2f position;
	Tile* tile;
	int cost;

public:

	Node(float posX, float posY);
	~Node() {};

	void click();
	void initNeighbours(std::map<int, std::map<int, Node*>>* nodeMap, const int rows, const int columns, const int posX, const int posY);

	inline sf::RectangleShape& getTileShape() { return tile->getShape(); }
	inline void setTile(Tile* _tile) { tile = _tile; }
	inline void setCost(int _cost) { cost = _cost; }
	inline int getCost() { return cost; }
	inline void setParent(Node* _parent) { parent = _parent; }
	inline Node* getParent() { return parent; }
	//inline std::vector<std::tuple<Node*, int>>& getNeighbours() { return neighbours; }
	inline std::unordered_map<Node*, int>& getNeighbours() { return neighbours; }

};

