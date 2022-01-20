#pragma once
#include"SFML/Graphics.hpp"
class Tile
{
private:

	sf::RectangleShape shape;

	bool occupied;

public:
	Tile(float posX, float posY, int size);

	sf::RectangleShape& getShape() { return shape; }
};

