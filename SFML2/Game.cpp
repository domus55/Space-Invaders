#include "Game.h"

Game::Game()
{
	isRunning = true;
	Window::window.create(sf::VideoMode(1600, 900, 32), "Space Invaders", sf::Style::Titlebar | sf::Style::Close);
	Window::window.clear(sf::Color(0, 0, 0));
	Window::window.display();
	Window::image.loadFromFile("Images/spaceship.png");
	Window::window.setIcon(Window::image.getSize().x, Window::image.getSize().y, Window::image.getPixelsPtr());

	std::thread t1(Background::create);
	std::thread t2(LevelManager::create);
	std::thread t3(Explosion::loadAnimation);
	
	t1.join();
	t2.join();
	t3.detach();

	BasicEnemy::loadSound();
	PowerUp::loadSound();
	GameVersion::create();
	Music::playMusic();
	GameHud::create();
	ClosingCredits::create();
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
	LevelManager::update();
	Shoot::updateAll();
	BasicEnemy::updateAll();
	LevelEvent::update();
	Player::update();
	Particle::updateAll();
	PowerUp::updateAll();
}

void Game::output()
{
	Window::window.clear();
	Background::render();
	Particle::renderAll();
	BasicEnemy::renderAll();
	Shoot::renderAll();
	BasicEnemy::renderAll();
	Player::render();
	PowerUp::renderAll();
	Explosion::renderAll();
	LevelManager::render();
	GameVersion::render();
	GameHud::render();
	if (ClosingCredits::render()) isRunning = false;
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
	GameInfo::setDeltaTime(clock() - start);
	start = clock();
}

Game::~Game()
{

}
