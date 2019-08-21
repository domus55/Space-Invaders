#include "EnemyMedium.h"

EnemyMedium::EnemyMedium(float x, float y, int level, int id)
	: BasicEnemy(id)
{
	if (level == 1)
	{
		shootDelay = 3000;
		sprite.setColor(sf::Color(255, 255, 255));
	}

	if (level == 2)
	{
		shootDelay = 2400;
		sprite.setColor(sf::Color(255, 230, 230));
	}

	if (level == 3)
	{
		shootDelay = 1800;
		sprite.setColor(sf::Color(255, 200, 200));
	}

	speed = 0.1;
	shootSpeed = 1.5;
	randShootDelay = 0;
	sprite.setScale(0.3, 0.3);

	hitbox1.setScale(0.5, 0.3);
	hitbox1pos.x = -60;
	hitbox1pos.y = 0;

	hitbox2.setScale(0.6, 0.55);
	hitbox2pos.x = 0;
	hitbox2pos.y = 0;

	hitbox3.setScale(0.5, 0.3);
	hitbox3pos.x = 60;
	hitbox3pos.y = 0;

	hp = 2;
	shootType = 2;
	shootScale = 1;

	texture.loadFromFile("Images/Enemies/EnemyMedium/normal.png");
	sprite.setTexture(texture);

	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(x, y);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;
}

void EnemyMedium::update(int enemyNumber)
{
	shoot();
	checkCollision(enemyNumber);	//musi byc na koncu metody, bo moze usunac obiekt
}

void EnemyMedium::create(float posX, float posY, int level, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyMedium>(posX, posY, level, id));
}

void EnemyMedium::createLeftParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox1pos.x, sprite.getPosition().y + hitbox1pos.y, "BasicEnemy", 15, 0.5);
	if (hp == 2)
	{
		hitbox1pos.x += 20;
		texture.loadFromFile("Images/Enemies/EnemyMedium/brokenLeft.png");
	}
}

void EnemyMedium::createMiddleParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox2pos.x, sprite.getPosition().y + hitbox2pos.y, "BasicEnemy", 15, 0.5);
	if (hp == 2) texture.loadFromFile("Images/Enemies/EnemyMedium/brokenMiddle.png");
}

void EnemyMedium::createRightParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox3pos.x, sprite.getPosition().y + hitbox3pos.y, "BasicEnemy", 15, 0.5);
	if (hp == 2)
	{
		hitbox3pos.x -= 20;
		texture.loadFromFile("Images/Enemies/EnemyMedium/brokenRight.png");
	}
}
