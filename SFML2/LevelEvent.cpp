#include "LevelEvent.h"

void LevelEvent::update()
{
	switch(LevelManager::actualLevel)
	{
	case 2: level2(); break;
	case 3: level3(); break;
	case 4: level4(); break;
	case 5: level5(); break;
	case 6: level6(); break;
	case 7: level7(); break;
	case 8: level8(); break;
	case 9: level9(); break;
	case 10: level10(); break;
	}
}

void LevelEvent::level2()
{
	static bool left = true;
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 1000)
	{
		left = true;
		down = true;
	}
	prevTime = clock();

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

void LevelEvent::level3()
{
	static bool left = true;
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 1000)
	{
		left = true;
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheBottom() > 100) down = false;
}

void LevelEvent::level4()
{
	static bool left = true;
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 1000)
	{
		left = true;
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheBottom() > 100) down = false;
}

void LevelEvent::level5()
{
	static bool army1Right = true;
	static bool army2Left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 1000)
	{
		army1Right = true;
		army2Left = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && army1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 0 && !army1Right) BasicEnemy::enemy[i]->moveLeft();

		if (BasicEnemy::enemy[i]->id == 1 && army2Left) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 1 && !army2Left) BasicEnemy::enemy[i]->moveRight();
	}

	if (BasicEnemy::mostToTheRight(0) > 1400) army1Right = false;
	if (BasicEnemy::mostToTheLeft(0) < 200) army1Right = true;

	if (BasicEnemy::mostToTheRight(1) > 1400) army2Left = true;
	if (BasicEnemy::mostToTheLeft(1) < 200) army2Left = false;
}

void LevelEvent::level6()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 1000)
	{
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheBottom() > 300) down = false;
}

void LevelEvent::level7()
{
	static bool left = true;
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 1000)
	{
		left = true;
		down = true;
	}
	prevTime = clock();

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

void LevelEvent::level8()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 1000)
	{
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheBottom() > 300) down = false;
}

void LevelEvent::level9()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 1000)
	{
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheBottom() > 300) down = false;
}

void LevelEvent::level10()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 1000)
	{
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheBottom() > 200) down = false;
}