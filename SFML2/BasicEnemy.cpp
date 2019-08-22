#include "BasicEnemy.h"
#include "PowerUp.h"

std::vector < std::shared_ptr <BasicEnemy> > BasicEnemy::enemy;
bool BasicEnemy::renderHitbox = false;

BasicEnemy::BasicEnemy(int id)
{
	hp = 3;
	speed = 0.2;
	shootDmg = 1;
	shootSpeed = 1;
	shootDelay = 1000;
	randShootDelay = 0;
	myDeltaTime = 0;
	shootType = 3;
	shootScale = 1;
	timeToDeath = 0;

	this->id = id;

	srand(time(NULL));

	hitboxTexture.loadFromFile("Images/hitbox.png");
	hitbox1.setTexture(hitboxTexture);
	hitbox2.setTexture(hitboxTexture);
	hitbox3.setTexture(hitboxTexture);

	sf::Vector2u Hitboxsize = hitboxTexture.getSize();
	hitbox1.setOrigin(Hitboxsize.x / 2, Hitboxsize.y / 2);
	hitbox2.setOrigin(Hitboxsize.x / 2, Hitboxsize.y / 2);
	hitbox3.setOrigin(Hitboxsize.x / 2, Hitboxsize.y / 2);
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
		Shoot::create(pos.x, pos.y, 0, shootSpeed, shootDmg, false, shootType, shootScale);
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
			
		if (timeToDeath > 300) enemy.erase(enemy.begin() + enemyNumber);

		timeToDeath += GameInfo::getDeltaTime();
	}


}

void BasicEnemy::destroy()
{
	Explosion::create(sprite.getPosition());
	int los = rand() % 100;
	if (los == 0) PowerUp::create(sprite.getPosition(), "shootSpeed");
	if (los == 1) PowerUp::create(sprite.getPosition(), "shootDelay");
	if (los == 2) PowerUp::create(sprite.getPosition(), "hp");
	if (los == 3) PowerUp::create(sprite.getPosition(), "shootAmmount");
	if (los == 4) PowerUp::create(sprite.getPosition(), "sizeDown");
}

void BasicEnemy::createLeftParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox1pos.x, sprite.getPosition().y + hitbox1pos.y, "BasicEnemy", 15, 0.5);
}

void BasicEnemy::createMiddleParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox2pos.x, sprite.getPosition().y + hitbox2pos.y, "BasicEnemy", 15, 0.5);
}

void BasicEnemy::createRightParticle()
{
	Particle::addParticle(sprite.getPosition().x + hitbox3pos.x, sprite.getPosition().y + hitbox3pos.y, "BasicEnemy", 15, 0.5);
}
