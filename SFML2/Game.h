#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <windows.h>
#include <iostream>
#include "Window.h"
#include "GameInfo.h"
#include "LevelManager.h"
#include "BasicEnemy.h"
#include "EnemyEasy.h"

class Game
{
public:
	bool isRunning;
	int maxFPS = 300;

	Game();
	void exit();
	void update();
	void output();
	void wait();
	~Game();
};

