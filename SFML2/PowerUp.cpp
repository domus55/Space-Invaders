#include "PowerUp.h"

std::vector < std::shared_ptr <PowerUp> > PowerUp::powerUp;
sf::SoundBuffer PowerUp::powerUpSoundBuffer;

PowerUp::PowerUp(sf::Vector2f pos, std::string name)
{
	if (name == "hp") texture.loadFromFile("Images/PowerUps/hp.png");
	if (name == "shootDelay") texture.loadFromFile("Images/PowerUps/shootDelay.png");
	if (name == "shootSpeed") texture.loadFromFile("Images/PowerUps/shootSpeed.png");
	if (name == "shootAmmount") texture.loadFromFile("Images/PowerUps/shootAmmount.png");
	if (name == "sizeDown") texture.loadFromFile("Images/PowerUps/sizeDown.png");

	this->name = name;
	destroy = false;
	color = 255;

	sprite.setTexture(texture);
	sf::Vector2u size = texture.getSize();
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(pos.x, pos.y);
	sprite.setScale(0.3, 0.3);

	powerUpSound.setBuffer(powerUpSoundBuffer);
}

void PowerUp::create(sf::Vector2f pos, std::string name)
{
	PowerUp::powerUp.push_back(std::make_shared <PowerUp>(pos, name));
}

void PowerUp::create(float posX, float posY, std::string name)
{
	PowerUp::powerUp.push_back(std::make_shared <PowerUp>(sf::Vector2f(posX, posY), name));
}

void PowerUp::updateAll()
{
	for (int i = PowerUp::powerUp.size() - 1; i >= 0; i--)
	{
		PowerUp::powerUp[i]->update(i);
	}
}

void PowerUp::renderAll()
{
	for (int i = PowerUp::powerUp.size() - 1; i >= 0; i--)
	{
		PowerUp::powerUp[i]->render();
	}
}

void PowerUp::update(int powerUpNumber)
{
	sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 0.08 * GameInfo::getDeltaTime());
	if (!destroy) checkCollision();
	else disappear(powerUpNumber);
}

void PowerUp::render()
{
	Window::window.draw(sprite);
}

void PowerUp::checkCollision()
{
	if (Collider::checkCollision(sprite, Player::player.drawPlayerModel))
	{
		powerUpSound.play();

		if (name == "hp") Player::player.addHp();
		if (name == "shootDelay") Player::player.addShootDelay();
		if (name == "shootSpeed") Player::player.addShootSpeed();
		if (name == "shootAmmount") Player::player.addShootAmmount();
		if (name == "sizeDown") Player::player.sizeDown();

		destroy = true;
	}
}

void PowerUp::disappear(int powerUpNumber)
{
	color -= 0.5 * GameInfo::getDeltaTime();
	sprite.setColor(sf::Color(255, 255, 255, color));

	if (color <= 0) sprite.setColor(sf::Color(255, 255, 255, 0));
	if (color < -2500) powerUp.erase(powerUp.begin() + powerUpNumber);
}

void PowerUp::loadSound()
{
	powerUpSoundBuffer.loadFromFile("Sounds/powerUp.wav");
}


