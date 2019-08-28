#pragma once

#include "BasicEnemy.h"
#include "Rocket.h"

class EnemyRocketMan : public BasicEnemy
{
public:
	EnemyRocketMan(float posX, float posY, int level, int id);
	static void create(float posX, float posY, int level, int id = -1);
	void shoot();

private:
	int level;
};
