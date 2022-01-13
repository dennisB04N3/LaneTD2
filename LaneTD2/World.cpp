#include "World.h"

World::World(sf::Vector2f _mapPosition, int _gridSize, int _rows, int _columns) :
	mapPosition(_mapPosition), gridSize(_gridSize), rows(_rows), columns(_columns)
{
	//Grid
	initMaps();
}

World::~World()
{

}

void World::initMaps()
{
	float posX = mapPosition.x;
	float posY = mapPosition.y;

	for (int x = 0; x < columns; x++)
	{
		tileMap.insert(std::make_pair(x, std::map<int, Tile*>()));
		
		for (int y = 0; y < rows; y++)
		{
			tileMap[x].insert(std::make_pair(y, new Tile(posX + (x * gridSize),	posY + (y * gridSize), gridSize)));
		}
	}
}

void World::draw(sf::RenderTarget& target)
{
	for (int x = 0; x < columns; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			target.draw(tileMap[x][y]->getShape());
		}
	}

}