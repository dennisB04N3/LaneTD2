#include "Tile.h"

Tile::Tile(float posX, float posY, int size)
{
	shape.setPosition(posX, posY);
	shape.setSize(sf::Vector2f(size, size));
	shape.setFillColor(sf::Color::White);
	traversable = true;
}
