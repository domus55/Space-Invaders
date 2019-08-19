#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Window.h"

class Explosion
{
	static int animation;
	sf::Texture texture;
	sf::Sprite sprite;
	
public:
	static std::vector < std::shared_ptr <Explosion> > explosion;

	Explosion(float x, float y);
	static void create(float x, float y);
	static void renderAll();
	void render();
};