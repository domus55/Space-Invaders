#include "Game.h"



Game::Game()
{
	isRunning = true;
	Window::window.create(sf::VideoMode(1600, 900, 32), "Space Invaders");
}

void Game::exit()
{
	sf::Event event;
	while (Window::window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			Window::window.close();
			isRunning = false;
		}
	}
}

void Game::update()
{

}

void Game::output()
{
	Window::window.clear();

	sf::Texture image;
	image.loadFromFile("Images/background.png");
	sf::Sprite background;
	background.setTexture(image);
	Window::window.draw(background);

	Window::window.display();
}

void Game::wait()
{
	static int FPS = 0;
	static clock_t start = clock();
	static int time;
	static int zegar = clock();
	static int delay = 1000 / maxFPS;

	time = clock() - start;

	if (delay > time)
	{
		Sleep(delay - time);
	}
	FPS++;

	if ((clock() - zegar) > 1000)
	{
		std::cout << "FPS: " << FPS << std::endl;

		FPS = 0;
		zegar = clock();
	}

	start = clock();
}

Game::~Game()
{

}
