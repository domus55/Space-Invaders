#pragma once

#include "BasicEnemy.h"

class EnemyFast : public BasicEnemy
{
	static sf::Texture texture;

public:
	EnemyFast(float posX, float posY, int level, int id);
	static void create(float posX, float posY, int level, int id = -1);
};
