#include "EnemyRocketMan.h"

EnemyRocketMan::EnemyRocketMan(float x, float y, int level, int id)
	: BasicEnemy(id)
{
	if (level == 1)
	{
		speed = 0.1;
		shootSpeed = 1;
		randShootDelay = 2000;
	}

	sprite.setScale(0.3, 0.3);

	hitbox1.setScale(0.35, 1);
	hitbox1pos.x = -50;
	hitbox1pos.y = 10;

	hitbox2.setScale(0.5, 0.7);
	hitbox2pos.x = 0;
	hitbox2pos.y = 0;

	hitbox3.setScale(0.35, 1);
	hitbox3pos.x = 50;
	hitbox3pos.y = 10;

	hp = 5;
	shootDelay = 5000;
	shootType = 2; // Tu ma byc zmieniony na nowy typ strzalu - rakiete
	shootScale = 1;

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

