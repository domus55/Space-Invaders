#include "Shoot.h"

std::vector < std::shared_ptr <Shoot> > Shoot::shoot;

Shoot::Shoot(float positionX, float positionY, float speedX, float speedY, float dmg, bool player, int type, float shootScale)
{
	this->dmg = dmg;
	this->speed.x = speedX;
	this->speed.y = speedY;
	this->playerShoot = player;

	switch (type)
	{
	case 1: texture.loadFromFile("Images/shoot1.png"); sprite.setScale(0.5 * shootScale, 0.5 * shootScale);	break;
	case 2: texture.loadFromFile("Images/shoot2.png"); sprite.setScale(0.4 * shootScale, 0.4 * shootScale);	break;
	case 3: texture.loadFromFile("Images/shoot3.png"); sprite.setScale(1 * shootScale, 1 * shootScale);	break;
	}

	
	sprite.setTexture(texture);

	sf::Vector2f pos(positionX, positionY);
	sprite.setPosition(pos);
	


	if (speedX == 0)
	{
		if(speedY > 0) sprite.setRotation(90);
		else sprite.setRotation(-90);
	}

	if(speedY == 0)
	{
		if(speedX > 0) sprite.setRotation(0);
		else sprite.setRotation(180);
	}

	if(speedX > 0 && speedY > 0) sprite.setRotation(45);
	if(speedX < 0 && speedY > 0) sprite.setRotation(135);
	if(speedX > 0 && speedY < 0) sprite.setRotation(-45);
	if(speedX < 0 && speedY < 0) sprite.setRotation(225);

	

	sf::Vector2u size = texture.getSize();
	sprite.setOrigin(size.x / 2, size.y / 2);

	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;
}

void Shoot::create(sf::Vector2f position, sf::Vector2f speed, float dmg, bool player, int type, float shootScale)
{
	Shoot::shoot.push_back(std::make_shared <Shoot>(position.x, position.y, speed.x, speed.y, dmg, player, type, shootScale));
}

void Shoot::create(float positionX, float positionY, float speedX, float speedY, float dmg, bool player, int type, float shootScale)
{
	Shoot::shoot.push_back(std::make_shared <Shoot>(positionX, positionY, speedX, speedY, dmg, player, type, shootScale));
}

void Shoot::updateAll()
{
	for (int i = Shoot::shoot.size() - 1; i >= 0; i--)
	{
		Shoot::shoot[i]->update(i);
	}
}

void Shoot::renderAll()
{
	for (int i = Shoot::shoot.size() - 1; i >= 0; i--)
	{
		Shoot::shoot[i]->render();
	}
}

float Shoot::getDmg()
{
	return dmg;
}

void Shoot::update(int shootNumber)
{
	sf::Vector2f newPos = sprite.getPosition();
	newPos.x += speed.x * GameInfo::getDeltaTime() * 0.1;
	newPos.y += speed.y * GameInfo::getDeltaTime() * 0.1;

	sprite.setPosition(newPos);
	
	shootDestroy(shootNumber);	//musi byc na koñcu motedy, bo mo¿e usun¹æ obiekt
}

void Shoot::render()
{
	Window::window.draw(sprite);
}

void Shoot::shootDestroy(int shootNumber)
{
	sf::Vector2f pos;
	pos = sprite.getPosition();
	if (pos.y < 0 || pos.y > 900 || pos.x < 0 || pos.x > 1600)
	{
		shoot.erase(shoot.begin() + shootNumber);
	}
}