#pragma once

#include "BasicEnemy.h"

class EnemyInvisible : public BasicEnemy
{
public:
	EnemyInvisible(float posX, float posY, int level, int id);
	void update(int enemyNumber);
	static void create(float posX, float posY, int level, int id = -1);
private:
	void createLeftParticle();
	void createMiddleParticle();
	void createRightParticle();
};