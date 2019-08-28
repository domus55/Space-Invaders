#pragma once

#include "BasicEnemy.h"
#include "Player.h"

class EnemyTrackingShots : public BasicEnemy
{
public:
	EnemyTrackingShots(float posX, float posY, int level, int id);
	static void create(float posX, float posY, int level, int id = -1);

protected:
	sf::Vector2f hitbox4pos;
	sf::CircleShape hitbox4;

	void update(int enemyNumber);
	void checkCollision(int enemyNumber);
	void shoot();
	void rotate();
	void render();
};
