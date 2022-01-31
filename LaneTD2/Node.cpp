#include "Node.h"

Node::Node(float posX, float posY) :
	parent(nullptr), tile(nullptr), cost(INT_MAX)
{
	neighbours = std::unordered_map<Node*, int>(0);
	position = sf::Vector2f(posX, posY);
	shape.setPosition(position);
	shape.setFillColor(sf::Color::Magenta);
	shape.setRadius(5);
}

void Node::click()
{
	tile->getShape().setFillColor(sf::Color::Black);
	for (auto& tuple : neighbours)
	{
		std::get<0>(tuple)->getTileShape().setFillColor(sf::Color::Yellow);
	}
}

void Node::initNeighbours(std::map<int, std::map<int, Node*>>* node_map, 
		const int rows, const int columns, const int posX, const int posY)
{
	//currently cost matrix is build and saved here
	int costArray[3][3] = {
		{14,10,14},
		{10,0 ,10},
		{14,10,14}
	};

	int x_costArray = 0;
	for (int x = posX - 1; x <= posX + 1; x++)
	{
		if (x >= 0 && x < columns)
		{
			int y_costArray = 0;
			for (int y = posY - 1; y <= posY + 1; y++)
			{
				if (y >= 0 && y < rows)
				{
					if (x == posX && y == posY)
					{
						y_costArray++;
						continue;
					}
					neighbours.insert(std::make_pair(
						node_map->at(x).at(y),
						costArray[x_costArray][y_costArray]
					));
				}
				y_costArray++;
			}
		}
		x_costArray++;
	}
}