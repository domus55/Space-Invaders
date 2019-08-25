#pragma once

#include "BasicEnemy.h"

class EnemyTank : public BasicEnemy
{
public:
	EnemyTank(float posX, float posY, int level, int id);
	static void create(float posX, float posY, int level, int id = -1);
};
