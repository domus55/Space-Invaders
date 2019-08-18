#include "LevelManager.h"

int LevelManager::actualLevel = 0;

void LevelManager::update()
{
	if (BasicEnemy::enemy.size() == 0)
	{
		LevelManager::actualLevel++;
		nextLevel();
	}
}

void LevelManager::nextLevel()
{
	switch (actualLevel)
	{
	case 1: level1(); break;
	case 2: level2(); break;
	}
}

void LevelManager::level1()
{
	for (int i = 0; i < 3; i++)
	{
		EnemyEasy::create(i * 300 + 500, 100);
	}
}

void LevelManager::level2()
{
	for (int i = 0; i < 4; i++)
	{
		EnemyEasy::create(i * 300 + 325, 100, 0);
	}
}

