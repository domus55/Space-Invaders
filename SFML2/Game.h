#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <windows.h>
#include <iostream>
#include "Window.h"

class Game
{
public:
	//sf::RenderWindow window;
	bool isRunning;
	int maxFPS = 3000;

	Game();
	void exit();
	void update();
	void output();
	void wait();
	~Game();
};

