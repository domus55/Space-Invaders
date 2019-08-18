#include "Player.h"

Player Player::player;

Player::Player()
{
	shootSpeed = 5;
	shootDmg = 1;
	shootDuration = 1000;
	speed = 0.5;
	hp = 3;

	playerModel.loadFromFile("Images/spaceship.png");
	drawPlayerModel.setTexture(playerModel);
	drawPlayerModel.setPosition(1600 / 2, 800);
	sf::Vector2u size = playerModel.getSize();
	drawPlayerModel.setOrigin(size.x / 2, size.y / 2);
	drawPlayerModel.setScale(0.2, 0.2);
}

void Player::render()
{
	Window::window.draw(Player::player.drawPlayerModel);
}

void Player::update()
{
	Player::player.playerMove();
	Player::player.playerShoot();
	Player::player.checkCollision();
}

void Player::playerMove()
{
	sf::Vector2f pos;
	pos = drawPlayerModel.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) pos.x -= GameInfo::getDeltaTime() * speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) pos.x += GameInfo::getDeltaTime() * speed;

	if (pos.x < 80) pos.x = 80;
	if (pos.x > 1520) pos.x = 1520;

	drawPlayerModel.setPosition(pos);
}


void Player::playerShoot()
{
	static int myDeltaTime = 0;
	myDeltaTime += GameInfo::getDeltaTime();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && myDeltaTime > shootDuration)
	{
		sf::Vector2f pos;
		pos = drawPlayerModel.getPosition();
		Shoot::create(pos.x, pos.y, 0, -shootSpeed, shootDmg, true);
		myDeltaTime = 0;
	}
}

void Player::checkCollision()
{
	for (int i = Shoot::shoot.size() - 1; i >= 0; i--)
	{
		if (Shoot::shoot[i]->playerShoot == false && Collider::checkCollision(drawPlayerModel, Shoot::shoot[i]->sprite))
		{
			hp -= Shoot::shoot[i]->getDmg();
			Shoot::shoot.erase(Shoot::shoot.begin() + i);
		}
	}
}
