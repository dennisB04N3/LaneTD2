#include "Game.h"
Game::Game()
{
	WINDOW_WIDTH = 1920;
	WINDOW_HEIGHT = 1080;

	gridSize = 50;
	rows = 15;
	columns = 20;
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
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					this->world->click(MPGrid);
				}
			}
			if (event.type == sf::Event::KeyPressed)
			{
				/*if (event.key.code == sf::Keyboard::W)
				{
					this->display->moveView('W', deltaTime);

				}
				if (event.key.code == sf::Keyboard::S)
				{
					this->display->moveView('S', deltaTime);

				}*/
			}
		}
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			std::cout << "another method" << std::endl;
			this->display->moveView('S', deltaTime);
		}*/
		update();
		window->clear();
		//Game elements
		world->draw(*window);

		window->setView(window->getDefaultView());
		window->draw(text_MP);
		window->display();
	}
}

void Game::updateMP()
{
	MPWindow = sf::Mouse::getPosition(*window);
	window->setView(window->getView());
	MPView = window->mapPixelToCoords(MPWindow);

	//TODO: how to make more efficient?
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
	std::string str;

	str = "Window:\t" + std::to_string(MPWindow.x) + " " + std::to_string(MPWindow.y) + "\n"
		+ "View:\t" + std::to_string(MPView.x) + " " + std::to_string(MPView.y) + "\n"
		+ "Grid:\t" + std::to_string(MPGrid.x) + " " + std::to_string(MPGrid.y);

	text_MP.setString(str);
}


/*For later use:

sf::Vertex vertices[] =
{
	sf::Vertex(sf::Vector2f(100, 0), sf::Color::Red),
	sf::Vertex(sf::Vector2f(100, 100), sf::Color::Red)
};
// draw it

sf::VertexArray lines(sf::LinesStrip, 4);
lines[0].position = sf::Vector2f(100, 100);
lines[1].position = sf::Vector2f(200, 100);
lines[2].position = sf::Vector2f(300, 500);
lines[3].position = sf::Vector2f(400, 200);
window->draw(vertices, 2, sf::Lines);
window->draw(lines);*/