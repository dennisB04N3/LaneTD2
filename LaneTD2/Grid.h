#pragma once
#include"SFML/Graphics.hpp"
class Grid
{
private:

	std::vector<sf::RectangleShape*> grid;

	bool visible;
public:
	//Grid() : grid(std::vector<sf::RectangleShape*>()), visible(false) {};
	Grid(int gridSize, int tileRows, int rileColumns, sf::Vector2f position);
	~Grid();

	void draw(sf::RenderTarget& target);
};

