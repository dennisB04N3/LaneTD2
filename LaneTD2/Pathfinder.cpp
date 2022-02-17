#include "Pathfinder.h"
Pathfinder::Pathfinder() :
	startNode(nullptr), endNode(nullptr), b_path_found(0), OPENLIST(0), CLOSEDLIST(0)
{}

Pathfinder::Pathfinder(Node* start, Node* end) :
	startNode(start), endNode(end), b_path_found(0), OPENLIST(0), CLOSEDLIST(0)
{
	startNode->getTileShape().setFillColor(sf::Color::Green);
	endNode->getTileShape().setFillColor(sf::Color::Red);
}

Node* Pathfinder::dijsktra()
{
	int current_cost = 0;
	OPENLIST.insert(std::make_pair(startNode, current_cost));
	Node* current = nullptr;

	while (OPENLIST.size() > 0)
	{
		current = get_lowest_cost_node();
		current_cost = OPENLIST[current];
		CLOSEDLIST.insert(std::make_pair(current, OPENLIST[current]));
		OPENLIST.erase(current);

		if (current == endNode) 
		{
			b_path_found = 1;
			return current; 
		}

		for (auto& neighbour_data : current->getNeighbours())
		{
			Node* current_neighbour = neighbour_data.first;
			if (CLOSEDLIST.count(current_neighbour) == 1 || !(current_neighbour->isTraversable()))
				continue;

			if (((current_cost + neighbour_data.second) < current_neighbour->getCost()) || OPENLIST.count(current_neighbour) == 0)
			{
				current_neighbour->setCost(current_cost + neighbour_data.second);
				current_neighbour->setParent(current);
				if (OPENLIST.count(current_neighbour) == 0)
					OPENLIST.insert(std::make_pair(current_neighbour, current_neighbour->getCost()));
			}
		}
	}
}

Node* Pathfinder::get_lowest_cost_node()
{
	Node* lowest_node = nullptr;
	int cost = INT_MAX;
	for (auto& node_data : OPENLIST)
	{
		int node_cost = node_data.second;
		if (node_cost < cost)
		{
			cost = node_cost;
			lowest_node = node_data.first;
		}
	}
	return lowest_node;
}

void Pathfinder::draw_path()
{
	Node* node = dijsktra();

	if (node)
	{
		node = node->getParent();
		while (node->getParent())
		{
			node->getTileShape().setFillColor(sf::Color::Magenta);
			node = node->getParent();
		}
	}
}

void Pathfinder::reset()
{
	CLOSEDLIST.clear();
	OPENLIST.clear();
	startNode = endNode = nullptr;
}

void Pathfinder::start()
{
	if (startNode && endNode)
	{
		draw_path();
	}
}
