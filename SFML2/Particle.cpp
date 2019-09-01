#include "Particle.h"

std::vector < std::shared_ptr <Particle> > Particle::particle;


Particle::Particle(float a, float h, std::string name, float speed)
{
	if (name == "BasicEnemy") teksture.loadFromFile("Images/Particles/BasicEnemy.png");
	if (name == "EnemyTank") teksture.loadFromFile("Images/Particles/EnemyTank.png");
	if (name == "EnemyFast") teksture.loadFromFile("Images/Particles/EnemyFast.png");
	if (name == "BossBrown1") teksture.loadFromFile("Images/Particles/BossBrown1.png");
	if (name == "BossBrown2") teksture.loadFromFile("Images/Particles/BossBrown2.png");
	if (name == "BossBlack1") teksture.loadFromFile("Images/Particles/BossBlack1.png");
	if (name == "BossBlack2") teksture.loadFromFile("Images/Particles/BossBlack2.png");
	if (name == "BossGold") teksture.loadFromFile("Images/Particles/BossGold.png");
	if (name == "BossBlue") teksture.loadFromFile("Images/Particles/BossBlue.png");

	static bool firstTime = true;
	if (firstTime)
	{
		srand(time(NULL));
		firstTime = false;
	}
	sprite.setTexture(teksture);

	sprite.setPosition(a, h);

	//else
	//{
	//	if (left) sprite.setPosition(a - 25, h);
	//	else sprite.setPosition(a + 25, h);
	//}


	timee = 0;

	int los = rand() % 100;
	int los2 = rand() % 100;
	int los3 = rand() % 100;
	this->speed.x = (los - 50) / 100.0f;
	this->speed.y = (los2 - 50) / 100.0f;
	rotation = (los3 - 50) / 100.0f;

	float c = sqrt(pow(this->speed.x, 2) + pow(this->speed.y, 2));
	this->speed.x /= c;
	this->speed.y /= c;

	this->speed.x *= (rand() % 100) / (float)100 * speed;
	this->speed.y *= (rand() % 100) / (float)100 * speed;
}

void Particle::renderAll()
{
	for (int i = particle.size() - 1; i >= 0; i--)
	{
		particle[i]->render();
	}
}

void Particle::render()
{
	Window::window.draw(sprite);
}

void Particle::updateAll()
{
	for (int i = particle.size() - 1; i >= 0; i--)
	{
		particle[i]->update();
	}

	for (int i = particle.size() - 1; i >= 0; i--)
	{
		if (particle[i]->timee > 3000) particle.erase(particle.begin() + i);
	}
}

void Particle::update()
{
	timee += GameInfo::getDeltaTime();
	sprite.move(speed.x * GameInfo::getDeltaTime() / 5.0, speed.y * GameInfo::getDeltaTime() / 5.0);
	rotation *= 0.998;
	speed.x *= 0.999;
	speed.y *= 0.999;

	sprite.rotate(rotation);
	if(timee>2000) sprite.setColor(sf::Color(255, 255, 255, -(timee - 2000) / 4));
}

void Particle::addParticle(float a, float h, std::string name, int ammount, float speed)
{
	for (int i = 0; i < ammount; i++)
	{
		Particle::particle.push_back(std::make_shared <Particle>(a, h, name, speed));
	}
}
