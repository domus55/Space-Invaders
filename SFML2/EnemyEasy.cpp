#include "EnemyEasy.h"

EnemyEasy::EnemyEasy(float x, float y, int id)
	: BasicEnemy(id)
{
	hp = 3;
	speed = 0.1;
	shootDmg = 1;
	shootSpeed = 1;
	shootDelay = 3000;
	randShootDelay = 1000;

	sprite.setScale(0.35, 0.35);						//ustawia skale sprajta(2 - jest wi�kszy, 0.5 - jest mniejszy)
	texture.loadFromFile("Images/EnemyEasy.png");		//�aduje teksture
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

void EnemyEasy::create(float posX, float posY, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyEasy>(posX, posY, id));
}

