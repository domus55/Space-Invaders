#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Player.h"

class Background
{
	static sf::Texture image;
	static sf::Sprite background;
public:
	static void render(); // Renderowanie t�a
	static void create(); // Wy�wietlanie t�a
	static void animatedBackground(); // Ruchome t�o wzgl�dem Player'a
};