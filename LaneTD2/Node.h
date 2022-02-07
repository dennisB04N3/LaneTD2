#pragma once
#include"SFML/Graphics.hpp"
#include"Tile.h"
#include<iostream>
#include<unordered_map>
class Node
{
private:
	std::unordered_map<Node*, int> neighbours;
	Node* parent;

	sf::Vector2f position;
	Tile* tile;
	int cost;

public:

	Node(float posX, float posY);
	~Node() {};

	void click();
	void initNeighbours(std::map<int, std::map<int, Node*>>* node_map, const int rows, const int columns, const int posX, const int posY);
	void changeState(char state);

	//getters/setters
	inline sf::RectangleShape& getTileShape() { return tile->getShape(); }
	inline void setTile(Tile* _tile) { tile = _tile; }
	inline void setCost(int _cost) { cost = _cost; }
	inline int getCost() { return cost; }
	inline void setParent(Node* _parent) { parent = _parent; }
	inline Node* getParent() { return parent; }
	inline std::unordered_map<Node*, int>& getNeighbours() { return neighbours; }
	inline bool isTraversable() { return tile->getTraversable(); }

};

