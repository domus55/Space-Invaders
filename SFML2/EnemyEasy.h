#pragma once

#include "BasicEnemy.h"

class EnemyEasy : public BasicEnemy
{
public:
	EnemyEasy(float posX, float posY, int level, int id);
	static void create(float posX, float posY, int level, int id = -1);
};
