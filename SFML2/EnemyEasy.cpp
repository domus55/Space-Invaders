#include "EnemyEasy.h"

EnemyEasy::EnemyEasy(float x, float y, int level, int id)
	: BasicEnemy(id)
{
	if (level == 1)
	{
		speed = 0.1;
		shootSpeed = 1;
		randShootDelay = 2000;

		sprite.setScale(0.3, 0.3);			//ustawia skale sprajta(2 - jest wiêkszy, 0.5 - jest mniejszy)
	}

	if (level == 2)
	{
		speed = 0.12;
		shootSpeed = 1.2;
		randShootDelay = 600;

		sprite.setScale(0.35, 0.35);			//ustawia skale sprajta(2 - jest wiêkszy, 0.5 - jest mniejszy)
	}

	if (level == 3)
	{
		speed = 0.15;
		shootSpeed = 1.5;
		randShootDelay = 0;

		sprite.setScale(0.4, 0.4);			//ustawia skale sprajta(2 - jest wiêkszy, 0.5 - jest mniejszy)
	}

	hp = 1;
	shootDelay = 3000;
	shootType = 2;
	shootScale = 1;
							
	texture.loadFromFile("Images/EnemyEasy.png");		//³aduje teksture
	sprite.setTexture(texture);							//ustawia teksture sprajtu
	
	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(x, y);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;
}

void EnemyEasy::update(int enemyNumber)
{
	shoot();
	checkCollision(enemyNumber);	//musi byc na koncu metody, bo moze usunac obiekt
}

void EnemyEasy::render()
{
	Window::window.draw(sprite);
}

void EnemyEasy::create(float posX, float posY, int level, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyEasy>(posX, posY, level, id));
}

