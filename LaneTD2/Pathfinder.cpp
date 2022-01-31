#include "Pathfinder.h"

Pathfinder::Pathfinder(Node* start, Node* end) :
	startNode(start), endNode(end), b_path_found(false), OPENLIST(0), CLOSEDLIST(0)
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
		current = get_lowest_cost_node(OPENLIST);
		current_cost = current->getCost();
		OPENLIST.erase(current);
		CLOSEDLIST.insert(std::make_pair(current, current->getCost()));

		if (current == endNode)
			return current; 

		for (auto& neighbours : current->getNeighbours())
		{
			Node* current_neighbour = neighbours.first;

			if (CLOSEDLIST.count(current_neighbour) == 1 /*or not traversable*/)
				continue;

			if (((current_cost + neighbours.second) < current_neighbour->getCost()) || OPENLIST.count(current_neighbour) == 0)
			{
				current_neighbour->setCost(current_cost + neighbours.second);
				current_neighbour->setParent(current);
				if (OPENLIST.count(current_neighbour) == 0)
					OPENLIST.insert(std::make_pair(current_neighbour, current_neighbour->getCost()));
			}
		}
	}
}

Node* Pathfinder::get_lowest_cost_node(const std::unordered_map<Node*, int>& OPENLIST)
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
	Node* node = dijsktra()->getParent();

	while (node->getParent())
	{
		node->getTileShape().setFillColor(sf::Color::Magenta);
		node = node->getParent();
	}
}

void Pathfinder::start()
{
	if (startNode && endNode)
	{
		draw_path();
	}
}
