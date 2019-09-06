#include "Shoot.h"
#include "Player.h"

std::vector < std::shared_ptr <Shoot> > Shoot::shoot;
bool Shoot::showHitbox = false;

Shoot::Shoot(float positionX, float positionY, float speedX, float speedY, bool player, int type, float shootScale)
{
	this->dmg = 1;
	this->speed.x = speedX;
	this->speed.y = speedY;
	this->playerShoot = player;
	this->type = type;


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

	hitbox1.setFillColor(sf::Color(0, 0, 0, 0));
	hitbox2.setFillColor(sf::Color(0, 0, 0, 0));

	hitbox1.setOutlineThickness(2);
	hitbox2.setOutlineThickness(2);

	hitbox1.setOutlineColor(sf::Color::Blue);
	hitbox2.setOutlineColor(sf::Color::Blue);

	if(type == 1) sprite.setOrigin(size.x - 45, size.y / 2);

	if (type == 1 || type == 3)
	{
		hitbox1.setRadius(24);
		hitbox1.setOrigin(24, 24);
		hitbox1.setScale(sprite.getScale());
	}
	if (type == 3)
	{
		hitbox1.setRadius(12);
		hitbox1.setOrigin(12, 12);
		hitbox1.setScale(sprite.getScale());
	}
	if (type == 2)
	{
		hitbox2.setSize(sf::Vector2f(10, 80));
		hitbox2.setOrigin(5, 40);
		hitbox2.setScale(sprite.getScale());
	}
}

Shoot::Shoot()
{
}

void Shoot::create(sf::Vector2f position, sf::Vector2f speed, bool player, int type, float shootScale)
{
	if (Player::blockShoots == false)
	{
		Shoot::shoot.push_back(std::make_shared <Shoot>(position.x, position.y, speed.x, speed.y, player, type, shootScale));
	}
}

void Shoot::create(float positionX, float positionY, float speedX, float speedY, bool player, int type, float shootScale)
{
	if (Player::blockShoots == false)
	{
		Shoot::shoot.push_back(std::make_shared <Shoot>(positionX, positionY, speedX, speedY, player, type, shootScale));
	}
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

bool Shoot::checkCollision(sf::Sprite sprite)
{
	if (type == 1 || type == 3 || type == 4) return Collider::checkCollision(sprite, hitbox1);
	if(type == 2 || type == 4) return Collider::checkCollision(sprite, hitbox2);
}

bool Shoot::checkCollision(sf::RectangleShape sprite)
{
	if (type == 1 || type == 3) return Collider::checkCollision(sprite, hitbox1);
	if (type == 2) return Collider::checkCollision(sprite, hitbox2);
	
}

bool Shoot::checkCollision(sf::CircleShape circle)
{
	if (type == 1 || type == 3) return Collider::checkCollision(hitbox1, circle);
	if (type == 2) return Collider::checkCollision(hitbox2, circle);
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

	//sprite.rotate(0.2);

	//if (type == 1)
	//{
	//	newPos.x = sf::Mouse::getPosition(Window::window).x;
	//	newPos.y = sf::Mouse::getPosition(Window::window).y;
	//}

	hitbox1.setPosition(newPos);
	hitbox2.setPosition(newPos);


	sprite.setPosition(newPos);
	
	shootDestroy(shootNumber);	//musi byc na koñcu metody, bo mo¿e usun¹æ obiekt
}

void Shoot::render()
{
	Window::window.draw(sprite);
	if (showHitbox)
	{
		if (type == 1 || type == 3) Window::window.draw(hitbox1);
		if(type == 2) Window::window.draw(hitbox2);
	}
}

void Shoot::shootDestroy(int shootNumber)
{
	sf::Vector2f pos;
	pos = sprite.getPosition();

	//   Ponad map¹ ||   Pod map¹  || lewo mapa || prawo mapa //
	if (pos.y < -50 || pos.y > 950 || pos.x < 0 || pos.x > 1600)
	{
		shoot.erase(shoot.begin() + shootNumber);
	}
}