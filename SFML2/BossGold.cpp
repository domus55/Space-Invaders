#include "BossGold.h"
#include "Player.h"
#include "PowerUp.h"

BossGold::BossGold(float posX, float posY, int lvl, int id)
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
	hitbox1pos.y = -30;

	hitbox2.setScale(1, 1);
	hitbox2pos.x = 0;
	hitbox2pos.y = 140;

	hitbox3.setScale(1, 1);
	hitbox3pos.x = 100;
	hitbox3pos.y = -30;

	hitbox4.setScale(0.9, 0.7);
	hitbox4pos.x = -190;
	hitbox4pos.y = -160;

	hitbox5.setScale(0.9, 0.7);
	hitbox5pos.x = 190;
	hitbox5pos.y = -160;


	this->lvl = lvl;

	if (lvl == 1)
	{
		texture.loadFromFile("Images/Enemies/Boss/5/normal.png");
		hp = 300;
		shootSpeed = 4;
		centerShootTime = 3000;
		wingShootTime = 1000;
		particleName = "BossGold";
	}
	if (lvl == 2)
	{
		texture.loadFromFile("Images/Enemies/Boss/7/normal.png");
		hp = 600;
		shootSpeed = 4;
		centerShootTime = 2100;
		wingShootTime = 700;
		particleName = "BossGold";
	}

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
	shootWing = 0;
}

void BossGold::create(float posX, float posY, int lvl, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <BossGold>(posX, posY, lvl, id));
}

void BossGold::render()
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

void BossGold::checkCollision(int enemyNumber)
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

void BossGold::shoot()
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
			sf::Vector2f playerPos = Player::player.drawPlayerModel.getPosition();
			speed.x = playerPos.x - hitboxPos.x;
			speed.y = playerPos.y - hitboxPos.y;

			float c1 = sqrt(pow(speed.x, 2) + pow(speed.y, 2));
			speed.x /= c1;
			speed.y /= c1;

			speed.x *= shootSpeed;
			speed.y *= shootSpeed;

			if ((i == 0 && haveLeftWing) || (i == 1 && haveRightWing)) Shoot::create(hitboxPos, speed, false, 3);
		}

		shootWing = 0;
	}

	shootCenter += GameInfo::getDeltaTime();

	if (shootCenter > centerShootTime)
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

		shootCenter = 0;
	}
}

void BossGold::destroy()
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

void BossGold::createLeftWingParticle()
{
	timesHitedLeft++;
	if (timesHitedLeft == (int)maxHp * 0.2)
	{
		haveLeftWing = false;
		if (lvl == 1)
		{
			if (haveRightWing) texture.loadFromFile("Images/Enemies/Boss/5/leftWing.png");
			else texture.loadFromFile("Images/Enemies/Boss/5/bothWings.png");
		}
		else
		{
			if (haveRightWing) texture.loadFromFile("Images/Enemies/Boss/7/leftWing.png");
			else texture.loadFromFile("Images/Enemies/Boss/7/bothWings.png");
		}
		

		Explosion::create(sprite.getPosition().x + hitbox4pos.x, sprite.getPosition().y + hitbox4pos.y);
		hitbox4pos.y -= 180;
		hitbox4.setScale(0.55, 0.8);
	}

	Particle::addParticle(sprite.getPosition().x + hitbox4pos.x, sprite.getPosition().y + hitbox4pos.y, particleName, particleAmmount, 0.5);
}

void BossGold::createRightWingParticle()
{
	timesHitedRight++;
	if (timesHitedRight == (int)maxHp * 0.2)
	{
		haveRightWing = false;
		if (lvl == 1)
		{
			if (haveLeftWing) texture.loadFromFile("Images/Enemies/Boss/5/rightWing.png");
			else texture.loadFromFile("Images/Enemies/Boss/5/bothWings.png");
		}
		else
		{
			if (haveLeftWing) texture.loadFromFile("Images/Enemies/Boss/7/rightWing.png");
			else texture.loadFromFile("Images/Enemies/Boss/7/bothWings.png");
		}
		Explosion::create(sprite.getPosition().x + hitbox5pos.x, sprite.getPosition().y + hitbox5pos.y);
		hitbox5pos.y -= 180;
		hitbox5.setScale(0.55, 0.8);
	}

	Particle::addParticle(sprite.getPosition().x + hitbox5pos.x, sprite.getPosition().y + hitbox5pos.y, particleName, particleAmmount, 0.5);
}
