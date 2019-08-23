#pragma once

#include "BasicEnemy.h"

class BasicBoss : public BasicEnemy {

protected:
	int maxHp;		//maksymalna iloœæ ¿ycia, jak¹ mo¿e mieæ boss
	bool loadPos;

	sf::Sprite hp1;
	sf::Sprite hp2;
	sf::Texture texture1;
	sf::Texture texture2;
public:
	BasicBoss(int id);
	virtual void render();
	void renderHp();
};
