#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "GameInfo.h"
#include "Shoot.h"
#include "Collider.h"

class Player
{
	float shootDmg; // obrazenia, jakie zadaje strzal
	float shootSpeed; // predkosc strzalu
	float shootDuration; // czestotliwosc wystrzalu
	float speed; // predkosc playera
	float hp; // zycie gracza
	sf::Texture playerModel;

public:
	sf::Sprite drawPlayerModel;
	static Player player; // obiekt player
	Player();
	static void render(); // render player'a
	static void update(); // zmiana pozycji, sprawdzenie czy strzela
	void playerMove(); // ruch gracza
	void playerShoot(); // strzal gracza
	void checkCollision();
};