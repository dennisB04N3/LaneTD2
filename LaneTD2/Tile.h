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
	inline void setColor(sf::Color _c) { shape.setFillColor(_c); }
	inline sf::RectangleShape& getShape() { return shape; }
	inline bool getTraversable() { return traversable; }
	inline void setTraversable(bool _t) { traversable = _t; }
};

