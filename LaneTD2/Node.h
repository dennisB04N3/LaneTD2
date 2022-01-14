#pragma once
#include"SFML/Graphics.hpp"
class Node
{
	// what does it need?
	// - position
	// - shape for visualisation
	// - cost-matrix for cost calculation (map or vector)?
	// -->how to get the right value?
	// - neighboring Nodes for Pathfinder (map or vector)?
	// -->how to "walk"?
	// - g-, f- and h-cost
	// -->how to evaluate?
private:
	sf::CircleShape shape;
	sf::Vector2f position;

public:

	Node(float posX, float posY);
	~Node() {};

	sf::CircleShape& getShape() { return shape; }

};

