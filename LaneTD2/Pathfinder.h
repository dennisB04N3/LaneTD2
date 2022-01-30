#pragma once
#include"Node.h"

#include<unordered_map>
class Pathfinder
{
private:
	Node* startNode, * endNode;
	std::unordered_map<Node*, int> CLOSEDLIST, OPENLIST;

	bool b_path_found;

	Node* dijsktra();

	Node* get_lowest_cost_node(const std::unordered_map<Node*, int>& OPENLIST);
public:

	Pathfinder(Node* start, Node* end);
	~Pathfinder() {};
	void start();
	void draw_path();
};

