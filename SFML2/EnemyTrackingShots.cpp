#include "EnemyTrackingShots.h"

EnemyTrackingShots::EnemyTrackingShots(float x, float y, int level, int id)
	: BasicEnemy(id)
{
	if (level == 1)
	{
		speed = 0.1;
		shootSpeed = 1;
		randShootDelay = 2000;
	}

	sprite.setScale(0.2, 0.2);

	hitbox1.setScale(0.4, 0.5);
	hitbox1pos.x = -50;
	hitbox1pos.y = -20;

	hitbox2.setScale(0.5, 0.9);
	hitbox2pos.x = 0;
	hitbox2pos.y = 10;

	hitbox3.setScale(0.4, 0.5);
	hitbox3pos.x = 50;
	hitbox3pos.y = -20;

	hp = 3;
	shootDelay = 5000;
	shootType = 2;
	shootScale = 1;

	texture.loadFromFile("Images/Enemies/trackingshots/EnemyTrackingShots.png");
	sprite.setTexture(texture);

	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(x, y);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;
}

void EnemyTrackingShots::create(float posX, float posY, int level, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyTrackingShots>(posX, posY, level, id));
}