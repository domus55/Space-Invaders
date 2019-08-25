#pragma once

#include "BasicEnemy.h"

class EnemyFast : public BasicEnemy
{
public:
	EnemyFast(float posX, float posY, int level, int id);
	static void create(float posX, float posY, int level, int id = -1);
};
