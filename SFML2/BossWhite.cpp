#include "BossWhite.h"
#include "Player.h"
#include "PowerUp.h"

BossWhite::BossWhite(float posX, float posY, int id)
	:BasicBoss(id)
{
	speed = 0.07;
	randShootDelay = 0;

	sprite.setScale(0.6, 0.6);

	hitbox4.setSize(sf::Vector2f(100, 100));
	hitbox5.setSize(sf::Vector2f(100, 100));

	hitbox4.setOrigin(50, 50);
	hitbox5.setOrigin(50, 50);

	hitbox1.setScale(1, 1);
	hitbox1pos.x = -100;
	hitbox1pos.y = 150;

	hitbox2.setScale(1, 1);
	hitbox2pos.x = 0;
	hitbox2pos.y = 160;

	hitbox3.setScale(1, 1);
	hitbox3pos.x = 100;
	hitbox3pos.y = 150;

	hitbox4.setScale(0.9, 1.2);
	hitbox4pos.x = -190;
	hitbox4pos.y = 160;

	hitbox5.setScale(0.9, 1.2);
	hitbox5pos.x = 190;
	hitbox5pos.y = 160;


	this->lvl = lvl;

	
	texture.loadFromFile("Images/Enemies/Boss/8/normal.png");
	hp = 1000;
	shootSpeed = 4;
	centerShootTime = 3000;
	wingShootTime = 1500;
	particleName = "BossGold";
	
	particleAmmount = 3;
	sprite.setTexture(texture);

	maxHp = hp;

	deathDeltaTime = 500;
	shootDelay = 3000;
	shootType = 2;
	shootScale = 1;

	hitbox4.setFillColor(sf::Color(0, 0, 0, 0));
	hitbox5.setFillColor(sf::Color(0, 0, 0, 0));

	hitbox4.setOutlineThickness(2);
	hitbox5.setOutlineThickness(2);

	hitbox4.setOutlineColor(sf::Color::Green);
	hitbox5.setOutlineColor(sf::Color::Green);

	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(posX, posY);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;

	haveRightWing = true;
	haveLeftWing = true;
	timesHitedLeft = 0;
	timesHitedRight = 0;

	shootCenter = 0;
	shootWing = 750;
	centerShooted = 0;
	wingShooted = 0;
}

void BossWhite::create(float posX, float posY, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <BossWhite>(posX, posY, id));
}

void BossWhite::render()
{
	Window::window.draw(sprite);
	renderHp();

	if (renderHitbox)
	{
		Window::window.draw(hitbox1);
		Window::window.draw(hitbox2);
		Window::window.draw(hitbox3);
		Window::window.draw(hitbox4);
		Window::window.draw(hitbox5);
	}
}

void BossWhite::checkCollision(int enemyNumber)
{
	sf::Vector2f pos = sprite.getPosition();
	hitbox1.setPosition(pos + hitbox1pos);
	hitbox2.setPosition(pos + hitbox2pos);
	hitbox3.setPosition(pos + hitbox3pos);
	hitbox4.setPosition(pos + hitbox4pos);
	hitbox5.setPosition(pos + hitbox5pos);

	for (int i = Shoot::shoot.size() - 1; i >= 0; i--)
	{
		if (Shoot::shoot[i]->playerShoot && Shoot::shoot[i]->checkCollision(hitbox2))
		{
			createMiddleParticle();
			hp -= Shoot::shoot[i]->getDmg();
			Shoot::shoot.erase(Shoot::shoot.begin() + i);
		}
		else
		{
			if (Shoot::shoot[i]->playerShoot && Shoot::shoot[i]->checkCollision(hitbox1))
			{
				createLeftParticle();
				hp -= Shoot::shoot[i]->getDmg();
				Shoot::shoot.erase(Shoot::shoot.begin() + i);
			}
			else
			{
				if (Shoot::shoot[i]->playerShoot && Shoot::shoot[i]->checkCollision(hitbox3))
				{
					createRightParticle();
					hp -= Shoot::shoot[i]->getDmg();
					Shoot::shoot.erase(Shoot::shoot.begin() + i);
				}
				else
				{
					if (Shoot::shoot[i]->playerShoot && Shoot::shoot[i]->checkCollision(hitbox4))
					{
						createLeftWingParticle();
						hp -= Shoot::shoot[i]->getDmg();
						Shoot::shoot.erase(Shoot::shoot.begin() + i);
					}
					else
					{
						if (Shoot::shoot[i]->playerShoot && Shoot::shoot[i]->checkCollision(hitbox5))
						{
							createRightWingParticle();
							hp -= Shoot::shoot[i]->getDmg();
							Shoot::shoot.erase(Shoot::shoot.begin() + i);
						}
					}
				}
			}
		}
	}

	if (hp <= 0)
	{
		if (timeToDeath == 0)
		{
			destroy();
			timeToDeath = 1;
		}

		if (timeToDeath > deathDeltaTime) enemy.erase(enemy.begin() + enemyNumber);

		timeToDeath += GameInfo::getDeltaTime();
	}
}

void BossWhite::shoot()
{
	shootWing += GameInfo::getDeltaTime();

	if (shootWing > wingShootTime)
	{
		for (int i = 0; i < 2; i++)
		{
			sf::Vector2f speed;
			sf::Vector2f hitboxPos;
			if (i == 0) hitboxPos = hitbox4.getPosition();
			else  hitboxPos = hitbox5.getPosition();

			for (int j = -1; j < 2; j++)
			{
				sf::Vector2f playerPos = Player::player.drawPlayerModel.getPosition();
				speed.x = playerPos.x - hitboxPos.x;
				speed.y = playerPos.y - hitboxPos.y;

				double angleInRadian = atan2((double)speed.x, (double)speed.y);
				double angleInDegree = angleInRadian * 180 / 3.141592653589793238463;

				angleInDegree += j * 20;

				int angle = angleInDegree;
				if (angle == 0) angle = 1;
				double angleInRadian2 = angle * 3.141592653589793238463 / 180;

				sf::Vector2f speed2;

				speed2.x = 1;
				speed2.y = speed2.x / tan(angleInRadian2);

				float c = sqrt(pow(speed2.x, 2) + pow(speed2.y, 2));
				speed2.x /= c;
				speed2.y /= c;

				speed2.x *= shootSpeed;
				speed2.y *= shootSpeed;

				if (-angle > 0 && -angle <= 180)
				{
					speed2.x *= -1;
					speed2.y *= -1;
				}
				if(!(wingShooted % 2 == 0 && j == 0))
				if ((i == 0 && haveLeftWing) || (i == 1 && haveRightWing)) Shoot::create(hitboxPos, speed2, false, 3);
			}
		}

		wingShooted++;
		shootWing = 0;
	}

	shootCenter += GameInfo::getDeltaTime();

	if (shootCenter > centerShootTime)
	{
		if (centerShooted % 3 == 1)
		{
			for (int i = -4; i < 5; i++)
			{
				int angle = i*5 + 1;
				angle %= 360;
				if (angle == 0) angle = 1;
				double angleInRadian = angle * 3.141592653589793238463 / 180;

				sf::Vector2f speed;

				speed.x = 1;
				speed.y = speed.x / tan(angleInRadian);

				float c1 = sqrt(pow(speed.x, 2) + pow(speed.y, 2));
				speed.x /= c1;
				speed.y /= c1;

				speed.x *= shootSpeed;
				speed.y *= shootSpeed;

				if (-angle > 0 && -angle <= 180)
				{
					speed.x *= -1;
					speed.y *= -1;
				}

				Shoot::create(sprite.getPosition(), speed, false, 3, shootScale);
			}
			
		}

		if (centerShooted % 3 == 0)
		{
			for (int i = 0; i < 18; i++)
			{
				int angle = -i * 20;
				angle %= 360;
				if (angle == 0) angle = 1;
				double angleInRadian = angle * 3.141592653589793238463 / 180;

				sf::Vector2f speed;

				speed.x = 1;
				speed.y = speed.x / tan(angleInRadian);

				float c1 = sqrt(pow(speed.x, 2) + pow(speed.y, 2));
				speed.x /= c1;
				speed.y /= c1;

				speed.x *= shootSpeed;
				speed.y *= shootSpeed;

				if (-angle > 0 && -angle <= 180)
				{
					speed.x *= -1;
					speed.y *= -1;
				}

				Shoot::create(sprite.getPosition(), speed, false, 3, shootScale);
			}
		}

		if (centerShooted % 3 == 2)
		{
			sf::Vector2f speed;
			sf::Vector2f hitboxPos;
			hitboxPos = hitbox2.getPosition();
			sf::Vector2f playerPos = Player::player.drawPlayerModel.getPosition();
			speed.x = playerPos.x - hitboxPos.x;
			speed.y = playerPos.y - hitboxPos.y;

			float c1 = sqrt(pow(speed.x, 2) + pow(speed.y, 2));
			speed.x /= c1;
			speed.y /= c1;

			speed.x *= shootSpeed;
			speed.y *= shootSpeed;

			Rocket::create(hitboxPos, speed, 3);
		}
		
		centerShooted++;
		shootCenter = 0;
	}
}

void BossWhite::destroy()
{
	Explosion::create(sprite.getPosition(), 2, 2.5);
	Explosion::create(sprite.getPosition().x + 100, sprite.getPosition().y - 50, 1, 2);
	Explosion::create(sprite.getPosition().x - 120, sprite.getPosition().y + 30, 1, 1.8);
	Explosion::create(sprite.getPosition().x - 60, sprite.getPosition().y - 100, 1, 1.9);
	Explosion::create(sprite.getPosition().x + 40, sprite.getPosition().y - 120, 1, 2.3);
	Explosion::create(sprite.getPosition().x + 50, sprite.getPosition().y + 120, 1.5, 2.2);
	Explosion::create(sprite.getPosition().x - 30, sprite.getPosition().y + 140, 1.5, 2);


	Particle::addParticle(sprite.getPosition().x, sprite.getPosition().y, particleName, 600, 2);
	Particle::addParticle(sprite.getPosition().x + 100, sprite.getPosition().y - 50, particleName, 20, 1);
	Particle::addParticle(sprite.getPosition().x - 120, sprite.getPosition().y + 30, particleName, 20, 1);
	Particle::addParticle(sprite.getPosition().x - 60, sprite.getPosition().y - 100, particleName, 20, 1);
	Particle::addParticle(sprite.getPosition().x + 40, sprite.getPosition().y - 120, particleName, 20, 1);
	Particle::addParticle(sprite.getPosition().x + 50, sprite.getPosition().y + 120, particleName, 20, 1);
	Particle::addParticle(sprite.getPosition().x - 30, sprite.getPosition().y + 140, particleName, 20, 1);
}

void BossWhite::createLeftWingParticle()
{
	timesHitedLeft++;
	if (timesHitedLeft == (int)maxHp * 0.2)
	{
		haveLeftWing = false;
		
		if (haveRightWing) texture.loadFromFile("Images/Enemies/Boss/8/leftWing.png");
		else texture.loadFromFile("Images/Enemies/Boss/8/bothWings.png");

		Explosion::create(sprite.getPosition().x + hitbox4pos.x, sprite.getPosition().y + hitbox4pos.y);
		hitbox4pos.x += 180;
		hitbox4.setScale(0.55, 0.8);
	}

	Particle::addParticle(sprite.getPosition().x + hitbox4pos.x, sprite.getPosition().y + hitbox4pos.y, particleName, particleAmmount, 0.5);
}

void BossWhite::createRightWingParticle()
{
	timesHitedRight++;
	if (timesHitedRight == (int)maxHp * 0.2)
	{
		haveRightWing = false;

		if (haveLeftWing) texture.loadFromFile("Images/Enemies/Boss/8/rightWing.png");
		else texture.loadFromFile("Images/Enemies/Boss/8/bothWings.png");

		Explosion::create(sprite.getPosition().x + hitbox5pos.x, sprite.getPosition().y + hitbox5pos.y);
		hitbox5pos.x -= 180;
		hitbox5.setScale(0.55, 0.8);
	}

	Particle::addParticle(sprite.getPosition().x + hitbox5pos.x, sprite.getPosition().y + hitbox5pos.y, particleName, particleAmmount, 0.5);
}
