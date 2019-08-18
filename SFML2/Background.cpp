#pragma once

#include "Background.h"

sf::Texture Background::image;
sf::Sprite Background::background;

sf::Texture Background::image2;
sf::Sprite Background::background2;

float Background::dynamicBackgroundSpeed = 0.2;

void Background::render()
{
	Window::window.draw(background);
	Window::window.draw(background2);
	Background::animatedBackgroundHorizontal();
	Background::animatedBackgroundVertical();
}

void Background::create()
{
	image.loadFromFile("Images/background.jpg");
	background.setTexture(image);
	sf::Vector2u backgroundSize = image.getSize();
	image2.loadFromFile("Images/background.jpg");
	background2.setTexture(image);
	sf::Vector2u background2Size = image.getSize();

	background.setOrigin(700, backgroundSize.y / 2);
	background.setScale(2, 2);

	background2.setOrigin(700, background2Size.y / 2);
	background2.setScale(2.f, -2.f);
	background2.setPosition(background2.getPosition().x, -1800);
}

void Background::animatedBackgroundHorizontal()
{

	sf::Vector2f playerPosition = Player::player.drawPlayerModel.getPosition(); // Pozycja gracza


	int dynamicBackground = (playerPosition.x - 800) / 800 * 100;

	background.setPosition(-dynamicBackground, background.getPosition().y);
	background2.setPosition(-dynamicBackground, background2.getPosition().y);
}

void Background::animatedBackgroundVertical()
{
	sf::Vector2f backgroundPosition = background.getPosition();
	backgroundPosition.y = backgroundPosition.y + dynamicBackgroundSpeed * GameInfo::getDeltaTime();
	background.setPosition(background.getPosition().x, backgroundPosition.y);

	sf::Vector2f background2Position = background2.getPosition();
	background2Position.y = background2Position.y + dynamicBackgroundSpeed * GameInfo::getDeltaTime();
	background2.setPosition(background2.getPosition().x, background2Position.y);

	if (backgroundPosition.y > 2700)
	{
		background.setPosition(background.getPosition().x, background2.getPosition().y - 1800);
	}

	if (background2Position.y > 2700)
	{
		background2.setPosition(background2.getPosition().x, background.getPosition().y - 1800);
	}
}