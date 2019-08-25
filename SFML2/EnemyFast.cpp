#include "EnemyFast.h"

EnemyFast::EnemyFast(float x, float y, int level, int id)
	: BasicEnemy(id)
{
	if (level == 1)
	{
		speed = 0.2;
		shootSpeed = 2.5;
		randShootDelay = 2000;

		sprite.setScale(0.45, 0.45);			//ustawia skale sprajta(2 - jest wi�kszy, 0.5 - jest mniejszy)

		hitbox1.setScale(0.3, 0.65);
		hitbox1pos.x = 0;
		hitbox1pos.y = 10;

		hitbox2.setScale(0.2, 0.75);
		hitbox2pos.x = 25;
		hitbox2pos.y = -5;

		hitbox3.setScale(0.2, 0.75);
		hitbox3pos.x = -25;
		hitbox3pos.y = -5;
	}

	hp = 1;
	shootDelay = 5000;
	shootType = 2;
	shootScale = 0.75;

	texture.loadFromFile("Images/EnemyFast.png");		//�aduje teksture
	sprite.setTexture(texture);							//ustawia teksture sprajtu

	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(x, y);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;
}

void EnemyFast::create(float posX, float posY, int level, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyFast>(posX, posY, level, id));
}