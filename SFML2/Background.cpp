#pragma once

#include "Background.h"

sf::Texture Background::image;
sf::Sprite Background::background;

void Background::render()
{
	Window::window.draw(background);
}

void Background::create()
{
	image.loadFromFile("Images/background.jpg");
	background.setTexture(image);
}