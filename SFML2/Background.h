#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"

class Background
{
	static sf::Texture image;
	static sf::Sprite background;
public:
	static void render();
	static void create();
};