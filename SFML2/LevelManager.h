#pragma once

#include <string>
#include "BasicEnemy.h"
#include "EnemyEasy.h"
#include "Animation.h"

class LevelManager {
public:
	static int actualLevel;

	static void create();
	static void update();	//sprawdza czy s¹ jacyœ przeciwnicy ¿ywi, jak nie to zaczyna nowy poziom
	static void render();
private:
	static sf::Font font;
	static sf::Text text;
	static bool animation;
	
	static void nextLevel();
	static void level1();
	static void level2();
};
