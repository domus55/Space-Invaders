#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include "GameInfo.h"
#include "Player.h"
#include "Collider.h"

class PowerUp
{
public:
	static std::vector < std::shared_ptr <PowerUp> > powerUp;

	PowerUp(sf::Vector2f pos, std::string name);
	static void create(sf::Vector2f pos, std::string name);
	static void create(float posX, float posY, std::string name);
	static void updateAll();
	static void renderAll();
	static void loadSound(); // Wczytywanie dŸwiêku podniesienia PowerUp'a

private:
	bool destroy;		//jezeli tak, to jest uruchamiana animacja znikania
	int color;
	sf::Sprite sprite;
	sf::Texture texture;
	std::string name;
	sf::Sound powerUpSound;
	static sf::SoundBuffer powerUpSoundBuffer;

	void update(int powerUpNumber);
	void render();
	void checkCollision();
	void disappear(int powerUpNumber);
};