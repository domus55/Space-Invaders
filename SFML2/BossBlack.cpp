#include "BossBlack.h"
#include "PowerUp.h"

BossBlack::BossBlack(float posX, float posY, int lvl, int id)
	:BasicBoss(id)
{
	speed = 0.07;
	shootSpeed = 1.5;
	randShootDelay = 0;

	sprite.setScale(0.6, 0.6);

	hitbox4.setSize(sf::Vector2f(100, 100));
	hitbox5.setSize(sf::Vector2f(100, 100));

	hitbox4.setOrigin(50, 50);
	hitbox5.setOrigin(50, 50);

	hitbox4.setScale(0.55, 2);
	hitbox4pos.x = -200;
	hitbox4pos.y = 140;

	hitbox2.setScale(1, 3);
	hitbox2pos.x = 0;
	hitbox2pos.y = 0;

	hitbox5.setScale(0.55, 2);
	hitbox5pos.x = 200;
	hitbox5pos.y = 140;

	hitbox1.setScale(1, 1);
	hitbox1pos.x = -120;
	hitbox1pos.y = 0;

	hitbox3.setScale(1, 1);
	hitbox3pos.x = 120;
	hitbox3pos.y = 0;

	this->lvl = lvl;

	if (lvl == 1)
	{
		texture.loadFromFile("Images/Enemies/Boss/2/normal.png");
		hp = 250;
		centerShootTime = 6000;
		wingShootTime = 3000;
		particleName = "BossBlack1";
	}
	if (lvl == 2)
	{
		texture.loadFromFile("Images/Enemies/Boss/4/normal.png");
		hp = 500;
		centerShootTime = 4000;
		wingShootTime = 2000;
		particleName = "BossBlack2";
		particleAmmount = 5;
	}

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

	shootWing = 1000;
	shootCenter = 0;
}

void BossBlack::create(float posX, float posY, int lvl, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <BossBlack>(posX, posY, lvl, id));
}

void BossBlack::render()
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

void BossBlack::checkCollision(int enemyNumber)
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

void BossBlack::shoot()
{
	shootWing += GameInfo::getDeltaTime();

	if (shootWing > wingShootTime)
	{
		for (int i = 0; i < 7; i++)
		{
			int angle = -45;

			switch (i)
			{
			case 0: angle = -45; break;
			case 1: angle = -60; break;
			case 2: angle = -30; break;
			case 3: angle = -15; break;
			case 4: angle = 0; break;
			case 5: angle = -1; break;
			case 6: angle = -1; break;
			default: break;
			}
			
			if (angle == -1)
			{

				sf::Vector2f speed;
				sf::Vector2f hitboxPos;
				if(i == 5) hitboxPos = hitbox1.getPosition();
				else  hitboxPos = hitbox3.getPosition();
				sf::Vector2f playerPos = Player::player.drawPlayerModel.getPosition();
				speed.x = playerPos.x - hitboxPos.x;
				speed.y = playerPos.y - hitboxPos.y;

				float c1 = sqrt(pow(speed.x, 2) + pow(speed.y, 2));
				speed.x /= c1;
				speed.y /= c1;

				speed.x *= shootSpeed;
				speed.y *= shootSpeed;

				Shoot::create(hitboxPos, speed, false, 3);

				
			}
			else
			{
				if (angle == 0) angle = 1;
				angle %= 360;
				if (angle == 0) angle = 1;
				double angleInRadian1 = angle * 3.141592653589793238463 / 180;

				sf::Vector2f speed;

				speed.x = 1;
				speed.y = speed.x / tan(angleInRadian1);

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

				if (haveLeftWing) Shoot::create(hitbox4.getPosition(), speed, false, 3);
				if (haveRightWing)
				{
					speed.x = -speed.x;
					Shoot::create(hitbox5.getPosition(), speed, false, 3);
				}
			}
		}

		shootWing = 0;
	}
	shootCenter += GameInfo::getDeltaTime();

	if (shootCenter > centerShootTime)
	{
		sf::Vector2f speed;
		speed.x = 0;
		speed.y = 10;
		Shoot::create(sprite.getPosition(), speed, false, 2, 3);
		shootCenter = 0;
	}
}

void BossBlack::destroy()
{
	if (Player::player.hp == 6)
	{
		int los = rand() % 4;
		if (los == 0) PowerUp::create(sprite.getPosition().x - 70, sprite.getPosition().y + 50, "shootSpeed");
		if (los == 1) PowerUp::create(sprite.getPosition().x - 70, sprite.getPosition().y + 50, "shootDelay");
		if (los == 2) PowerUp::create(sprite.getPosition().x - 70, sprite.getPosition().y + 50, "shootAmmount");
		if (los == 3) PowerUp::create(sprite.getPosition().x - 70, sprite.getPosition().y + 50, "sizeDown");

		los = rand() % 4;
		if (los == 0) PowerUp::create(sprite.getPosition().x + 70, sprite.getPosition().y + 50, "shootSpeed");
		if (los == 1) PowerUp::create(sprite.getPosition().x + 70, sprite.getPosition().y + 50, "shootDelay");
		if (los == 2) PowerUp::create(sprite.getPosition().x + 70, sprite.getPosition().y + 50, "shootAmmount");
		if (los == 3) PowerUp::create(sprite.getPosition().x + 70, sprite.getPosition().y + 50, "sizeDown");

		los = rand() % 3;
		if (los == 0) PowerUp::create(sprite.getPosition(), "shootSpeed");
		if (los == 1) PowerUp::create(sprite.getPosition(), "shootDelay");
		if (los == 2) PowerUp::create(sprite.getPosition(), "sizeDown");
	}
	else
	{
		int los = rand() % 5;
		if (los == 0) PowerUp::create(sprite.getPosition().x - 70, sprite.getPosition().y + 50, "shootSpeed");
		if (los == 1) PowerUp::create(sprite.getPosition().x - 70, sprite.getPosition().y + 50, "shootDelay");
		if (los == 2) PowerUp::create(sprite.getPosition().x - 70, sprite.getPosition().y + 50, "hp");
		if (los == 3) PowerUp::create(sprite.getPosition().x - 70, sprite.getPosition().y + 50, "shootAmmount");
		if (los == 4) PowerUp::create(sprite.getPosition().x - 70, sprite.getPosition().y + 50, "sizeDown");

		los = rand() % 5;
		if (los == 0) PowerUp::create(sprite.getPosition().x + 70, sprite.getPosition().y + 50, "shootSpeed");
		if (los == 1) PowerUp::create(sprite.getPosition().x + 70, sprite.getPosition().y + 50, "shootDelay");
		if (los == 2) PowerUp::create(sprite.getPosition().x + 70, sprite.getPosition().y + 50, "hp");
		if (los == 3) PowerUp::create(sprite.getPosition().x + 70, sprite.getPosition().y + 50, "shootAmmount");
		if (los == 4) PowerUp::create(sprite.getPosition().x + 70, sprite.getPosition().y + 50, "sizeDown");

		los = rand() % 4;
		if (los == 0) PowerUp::create(sprite.getPosition(), "shootSpeed");
		if (los == 1) PowerUp::create(sprite.getPosition(), "shootDelay");
		if (los == 2) PowerUp::create(sprite.getPosition(), "hp");
		if (los == 3) PowerUp::create(sprite.getPosition(), "sizeDown");
	}

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

void BossBlack::createLeftWingParticle()
{
	timesHitedLeft++;
	if (timesHitedLeft == (int)maxHp * 0.2)
	{
		haveLeftWing = false;
		if (lvl == 1)
		{
			if (haveRightWing) texture.loadFromFile("Images/Enemies/Boss/2/leftWing.png");
			else texture.loadFromFile("Images/Enemies/Boss/2/bothWings.png");
		}
		else
		{
			if (haveRightWing) texture.loadFromFile("Images/Enemies/Boss/4/leftWing.png");
			else texture.loadFromFile("Images/Enemies/Boss/4/bothWings.png");
		}
		

		Explosion::create(sprite.getPosition().x + hitbox4pos.x, sprite.getPosition().y + hitbox4pos.y);
		hitbox4pos.y -= 180;
		hitbox4.setScale(0.55, 0.8);
	}

	Particle::addParticle(sprite.getPosition().x + hitbox4pos.x, sprite.getPosition().y + hitbox4pos.y, particleName, particleAmmount, 0.5);
}

void BossBlack::createRightWingParticle()
{
	timesHitedRight++;
	if (timesHitedRight == (int)maxHp * 0.2)
	{
		haveRightWing = false;
		if (lvl == 1)
		{
			if (haveLeftWing) texture.loadFromFile("Images/Enemies/Boss/2/rightWing.png");
			else texture.loadFromFile("Images/Enemies/Boss/2/bothWings.png");
		}
		else
		{
			if (haveLeftWing) texture.loadFromFile("Images/Enemies/Boss/4/rightWing.png");
			else texture.loadFromFile("Images/Enemies/Boss/4/bothWings.png");
		}
		Explosion::create(sprite.getPosition().x + hitbox5pos.x, sprite.getPosition().y + hitbox5pos.y);
		hitbox5pos.y -= 180;
		hitbox5.setScale(0.55, 0.8);
	}

	Particle::addParticle(sprite.getPosition().x + hitbox5pos.x, sprite.getPosition().y + hitbox5pos.y, particleName, particleAmmount, 0.5);
}
