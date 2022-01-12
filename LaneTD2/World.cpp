#include "World.h"

World::World(sf::Vector2f _mapPosition, int _gridSize, int _rows, int _columns) :
	mapPosition(_mapPosition), gridSize(_gridSize), rows(_rows), columns(_columns)
{

}

World::~World()
{

}

void World::initMaps()
{}

void World::draw(sf::RenderTarget& target)
{}