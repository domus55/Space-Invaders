#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Player.h"

class Background
{
	static float dynamicBackgroundSpeed; // Prêdkoœæ poruszania siê t³a góra-dó³

	static sf::Texture image;
	static sf::Sprite background;
	static sf::Texture image2;
	static sf::Sprite background2;
public:
	static void render(); // Renderowanie t³a
	static void create(); // Wyœwietlanie t³a
	static void animatedBackgroundHorizontal(); // Ruchome t³o wzglêdem Player'a
	static void animatedBackgroundVertical(); // P³ywaj¹ce t³o góra-dó³
};