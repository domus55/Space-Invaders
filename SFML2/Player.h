#include <SFML/Graphics.hpp>
#include "Window.h"
#include "GameInfo.h"
#include "Shoot.h"

class Player
{
	float shootDmg; // obrazenia, jakie zadaje strzal
	float shootSpeed; // predkosc strzalu
	float shootDuration; // czestotliwosc wystrzalu
	float speed; // predkosc playera
	sf::Texture playerModel;
	sf::Sprite drawPlayerModel;

public:
	static Player player; // obiekt player
	Player();
	static void render(); // render player'a
	static void update(); // zmiana pozycji, sprawdzenie czy strzela
	void playerMove(); // ruch gracza
	void playerShoot(); // strzal gracza
};