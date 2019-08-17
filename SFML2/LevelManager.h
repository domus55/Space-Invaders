#pragma once

#include "BasicEnemy.h"
#include "EnemyEasy.h"

class LevelManager {
public:
	static int acutalLevel;

	static void update();	//sprawdza czy s¹ jacyœ przeciwnicy ¿ywi, jak nie to zaczyna nowy poziom
private:
	static void nextLevel();
	static void level1();
};
