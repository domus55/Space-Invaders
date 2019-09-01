#pragma once

#include "BasicEnemy.h"

class EnemyFidgetSpinner : public BasicEnemy
{
public:
	EnemyFidgetSpinner(float posX, float posY, int level, int id);
	void update(int enemyNumber);
	static void create(float posX, float posY, int level, int id = -1);
protected:
	bool dropHp;
	float rotateSpeed;
	sf::Vector2f hitbox4pos;
	sf::CircleShape hitbox4;

	void shoot();
	void checkCollision(int enemyNumber);
	void render();
	void destroy();
};
