#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.h"
#include "Window.h"
#include <iostream>

class Explosion
{
	static int animation;
	int animationObject;
	sf::Texture texture;
	sf::Sprite sprite;
	static sf::SoundBuffer soundBuffer;
	sf::Sound sound;
	int deltaTime;
	int timeDelay;	//odstêp po jakim eksplozja sie zacznie
	
public:
	static std::vector < std::shared_ptr <Explosion> > explosion;
	bool destroyed;

	Explosion(float x, float y, float scale = 1, float timeScale = 1, int timeDelay = 0);
	static void loadAnimation();
	static void create(sf::Vector2f position, float scale = 1, float timeScale = 1, int timeDelay = 0);
	static void create(float x, float y, float scale = 1, float timeScale = 1, int timeDelay = 0);
	static void renderAll();
	void render(int explosionNumber);
};