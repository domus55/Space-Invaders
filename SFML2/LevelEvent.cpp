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
	case 11: level11(); break;
	case 12: level12(); break;
	case 13: level13(); break;
	case 14: level14(); break;
	case 15: level15(); break;
	case 16: level16(); break;
	case 17: level17(); break;
	case 18: level18(); break;
	case 19: level19(); break;
	case 20: level20(); break;
	case 21: level21(); break;
	case 22: level22(); break;
	case 23: level23(); break;
	case 24: level24(); break;
	case 25: level25(); break;
	case 26: level26(); break;
	case 27: level27(); break;
	case 28: level28(); break;
	case 29: level29(); break;
	case 30: level30(); break;
	case 31: level31(); break;
	case 32: level32(); break;
	case 33: level33(); break;
	case 34: level34(); break;
	case 35: level35(); break;
	case 36: level36(); break;
	case 37: level37(); break;
	case 38: level38(); break;
	case 39: level39(); break;
	case 40: level40(); break;
	case 41: level41(); break;
	case 42: level42(); break;
	case 43: level43(); break;
	case 44: level44(); break;
	case 45: level45(); break;
	case 46: level46(); break;
	case 47: level47(); break;
	case 48: level48(); break;
	case 49: level49(); break;
	case 50: level50(); break;
	}
}

void LevelEvent::level2()
{
	static bool left = true;
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 2000)
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
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
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
	if (clock() - prevTime > 5000)
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
	if (clock() - prevTime > 5000)
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
	if (clock() - prevTime > 5000)
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
	if (clock() - prevTime > 5000)
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
	if (clock() - prevTime > 5000)
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
	if (clock() - prevTime > 5000)
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
	if (clock() - prevTime > 5000)
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

void LevelEvent::level11()
{
	static bool left = true;
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		left = true;
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheBottom() > 200) down = false;
}

void LevelEvent::level12()
{
	static bool tank1Right = true;
	static bool tank2Left = true;
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		tank1Right = true;
		tank2Left = true;
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && tank1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 1 && tank2Left) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 2 && down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheRight(0) > 650) tank1Right = false;
	if (BasicEnemy::mostToTheLeft(1) < 950) tank2Left = false;
	if (BasicEnemy::mostToTheBottom(2) > 125) down = false;
}

void LevelEvent::level13()
{
	static bool army1Right = true;
	static bool army2Left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
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

	if (BasicEnemy::mostToTheRight(0) > 1550) army1Right = false;
	if (BasicEnemy::mostToTheLeft(0) < 50) army1Right = true;

	if (BasicEnemy::mostToTheRight(1) > 1550) army2Left = true;
	if (BasicEnemy::mostToTheLeft(1) < 50) army2Left = false;
}

void LevelEvent::level14()
{
	static bool tank1Right = true;
	static bool tank2Left = true;
	static bool down = true;
	static bool left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		tank1Right = true;
		tank2Left = true;
		down = true;
		left = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && tank1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 1 && tank2Left) BasicEnemy::enemy[i]->moveLeft();

		if (BasicEnemy::enemy[i]->id == 2 && down) BasicEnemy::enemy[i]->moveDown();
		if (BasicEnemy::enemy[i]->id == 2 && left && !down) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 2 && !left && !down) BasicEnemy::enemy[i]->moveRight();
	}

	if (BasicEnemy::mostToTheRight(0) > 650) tank1Right = false;
	if (BasicEnemy::mostToTheLeft(1) < 950) tank2Left = false;
	if (BasicEnemy::mostToTheBottom(2) > 125) down = false;
	if (BasicEnemy::mostToTheLeft(2) < 100) left = false;
	if (BasicEnemy::mostToTheRight(2) > 1500) left = true;
}

void LevelEvent::level15()
{
	static bool left = true;
	static bool down = true;
	static bool army1Right = true;
	static bool army2Left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		left = true;
		down = true;
		army1Right = true;
		army2Left = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && left && !down) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 0 && !left && !down) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();

		if (BasicEnemy::enemy[i]->id == 1 && army1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 2 && army2Left) BasicEnemy::enemy[i]->moveLeft();
	}

	if (BasicEnemy::mostToTheLeft(0) < 100) left = false;
	if (BasicEnemy::mostToTheRight(0) > 1500) left = true;
	if (BasicEnemy::mostToTheBottom(0) > 100) down = false;

	if (BasicEnemy::mostToTheRight(1) > 675) army1Right = false;
	if (BasicEnemy::mostToTheLeft(2) < 925) army2Left = false;
}

void LevelEvent::level16()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
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

void LevelEvent::level17()
{
	static bool tank1Right = true;
	static bool tank2Left = true;
	static bool down = true;
	static bool left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		tank1Right = true;
		tank2Left = true;
		down = true;
		left = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && tank1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 1 && tank2Left) BasicEnemy::enemy[i]->moveLeft();

		if (BasicEnemy::enemy[i]->id == 2 && down) BasicEnemy::enemy[i]->moveDown();
		if (BasicEnemy::enemy[i]->id == 2 && left && !down) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 2 && !left && !down) BasicEnemy::enemy[i]->moveRight();
	}

	if (BasicEnemy::mostToTheRight(0) > 650) tank1Right = false;
	if (BasicEnemy::mostToTheLeft(1) < 950) tank2Left = false;
	if (BasicEnemy::mostToTheBottom(2) > 125) down = false;
	if (BasicEnemy::mostToTheLeft(2) < 100) left = false;
	if (BasicEnemy::mostToTheRight(2) > 1500) left = true;
}

void LevelEvent::level18()
{
	static bool tank1Right = true;
	static bool tank2Left = true;
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		tank1Right = true;
		tank2Left = true;
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && tank1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 1 && tank2Left) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 2 && down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheRight(0) > 650) tank1Right = false;
	if (BasicEnemy::mostToTheLeft(1) < 950) tank2Left = false;
	if (BasicEnemy::mostToTheBottom(2) > 125) down = false;
}

void LevelEvent::level19()
{
	static bool left = true;
	static bool down = true;
	static bool army1Right = true;
	static bool army2Right = true;
	static bool army3Left = true;
	static bool army4Left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		left = true;
		down = true;
		army1Right = true;
		army2Right = true;
		army3Left = true;
		army4Left = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && left && !down) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 0 && !left && !down) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();

		if (BasicEnemy::enemy[i]->id == 1 && army1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 2 && army2Right) BasicEnemy::enemy[i]->moveRight();

		if (BasicEnemy::enemy[i]->id == 3 && army3Left) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 4 && army4Left) BasicEnemy::enemy[i]->moveLeft();
	}

	if (BasicEnemy::mostToTheLeft(0) < 100) left = false;
	if (BasicEnemy::mostToTheRight(0) > 1500) left = true;
	if (BasicEnemy::mostToTheBottom(0) > 100) down = false;

	if (BasicEnemy::mostToTheRight(1) > 600) army1Right = false;
	if (BasicEnemy::mostToTheRight(2) > 600) army2Right = false;

	if (BasicEnemy::mostToTheLeft(3) < 1000) army3Left = false;
	if (BasicEnemy::mostToTheLeft(4) < 1000) army4Left = false;
}

void LevelEvent::level20()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
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

void LevelEvent::level21()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
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

void LevelEvent::level22()
{
	static bool tank1Right = true;
	static bool tank2Left = true;
	static bool down = true;
	static bool left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		tank1Right = true;
		tank2Left = true;
		down = true;
		left = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && tank1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 1 && tank2Left) BasicEnemy::enemy[i]->moveLeft();

		if (BasicEnemy::enemy[i]->id == 2 && down) BasicEnemy::enemy[i]->moveDown();
		if (BasicEnemy::enemy[i]->id == 2 && left && !down) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 2 && !left && !down) BasicEnemy::enemy[i]->moveRight();
	}

	if (BasicEnemy::mostToTheRight(0) > 700) tank1Right = false;
	if (BasicEnemy::mostToTheLeft(1) < 900) tank2Left = false;
	if (BasicEnemy::mostToTheBottom(2) > 125) down = false;
	if (BasicEnemy::mostToTheLeft(2) < 100) left = false;
	if (BasicEnemy::mostToTheRight(2) > 1500) left = true;
}

void LevelEvent::level23()
{
}

void LevelEvent::level24()
{
	static bool army1Right = true;
	static bool army2Left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
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

	if (BasicEnemy::mostToTheRight(0) > 1550) army1Right = false;
	if (BasicEnemy::mostToTheLeft(0) < 50) army1Right = true;

	if (BasicEnemy::mostToTheRight(1) > 1550) army2Left = true;
	if (BasicEnemy::mostToTheLeft(1) < 50) army2Left = false;
}

void LevelEvent::level25()
{
	static bool down = true;
	static bool army1Right = true;
	static bool army2Left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		down = true;
		army1Right = false;
		army2Left = false;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();

		if (BasicEnemy::enemy[i]->id == 1 && army1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 2 && army2Left) BasicEnemy::enemy[i]->moveLeft();
	}

	if (BasicEnemy::mostToTheBottom(0) > 200) down = false;
	if (BasicEnemy::mostToTheRight(1) > 600) army1Right = false;
	if (BasicEnemy::mostToTheLeft(2) < 1000) army2Left = false;
}

void LevelEvent::level26()
{
	static bool army1Left = true;
	static bool army2Right = true;
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		army1Left = true;
		army2Right = true;
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (down) BasicEnemy::enemy[i]->moveDown();

		if (BasicEnemy::enemy[i]->id == 0 && army1Left && !down) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 0 && !army1Left && !down) BasicEnemy::enemy[i]->moveRight();
		
		if (BasicEnemy::enemy[i]->id == 1 && army2Right && !down) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 1 && !army2Right && !down) BasicEnemy::enemy[i]->moveLeft();
	}

	if (BasicEnemy::mostToTheBottom() > 300) down = false;

	if (BasicEnemy::mostToTheLeft(0) < 100) army1Left = false;
	if (BasicEnemy::mostToTheRight(0) > 1500) army1Left = true;

	if (BasicEnemy::mostToTheLeft(1) < 100) army2Right = true;
	if (BasicEnemy::mostToTheRight(1) > 1500) army2Right = false;
}

void LevelEvent::level27()
{
	static bool left = true;
	static bool down = true;
	static bool army1Right = true;
	static bool army2Left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		left = true;
		down = true;
		army1Right = true;
		army2Left = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();

		if (BasicEnemy::enemy[i]->id == 1 && army1Right) BasicEnemy::enemy[i]->moveRight();

		if (BasicEnemy::enemy[i]->id == 2 && army2Left) BasicEnemy::enemy[i]->moveLeft();
	}

	if (BasicEnemy::mostToTheBottom(0) > 100) down = false;

	if (BasicEnemy::mostToTheRight(1) > 675) army1Right = false;

	if (BasicEnemy::mostToTheLeft(2) < 925) army2Left = false;
}

void LevelEvent::level28()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheBottom() > 350) down = false;
}

void LevelEvent::level29()
{
	static bool army1Left = true;
	static bool army2Right = true;
	static bool army3Left = true;
	static bool army4Right = true;
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		army1Left = true;
		army2Right = true;
		army3Left = true;
		army4Right = true;
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();
		if (BasicEnemy::enemy[i]->id == 1 && down) BasicEnemy::enemy[i]->moveDown();

		if (BasicEnemy::enemy[i]->id == 0 && army1Left && !down) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 0 && !army1Left && !down) BasicEnemy::enemy[i]->moveRight();

		if (BasicEnemy::enemy[i]->id == 1 && army2Right && !down) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 1 && !army2Right && !down) BasicEnemy::enemy[i]->moveLeft();

		if (BasicEnemy::enemy[i]->id == 2 && army3Left) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 3 && army4Right) BasicEnemy::enemy[i]->moveRight();
	}

	if (BasicEnemy::mostToTheBottom(0) > 300 || BasicEnemy::mostToTheBottom(1) > 300) down = false;

	if (BasicEnemy::mostToTheLeft(0) < 100) army1Left = false;
	if (BasicEnemy::mostToTheRight(0) > 1500) army1Left = true;

	if (BasicEnemy::mostToTheLeft(1) < 100) army2Right = true;
	if (BasicEnemy::mostToTheRight(1) > 1500) army2Right = false;

	if (BasicEnemy::mostToTheLeft(2) < 925) army3Left = false;
	if (BasicEnemy::mostToTheRight(3) > 675) army4Right = false;
}

void LevelEvent::level30()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
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

void LevelEvent::level31()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheBottom() > 350) down = false;
}

void LevelEvent::level32()
{
	static bool army1Left = true;
	static bool army2Right = true;
	static bool army3Left = true;
	static bool army4Right = true;
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		army1Left = true;
		army2Right = true;
		army3Left = true;
		army4Right = true;
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();
		if (BasicEnemy::enemy[i]->id == 1 && down) BasicEnemy::enemy[i]->moveDown();
		if (BasicEnemy::enemy[i]->id == 4 && down) BasicEnemy::enemy[i]->moveDown();

		if (BasicEnemy::enemy[i]->id == 0 && army1Left && !down) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 0 && !army1Left && !down) BasicEnemy::enemy[i]->moveRight();

		if (BasicEnemy::enemy[i]->id == 1 && army2Right && !down) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 1 && !army2Right && !down) BasicEnemy::enemy[i]->moveLeft();

		if (BasicEnemy::enemy[i]->id == 2 && army3Left) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 3 && army4Right) BasicEnemy::enemy[i]->moveRight();
	}

	if (BasicEnemy::mostToTheBottom(0) > 300 || BasicEnemy::mostToTheBottom(1) > 300) down = false;

	if (BasicEnemy::mostToTheLeft(0) < 100) army1Left = false;
	if (BasicEnemy::mostToTheRight(0) > 1500) army1Left = true;

	if (BasicEnemy::mostToTheLeft(1) < 100) army2Right = true;
	if (BasicEnemy::mostToTheRight(1) > 1500) army2Right = false;

	if (BasicEnemy::mostToTheLeft(2) < 925) army3Left = false;
	if (BasicEnemy::mostToTheRight(3) > 675) army4Right = false;
}

void LevelEvent::level33()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 1 && down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheBottom() > 400) down = false;
}

void LevelEvent::level34()
{
	static bool down = true;
	static bool army1Right = true;
	static bool army2Left = true;
	static bool army4Left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		down = true;
		army1Right = true;
		army2Left = true;
		army4Left = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && army1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 0 && !army1Right) BasicEnemy::enemy[i]->moveLeft();

		if (BasicEnemy::enemy[i]->id == 1 && army2Left) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 1 && !army2Left) BasicEnemy::enemy[i]->moveRight();

		if (BasicEnemy::enemy[i]->id == 2 && down) BasicEnemy::enemy[i]->moveDown();

		if (BasicEnemy::enemy[i]->id == 3 && army4Left) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 3 && !army4Left) BasicEnemy::enemy[i]->moveRight();
	}

	if (BasicEnemy::mostToTheBottom(2) > 450) down = false;

	if (BasicEnemy::mostToTheRight(0) > 1550) army1Right = false;
	if (BasicEnemy::mostToTheLeft(0) < 50) army1Right = true;

	if (BasicEnemy::mostToTheRight(1) > 1550) army2Left = true;
	if (BasicEnemy::mostToTheLeft(1) < 50) army2Left = false;

	if (BasicEnemy::mostToTheRight(3) > 1550) army4Left = true;
	if (BasicEnemy::mostToTheLeft(3) < 50) army4Left = false;
}

void LevelEvent::level35()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
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

void LevelEvent::level36()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
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

void LevelEvent::level37()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 1 && down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheBottom() > 300) down = false;
}

void LevelEvent::level38()
{
	static bool down = true;
	static bool army1Right = true;
	static bool army2Left = true;

	static bool army3Right = true;
	static bool army4Left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		down = true;
		army1Right = true;
		army2Left = true;
		army3Right = true;
		army4Left = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();

		if (BasicEnemy::enemy[i]->id == 1 && army1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 2 && army2Left) BasicEnemy::enemy[i]->moveLeft();

		if (BasicEnemy::enemy[i]->id == 3 && army3Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 4 && army4Left) BasicEnemy::enemy[i]->moveLeft();
	}

	if (BasicEnemy::mostToTheBottom(0) > 150) down = false;

	if (BasicEnemy::mostToTheRight(1) > 100) army1Right = false;
	if (BasicEnemy::mostToTheLeft(2) < 1500) army2Left = false;

	if (BasicEnemy::mostToTheRight(3) > 600) army3Right = false;
	if (BasicEnemy::mostToTheLeft(4) < 1000) army4Left = false;
}

void LevelEvent::level39()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 1 && down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheBottom() > 300) down = false;
}

void LevelEvent::level40()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
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

void LevelEvent::level41()
{
	static bool army1Left = true;
	static bool army2Right = true;
	static bool army3Left = true;
	static bool army4Right = true;
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		army1Left = true;
		army2Right = true;
		army3Left = true;
		army4Right = true;
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();
		if (BasicEnemy::enemy[i]->id == 1 && down) BasicEnemy::enemy[i]->moveDown();
		if (BasicEnemy::enemy[i]->id == 4 && down) BasicEnemy::enemy[i]->moveDown();

		if (BasicEnemy::enemy[i]->id == 0 && army1Left && !down) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 0 && !army1Left && !down) BasicEnemy::enemy[i]->moveRight();

		if (BasicEnemy::enemy[i]->id == 1 && army2Right && !down) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 1 && !army2Right && !down) BasicEnemy::enemy[i]->moveLeft();

		if (BasicEnemy::enemy[i]->id == 2 && army3Left) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 3 && army4Right) BasicEnemy::enemy[i]->moveRight();
	}

	if (BasicEnemy::mostToTheBottom(0) > 300 || BasicEnemy::mostToTheBottom(1) > 300) down = false;

	if (BasicEnemy::mostToTheLeft(0) < 100) army1Left = false;
	if (BasicEnemy::mostToTheRight(0) > 1500) army1Left = true;

	if (BasicEnemy::mostToTheLeft(1) < 100) army2Right = true;
	if (BasicEnemy::mostToTheRight(1) > 1500) army2Right = false;

	if (BasicEnemy::mostToTheLeft(2) < 925) army3Left = false;
	if (BasicEnemy::mostToTheRight(3) > 675) army4Right = false;
}

void LevelEvent::level42()
{
	static bool army1Right = true;
	static bool army2Left = true;

	static bool army3Right = true;
	static bool army4Left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		army1Right = true;
		army2Left = true;
		army3Right = true;
		army4Left = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 1 && army1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 2 && army2Left) BasicEnemy::enemy[i]->moveLeft();

		if (BasicEnemy::enemy[i]->id == 3 && army3Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 4 && army4Left) BasicEnemy::enemy[i]->moveLeft();
	}

	if (BasicEnemy::mostToTheRight(1) > 300) army1Right = false;
	if (BasicEnemy::mostToTheLeft(2) < 1300) army2Left = false;

	if (BasicEnemy::mostToTheRight(3) > 300) army3Right = false;
	if (BasicEnemy::mostToTheLeft(4) < 1300) army4Left = false;
}

void LevelEvent::level43()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheBottom() > 350) down = false;
}

void LevelEvent::level44()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
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

void LevelEvent::level45()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
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

void LevelEvent::level46()
{
	static bool down = true;
	static bool army1Right = true;
	static bool army2Left = true;

	static bool army3Right = true;
	static bool army4Left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		down = true;
		army1Right = true;
		army2Left = true;
		army3Right = true;
		army4Left = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();

		if (BasicEnemy::enemy[i]->id == 1 && army1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 2 && army2Left) BasicEnemy::enemy[i]->moveLeft();

		if (BasicEnemy::enemy[i]->id == 3 && army3Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 4 && army4Left) BasicEnemy::enemy[i]->moveLeft();
	}

	if (BasicEnemy::mostToTheBottom(0) > 350) down = false;

	if (BasicEnemy::mostToTheRight(1) > 300) army1Right = false;
	if (BasicEnemy::mostToTheLeft(2) < 1300) army2Left = false;

	if (BasicEnemy::mostToTheRight(3) > 300) army3Right = false;
	if (BasicEnemy::mostToTheLeft(4) < 1300) army4Left = false;
}

void LevelEvent::level47()
{
	static bool army1Right = true;
	static bool army2Left = true;
	static bool army3Right = true;
	static bool army4Left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		army1Right = true;
		army2Left = true;
		army3Right = true;
		army4Left = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && army1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 0 && !army1Right) BasicEnemy::enemy[i]->moveLeft();

		if (BasicEnemy::enemy[i]->id == 1 && army2Left) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 1 && !army2Left) BasicEnemy::enemy[i]->moveRight();

		if (BasicEnemy::enemy[i]->id == 2 && army3Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 2 && !army3Right) BasicEnemy::enemy[i]->moveLeft();

		
		if (BasicEnemy::enemy[i]->id == 3 && army4Left) BasicEnemy::enemy[i]->moveLeft();
		if (BasicEnemy::enemy[i]->id == 3 && !army4Left) BasicEnemy::enemy[i]->moveRight();
	}

	if (BasicEnemy::mostToTheRight(0) > 1550) army1Right = false;
	if (BasicEnemy::mostToTheLeft(0) < 50) army1Right = true;

	if (BasicEnemy::mostToTheRight(1) > 1550) army2Left = true;
	if (BasicEnemy::mostToTheLeft(1) < 50) army2Left = false;

	if (BasicEnemy::mostToTheRight(2) > 1550) army3Right = false;
	if (BasicEnemy::mostToTheLeft(2) < 50) army3Right = true;

	if (BasicEnemy::mostToTheRight(3) > 1550) army4Left = true;
	if (BasicEnemy::mostToTheLeft(3) < 50) army4Left = false;
}

void LevelEvent::level48()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		down = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();
	}

	if (BasicEnemy::mostToTheBottom() > 500) down = false;
}

void LevelEvent::level49()
{
	static bool down = true;
	static bool army1Right = true;
	static bool army2Left = true;

	static bool army3Right = true;
	static bool army4Left = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
	{
		down = true;
		army1Right = true;
		army2Left = true;
		army3Right = true;
		army4Left = true;
	}
	prevTime = clock();

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->id == 0 && down) BasicEnemy::enemy[i]->moveDown();

		if (BasicEnemy::enemy[i]->id == 1 && army1Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 2 && army2Left) BasicEnemy::enemy[i]->moveLeft();

		if (BasicEnemy::enemy[i]->id == 3 && army3Right) BasicEnemy::enemy[i]->moveRight();
		if (BasicEnemy::enemy[i]->id == 4 && army4Left) BasicEnemy::enemy[i]->moveLeft();
	}

	if (BasicEnemy::mostToTheBottom(0) > 150) down = false;

	if (BasicEnemy::mostToTheRight(1) > 100) army1Right = false;
	if (BasicEnemy::mostToTheLeft(2) < 1500) army2Left = false;	

	if (BasicEnemy::mostToTheRight(3) > 650) army3Right = false;
	if (BasicEnemy::mostToTheLeft(4) < 950) army4Left = false;
}

void LevelEvent::level50()
{
	static bool down = true;

	static clock_t prevTime = clock();
	if (clock() - prevTime > 5000)
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

