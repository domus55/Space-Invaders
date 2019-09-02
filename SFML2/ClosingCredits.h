#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Window.h"
#include "LevelManager.h"
#include "Music.h"

class ClosingCredits
{
	static float time;
	static sf::Font headerFont;
	static sf::Font font;
	static sf::Text gameName;
	static sf::Text thanks;
	static sf::Text authors;
	static sf::Text authorsNames;
	static sf::RectangleShape background;

	static void textTransition();
	static void backgroundTransition();

public:
	static void create();	// Tworzenie napisów koñcowych
	static bool render();	// Renderowanie napisów koñcowych
};

