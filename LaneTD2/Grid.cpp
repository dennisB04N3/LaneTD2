#include "Grid.h"

Grid::Grid(int gridSize, int tileRows, int tileColumns, sf::Vector2f position) :
	visible(true)
{
	sf::Color color = sf::Color::Color(50, 150, 150);
	int lineWidth = tileColumns * gridSize;
	int lineHeight = tileRows * gridSize;

	float posX = position.x;
	float posY = position.y;
	int lineThickness = 2;

	//templates of horizontal and vertical line that gets copied into grid-vector
	sf::RectangleShape horizontalLine;
	horizontalLine.setFillColor(color);
	horizontalLine.setSize(sf::Vector2f(static_cast<float>(lineWidth), static_cast<float>(lineThickness)));

	sf::RectangleShape verticalLine;
	verticalLine.setFillColor(color);
	verticalLine.setSize(sf::Vector2f((float)lineThickness, (float)lineHeight));
	verticalLine.setPosition(0, posY);

	int count = 0;
	for (int x = 0; x < tileColumns; x++)
	{
		this->grid.push_back(new sf::RectangleShape(verticalLine));
		this->grid[count]->setPosition(posX + (x * gridSize), posY);
		count++;
		if (x == tileColumns - 1)
		{
			this->grid.push_back(new sf::RectangleShape(verticalLine));
			this->grid[count]->setPosition(posX + ((x + 1) * gridSize), posY);
			count++;
		}
	}
	for (int y = 0; y < tileRows; y++)
	{
		this->grid.push_back(new sf::RectangleShape(horizontalLine));
		this->grid[count]->setPosition(posX, posY + (y * gridSize));
		count++;
		if (y == tileRows - 1)
		{
			this->grid.push_back(new sf::RectangleShape(horizontalLine));
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