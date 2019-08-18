#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Player.h"

class Background
{
	static sf::Texture image;
	static sf::Sprite background;
	static sf::Texture image2;
	static sf::Sprite background2;
public:
	static void render(); // Renderowanie t�a
	static void create(); // Wy�wietlanie t�a
	static void animatedBackgroundHorizontal(); // Ruchome t�o wzgl�dem Player'a
	static void animatedBackgroundVertical(); // P�ywaj�ce t�o g�ra-d�
};