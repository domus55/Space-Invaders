#include "EnemyInvisible.h"

sf::Texture EnemyInvisible::texture;

EnemyInvisible::EnemyInvisible(float x, float y, int level, int id)
	: BasicEnemy(id)
{
	if (level == 1)
	{
		invisibleScale = 1;
		shootDelay = 2000;
	}

	if (level == 2)
	{
		invisibleScale = 1.5;
		shootDelay = 1200;
	}

	if (level == 3)
	{
		invisibleScale = 2;
		shootDelay = 800;
	}


	speed = 0.1;
	shootSpeed = 2.5;
	randShootDelay = 300;
	sprite.setScale(0.5, 0.5);
	sprite.setColor(sf::Color(255, 255, 20));

	hitbox1.setScale(0.5, 0.75);
	hitbox1pos.x = 0;
	hitbox1pos.y = 0;

	hitbox2.setScale(0.3, 0.4);
	hitbox2pos.x = -40;
	hitbox2pos.y = -30;

	hitbox3.setScale(0.3, 0.4);
	hitbox3pos.x = 40;
	hitbox3pos.y = -30;

	hp = 3;
	shootType = 2;
	shootScale = 1;
	invisibleDeltaTime = 0;

	static bool firstTime = true;
	if (firstTime)
	{
		texture.loadFromFile("Images/Enemies/EnemyInvisible/normal.png");
		firstTime = false;
	}
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 255, 255, 30));

	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(x, y);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;
}

void EnemyInvisible::update(int enemyNumber)
{
	invisibleDeltaTime += GameInfo::getDeltaTime();
	if (invisibleDeltaTime < 1000)
	{
		sprite.setColor(sf::Color(255, 255, 255, invisibleDeltaTime / 50));
	}
	else if (invisibleDeltaTime >= 1000 && invisibleDeltaTime < 4000)	//widzialny
	{
		sprite.setColor(sf::Color(255, 255, 255, 20));
	}
	else if (invisibleDeltaTime >= 4000 && invisibleDeltaTime < 5000)
	{
		sprite.setColor(sf::Color(255, 255, 255, (invisibleDeltaTime - 5000) / -50));
	}
	else if (invisibleDeltaTime >= 5000 && invisibleDeltaTime < 8000 * invisibleScale)	//niewidzialny
	{
		sprite.setColor(sf::Color(255, 255, 255, 0));
	}
	else if (invisibleDeltaTime >= 8000 * invisibleScale) invisibleDeltaTime -= 8000 * invisibleScale;

	shoot();
	checkCollision(enemyNumber);	//musi byc na koncu metody, bo moze usunac obiekt
}

void EnemyInvisible::create(float posX, float posY, int level, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyInvisible>(posX, posY, level, id));
}
