#include "Wallbuilder.h"
Wallbuilder::Wallbuilder() /*:
	grid_size(grid_size)*/
{
	walls = std::vector<std::tuple<int, int>>(0);
	//start_x = start_y = end_x = end_y = function_x = function_y = 0;
}


void Wallbuilder::start_building_walls(sf::Vector2u MPGrid)
{
	walls.push_back(std::make_tuple(MPGrid.x, MPGrid.y));
}

void Wallbuilder::update(sf::Vector2u MPGrid)
{
	/*end_x = x; end_y = y;
	function_x = end_x - start_y; function_y = end_y - start_y;*/
	int x = MPGrid.x; int y = MPGrid.y;

	auto it = std::find_if(walls.begin(), walls.end(), [](const std::tuple<int, int>& e) { return std::get<0>(e) == 0; });
	if (it != walls.end()) 
		std::cout << "Found" << std::endl;
	
}