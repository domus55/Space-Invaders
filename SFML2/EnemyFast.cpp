#include "EnemyFast.h"

sf::Texture EnemyFast::texture;

EnemyFast::EnemyFast(float x, float y, int level, int id)
	: BasicEnemy(id)
{

	switch (level)
	{
	case 1: shootDelay = 3000; break;
	case 2: shootDelay = 2000; break;
	case 3: shootDelay = 1000; break;
	}

	speed = 0.3;
	shootSpeed = 2.5;
	randShootDelay = 300;

	sprite.setScale(0.45, 0.45);

	hitbox1.setScale(0.3, 0.65);
	hitbox1pos.x = 0;
	hitbox1pos.y = 10;

	hitbox2.setScale(0.2, 0.75);
	hitbox2pos.x = 25;
	hitbox2pos.y = -5;

	hitbox3.setScale(0.2, 0.75);
	hitbox3pos.x = -25;
	hitbox3pos.y = -5;

	hp = 1;
	shootType = 2;
	shootScale = 0.75;

	static bool firstTime = true;
	if (firstTime)
	{
		texture.loadFromFile("Images/Enemies/EnemyFast/normal.png");
		firstTime = false;
	}
	sprite.setTexture(texture);

	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(x, y);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;

	particleName = "EnemyFast";
	particleAmmount = 12;
}

void EnemyFast::create(float posX, float posY, int level, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyFast>(posX, posY, level, id));
}