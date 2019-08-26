#include "EnemyInvisible.h"

EnemyInvisible::EnemyInvisible(float x, float y, int level, int id)
	: BasicEnemy(id)
{
	if (level == 1)
	{
		shootDelay = 3000;
		sprite.setColor(sf::Color(255, 255, 20));
	}

	if (level == 2)
	{
		shootDelay = 2400;
		sprite.setColor(sf::Color(255, 230, 10));
	}

	if (level == 3)
	{
		shootDelay = 1800;
		sprite.setColor(sf::Color(255, 200, 5));
	}

	speed = 0.1;
	shootSpeed = 1.5;
	randShootDelay = 0;
	sprite.setScale(0.5, 0.5);

	hitbox1.setScale(0.5, 0.75);
	hitbox1pos.x = 0;
	hitbox1pos.y = 0;

	hitbox2.setScale(0.3, 0.4);
	hitbox2pos.x = -40;
	hitbox2pos.y = -30;

	hitbox3.setScale(0.3, 0.4);
	hitbox3pos.x = 40;
	hitbox3pos.y = -30;

	hp = 2;
	shootType = 2;
	shootScale = 1;

	texture.loadFromFile("Images/EnemyInvisible.png");
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
	shoot();
	checkCollision(enemyNumber);	//musi byc na koncu metody, bo moze usunac obiekt
}

void EnemyInvisible::create(float posX, float posY, int level, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyInvisible>(posX, posY, level, id));
}

void EnemyInvisible::createLeftParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox1pos.x, sprite.getPosition().y + hitbox1pos.y, "BasicEnemy", 15, 0.5);
	if (hp == 2)
	{
		hitbox1pos.x += 20;
		texture.loadFromFile("Images/Enemies/EnemyInvisible/brokenLeft.png");
	}
}

void EnemyInvisible::createMiddleParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox2pos.x, sprite.getPosition().y + hitbox2pos.y, "BasicEnemy", 15, 0.5);
	if (hp == 2) texture.loadFromFile("Images/Enemies/EnemyInvisible/brokenMiddle.png");
}

void EnemyInvisible::createRightParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox3pos.x, sprite.getPosition().y + hitbox3pos.y, "BasicEnemy", 15, 0.5);
	if (hp == 2)
	{
		hitbox3pos.x -= 20;
		texture.loadFromFile("Images/Enemies/EnemyInvisible/brokenRight.png");
	}
}
