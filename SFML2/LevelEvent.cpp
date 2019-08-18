#include "LevelEvent.h"

void LevelEvent::update()
{
	switch(LevelManager::actualLevel)
	{
	case 2: level2(); break;
	}
	
}

void LevelEvent::level2()
{
	static bool left = true;

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && left) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 0 && !left) BasicEnemy::enemy[i]->moveRight();
	}

	if (BasicEnemy::mostToTheLeft() < 100) left = false;
	if (BasicEnemy::mostToTheRight() > 1500) left = true;
}

