#pragma once
#include"SFML/Graphics.hpp"
class Tile
{
private:
	sf::RectangleShape shape;

	bool traversable;

public:
	Tile(float posX, float posY, int size);

	//getter/setter
	inline sf::RectangleShape& getShape() { return shape; }
};

