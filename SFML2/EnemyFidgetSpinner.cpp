#include "EnemyFidgetSpinner.h"
#include "PowerUp.h"

EnemyFidgetSpinner::EnemyFidgetSpinner(float x, float y, int level, int id)
	: BasicEnemy(id)
{
	dropHp = false;

	if (level == 99)
	{
		level = 1;
		dropHp = true;
	}
	if (level == 100)
	{
		level = 2;
		dropHp = true;
	}

	if (level == 1)
	{
		shootDelay = 800;
		shootSpeed = 5;
		rotateSpeed = 0.02;
		sprite.setColor(sf::Color(255, 255, 255));
	}

	if (level == 2)
	{
		shootDelay = 500;
		shootSpeed = 8;
		rotateSpeed = 0.03;
		sprite.setColor(sf::Color(255, 230, 230));
	}

	if (level == 3)
	{
		shootDelay = 300;
		shootSpeed = 10;
		rotateSpeed = 0.04;
		sprite.setColor(sf::Color(255, 200, 200));
	}

	speed = 0.1;
	randShootDelay = 100;
	sprite.setScale(0.3, 0.3);

	hitbox1.setScale(0, 0);
	hitbox2.setScale(0, 0);
	hitbox3.setScale(0, 0);

	hitbox4.setRadius(35);
	hitbox4.setOrigin(35, 35);
	hitbox4.setFillColor(sf::Color(0, 0, 0, 0));
	hitbox4.setOutlineThickness(2);
	hitbox4.setOutlineColor(sf::Color::Green);


	hp = 3;
	shootType = 2;
	shootScale = 1;
	particleName = "EnemyFast";

	texture.loadFromFile("Images/Enemies/FidgetSpinner/normal.png");
	sprite.setTexture(texture);

	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2 - 3, size.y / 2 - 60);
	sprite.setPosition(x, y);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;
}

void EnemyFidgetSpinner::update(int enemyNumber)
{
	sprite.rotate(GameInfo::getDeltaTime() * rotateSpeed);
	shoot();
	checkCollision(enemyNumber);	//musi byc na koncu metody, bo moze usunac obiekt
}

void EnemyFidgetSpinner::create(float posX, float posY, int level, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <EnemyFidgetSpinner>(posX, posY, level, id));
}

void EnemyFidgetSpinner::shoot()
{
	myDeltaTime += GameInfo::getDeltaTime();

	if (myDeltaTime > shootDelay)
	{
		int angle1 = -sprite.getRotation();
		if (angle1 == 0) angle1 = 1;
		angle1 %= 360;
		if (angle1 == 0) angle1 = 1;
		double angleInRadian1 = angle1 * 3.141592653589793238463 / 180;

		sf::Vector2f speed1;

		speed1.x = 1;
		speed1.y = speed1.x / tan(angleInRadian1);

		float c1 = sqrt(pow(speed1.x, 2) + pow(speed1.y, 2));
		speed1.x /= c1;
		speed1.y /= c1;

		speed1.x *= shootSpeed;
		speed1.y *= shootSpeed;

		if (-angle1 > 0 && -angle1 <= 180)
		{
			speed1.x *= -1;
			speed1.y *= -1;
		}

		Shoot::create(sprite.getPosition(), speed1, false, shootType, shootScale);
		
		int angle2 = -sprite.getRotation() + 120;
		if (angle2 == 0) angle2 = 1;
		angle2 %= 360;
		if (angle2 == 0) angle2 = 1;
		double angleInRadian2 = angle2 * 3.141592653589793238463 / 180;

		sf::Vector2f speed2;

		speed2.x = 1;
		speed2.y = speed2.x / tan(angleInRadian2);

		float c2 = sqrt(pow(speed2.x, 2) + pow(speed2.y, 2));
		speed2.x /= c2;
		speed2.y /= c2;
		
		speed2.x *= shootSpeed;
		speed2.y *= shootSpeed;

		if (-angle2 > 0 && -angle2 <= 180)
		{
			speed2.x *= -1;
			speed2.y *= -1;
		}

		Shoot::create(sprite.getPosition(), speed2, false, shootType, shootScale);

		int angle3 = -sprite.getRotation() - 120;
		if (angle3 == 0) angle3 = 1;
		angle3 %= 360;
		if (angle3 == 0) angle3 = 1;
		double angleInRadian3 = angle3 * 3.141592653589793238463 / 180;

		sf::Vector2f speed3;

		speed3.x = 1;
		speed3.y = speed3.x / tan(angleInRadian3);

		float c3 = sqrt(pow(speed3.x, 2) + pow(speed3.y, 2));
		speed3.x /= c3;
		speed3.y /= c3;
		
		speed3.x *= shootSpeed;
		speed3.y *= shootSpeed;

		if (-angle3 > 0 && -angle3 <= 180)
		{
			speed3.x *= -1;
			speed3.y *= -1;
		}

		Shoot::create(sprite.getPosition(), speed3, false, shootType, shootScale);

		if (randShootDelay == 0) myDeltaTime = 0;
		else myDeltaTime = (std::rand() % randShootDelay) - randShootDelay / 2;
	}
}

void EnemyFidgetSpinner::checkCollision(int enemyNumber)
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

void EnemyFidgetSpinner::render()
{
	Window::window.draw(sprite);
	if (renderHitbox)
	{
		Window::window.draw(hitbox4);
	}
}

void EnemyFidgetSpinner::destroy()
{
	Explosion::create(sprite.getPosition());

	if (dropHp)
	{
		PowerUp::create(sprite.getPosition(), "hp");
		PowerUp::create(sprite.getPosition(), "hp");
		PowerUp::create(sprite.getPosition(), "hp");
	}
	else
	{
		int los;
		los = rand() % 50;

		if (los == 0) PowerUp::create(sprite.getPosition(), "shootSpeed");
		if (los == 1) PowerUp::create(sprite.getPosition(), "shootDelay");
		if (los == 2) PowerUp::create(sprite.getPosition(), "hp");
		if (los == 3) PowerUp::create(sprite.getPosition(), "shootAmmount");
		if (los == 4) PowerUp::create(sprite.getPosition(), "sizeDown");
	}
}