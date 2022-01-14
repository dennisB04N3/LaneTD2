#include "Node.h"

Node::Node(float posX, float posY)
{
	position = sf::Vector2f(posX, posY);
	shape.setPosition(position);
	shape.setFillColor(sf::Color::Magenta);
	shape.setRadius(5);
}
