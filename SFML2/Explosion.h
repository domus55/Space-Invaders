#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Window.h"
#include <iostream>

class Explosion
{
	static int animation;
	int animationObject;
	sf::Texture texture;
	sf::Sprite sprite;
	
public:
	static std::vector < std::shared_ptr <Explosion> > explosion;

	Explosion(float x, float y, float scale = 1, float timeScale = 1);
	static void loadAnimation();
	static void create(sf::Vector2f position, float scale = 1, float timeScale = 1);
	static void create(float x, float y, float scale = 1, float timeScale = 1);
	static void renderAll();
	void render(int explosionNumber);
};