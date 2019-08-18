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

void Background::animatedBackground()
{
	sf::Vector2u backgroundSize = image.getSize(); // Rozmiary tla
	sf::Vector2f playerPosition = Player::player.drawPlayerModel.getPosition(); // Pozycja gracza
	background.setOrigin(700, backgroundSize.y / 2);
	//background.setPosition(1600 / 2, 900 / 2);
	background.setScale(2, 2);

	int dynamicBackground = (playerPosition.x - 800) / 800 * 100;
	background.setPosition(-dynamicBackground, 900/2);
}