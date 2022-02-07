#include "Game.h"
Game::Game() :
	place_endNode_onClick(0), place_startNode_onClick(0), button_pressed(0)
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
		deltaTime = clock.restart().asSeconds();
		updateMP();
		sf::Event event;

		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::W)
					this->display->moveView('W', deltaTime);
				if (event.key.code == sf::Keyboard::S)
					this->display->moveView('S', deltaTime);
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
					if (MPGrid.x < INT_MAX && MPGrid.y < INT_MAX)
					{
						if (place_endNode_onClick == true)
							world->place_endNode(MPGrid);
						else if(place_startNode_onClick == true)
							world->place_startNode(MPGrid);
						else
							this->world->place_wall(MPGrid);
					}
					if (button_resetNodes.getGlobalBounds().contains(MPWindow.x, MPWindow.y))
					{
						std::cout << "button pressed" << std::endl;
						if (!button_pressed)
						{
							std::cout << "start pathfinder" << std::endl;
							world->start_pathfinder();
							button_pressed = 1;
						}
						else
						{
							std::cout << "reset pathfinder" << std::endl;
							world->reset_pathfinder();
							button_pressed = 0;
						}
					}
				}

			}
			/*if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (MPGrid.x < INT_MAX && MPGrid.y < INT_MAX)
					{
						this->world->click(MPGrid);
					}
				}
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					this->display->moveView('W', deltaTime);

				}
				if (event.key.code == sf::Keyboard::S)
				{
					this->display->moveView('S', deltaTime);

				}
			}*/
		}
		window->clear();
		//display->set_window_to_view();
		update();

		//Game elements
		world->draw(*window);

		display->set_window_to_default();
		window->draw(button_resetNodes);
		window->draw(text_MP);
		window->display();
	}
}

void Game::updateMP()
{
	MPWindow = sf::Mouse::getPosition(*window);
	display->set_window_to_view();
	MPView = window->mapPixelToCoords(MPWindow);

	//TODO: how to make a better read? -> checktarget? 
	//if GUI implemented there must be a checkTarget function anyways
	if ((MPView.x > mapPosition.x && MPView.x < (mapPosition.x + columns * gridSize)) && (MPView.y > mapPosition.y && MPView.y < (mapPosition.y + rows * gridSize)))
	{
		MPGrid.x = static_cast<unsigned>(((MPView.x) - mapPosition.x) / gridSize);
		MPGrid.y = static_cast<unsigned>(((MPView.y) - mapPosition.y) / gridSize);
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
