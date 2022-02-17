#include "Node.h"

Node::Node(float posX, float posY) :
	parent(nullptr), tile(nullptr), cost(INT_MAX)
{
	neighbours = std::unordered_map<Node*, int>(0);
	position = sf::Vector2f(posX, posY);
}

//delete
void Node::click()
{
	tile->getShape().setFillColor(sf::Color::Black);
	for (auto& tuple : neighbours)
	{
		std::get<0>(tuple)->getTileShape().setFillColor(sf::Color::Yellow);
	}
}

void Node::initNeighbours( std::map<int,std::map<int,Node*>>* node_map, 
		const int rows, const int columns, const int posX, const int posY)
{
	//cost matrix
	int costArray[3][3] = {
		{INT_MAX,10,INT_MAX},
		{10,     0 ,10},
		{INT_MAX,10,INT_MAX}
	};

	//merging cost-array with neighbours of current node (represented with posX and Y)
	//on node_map to create the neighbour-vertices(as hashmap) held by current node <- (neighbour, cost)
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
					if (costArray[x_costArray][y_costArray] != INT_MAX) {
						neighbours.insert(std::make_pair(
							node_map->at(x).at(y),
							costArray[x_costArray][y_costArray]
						));
					}
				}
				y_costArray++;
			}
		}
		x_costArray++;
	}
}

void Node::changeState(char state)
{
	switch (state)
	{
		case 's'://startNode
			tile->setTraversable(1);
			tile->setColor(sf::Color::Green);
			break;
		case 'e'://endNode
			tile->setTraversable(1);
			tile->setColor(sf::Color::Red);
			break;
		case 'w'://wall
			tile->setTraversable(0);
			tile->setColor(sf::Color::Black);
			break;
		case 'r'://reset
			cost = INT_MAX;
			parent = nullptr;
			tile->setTraversable(1);
			tile->setColor(sf::Color::White);
			break;
		default:
			break;
	}
}
