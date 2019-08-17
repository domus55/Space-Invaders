#include "EnemyEasy.h"

EnemyEasy::EnemyEasy(float x, float y)
	: BasicEnemy()
{
	hp = 3;
	speed = 1;
	shootDmg = 1;
	shootSpeed = 1;
	shootDelay = 1;

	sprite.setScale(1, 1);						//ustawia skale sprajta(2 - jest wiêkszy, 0.5 - jest mniejszy)
	texture.loadFromFile("Images/dot.png");		//³aduje teksture
	sprite.setTexture(texture);					//ustawia teksture sprajtu
	
	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(x, y);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;
}

void EnemyEasy::update()
{
	//sprite.setPosition(sprite.getPosition().x + 1 * GameInfo::getDeltaTime(), sprite.getPosition().y);
}

void EnemyEasy::render()
{
	Window::window.draw(sprite);
}

void EnemyEasy::create(float posX, float posY)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyEasy>(posX, posY));
}

