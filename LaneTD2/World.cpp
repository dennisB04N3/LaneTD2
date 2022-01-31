#include "World.h"

World::World(sf::Vector2f _mapPosition, int _gridSize, int _rows, int _columns) :
	mapPosition(_mapPosition), gridSize(_gridSize), rows(_rows), columns(_columns)
{
	grid = new Grid(gridSize, rows, columns, mapPosition);
	init_Maps();
	build_neighbour_nodes();
	pathfinder = new Pathfinder(node_map.at(1).at(1), node_map.at(columns-2).at(rows-2)/*, node_hashMap*/);

}

//TODO: delete pointers
World::~World()
{}

void World::click(const sf::Vector2u& MPGrid)
{
	unsigned CoordinateX = MPGrid.x;
	unsigned CoordinateY = MPGrid.y;
	node_map.at(CoordinateX).at(CoordinateY)->click();
}

void World::init_Maps()
{
	float posX = mapPosition.x;
	float posY = mapPosition.y;
	float halfGrid = static_cast<float>(gridSize / 2);

	for (int x = 0; x < columns; x++)
	{
		tile_map.insert(std::make_pair(x, std::map<int, Tile*>()));
		node_map.insert(std::make_pair(x, std::map<int, Node*>()));
		for (int y = 0; y < rows; y++)
		{
			tile_map[x].insert(std::make_pair(y, new Tile(posX + (x * gridSize),	posY + (y * gridSize), gridSize)));
			node_map[x].insert(std::make_pair(y, new Node(posX + (x * gridSize) + halfGrid, posY + (y * gridSize) + halfGrid)));
			node_map[x][y]->setTile(tile_map[x][y]);
		}
	}
}

void World::build_neighbour_nodes()
{
	for (int x = 0; x < columns; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			node_map.at(x).at(y)->initNeighbours(&node_map, rows, columns, x, y);
		}
	}
}

void World::draw(sf::RenderTarget& target)
{
	for (int x = 0; x < columns; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			target.draw(tile_map[x][y]->getShape());
		}
	}
	grid->draw(target);
}