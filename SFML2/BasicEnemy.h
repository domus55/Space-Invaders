#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Window.h"
#include "GameInfo.h"
#include "Collider.h"
#include "Shoot.h"

class BasicEnemy{

public:
	static std::vector < std::shared_ptr <BasicEnemy> > enemy;	//inteligantna tablica w której bêd¹ wszyscy dziedziczeni przeciwnicy

protected:
	sf::Vector2f size;		//szerokosc i wysokosc statku w pikselach
	float hp;				//iloœæ ¿ycia
	float speed;			//prêdkoœæ przeciwnika
	float shootDmg;			//obra¿enia zadawane przez strza³y
	float shootSpeed;		//prêdkoœæ strza³u
	float shootDelay;		//odstêp miêdzy strza³ami

	sf::Texture texture;
	sf::Sprite sprite;
	
public:
	BasicEnemy();
	static void updateAll();
	static void renderAll();

protected:
	virtual void render() = 0;
	virtual void update(int enemyNumber) = 0;

	void checkCollision(int enemyNumber);
};