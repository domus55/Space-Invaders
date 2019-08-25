#pragma once

#include "BasicEnemy.h"

class EnemyTank : public BasicEnemy
{
public:
	EnemyTank(float posX, float posY, int level, int id);
	static void create(float posX, float posY, int level, int id = -1);
	

private:
	int leftWingHp;
	int rightWingHp;
	int level;
	int deltaTime2;
	int deltaTime3;

	void shoot();
	void destroy();
	void createLeftParticle();
	void createMiddleParticle();
	void createRightParticle();
};
