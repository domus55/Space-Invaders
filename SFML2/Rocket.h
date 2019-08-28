#pragma once

#include "Shoot.h"
#include "Explosion.h"

class Rocket : public Shoot
{
public:
	Rocket(float positionX, float positionY, float speedX, float speedY, int lvl);
	static void create(sf::Vector2f position, sf::Vector2f speed, int lvl);						//tworzy pocisk
	static void create(float positionX, float positionY, float speedX, float speedY, int lvl);	//tworzy pocisk
protected:
	int deltaTime;
	float explosionSize;

	void update(int shootNumber);
	void explode(int shootNumber);
};
