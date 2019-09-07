#include "BossBrown.h"

BossBrown::BossBrown(float posX, float posY, int lvl, int id)
	:BasicBoss(id)
{
	speed = 0.07;
	shootSpeed = 1.5;
	randShootDelay = 0;

	sprite.setScale(0.8, 0.8);

	hitbox4.setSize(sf::Vector2f(100, 100));
	hitbox5.setSize(sf::Vector2f(100, 100));

	hitbox4.setOrigin(50, 50);
	hitbox5.setOrigin(50, 50);

	hitbox1.setScale(0.55, 0.8);
	hitbox1pos.x = -50;
	hitbox1pos.y = 180;

	hitbox2.setScale(1, 3);
	hitbox2pos.x = 0;
	hitbox2pos.y = 0;

	hitbox3.setScale(0.55, 0.8);
	hitbox3pos.x = 50;
	hitbox3pos.y = 180;

	hitbox4.setScale(0.6, 1);
	hitbox4pos.x = -120;
	hitbox4pos.y = 0;

	hitbox5.setScale(0.6, 1);
	hitbox5pos.x = 120;
	hitbox5pos.y = 0;
	
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

	this->lvl = lvl;

	if (lvl == 1)
	{
		texture.loadFromFile("Images/Enemies/Boss/1/normal.png");
		hp = 100;
		shootCenter = 0;
		shootWing = 1000;
		shootWingDeltaTime = 3000;
		shootCenterDeltaTime = 6000;
		particleName = "BossBrown1";
	}
	if (lvl == 2)
	{
		texture.loadFromFile("Images/Enemies/Boss/3/normal.png");
		hp = 200;
		shootCenter = -12000;
		shootWing = 500;
		shootWingDeltaTime = 2000;
		shootCenterDeltaTime = 4000;
		particleName = "BossBrown2";
	}

	particleAmmount = 5;

	maxHp = hp;
	
	sprite.setTexture(texture);		

	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(posX, posY);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;

	haveRightWing = true;
	haveLeftWing = true;

	timesHitedLeft = 0;
	timesHitedRight = 0;
}

void BossBrown::create(float posX, float posY, int lvl, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <BossBrown>(posX, posY, lvl, id));
}

void BossBrown::render()
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

void BossBrown::checkCollision(int enemyNumber)
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

void BossBrown::shoot()
{
	shootWing += GameInfo::getDeltaTime();

	if (shootWing > shootWingDeltaTime)
	{
		for (int i = 0; i < 9; i++)
		{
			int angle = i * 10;
			if (lvl == 2 && angle == 0) angle = 1;
			double angleInRadian = angle * 3.141592653589793238463 / 180;

			sf::Vector2f speed;

			speed.x = 1;
			speed.y = speed.x / tan(angleInRadian);

			float c = sqrt(pow(speed.x, 2) + pow(speed.y, 2));
			speed.x /= c;
			speed.y /= c;

			if(haveRightWing) Shoot::create(hitbox5.getPosition(), speed, false, 3);
			if (haveLeftWing)
			{
				speed.x = -speed.x;
				Shoot::create(hitbox4.getPosition(), speed, false, 3);
			}
		}

		
		shootWing = 0;
	}

	shootCenter += GameInfo::getDeltaTime();


	if (shootCenter > shootCenterDeltaTime)
	{
		sf::Vector2f speed;
		speed.x = 0;
		speed.y = 10;
		Shoot::create(hitbox1.getPosition(), speed, false, 2, 3);
		Shoot::create(hitbox1.getPosition(), speed, false, 2, 3);

		Shoot::create(hitbox3.getPosition(), speed, false, 2, 3);
		Shoot::create(hitbox3.getPosition(), speed, false, 2, 3);
		shootCenter = 0;
	}
}

void BossBrown::destroy()
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

void BossBrown::createLeftWingParticle()
{
	timesHitedLeft++;
	if (timesHitedLeft == (int)maxHp/3)
	{
		haveLeftWing = false;
		if (lvl == 1)
		{
			if (haveRightWing) texture.loadFromFile("Images/Enemies/Boss/1/leftWing.png");
			else texture.loadFromFile("Images/Enemies/Boss/1/bothWings.png");
		}
		else
		{
			if (haveRightWing) texture.loadFromFile("Images/Enemies/Boss/3/leftWing.png");
			else texture.loadFromFile("Images/Enemies/Boss/3/bothWings.png");
		}
		
		
		Explosion::create(sprite.getPosition().x + hitbox4pos.x, sprite.getPosition().y + hitbox4pos.y);
		hitbox4.setScale(0, 0);
		hitbox4pos.x = 0;
		hitbox4pos.y = 0;
	}

	Particle::addParticle(sprite.getPosition().x + hitbox4pos.x, sprite.getPosition().y + hitbox4pos.y, particleName, particleAmmount, 0.5);
}

void BossBrown::createRightWingParticle()
{
	timesHitedRight++;
	if (timesHitedRight == (int)maxHp / 3)
	{
		haveRightWing = false;
		if (lvl == 1)
		{
			if (haveLeftWing) texture.loadFromFile("Images/Enemies/Boss/1/rightWing.png");
			else texture.loadFromFile("Images/Enemies/Boss/1/bothWings.png");
		}
		else
		{
			if (haveLeftWing) texture.loadFromFile("Images/Enemies/Boss/3/rightWing.png");
			else texture.loadFromFile("Images/Enemies/Boss/3/bothWings.png");
		}
		Explosion::create(sprite.getPosition().x + hitbox5pos.x, sprite.getPosition().y + hitbox5pos.y);
		hitbox5.setScale(0, 0);
		hitbox5pos.x = 0;
		hitbox5pos.y = 0;
	}

	Particle::addParticle(sprite.getPosition().x + hitbox5pos.x, sprite.getPosition().y + hitbox5pos.y, particleName, particleAmmount, 0.5);
}
