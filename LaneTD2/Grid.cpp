#include "Grid.h"

Grid::Grid(int gridSize, int tileRows, int tileColumns, sf::Vector2f position) :
	visible(true)
{
	sf::Color color = sf::Color::Color(50, 150, 150);
	int line_width = tileColumns * gridSize;
	int line_height = tileRows * gridSize;

	float posX = position.x;
	float posY = position.y;
	int line_thickness = 2;

	//templates of horizontal and vertical line that gets copied into grid-vector
	sf::RectangleShape horizontal_line;
	horizontal_line.setFillColor(color);
	horizontal_line.setSize(sf::Vector2f(static_cast<float>(line_width), static_cast<float>(line_thickness)));

	sf::RectangleShape vertical_line;
	vertical_line.setFillColor(color);
	vertical_line.setSize(sf::Vector2f((float)line_thickness, (float)line_height));
	vertical_line.setPosition(0, posY);

	int count = 0;
	for (int x = 0; x < tileColumns; x++)
	{
		this->grid.push_back(new sf::RectangleShape(vertical_line));
		this->grid[count]->setPosition(posX + (x * gridSize), posY);
		count++;
		if (x == tileColumns - 1)
		{
			this->grid.push_back(new sf::RectangleShape(vertical_line));
			this->grid[count]->setPosition(posX + ((x + 1) * gridSize), posY);
			count++;
		}
	}
	for (int y = 0; y < tileRows; y++)
	{
		this->grid.push_back(new sf::RectangleShape(horizontal_line));
		this->grid[count]->setPosition(posX, posY + (y * gridSize));
		count++;
		if (y == tileRows - 1)
		{
			this->grid.push_back(new sf::RectangleShape(horizontal_line));
			this->grid[count]->setPosition(posX, posY + ((y + 1) * gridSize));
		}
	}
}

Grid::~Grid()
{
	for (int i = 0; i < this->grid.size(); i++)
	{
		delete this->grid[i];
		this->grid[i] = nullptr;
	}
}

void Grid::draw(sf::RenderTarget& target)
{
	if (this->visible)
	{
		for (auto& elem : grid)
		{
			target.draw(*elem);
		}
	}
}