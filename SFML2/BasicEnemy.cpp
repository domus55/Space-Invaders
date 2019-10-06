#include "BasicEnemy.h"
#include "PowerUp.h"
#include "Player.h"

std::vector < std::shared_ptr <BasicEnemy> > BasicEnemy::enemy;
bool BasicEnemy::renderHitbox = false;
sf::SoundBuffer BasicEnemy::enemyHitSoundBuffer;

BasicEnemy::BasicEnemy(int id)
{
	hp = 3;
	speed = 0.2;
	shootSpeed = 1;
	shootDelay = 1000;
	randShootDelay = 0;
	myDeltaTime = 0;
	shootType = 3;
	shootScale = 1;
	timeToDeath = 0;
	deathDeltaTime = 300;
	particleName = "BasicEnemy";
	particleAmmount = 15;

	this->id = id;

	srand(time(NULL));

	hitboxTexture.loadFromFile("Images/hitbox.png");
	//hitbox1.setTexture(hitboxTexture);
	//hitbox2.setTexture(hitboxTexture);
	//hitbox3.setTexture(hitboxTexture);

	hitbox1.setSize(sf::Vector2f(100, 100));
	hitbox2.setSize(sf::Vector2f(100, 100));
	hitbox3.setSize(sf::Vector2f(100, 100));

	hitbox1.setOrigin(50, 50);
	hitbox2.setOrigin(50, 50);
	hitbox3.setOrigin(50, 50);

	hitbox1.setFillColor(sf::Color(0, 0, 0, 0));
	hitbox2.setFillColor(sf::Color(0, 0, 0, 0));
	hitbox3.setFillColor(sf::Color(0, 0, 0, 0));

	hitbox1.setOutlineThickness(2);
	hitbox2.setOutlineThickness(2);
	hitbox3.setOutlineThickness(2);

	hitbox1.setOutlineColor(sf::Color::Green);
	hitbox2.setOutlineColor(sf::Color::Green);
	hitbox3.setOutlineColor(sf::Color::Green);

	enemyHit.setBuffer(enemyHitSoundBuffer);
}

void BasicEnemy::updateAll()
{
	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		BasicEnemy::enemy[i]->update(i);
	}
}

void BasicEnemy::renderAll()
{
	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		BasicEnemy::enemy[i]->render();
	}
}

sf::Vector2f BasicEnemy::getPosition()
{
	return sprite.getPosition();
}

int BasicEnemy::mostToTheRight(int id)
{
	int max = -10000;

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->getPosition().x > max && (id == -1 || id == BasicEnemy::enemy[i]->id)) max = BasicEnemy::enemy[i]->getPosition().x;
	}

	return max;
}

int BasicEnemy::mostToTheLeft(int id)
{
	int max = 10000;

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->getPosition().x < max && (id == -1 || id == BasicEnemy::enemy[i]->id)) max = BasicEnemy::enemy[i]->getPosition().x;
	}

	return max;
}

int BasicEnemy::mostToTheTop(int id)
{
	int max = 10000;

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->getPosition().y < max && (id == -1 || id == BasicEnemy::enemy[i]->id)) max = BasicEnemy::enemy[i]->getPosition().y;
	}

	return max;
}

int BasicEnemy::mostToTheBottom(int id)
{
	int max = -10000;

	for (int i = BasicEnemy::enemy.size() - 1; i >= 0; i--)
	{
		if (BasicEnemy::enemy[i]->getPosition().y > max && (id == -1 || id == BasicEnemy::enemy[i]->id)) max = BasicEnemy::enemy[i]->getPosition().y;
	}

	return max;
}

void BasicEnemy::moveRight()
{
	if (timeToDeath == 0)
	{
		sf::Vector2f pos = sprite.getPosition();
		pos.x += speed * GameInfo::getDeltaTime();
		sprite.setPosition(pos);
	}
}

void BasicEnemy::moveLeft()
{
	if (timeToDeath == 0)
	{
		sf::Vector2f pos = sprite.getPosition();
		pos.x -= speed * GameInfo::getDeltaTime();
		sprite.setPosition(pos);
	}
}

void BasicEnemy::moveUp()
{
	if (timeToDeath == 0)
	{
		sf::Vector2f pos = sprite.getPosition();
		pos.y -= speed * GameInfo::getDeltaTime();
		sprite.setPosition(pos);
	}
}

void BasicEnemy::moveDown()
{
	if (timeToDeath == 0)
	{
		sf::Vector2f pos = sprite.getPosition();
		pos.y += speed * GameInfo::getDeltaTime();
		sprite.setPosition(pos);
	}
}

void BasicEnemy::loadSound()
{
	enemyHitSoundBuffer.loadFromFile("Sounds/enemyHit.wav");
}

void BasicEnemy::render()
{
	Window::window.draw(sprite);
	if (renderHitbox)
	{
		Window::window.draw(hitbox1);
		Window::window.draw(hitbox2);
		Window::window.draw(hitbox3);
	}
}

void BasicEnemy::update(int enemyNumber)
{
	shoot();
	checkCollision(enemyNumber);	//musi byc na koncu metody, bo moze usunac obiekt
}

void BasicEnemy::shoot()
{
	myDeltaTime += GameInfo::getDeltaTime();

	if (myDeltaTime > shootDelay)
	{
		sf::Vector2f pos;
		pos = sprite.getPosition();
		Shoot::create(pos.x, pos.y, 0, shootSpeed, false, shootType, shootScale);
		if (randShootDelay == 0) myDeltaTime = 0;
		else myDeltaTime = (std::rand() % randShootDelay) - randShootDelay/2;
	}
}

void BasicEnemy::checkCollision(int enemyNumber)
{
	sf::Vector2f pos = sprite.getPosition();
	hitbox1.setPosition(pos + hitbox1pos);
	hitbox2.setPosition(pos + hitbox2pos);
	hitbox3.setPosition(pos + hitbox3pos);

	for (int i = Shoot::shoot.size() - 1; i >= 0; i--)
	{
		if (Shoot::shoot[i]->playerShoot && Shoot::shoot[i]->checkCollision(hitbox2))
		{
			createMiddleParticle();
			hp -= Shoot::shoot[i]->getDmg();
			Shoot::shoot.erase(Shoot::shoot.begin() + i);
			enemyHit.play();
		}
		else
		{
			if (Shoot::shoot[i]->playerShoot && Shoot::shoot[i]->checkCollision(hitbox1))
			{
				createLeftParticle();
				hp -= Shoot::shoot[i]->getDmg();
				Shoot::shoot.erase(Shoot::shoot.begin() + i);
				enemyHit.play();
			}
			else
			{
				if (Shoot::shoot[i]->playerShoot && Shoot::shoot[i]->checkCollision(hitbox3))
				{
					createRightParticle();
					hp -= Shoot::shoot[i]->getDmg();
					Shoot::shoot.erase(Shoot::shoot.begin() + i);
					enemyHit.play();
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

		timeToDeath += GameInfo::getDeltaTime();
		if (timeToDeath > deathDeltaTime) enemy.erase(enemy.begin() + enemyNumber);

		
	}
}

void BasicEnemy::destroy()
{
	Explosion::create(sprite.getPosition());

	int los;
	if(LevelManager::actualLevel < 10) los = rand() % 33;
	else los = rand() % 100;

	if (Player::player.hp > 5 && los == 2)
	{
		los = rand() % 4;

		if (los == 0) PowerUp::create(sprite.getPosition(), "shootSpeed");
		if (los == 1) PowerUp::create(sprite.getPosition(), "shootDelay");
		if (los == 2) PowerUp::create(sprite.getPosition(), "shootAmmount");
		if (los == 3) PowerUp::create(sprite.getPosition(), "sizeDown");
	}
	else
	{
		if (los == 3 && Player::player.shootAmmount == 12)
		{
			los = rand() % 4;

			if (los == 0) PowerUp::create(sprite.getPosition(), "shootSpeed");
			if (los == 1) PowerUp::create(sprite.getPosition(), "shootDelay");
			if (los == 2) PowerUp::create(sprite.getPosition(), "hp");
			if (los == 3) PowerUp::create(sprite.getPosition(), "sizeDown");
		}
		else
		{
			if (los == 0) PowerUp::create(sprite.getPosition(), "shootSpeed");
			if (los == 1) PowerUp::create(sprite.getPosition(), "shootDelay");
			if (los == 2) PowerUp::create(sprite.getPosition(), "hp");
			if (los == 3) PowerUp::create(sprite.getPosition(), "shootAmmount");
			if (los == 4) PowerUp::create(sprite.getPosition(), "sizeDown");
		}
	}
	

	
}

void BasicEnemy::createLeftParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox1pos.x, sprite.getPosition().y + hitbox1pos.y, particleName, particleAmmount, 0.5);
}

void BasicEnemy::createMiddleParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox2pos.x, sprite.getPosition().y + hitbox2pos.y, particleName, particleAmmount, 0.5);
}

void BasicEnemy::createRightParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox3pos.x, sprite.getPosition().y + hitbox3pos.y, particleName, particleAmmount, 0.5);
}
