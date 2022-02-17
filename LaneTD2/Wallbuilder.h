#pragma once
#include"SFML/Graphics.hpp"
#include<vector>
#include<tuple>
#include<iostream>

/* This class is for building a connected chain of wall per
 * click&release (click = start collecting information,
 * release = place all hit tiles in world).
 * Right now not used yet.
 */
class Wallbuilder
{
private:
	/*following is for drawing walls in a straight line
	int start_x, start_y;
	int end_x, end_y;
	int function_x, function_y;
	int grid_size;
	const int step = 5;*/

	std::vector<std::tuple<int, int>> walls;


public:
	Wallbuilder();
	
	void start_building_walls(sf::Vector2u MPGrid);
	void update(sf::Vector2u MPGrid);


	std::vector<std::tuple<int, int>>* getWalls() { return &walls; }
};

