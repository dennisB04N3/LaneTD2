#pragma once
#include"Node.h"

#include<unordered_map>
class Pathfinder
{
private:
	std::unordered_map<Node*, int> CLOSEDLIST, OPENLIST;

	bool b_path_found;

	Node* dijsktra();
	Node* get_lowest_cost_node();

public:
	Node* startNode, * endNode;

	Pathfinder();
	Pathfinder(Node* start, Node* end);
	~Pathfinder() {};

	void start();
	void draw_path();
	void reset();
};

