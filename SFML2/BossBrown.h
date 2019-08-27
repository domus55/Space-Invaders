#pragma once

#include "BasicBoss.h"
#include "PowerUp.h"

class BossBrown : public BasicBoss
{
	sf::Vector2f hitbox4pos;
	sf::Vector2f hitbox5pos;
	sf::RectangleShape hitbox4;
	sf::RectangleShape hitbox5;

	bool haveRightWing;
	bool haveLeftWing;

public:
	BossBrown(float posX, float posY, int id);
	static void create(float posX, float posY, int id = -1);
	void render();
	void checkCollision(int enemyNumber);
	void shoot();
	void destroy();
	void createLeftWingParticle();
	void createRightWingParticle();
};
