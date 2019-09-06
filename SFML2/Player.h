#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include "Window.h"
#include "GameInfo.h"
#include "Shoot.h"
#include "Collider.h"
#include <string>
#include "BasicEnemy.h"
#include "LevelManager.h"
#include "Particle.h"
#include "Explosion.h"
#include "GameHud.h"

class Player
{
	float shootSpeed; // predkosc strzalu
	float shootDuration; // czestotliwosc wystrzalu
	float speed; // predkosc playera
	float hitbox2PosY;
	static bool renderHitbox;
	sf::Texture playerModel;
	sf::Texture playerModelLighted;
	sf::Texture hitboxTexture;
	sf::Sprite hitbox1;
	sf::Sprite hitbox2;
	sf::Texture heart;
	sf::Texture halfHeart;
	sf::Texture emptyHeart;
	sf::Sound playerShootSound;
	sf::Sound playerDeathSound;
	sf::SoundBuffer playerShootSoundBuffer;
	sf::SoundBuffer playerDeathSoundBuffer;
	static sf::Font font;
	static sf::Text text;
	bool shooted;
	bool deathDelay;
	bool renderDeath;
	bool checkDeathFx;
	bool canMove;
	bool canShoot;
	bool light;

public:
	Player();

	int shootAmmount;			// iloœæ strza³ów
	int hp;						// ¿ycie gracza
	static bool blockShoots;	// blokowanie strza³ów wszystkich obiektów
	sf::Sprite drawPlayerModel;
	sf::Sprite drawHeartModel1;
	sf::Sprite drawHeartModel2;
	sf::Sprite drawHeartModel3;

	static Player player;		// obiekt player
	static void render();		// render player'a
	static void update();		// zmiana pozycji, sprawdzenie czy strzela
	void playerMove();			// ruch gracza
	void playerShoot();			// strzal gracza
	void checkCollision();		// kolizja
	void playerHp();			// ¿ycie gracza
	void playerShooted();		// postrzelony gracz
	void playerDeath();			// œmieræ gracza
	void playerDeathTime();		// dzia³ania w okresie trwania œmierci
	void addHp();				// wywolywana po zebraniu serduszka
	void addShootDelay();		// wywolywana po zebraniu powerup'a
	void addShootSpeed();		// wywolywana po zebraniu powerup'a
	void addShootAmmount();		// wywolywana po zebraniu powerup'a
	void sizeDown();			// wywolywana po zebraniu powerup'a
	void deathFx();				// wybuch i particle po œmierci
	void resetStats();			// przywrócenie bazowych statystyk
	void playerLighted();		// oœwietlenie statku
};