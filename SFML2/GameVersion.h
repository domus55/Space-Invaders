#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"

class GameVersion
{
	static sf::Text text;
	static sf::Text text2;
	static sf::Font font;

public:
	static void create();
	static void render();
};