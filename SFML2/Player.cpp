#include "Player.h"

Player Player::player;

void Player::render()
{
	Window::window.draw(Player::player.drawPlayerModel);
}

void Player::create()
{
	Player::player.speed = 0.5;
	Player::player.playerModel.loadFromFile("Images/dot.png");
	Player::player.drawPlayerModel.setTexture(Player::player.playerModel);
	Player::player.drawPlayerModel.setPosition(1600 / 2, 800);
}

void Player::update()
{
	Player::player.playerMove();
}

void Player::playerMove()
{
	sf::Vector2f pos;
	pos = drawPlayerModel.getPosition();

	if (pos.x <= 1590 && pos.x >= 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) pos.x += GameInfo::getDeltaTime() * speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) pos.x -= GameInfo::getDeltaTime() * speed;
	}

	else if (pos.x <= 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) pos.x += GameInfo::getDeltaTime() * speed;
	}

	else if (pos.x <= 1600)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) pos.x -= GameInfo::getDeltaTime() * speed;
	}

	drawPlayerModel.setPosition(pos);
}