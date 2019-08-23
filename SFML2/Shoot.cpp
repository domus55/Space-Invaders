#include "Shoot.h"

std::vector < std::shared_ptr <Shoot> > Shoot::shoot;

Shoot::Shoot(float positionX, float positionY, float speedX, float speedY, bool player, int type, float shootScale)
{
	this->dmg = 1;
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

	double angleInRadian = atan2((double)speedY, (double)speedX); //angle in radian
	double angleInDegree = angleInRadian * 180 / 3.141592653589793238463; //angle in degree

	sprite.setRotation(angleInDegree);

	sf::Vector2u size = texture.getSize();
	sprite.setOrigin(size.x / 2, size.y / 2);

	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;
}

void Shoot::create(sf::Vector2f position, sf::Vector2f speed, bool player, int type, float shootScale)
{
	Shoot::shoot.push_back(std::make_shared <Shoot>(position.x, position.y, speed.x, speed.y, player, type, shootScale));
}

void Shoot::create(float positionX, float positionY, float speedX, float speedY, bool player, int type, float shootScale)
{
	Shoot::shoot.push_back(std::make_shared <Shoot>(positionX, positionY, speedX, speedY, player, type, shootScale));
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
	
	shootDestroy(shootNumber);	//musi byc na ko�cu motedy, bo mo�e usun�� obiekt
}

void Shoot::render()
{
	Window::window.draw(sprite);
}

void Shoot::shootDestroy(int shootNumber)
{
	sf::Vector2f pos;
	pos = sprite.getPosition();

	//   Ponad map� ||   Pod map�  || lewo mapa || prawo mapa //
	if (pos.y < -50 || pos.y > 950 || pos.x < 0 || pos.x > 1600)
	{
		shoot.erase(shoot.begin() + shootNumber);
	}
}