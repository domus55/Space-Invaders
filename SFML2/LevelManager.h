#pragma once

#include <string>
#include "Animation.h"
#include "BasicEnemy.h"
#include "EnemyEasy.h"
#include "EnemyMedium.h"
#include "EnemyTank.h"
#include "EnemyFast.h"
#include "EnemyFidgetSpinner.h"
#include "EnemyInvisible.h"
#include "EnemyRocketMan.h"
#include "EnemyTrackingShots.h"
#include "BossBrown.h"
#include "BossBlack.h"
#include "BossGold.h"
#include "BossBlue.h"

class LevelManager {
public:
	static int actualLevel;

	static void create();
	static void update();	//sprawdza czy s� jacy� przeciwnicy �ywi, jak nie to zaczyna nowy poziom
	static void render();
private:
	static sf::Font font;
	static sf::Text text;
	static bool animation;
	
	static void nextLevel();
	static void level1();
	static void level2();
	static void level3();
	static void level4();
	static void level5();
	static void level6();
	static void level7();
	static void level8();
	static void level9();
	static void level10();
	static void level11();
	static void level12();
	static void level13();
	static void level14();
	static void level15();
	static void level16();
	static void level17();
	static void level18();
	static void level19();
	static void level20();
	static void level21();
	static void level22();
	static void level23();
	static void level24();
	static void level25();
	static void level26();
	static void level27();
	static void level28();
	static void level29();
	static void level30();
	static void level31();
	static void level32();
	static void level33();
	static void level34();
	static void level35();
	static void level36();
	static void level37();
	static void level38();
	static void level39();
	static void level40();
	static void level41();
	static void level42();
	static void level43();
	static void level44();
	static void level45();
	static void level46();
	static void level47();
	static void level48();
	static void level49();
	static void level50();
};
