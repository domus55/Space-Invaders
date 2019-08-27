#pragma once

#include "BasicEnemy.h"

class EnemyRocketMan : public BasicEnemy
{
public:
	EnemyRocketMan(float posX, float posY, int level, int id);
	static void create(float posX, float posY, int level, int id = -1);
};
