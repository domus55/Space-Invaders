#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"

class Background
{
	sf::Texture image;
	sf::Sprite background;
	Background();
	void render();
};