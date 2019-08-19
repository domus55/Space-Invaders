#include "BasicEnemy.h"

std::vector < std::shared_ptr <BasicEnemy> > BasicEnemy::enemy;

BasicEnemy::BasicEnemy(int id)
{
	hp = 3;
	speed = 0.2;
	shootDmg = 1;
	shootSpeed = 1;
	shootDelay = 1000;
	randShootDelay = 0;
	myDeltaTime = 0;
	shootType = 3;
	shootScale = 1;

	this->id = id;

	srand(time(NULL));
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

sf::Vector2f BasicEnemy::getPosition()
{
	return sprite.getPosition();
}

int BasicEnemy::mostToTheRight()
{
	int max = -10000;

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->getPosition().x > max) max = BasicEnemy::enemy[i]->getPosition().x;
	}

	return max;
}

int BasicEnemy::mostToTheLeft()
{
	int max = 10000;

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->getPosition().x < max) max = BasicEnemy::enemy[i]->getPosition().x;
	}

	return max;
}

void BasicEnemy::moveRight()
{
	sf::Vector2f pos = sprite.getPosition();
	pos.x += speed * GameInfo::getDeltaTime();
	sprite.setPosition(pos);
}

void BasicEnemy::moveLeft()
{
	sf::Vector2f pos = sprite.getPosition();
	pos.x -= speed * GameInfo::getDeltaTime();
	sprite.setPosition(pos);
}

void BasicEnemy::shoot()
{
	myDeltaTime += GameInfo::getDeltaTime();

	if (myDeltaTime > shootDelay)
	{
		sf::Vector2f pos;
		pos = sprite.getPosition();
		Shoot::create(pos.x, pos.y, 0, shootSpeed, shootDmg, false, shootType, shootScale);
		if (randShootDelay == 0) myDeltaTime = 0;
		else myDeltaTime = (std::rand() % randShootDelay) - randShootDelay/2;
	}
}

void BasicEnemy::checkCollision(int enemyNumber)
{
	for (int i = Shoot::shoot.size() - 1; i >= 0; i--)
	{
		if (Shoot::shoot[i]->playerShoot && Collider::checkCollision(sprite, Shoot::shoot[i]->sprite))
		{
			hp -= Shoot::shoot[i]->getDmg();
			Shoot::shoot.erase(Shoot::shoot.begin() + i);
		}
	}

	if (hp <= 0) enemy.erase(enemy.begin() + enemyNumber);
}
