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
		BasicEnemy::enemy[i]->update();
	}
}

void BasicEnemy::renderAll()
{
	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		BasicEnemy::enemy[i]->render();
	}
}

void BasicEnemy::create(std::string name, float x, float y)
{

}
