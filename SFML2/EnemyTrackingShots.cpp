#include "EnemyTrackingShots.h"

EnemyTrackingShots::EnemyTrackingShots(float x, float y, int level, int id)
	: BasicEnemy(id)
{
	if (level == 1)
	{
		shootSpeed = 3;
		randShootDelay = 500;
		shootDelay = 1500;
	}
	if (level == 2)
	{
		shootSpeed = 4;
		randShootDelay = 300;
		shootDelay = 1000;
	}
	if (level == 3)
	{
		shootSpeed = 6;
		randShootDelay = 0;
		shootDelay = 700;
	}

	sprite.setScale(0.2, 0.2);

	hitbox1.setScale(0.0, 0.0);
	hitbox2.setScale(0.0, 0.0);
	hitbox3.setScale(0.0, 0.0);

	speed = 0.1;
	hp = 3;
	shootType = 2;
	shootScale = 1;
	particleName = "EnemyTank";
	particleAmmount = 5;

	texture.loadFromFile("Images/Enemies/trackingshots/EnemyTrackingShots.png");
	sprite.setTexture(texture);

	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(x, y);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;

	hitbox4.setRadius(35);
	hitbox4.setOrigin(35, 35);
	hitbox4.setFillColor(sf::Color(0, 0, 0, 0));
	hitbox4.setOutlineThickness(2);
	hitbox4.setOutlineColor(sf::Color::Green);
}

void EnemyTrackingShots::create(float posX, float posY, int level, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyTrackingShots>(posX, posY, level, id));
}

void EnemyTrackingShots::update(int enemyNumber)
{
	rotate();
	shoot();
	checkCollision(enemyNumber);	//musi byc na koncu metody, bo moze usunac obiekt
}

void EnemyTrackingShots::checkCollision(int enemyNumber)
{
	sf::Vector2f pos = sprite.getPosition();
	hitbox4.setPosition(pos);

	for (int i = Shoot::shoot.size() - 1; i >= 0; i--)
	{
		if (Shoot::shoot[i]->playerShoot && Shoot::shoot[i]->checkCollision(hitbox4))
		{
			createMiddleParticle();
			hp -= Shoot::shoot[i]->getDmg();
			Shoot::shoot.erase(Shoot::shoot.begin() + i);
			enemyHit.play();
		}
	}

	if (hp <= 0)
	{
		if (timeToDeath == 0)
		{
			destroy();
			timeToDeath = 1;
		}

		timeToDeath += GameInfo::getDeltaTime();
		if (timeToDeath > deathDeltaTime) enemy.erase(enemy.begin() + enemyNumber);
	}
}

void EnemyTrackingShots::shoot()
{
	myDeltaTime += GameInfo::getDeltaTime();

	if (myDeltaTime > shootDelay)
	{
		sf::Vector2f speed;
		sf::Vector2f spritePos = sprite.getPosition();
		sf::Vector2f playerPos = Player::player.drawPlayerModel.getPosition();
		speed.x = playerPos.x - spritePos.x;
		speed.y = playerPos.y - spritePos.y;

		float c1 = sqrt(pow(speed.x, 2) + pow(speed.y, 2));
		speed.x /= c1;
		speed.y /= c1;

		speed.x *= shootSpeed;
		speed.y *= shootSpeed;

		Shoot::create(spritePos, speed, false, 3);

		if (randShootDelay == 0) myDeltaTime = 0;
		else myDeltaTime = (std::rand() % randShootDelay) - randShootDelay / 2;
	}
}

void EnemyTrackingShots::rotate()
{
	sf::Vector2f speed;
	sf::Vector2f spritePos = sprite.getPosition();
	sf::Vector2f playerPos = Player::player.drawPlayerModel.getPosition();
	speed.x = playerPos.x - spritePos.x;
	speed.y = playerPos.y - spritePos.y;

	float c1 = sqrt(pow(speed.x, 2) + pow(speed.y, 2));
	speed.x /= c1;
	speed.y /= c1;

	speed.x *= shootSpeed;
	speed.y *= shootSpeed;

	double angleInRadian = atan2((double)speed.y, (double)speed.x); //angle in radian
	double angleInDegree = angleInRadian * 180 / 3.141592653589793238463; //angle in degree

	sprite.setRotation(angleInDegree - 90);
}

void EnemyTrackingShots::render()
{
	Window::window.draw(sprite);
	if (renderHitbox)
	{
		Window::window.draw(hitbox4);
	}
}
