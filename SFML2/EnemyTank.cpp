#include "EnemyTank.h"

EnemyTank::EnemyTank(float x, float y, int level, int id)
	: BasicEnemy(id)
{
	if (level == 1)
	{
		speed = 0.1;
		shootSpeed = 1;
		randShootDelay = 2000;

		sprite.setScale(0.45, 0.45);			//ustawia skale sprajta(2 - jest wiêkszy, 0.5 - jest mniejszy)

		hitbox1.setScale(1.2, 1);
		hitbox1pos.x = 0;
		hitbox1pos.y = 40;

		hitbox2.setScale(0.4, 1);
		hitbox2pos.x = 80;
		hitbox2pos.y = 0;

		hitbox3.setScale(0.4, 1);
		hitbox3pos.x = -80;
		hitbox3pos.y = 0;
	}

	hp = 10;
	shootDelay = 5000;
	shootType = 2;
	shootScale = 1.5;

	texture.loadFromFile("Images/EnemyTank.png");		//³aduje teksture
	sprite.setTexture(texture);							//ustawia teksture sprajtu

	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(x, y);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;
}

void EnemyTank::create(float posX, float posY, int level, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyTank>(posX, posY, level, id));
}

