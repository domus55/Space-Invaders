#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Window.h"
#include "GameInfo.h"
#include "Collider.h"
#include "Shoot.h"
#include "Explosion.h"
#include "Particle.h"

class BasicEnemy{

public:
	static std::vector < std::shared_ptr <BasicEnemy> > enemy;	//inteligantna tablica w kt�rej b�d� wszyscy dziedziczeni przeciwnicy
	int id;				//id danego przeciwnika, umozliwia poruszanie ich

protected:
	sf::Vector2f size;		//szerokosc i wysokosc statku w pikselach
	std::string particleName;	//nazwa partila tworzonego po trafieniu
	float hp;				//ilo�� �ycia
	float speed;			//pr�dko�� przeciwnika
	float shootSpeed;		//pr�dko�� strza�u
	float shootScale;		//okresla wielkosc strzalu
	int particleAmmount;		//ilosc particli tworzonych po trafieniu
	int shootDelay;			//odst�p mi�dzy strza�ami w milisekundach
	int randShootDelay;		//gdy jest r�wny 0, wszystkie statki strzalaj� jednocze�nie, czym wi�kszy, tym bardziej losowo b�d� strzela�
	int myDeltaTime;		//zmienna wykorzystywana, aby strzaly byly stworzone w odpowiednim odstepie, nie tykac
	int shootType;			//rodzaj textury pocisku, od 1 do 3
	int deathDeltaTime;		//czas w milisekundach do usuniecia obiektu, domyslnie 300
	int timeToDeath;		//czas w milisekundach do usuniecia obiektu, potrzebny zeby wybuch ladnie wygladal, nie tykac
	static bool renderHitbox;

	sf::Vector2f hitbox1pos;
	sf::Vector2f hitbox2pos;
	sf::Vector2f hitbox3pos;
	sf::Texture hitboxTexture;
	sf::Sprite hitbox1;
	sf::Sprite hitbox2;
	sf::Sprite hitbox3;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Sound enemyHit;
	static sf::SoundBuffer enemyHitSoundBuffer;
	
public:
	BasicEnemy(int id);
	static void updateAll();
	static void renderAll();

	static int mostToTheRight(int id = -1);		//zwraca pozycje x statku najbardziej wysunietago na prawo
	static int mostToTheLeft(int id = -1);			//zwraca pozycje x statku najbardziej wysunietago na lewo
	static int mostToTheTop(int id = -1);			//zwraca pozycje y statku najbardziej wysunietago na gore
	static int mostToTheBottom(int id = -1);		//zwraca pozycje y statku najbardziej wysunietago na dol

	sf::Vector2f getPosition();
	void moveRight();					//porusza statek w prawo
	void moveLeft();					//porusza statek w lewo
	void moveUp();						//porusza statek w gore
	void moveDown();					//porusza statek w dol
	static void loadSound();

protected:
	virtual void render();
	virtual void update(int enemyNumber);

	virtual void shoot();
	virtual void checkCollision(int enemyNumber);
	virtual void destroy();					//metoda wykonywana, gdy przeciwnik umiera
	virtual void createLeftParticle();
	virtual void createMiddleParticle();
	virtual void createRightParticle();
};