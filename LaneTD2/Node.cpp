#include "Node.h"

Node::Node(float posX, float posY) :
	parent(nullptr), tile(nullptr), cost(INT_MAX)
{
	//neighbours = std::vector<std::tuple<Node*, int>>(0);
	neighbours = std::unordered_map<Node*, int>(0);
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
	//currently cost matrix is build and saved here

	int costArray[3][3] = {
		{14,10,14},
		{10,0 ,10},
		{14,10,14}
	};

	/*Functionality and Circumstances:
	 * Problem: posX and posY of Node N are the true coordinates of the complete nodeGrid,
	 * so n of posX and posY might be [0...columns]x[0...rows]. We must mesh the surrounding
	 * neighbours of N with with the cost-matrix, which always has size [3][3], therefore index [0-2]x[0-2].
	 * Additional counters of indexes of cost-matrix are added, to keep track of the actual cost fitting
	 * to the nodeGrid from the perspective of the active node.
	 **/
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
					//push tuple to neighbour with the actual neighbour (pointer as ID)
					//and its actual cost. There is no need for adjacency matrix (and
					//endless amount of infinite ints)
					/*neighbours.push_back(std::make_tuple(
						nodeMap->at(x).at(y),
						costArray[x_costArray][y_costArray]
					));*/
					neighbours.insert(std::make_pair(
						nodeMap->at(x).at(y),
						costArray[x_costArray][y_costArray]
					));
				}
				y_costArray++;
			}
		}
		x_costArray++;
	}
}


