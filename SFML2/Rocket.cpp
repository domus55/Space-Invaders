#include "Rocket.h"

Rocket::Rocket(float positionX, float positionY, float speedX, float speedY, int lvl)
	:Shoot()
{
	this->dmg = 1;
	this->speed.x = speedX;
	this->speed.y = speedY;
	this->playerShoot = false;
	this->type = 3;
	switch (lvl)
	{
	case 1: explosionSize = 1; break;
	case 2: explosionSize = 1.5; break;
	case 3: explosionSize = 2; break;
	}

	texture.loadFromFile("Images/shootRocket.png");
	sprite.setScale(0.2, 0.2);
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

	hitbox1.setFillColor(sf::Color(0, 0, 0, 0));
	hitbox2.setFillColor(sf::Color(0, 0, 0, 0));

	hitbox1.setOutlineThickness(5);
	hitbox2.setOutlineThickness(2);

	hitbox1.setOutlineColor(sf::Color::Green);
	hitbox2.setOutlineColor(sf::Color::Blue);

	if (type == 1) sprite.setOrigin(size.x - 45, size.y / 2);

	hitbox1.setRadius(10);
	hitbox1.setOrigin(10, 10);
	hitbox1.setScale(sprite.getScale());

	deltaTime = 0;
}

void Rocket::create(sf::Vector2f position, sf::Vector2f speed, int lvl)
{
	Shoot::shoot.push_back(std::make_shared <Rocket>(position.x, position.y, speed.x, speed.y, lvl));
}

void Rocket::create(float positionX, float positionY, float speedX, float speedY, int lvl)
{
	Shoot::shoot.push_back(std::make_shared <Rocket>(positionX, positionY, speedX, speedY, lvl));
}

void Rocket::update(int shootNumber)
{
	sf::Vector2f newPos = sprite.getPosition();
	newPos.x += speed.x * GameInfo::getDeltaTime() * 0.1;
	newPos.y += speed.y * GameInfo::getDeltaTime() * 0.1;

	//hitbox1.setPosition(newPos);
	//hitbox2.setPosition(newPos);
	if(deltaTime < 50) sprite.setPosition(newPos);

	if (newPos.y > 800) explode(shootNumber);
	else shootDestroy(shootNumber);	//musi byc na koñcu metody, bo mo¿e usun¹æ obiekt
}

void Rocket::explode(int shootNumber)
{
	if (deltaTime == 0)
	{
		hitbox1.setPosition(sprite.getPosition());
		Explosion::create(sprite.getPosition(), 1 * explosionSize, 1.5);	//skala, czas
	}
	deltaTime += GameInfo::getDeltaTime();

	if (deltaTime < 510)
	{
		sprite.setColor(sf::Color(255, 255, 255, 255 - deltaTime * 0.5));
	}
	else sprite.setColor(sf::Color(255, 255, 255, 0));

	float scale = 0.02 * explosionSize;

	hitbox1.setScale(sf::Vector2f(deltaTime * scale, deltaTime * scale));
	if (deltaTime > 300)
	{
		hitbox1.setScale(sf::Vector2f((deltaTime - 500) * -1.5 * scale, (deltaTime - 500) * -1.5 * scale));

		if (deltaTime > 500)
		{
			shoot.erase(shoot.begin() + shootNumber);
		}
	}
}
