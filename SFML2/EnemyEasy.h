#pragma once

#include "BasicEnemy.h"

class EnemyEasy : public BasicEnemy
{
public:
	EnemyEasy(float posX, float posY);

	void update();
	void render();
	static void create(float posX, float posY);
};
