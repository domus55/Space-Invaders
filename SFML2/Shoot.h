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
	static std::vector < std::shared_ptr <Shoot> > shoot;	//inteligantna tablica w kt�rej b�d� wszystkie pociski

private:
	float dmg;			//obra�enia pocisku
	sf::Vector2f speed;	//pr�dko�� pocisku
	sf::Vector2f size;	//wielko�� pocisku
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Shoot(float positionX, float positionY, float speedX, float speedY, float dmg);
	static void create(sf::Vector2f position, sf::Vector2f speed, float dmg);						//tworzy pocisk
	static void create(float positionX, float positionY, float speedX, float speedY, float dmg);	//tworzy pocisk
	static void updateAll();						//przesuwa wszystkie pociski i sprawdza ich kolizje
	static void renderAll();						//renderuje wszystkie pociski										

private:
	void update();
	void render();
};