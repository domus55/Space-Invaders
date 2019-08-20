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
	static bool down = true;

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && left && !down) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 0 && !left && !down) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheLeft() < 100) left = false;
	if (BasicEnemy::mostToTheRight() > 1500) left = true;
	if (BasicEnemy::mostToTheBottom() > 100) down = false;
}

