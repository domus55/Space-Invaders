#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "GameInfo.h"
#include "Shoot.h"
#include "Collider.h"
#include <string>
#include "BasicEnemy.h"
#include "LevelManager.h"

class Player
{
	float shootDmg; // obrazenia, jakie zadaje strzal
	float shootSpeed; // predkosc strzalu
	float shootDuration; // czestotliwosc wystrzalu
	float speed; // predkosc playera
	int hp; // zycie gracza
	static bool renderHitbox;
	sf::Texture playerModel;
	sf::Texture hitboxTexture;
	sf::Sprite hitbox1;
	sf::Sprite hitbox2;
	sf::Texture heart;
	sf::Texture halfHeart;
	sf::Texture emptyHeart;
	static sf::Font font;
	static sf::Text text;
	bool deathDelay;
	bool renderDeath;

public:
	sf::Sprite drawPlayerModel;
	sf::Sprite drawHeartModel1;
	sf::Sprite drawHeartModel2;
	sf::Sprite drawHeartModel3;

	static Player player; // obiekt player
	Player();
	static void render();		// render player'a
	static void update();		// zmiana pozycji, sprawdzenie czy strzela
	void playerMove();			// ruch gracza
	void playerShoot();			// strzal gracza
	void checkCollision();		// kolizja
	void playerHp();			// ¿ycie gracza
	void playerDeath();			// œmieræ gracza
	void playerDeathTime();		// dzia³ania w okresie trwania œmierci
};