#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <math.h>
#include "Window.h"
#include "GameInfo.h"
#include "Collider.h"

class Shoot
{
public:
	static std::vector < std::shared_ptr <Shoot> > shoot;	//inteligantna tablica w której bêd¹ wszystkie pociski
	sf::Sprite sprite;
	bool playerShoot;		//je¿eli true, to oznacza ¿e strza³ wystrzeli³ gracz, je¿eli false, to bot

protected:
	static bool showHitbox;
	int type;
	float dmg;			//obra¿enia pocisku
	sf::Vector2f speed;	//prêdkoœæ pocisku
	sf::Vector2f size;	//wielkoœæ pocisku
	sf::Texture texture;
	sf::CircleShape hitbox1;
	sf::RectangleShape hitbox2;
	

public:
	Shoot(float positionX, float positionY, float speedX, float speedY, bool player, int type, float shootScale);
	Shoot();
	static void create(sf::Vector2f position, sf::Vector2f speed, bool player, int type, float shootScale = 1);						//tworzy pocisk
	static void create(float positionX, float positionY, float speedX, float speedY, bool player, int type, float shootScale = 1);	//tworzy pocisk
	static void updateAll();						//przesuwa wszystkie pociski i sprawdza ich kolizje
	static void renderAll();						//renderuje wszystkie pociski		
	bool checkCollision(sf::Sprite sprite);
	bool checkCollision(sf::RectangleShape sprite);
	bool checkCollision(sf::CircleShape sprite);
	float getDmg();

protected:
	virtual void update(int shootNumber);
	void render();
	void shootDestroy(int shootNumber);
};
