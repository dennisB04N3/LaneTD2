#include "Node.h"

Node::Node(float posX, float posY)
{
	neighbours = std::vector<std::tuple<Node*, int>>(0);
	tile = nullptr;
	position = sf::Vector2f(posX, posY);
	shape.setPosition(position);
	shape.setFillColor(sf::Color::Magenta);
	shape.setRadius(5);
}

void Node::click()
{
	std::cout << "Neighbours from " << this << ":" << std::endl;
	tile->getShape().setFillColor(sf::Color::Black);
	for (auto& tuple : neighbours)
	{
		std::cout << std::get<0>(tuple) << " " << std::get<1>(tuple) << std::endl;
		std::get<0>(tuple)->getTileShape().setFillColor(sf::Color::Yellow);
	}
	std::cout << std::endl;
}

void Node::initNeighbours(std::map<int, std::map<int, Node*>>* nodeMap, 
		const int rows, const int columns, const int posX, const int posY)
{
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
					neighbours.push_back(std::make_tuple(
						nodeMap->at(x).at(y),//node,
						costArray[x_costArray][y_costArray]//cost
					));
				}
				y_costArray++;
			}
		}
		x_costArray++;
	}
}
