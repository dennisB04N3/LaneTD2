#include "World.h"

World::World(sf::Vector2f _mapPosition, int _gridSize, int _rows, int _columns) :
	mapPosition(_mapPosition), gridSize(_gridSize), rows(_rows), columns(_columns)
{
	grid = new Grid(gridSize, rows, columns, mapPosition);
	initMaps();
	buildNeighbourNodes();

	/*std::unordered_map<Node*, int> node_hashMap;
	for (int x = 0; x < columns; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			node_hashMap.insert(std::make_pair(nodeMap.at(x).at(y), INT_MAX));
		}
	}*/
	pathfinder = new Pathfinder(nodeMap.at(1).at(1), nodeMap.at(columns-2).at(rows-2)/*, node_hashMap*/);

}

World::~World()
{

}

void World::click(const sf::Vector2u& MPGrid)
{
	unsigned CoordinateX = MPGrid.x;
	unsigned CoordinateY = MPGrid.y;

	nodeMap.at(CoordinateX).at(CoordinateY)->click();
}

void World::initMaps()
{
	float posX = mapPosition.x;
	float posY = mapPosition.y;
	float halfGrid = static_cast<float>(gridSize / 2);

	for (int x = 0; x < columns; x++)
	{
		tileMap.insert(std::make_pair(x, std::map<int, Tile*>()));
		nodeMap.insert(std::make_pair(x, std::map<int, Node*>()));
		for (int y = 0; y < rows; y++)
		{
			tileMap[x].insert(std::make_pair(y, new Tile(posX + (x * gridSize),	posY + (y * gridSize), gridSize)));
			nodeMap[x].insert(std::make_pair(y, new Node(posX + (x * gridSize) + halfGrid, posY + (y * gridSize) + halfGrid)));
			nodeMap[x][y]->setTile(tileMap[x][y]);
		}
	}
}

void World::buildNeighbourNodes()
{


	for (int x = 0; x < columns; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			nodeMap.at(x).at(y)->initNeighbours(&nodeMap, rows, columns, x, y);
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
	grid->draw(target);
}