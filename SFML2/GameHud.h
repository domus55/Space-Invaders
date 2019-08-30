#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Window.h"

class GameHud
{
	static sf::Text text;
	static sf::Font font;

public:
	static void create();				// Tworzenie hud
	static void render();				// Renderowanie hud
	static void shootDelayLevel();		// Zwi�kszanie poziomu shootDelay
	static void shootSpeedLevel();		// Zwi�kszanie poziomu shootSpeed
	static void shootAmmountLevel();	// Zwi�kszanie poziomu shootAmmount
	static void sizeDownLevel();		// Zwi�kszanie poziomu sizeDown

private:
	static int shootDelay;
	static int shootSpeed;	
	static int shootAmmount;
	static int sizeDown;

	static void hud();
};