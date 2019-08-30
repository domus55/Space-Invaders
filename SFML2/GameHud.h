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
	static void shootDelayLevel();		// Zwiêkszanie poziomu shootDelay
	static void shootSpeedLevel();		// Zwiêkszanie poziomu shootSpeed
	static void shootAmmountLevel();	// Zwiêkszanie poziomu shootAmmount
	static void sizeDownLevel();		// Zwiêkszanie poziomu sizeDown

private:
	static int shootDelay;
	static int shootSpeed;	
	static int shootAmmount;
	static int sizeDown;

	static void hud();
};