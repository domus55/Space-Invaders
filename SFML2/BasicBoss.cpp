#include "BasicBoss.h"

BasicBoss::BasicBoss(int id)
	: BasicEnemy(id)
{
	texture1.loadFromFile("images/HUD/hp1.png");
	texture2.loadFromFile("images/HUD/hp2.png");
	hp1.setTexture(texture1);
	hp2.setTexture(texture2);
	hp1.setOrigin(52, 11);
	hp2.setOrigin(50, 10);

	hp1.setScale(5, 1.5);
	hp1.setPosition(800, 50);
	hp2.setPosition(800, 50);
}

void BasicBoss::render()
{
	Window::window.draw(sprite);
	renderHp();

	if (renderHitbox)
	{
		Window::window.draw(hitbox1);
		Window::window.draw(hitbox2);
		Window::window.draw(hitbox3);
	}
}

void BasicBoss::renderHp()
{
	//hp1.setScale(5, 1.5);
	hp2.setScale(hp / maxHp * 5, 1.5);
	Window::window.draw(hp1);
	Window::window.draw(hp2);
}
