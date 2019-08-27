#pragma once

#include "BasicEnemy.h"

class EnemyTrackingShots : public BasicEnemy
{
public:
	EnemyTrackingShots(float posX, float posY, int level, int id);
	static void create(float posX, float posY, int level, int id = -1);
};
