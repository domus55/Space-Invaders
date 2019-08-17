#include "LevelManager.h"

int LevelManager::acutalLevel = 0;

void LevelManager::update()
{
	if (BasicEnemy::enemy.size() == 0)
	{
		LevelManager::acutalLevel++;
		nextLevel();
	}
}

void LevelManager::nextLevel()
{
	switch (acutalLevel)
	{
	case 1: level1();
	//case 2: level2();
	}
}

void LevelManager::level1()
{
	for (int i = 0; i < 3; i++)
	{
		EnemyEasy::create(i * 300 + 500, 100);
	}
	
}
