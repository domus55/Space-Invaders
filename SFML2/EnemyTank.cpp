#include "EnemyTank.h"
#include "PowerUp.h"

EnemyTank::EnemyTank(float x, float y, int level, int id)
	: BasicEnemy(id)
{
	this->level = level;
	switch (level)
	{
	case 1: hp = 10; leftWingHp = 3; rightWingHp = 3; break;
	case 2: hp = 20; leftWingHp = 6; rightWingHp = 6; break;
	case 3: hp = 30; leftWingHp = 9; rightWingHp = 9; break;
	}

	speed = 0.1;
	shootSpeed = 1;
	randShootDelay = 2000;

	sprite.setScale(0.45, 0.45);

	hitbox1.setScale(0.4, 1);
	hitbox1pos.x = -80;
	hitbox1pos.y = 0;

	hitbox2.setScale(1.2, 1);
	hitbox2pos.x = 0;
	hitbox2pos.y = 40;

	hitbox3.setScale(0.4, 1);
	hitbox3pos.x = 80;
	hitbox3pos.y = 0;

	shootDelay = 5000;
	shootType = 2;
	shootScale = 1.5;
	particleName = "EnemyTank";
	particleAmmount = 2;

	texture.loadFromFile("Images/Enemies/EnemyTank/normal.png");
	sprite.setTexture(texture);

	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(x, y);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;

	deltaTime2 = 0;
	deltaTime3 = 0;
}

void EnemyTank::create(float posX, float posY, int level, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyTank>(posX, posY, level, id));
}

void EnemyTank::shoot()
{
	myDeltaTime += GameInfo::getDeltaTime();

	if (myDeltaTime > shootDelay)
	{
		sf::Vector2f pos;
		pos = sprite.getPosition();
		

		if (level > 1)
		{
			if(deltaTime2 == 0) Shoot::create(pos.x, pos.y, 0, shootSpeed, false, shootType, shootScale);
			deltaTime2 += GameInfo::getDeltaTime();

			if (deltaTime2 > 800)
			{
				
				if (level > 2)
				{
					if (deltaTime3 == 0) Shoot::create(pos.x, pos.y, 0, shootSpeed, false, shootType, shootScale);
					deltaTime3 += GameInfo::getDeltaTime();
					if (deltaTime3 > 800)
					{
						Shoot::create(pos.x, pos.y, 0, shootSpeed, false, shootType, shootScale);
						myDeltaTime = 0;
						deltaTime2 = 0;
						deltaTime3 = 0;
					}
				}
				else
				{
					Shoot::create(pos.x, pos.y, 0, shootSpeed, false, shootType, shootScale);
					deltaTime2 = 0;
					myDeltaTime = 0;
				}
			}
		}
		else
		{
			Shoot::create(pos.x, pos.y, 0, shootSpeed, false, shootType, shootScale);
			myDeltaTime = 0;
		}
	}
}

void EnemyTank::destroy()
{
	Explosion::create(sprite.getPosition().x + (rand() % 50) - 25, sprite.getPosition().y + (rand() % 50) - 25, 1, 1.2);
	Explosion::create(sprite.getPosition().x + (rand() % 50) - 25, sprite.getPosition().y + (rand() % 50) - 25, 1, 1);
	Explosion::create(sprite.getPosition().x + (rand() % 50) - 25, sprite.getPosition().y + (rand() % 50) - 25, 1, 1, 100);
	Explosion::create(sprite.getPosition().x + (rand() % 50) - 25, sprite.getPosition().y + (rand() % 50) - 25, 1, 1, 50);
	Explosion::create(sprite.getPosition(), 2, 1.5, 200);

	Particle::addParticle(sprite.getPosition().x, sprite.getPosition().y, "EnemyTank", 30, 1);

	int los = rand() % 50;
	if (los == 0) PowerUp::create(sprite.getPosition(), "shootSpeed");
	if (los == 1) PowerUp::create(sprite.getPosition(), "shootDelay");
	if (los == 2) PowerUp::create(sprite.getPosition(), "hp");
	if (los == 3) PowerUp::create(sprite.getPosition(), "shootAmmount");
	if (los == 4) PowerUp::create(sprite.getPosition(), "sizeDown");
}

void EnemyTank::createLeftParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox1pos.x, sprite.getPosition().y + hitbox1pos.y, particleName, particleAmmount, 0.5);

	leftWingHp--;

	if (leftWingHp == 0)
	{
		Explosion::create(hitbox1.getPosition(), 0.8, 1);
		hitbox1pos.x += 80;
		hitbox1.setScale(0, 0);
		if(rightWingHp > 0) texture.loadFromFile("Images/Enemies/EnemyTank/brokenLeft.png");
		else texture.loadFromFile("Images/Enemies/EnemyTank/brokenBoth.png");
	}
}

void EnemyTank::createMiddleParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox2pos.x, sprite.getPosition().y + hitbox2pos.y, particleName, particleAmmount, 0.5);
}

void EnemyTank::createRightParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox3pos.x, sprite.getPosition().y + hitbox3pos.y, particleName, particleAmmount, 0.5);

	rightWingHp--;

	if (rightWingHp == 0)
	{
		Explosion::create(hitbox3.getPosition(), 0.8, 1);
		hitbox3pos.x -= 80;
		hitbox3.setScale(0, 0);
		if (leftWingHp > 0) texture.loadFromFile("Images/Enemies/EnemyTank/brokenRight.png");
		else texture.loadFromFile("Images/Enemies/EnemyTank/brokenBoth.png");
	}
}

