#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <math.h>
#include "Window.h"
#include "GameInfo.h"
#include <iostream>

class Shoot
{
public:
	static std::vector < std::shared_ptr <Shoot> > shoot;	//inteligantna tablica w której bêd¹ wszystkie pociski
	sf::Sprite sprite;

private:
	float dmg;			//obra¿enia pocisku
	sf::Vector2f speed;	//prêdkoœæ pocisku
	sf::Vector2f size;	//wielkoœæ pocisku
	sf::Texture texture;
	

public:
	Shoot(float positionX, float positionY, float speedX, float speedY, float dmg);
	static void create(sf::Vector2f position, sf::Vector2f speed, float dmg);						//tworzy pocisk
	static void create(float positionX, float positionY, float speedX, float speedY, float dmg);	//tworzy pocisk
	static void updateAll();						//przesuwa wszystkie pociski i sprawdza ich kolizje
	static void renderAll();						//renderuje wszystkie pociski		
	float getDmg();

private:
	void update(int shootNumber);
	void render();
	void shootDestroy(int shootNumber);
};
