#include "BossBrown.h"

BossBrown::BossBrown(float posX, float posY, int id)
	:BasicBoss(id)
{
	speed = 0.07;
	shootSpeed = 1.5;
	randShootDelay = 0;

	sprite.setScale(0.8, 0.8);

	hitbox4.setTexture(hitboxTexture);
	hitbox5.setTexture(hitboxTexture);

	sf::Vector2u Hitboxsize = hitboxTexture.getSize();
	hitbox4.setOrigin(Hitboxsize.x / 2, Hitboxsize.y / 2);
	hitbox5.setOrigin(Hitboxsize.x / 2, Hitboxsize.y / 2);

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

	hp = 100;
	maxHp = hp;

	deathDeltaTime = 500;
	shootDelay = 3000;
	shootType = 2;
	shootScale = 1;

	texture.loadFromFile("Images/Enemies/Boss/1/normal.png");
	sprite.setTexture(texture);		

	sf::Vector2u size = texture.getSize();

	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(posX, posY);
	this->size.x = size.x * sprite.getScale().x;
	this->size.y = size.y * sprite.getScale().y;

	haveRightWing = true;
	haveLeftWing = true;
}

void BossBrown::create(float posX, float posY, int id)
{
	BasicEnemy::enemy.push_back(std::make_shared <BossBrown>(posX, posY, id));
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
		if (Shoot::shoot[i]->playerShoot && Collider::checkCollision(hitbox2, Shoot::shoot[i]->sprite))
		{
			createMiddleParticle();
			hp -= Shoot::shoot[i]->getDmg();
			Shoot::shoot.erase(Shoot::shoot.begin() + i);
		}
		else
		{
			if (Shoot::shoot[i]->playerShoot && Collider::checkCollision(hitbox1, Shoot::shoot[i]->sprite))
			{
				createLeftParticle();
				hp -= Shoot::shoot[i]->getDmg();
				Shoot::shoot.erase(Shoot::shoot.begin() + i);
			}
			else
			{
				if (Shoot::shoot[i]->playerShoot && Collider::checkCollision(hitbox3, Shoot::shoot[i]->sprite))
				{
					createRightParticle();
					hp -= Shoot::shoot[i]->getDmg();
					Shoot::shoot.erase(Shoot::shoot.begin() + i);
				}
				else
				{
					if (Shoot::shoot[i]->playerShoot && Collider::checkCollision(hitbox4, Shoot::shoot[i]->sprite))
					{
						createLeftWingParticle();
						hp -= Shoot::shoot[i]->getDmg();
						Shoot::shoot.erase(Shoot::shoot.begin() + i);
					}
					else
					{
						if (Shoot::shoot[i]->playerShoot && Collider::checkCollision(hitbox5, Shoot::shoot[i]->sprite))
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
	static int shootWing = 1000;
	shootWing += GameInfo::getDeltaTime();

	if (shootWing > 3000)
	{
		for (int i = 0; i < 9; i++)
		{
			int angle = i * 10;
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

	static int shootCenter = 0;
	shootCenter += GameInfo::getDeltaTime();


	if (shootCenter > 6000)
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

	Explosion::create(sprite.getPosition(), 2, 2.5);
	Explosion::create(sprite.getPosition().x + 100, sprite.getPosition().y - 50, 1, 2);
	Explosion::create(sprite.getPosition().x - 120, sprite.getPosition().y + 30, 1, 1.8);
	Explosion::create(sprite.getPosition().x - 60, sprite.getPosition().y - 100, 1, 1.9);
	Explosion::create(sprite.getPosition().x + 40, sprite.getPosition().y - 120, 1, 2.3);
	Explosion::create(sprite.getPosition().x + 50, sprite.getPosition().y + 120, 1.5, 2.2);
	Explosion::create(sprite.getPosition().x - 30, sprite.getPosition().y + 140, 1.5, 2);


	Particle::addParticle(sprite.getPosition().x, sprite.getPosition().y, "BasicEnemy", 600, 2);
	Particle::addParticle(sprite.getPosition().x + 100, sprite.getPosition().y - 50, "BasicEnemy", 20, 1);
	Particle::addParticle(sprite.getPosition().x - 120, sprite.getPosition().y + 30, "BasicEnemy", 20, 1);
	Particle::addParticle(sprite.getPosition().x - 60, sprite.getPosition().y - 100, "BasicEnemy", 20, 1);
	Particle::addParticle(sprite.getPosition().x + 40, sprite.getPosition().y - 120, "BasicEnemy", 20, 1);
	Particle::addParticle(sprite.getPosition().x + 50, sprite.getPosition().y + 120, "BasicEnemy", 20, 1);
	Particle::addParticle(sprite.getPosition().x - 30, sprite.getPosition().y + 140, "BasicEnemy", 20, 1);
}

void BossBrown::createLeftWingParticle()
{
	static int timesHited = 0;
	timesHited++;
	if (timesHited == 30)
	{
		haveLeftWing = false;
		if(haveRightWing) texture.loadFromFile("Images/Enemies/Boss/1/leftWing.png");
		else texture.loadFromFile("Images/Enemies/Boss/1/bothWings.png");
		
		Explosion::create(sprite.getPosition().x + hitbox4pos.x, sprite.getPosition().y + hitbox4pos.y);
		hitbox4.setScale(0, 0);
		hitbox4pos.x = 0;
		hitbox4pos.y = 0;
	}

	Particle::addParticle(sprite.getPosition().x + hitbox4pos.x, sprite.getPosition().y + hitbox4pos.y, "BasicEnemy", 15, 0.5);
}

void BossBrown::createRightWingParticle()
{
	static int timesHited = 0;
	timesHited++;
	if (timesHited == 30)
	{
		haveRightWing = false;
		if(haveLeftWing) texture.loadFromFile("Images/Enemies/Boss/1/rightWing.png");
		else texture.loadFromFile("Images/Enemies/Boss/1/bothWings.png");
		Explosion::create(sprite.getPosition().x + hitbox5pos.x, sprite.getPosition().y + hitbox5pos.y);
		hitbox5.setScale(0, 0);
		hitbox5pos.x = 0;
		hitbox5pos.y = 0;
	}

	Particle::addParticle(sprite.getPosition().x + hitbox5pos.x, sprite.getPosition().y + hitbox5pos.y, "BasicEnemy", 15, 0.5);
}
