#include "EnemyRocketMan.h"

EnemyRocketMan::EnemyRocketMan(float x, float y, int level, int id)
	: BasicEnemy(id)
{
	if (level == 1)
	{
		sprite.setColor(sf::Color(70, 70, 70));
		shootDelay = 6000;
		shootSpeed = 2;
	}
	if (level == 2)
	{
		sprite.setColor(sf::Color(150, 150, 150));
		shootDelay = 4000;
		shootSpeed = 3;
	}
	if (level == 3)
	{
		shootDelay = 2000;
		shootSpeed = 5;
	}

	this->level = level;

	sprite.setScale(0.45, 0.4);

	hitbox1.setScale(0.45, 1);
	hitbox1pos.x = -65;
	hitbox1pos.y = 10;

	hitbox2.setScale(0.5, 0.7);
	hitbox2pos.x = 0;
	hitbox2pos.y = 0;

	hitbox3.setScale(0.45, 1);
	hitbox3pos.x = 65;
	hitbox3pos.y = 10;

	hp = 5;
	speed = 0.1;
	shootScale = 1;
	randShootDelay = 500;

	texture.loadFromFile("Images/Enemies/RocketMan/EnemyRocketMan.png");
	sprite.setTexture(texture);

	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(x, y);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;
}

void EnemyRocketMan::create(float posX, float posY, int level, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyRocketMan>(posX, posY, level, id));
}

void EnemyRocketMan::shoot()
{
	myDeltaTime += GameInfo::getDeltaTime();

	if (myDeltaTime > shootDelay)
	{
		sf::Vector2f pos;
		pos = sprite.getPosition();
		Rocket::create(pos.x, pos.y, 0, shootSpeed, level);
		if (randShootDelay == 0) myDeltaTime = 0;
		else myDeltaTime = (std::rand() % randShootDelay) - randShootDelay / 2;
	}
}

