#include "BasicEnemy.h"

std::vector < std::shared_ptr <BasicEnemy> > BasicEnemy::enemy;

BasicEnemy::BasicEnemy()
{
	hp = 3;
	speed = 1;
	shootDmg = 1;
	shootSpeed = 1;
	shootDelay = 1;
}

void BasicEnemy::updateAll()
{
	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		BasicEnemy::enemy[i]->update(i);
	}
}

void BasicEnemy::renderAll()
{
	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		BasicEnemy::enemy[i]->render();
	}
}

void BasicEnemy::checkCollision(int enemyNumber)
{
	for (int i = Shoot::shoot.size() - 1; i >= 0; i--)
	{
		if (Collider::checkCollision(sprite, Shoot::shoot[i]->sprite))
		{
			hp -= Shoot::shoot[i]->getDmg();
			Shoot::shoot.erase(Shoot::shoot.begin() + i);
		}
	}

	if (hp <= 0) enemy.erase(enemy.begin() + enemyNumber);
}
