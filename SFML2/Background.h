#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Player.h"

class Background
{
	static sf::Texture image;
	static sf::Sprite background;
public:
	static void render(); // Renderowanie t³a
	static void create(); // Wyœwietlanie t³a
	static void animatedBackground(); // Ruchome t³o wzglêdem Player'a
};