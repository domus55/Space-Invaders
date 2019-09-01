#include "EnemyEasy.h"

sf::Texture EnemyEasy::texture;

EnemyEasy::EnemyEasy(float x, float y, int level, int id)
	: BasicEnemy(id)
{
	if (level == 1)
	{
		speed = 0.1;
		shootSpeed = 1;
		randShootDelay = 2000;

		sprite.setScale(0.45, 0.45);

		hitbox1.setScale(0.5, 0.3);
		hitbox1pos.x = -60;
		hitbox1pos.y = 0;

		hitbox2.setScale(0.6, 0.55);
		hitbox2pos.x = 0;
		hitbox2pos.y = 0;

		hitbox3.setScale(0.5, 0.3);
		hitbox3pos.x = 60;
		hitbox3pos.y = 0;
	}

	if (level == 2)
	{
		speed = 0.12;
		shootSpeed = 1.2;
		randShootDelay = 600;

		sprite.setScale(0.35, 0.35);

		hitbox1.setScale(0.4, 0.25);
		hitbox1pos.x = -45;
		hitbox1pos.y = 0;

		hitbox2.setScale(0.5, 0.45);
		hitbox2pos.x = 0;
		hitbox2pos.y = 0;

		hitbox3.setScale(0.4, 0.25);
		hitbox3pos.x = 45;
		hitbox3pos.y = 0;
	}

	if (level == 3)
	{
		speed = 0.15;
		shootSpeed = 1.5;
		randShootDelay = 0;

		sprite.setScale(0.25, 0.25);

		hitbox1.setScale(0.3, 0.15);
		hitbox1pos.x = -25;
		hitbox1pos.y = 0;

		hitbox2.setScale(0.3, 0.3);
		hitbox2pos.x = 0;
		hitbox2pos.y = 0;

		hitbox3.setScale(0.3, 0.15);
		hitbox3pos.x = 25;
		hitbox3pos.y = 0;
	}

	hp = 1;
	shootDelay = 3000;
	shootType = 2;
	shootScale = 1;
		
	static bool firstTime = true;
	if (firstTime)
	{
		EnemyEasy::texture.loadFromFile("Images/Enemies/EnemyEasy/normal.png");
		firstTime = false;
	}
	sprite.setTexture(EnemyEasy::texture);
	
	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(x, y);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;
}

void EnemyEasy::create(float posX, float posY, int level, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyEasy>(posX, posY, level, id));
}

