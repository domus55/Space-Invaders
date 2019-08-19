#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Window.h"
#include "GameInfo.h"
#include "Collider.h"
#include "Shoot.h"

class BasicEnemy{

public:
	static std::vector < std::shared_ptr <BasicEnemy> > enemy;	//inteligantna tablica w której bêd¹ wszyscy dziedziczeni przeciwnicy
	int id;				//id danego przeciwnika, umozliwia poruszanie ich

protected:
	sf::Vector2f size;		//szerokosc i wysokosc statku w pikselach
	float hp;				//iloœæ ¿ycia
	float speed;			//prêdkoœæ przeciwnika
	float shootDmg;			//obra¿enia zadawane przez strza³y
	float shootSpeed;		//prêdkoœæ strza³u
	float shootScale;		//okresla wielkosc strzalu
	int shootDelay;			//odstêp miêdzy strza³ami w milisekundach
	int randShootDelay;		//gdy jest równy 0, wszystkie statki strzalaj¹ jednoczeœnie, czym wiêkszy, tym bardziej losowo bêd¹ strzelaæ
	int myDeltaTime;		//zmienna wykorzystywana, aby strzaly byly stworzone w odpowiednim odstepie, nie tykac
	int shootType;			//rodzaj textury pocisku, od 1 do 3

	sf::Texture texture;
	sf::Sprite sprite;
	
public:
	BasicEnemy(int id);
	static void updateAll();
	static void renderAll();

	static int mostToTheRight();		//zwraca pozycje x statku najbardziej wysunietago na prawo
	static int mostToTheLeft();			//zwraca pozycje x statku najbardziej wysunietago na lewo

	sf::Vector2f getPosition();
	void moveRight();		//porusza statek w prawo
	void moveLeft();		//porusza statek w lewo

protected:
	virtual void render() = 0;
	virtual void update(int enemyNumber) = 0;

	void shoot();
	void checkCollision(int enemyNumber);
};