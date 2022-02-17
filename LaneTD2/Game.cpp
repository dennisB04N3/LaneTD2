#include "Game.h"
Game::Game() :
	place_endNode_onClick(0), place_startNode_onClick(0), button_pressed(0), left_mouse_button_pressed(0)
{
	WINDOW_WIDTH = 1920;
	WINDOW_HEIGHT = 1080;

	gridSize = 30;
	rows = 50;
	columns = 15;
	mapPosition = sf::Vector2f(static_cast<float>((WINDOW_WIDTH / 2) - ((columns * gridSize) / 2)), 100);

	if (!font.loadFromFile("D:/workspaces/libs/SFML-2.5.1/examples/island/resources/sansation.ttf"))
	{
		std::cout << "Font not foundlololo" << std::endl;
	}
	else
	{
		text_MP.setFont(font);
		text_MP.setCharacterSize(12);
		text_MP.setFillColor(sf::Color::White);
		text_MP.setPosition(20.f, 20.f);
	}
	world = new World(mapPosition, gridSize, rows, columns);
	display = new Display();
	window = display->getWindow();

	button_resetNodes.setSize(sf::Vector2f(80, 40));
	button_resetNodes.setFillColor(sf::Color::Yellow);
	button_resetNodes.setPosition(20,WINDOW_HEIGHT - 100);
	tile_selector = sf::RectangleShape(sf::Vector2f(gridSize, gridSize));
	tile_selector.setOutlineThickness(2);
	tile_selector.setOutlineColor(sf::Color::Green);
	tile_selector.setFillColor(sf::Color::Transparent);
	map_borders.setSize(sf::Vector2f(columns * gridSize, rows * gridSize));
	map_borders.setPosition(mapPosition);

}

Game::~Game()
{
	delete this->display;
	delete this->world;
	this->display = nullptr;
	this->world = nullptr;
	this->window = nullptr;
}

void Game::start()
{
	float deltaTime = 0;

	while (window->isOpen())
	{
		pre_event_update();
		deltaTime = clock.restart().asSeconds();
		sf::Event event;

		while (window->pollEvent(event))
		{
			if (left_mouse_button_pressed && map_borders.getGlobalBounds().contains(MPView.x, MPView.y))
			{
				world->place_wall(MPGrid);
			}
			if (right_mouse_button_pressed && map_borders.getGlobalBounds().contains(MPView.x, MPView.y))
			{
				world->reset_node(MPGrid);
			}

			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			
			case sf::Event::MouseButtonReleased:
				left_mouse_button_pressed = 0;
				right_mouse_button_pressed = 0;
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::W)
				{
					this->display->moveView('W', deltaTime);
				}
				if (event.key.code == sf::Keyboard::S)
				{
					this->display->moveView('S', deltaTime);
				}
				if (event.key.code == sf::Keyboard::E)
				{
					place_startNode_onClick = false; 
					place_endNode_onClick = !place_endNode_onClick; 
					//std::cout << place_startNode_onClick << " " << place_endNode_onClick << std::endl;
				}
				if (event.key.code == sf::Keyboard::D)
				{
					place_endNode_onClick = false; 
					place_startNode_onClick = !place_startNode_onClick;
					//std::cout << place_startNode_onClick << " " << place_endNode_onClick << std::endl;
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (map_borders.getGlobalBounds().contains(MPView.x, MPView.y))
					{	
						if (place_endNode_onClick)
							world->place_endNode(MPGrid);
						else if(place_startNode_onClick)
							world->place_startNode(MPGrid);
						else
						{
							this->world->place_wall(MPGrid);
							left_mouse_button_pressed = 1;
						}
					}
					if (button_resetNodes.getGlobalBounds().contains(MPView.x, MPView.y))
					{
						if (!button_pressed)
						{
							world->start_pathfinder();
							button_pressed = 1;
						}
						else
						{
							world->reset_pathfinder();
							button_pressed = 0;
						}
					}
				}
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					if (map_borders.getGlobalBounds().contains(MPView.x, MPView.y))
					{
						world->reset_node(MPGrid);
						right_mouse_button_pressed = 1;
					}
				}
			}
		}
		update();
		window->clear();

		//Game elements
		world->draw(*window);
		window->draw(tile_selector);

		//static objects
		display->set_window_to_default();
		window->draw(button_resetNodes);
		window->draw(text_MP);

		window->display();
	}
}

void Game::pre_event_update()
{
	MPWindow = sf::Mouse::getPosition(*window);
	display->set_window_to_view();
	MPView = window->mapPixelToCoords(MPWindow);

	//TODO: how to make a better read? -> checktarget? 
	//if GUI implemented there must be a checkTarget function anyways
	if (map_borders.getGlobalBounds().contains(MPView.x, MPView.y))
	{
		MPGrid.x = static_cast<unsigned>(((MPView.x) - mapPosition.x) / gridSize);
		MPGrid.y = static_cast<unsigned>(((MPView.y) - mapPosition.y) / gridSize);
		tile_selector.setPosition(sf::Vector2f(MPGrid.x * gridSize + mapPosition.x, MPGrid.y * gridSize + mapPosition.y));
	}
	else
	{
		MPGrid.x = INT_MAX;
		MPGrid.y = INT_MAX;
	}


}

void Game::update()
{
	//right now for testing
	std::string str;

	str = "Window:\t" + std::to_string(MPWindow.x) + " " + std::to_string(MPWindow.y) + "\n"
		+ "View:\t" + std::to_string(MPView.x) + " " + std::to_string(MPView.y) + "\n"
		+ "Grid:\t" + std::to_string(MPGrid.x) + " " + std::to_string(MPGrid.y);

	text_MP.setString(str);
}
