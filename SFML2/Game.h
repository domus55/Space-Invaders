#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <windows.h>
#include <iostream>
#include <thread>
#include "Window.h"
#include "Background.h"
#include "GameInfo.h"
#include "LevelManager.h"
#include "LevelEvent.h"
#include "Shoot.h"
#include "Player.h"
#include "Explosion.h"
#include "Particle.h"
#include "PowerUp.h"
#include "BasicEnemy.h"
#include "EnemyEasy.h"
#include "GameVersion.h"
#include "Music.h"
#include "GameHud.h"
#include "ClosingCredits.h"

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

