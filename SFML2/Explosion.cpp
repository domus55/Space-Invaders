#include "Explosion.h"

int Explosion::animation = -1;
std::vector < std::shared_ptr <Explosion> > Explosion::explosion;
sf::SoundBuffer Explosion::soundBuffer;

Explosion::Explosion(float x, float y, float scale, float timeScale, int timeDelay)
{
	texture.loadFromFile("Images/explosion/explosion1.png");
	sprite.setTexture(texture);
	sf::Vector2u size = texture.getSize();
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(x, y);
	sprite.setScale(scale, scale);
	animationObject = Animation::addObject(animation, 15 * timeScale);
	destroyed = false;
	sound.setBuffer(soundBuffer);
	sound.setVolume(25);
	sound.play();
	deltaTime = 0;
	this->timeDelay = timeDelay;
}

void Explosion::loadAnimation()
{
	soundBuffer.loadFromFile("Sounds/explosion.ogg");

	animation = Animation::addAnimation();

	Animation::addImage(animation, "Images/explosion/explosion1.png");
	Animation::addImage(animation, "Images/explosion/explosion2.png");
	Animation::addImage(animation, "Images/explosion/explosion3.png");
	Animation::addImage(animation, "Images/explosion/explosion4.png");
	Animation::addImage(animation, "Images/explosion/explosion5.png");
	Animation::addImage(animation, "Images/explosion/explosion6.png");
	Animation::addImage(animation, "Images/explosion/explosion7.png");
	Animation::addImage(animation, "Images/explosion/explosion8.png");
	Animation::addImage(animation, "Images/explosion/explosion9.png");
	Animation::addImage(animation, "Images/explosion/explosion10.png");
	Animation::addImage(animation, "Images/explosion/explosion11.png");
	Animation::addImage(animation, "Images/explosion/explosion12.png");
	Animation::addImage(animation, "Images/explosion/explosion13.png");
	Animation::addImage(animation, "Images/explosion/explosion14.png");
	Animation::addImage(animation, "Images/explosion/explosion13.png");
	Animation::addImage(animation, "Images/explosion/explosion12.png");
	Animation::addImage(animation, "Images/explosion/explosion11.png");
	Animation::addImage(animation, "Images/explosion/explosion10.png");
	Animation::addImage(animation, "Images/explosion/explosion9.png");
	Animation::addImage(animation, "Images/explosion/explosion8.png");
	Animation::addImage(animation, "Images/explosion/explosion7.png");
	Animation::addImage(animation, "Images/explosion/explosion6.png");
	Animation::addImage(animation, "Images/explosion/explosion5.png");
	Animation::addImage(animation, "Images/explosion/explosion4.png");
	Animation::addImage(animation, "Images/explosion/explosion3.png");
	Animation::addImage(animation, "Images/explosion/explosion2.png");
	Animation::addImage(animation, "Images/explosion/explosion1.png");
}

void Explosion::create(sf::Vector2f position, float scale, float timeScale, int timeDelay)
{
	Explosion::explosion.push_back(std::make_shared <Explosion>(position.x, position.y, scale, timeScale, timeDelay));
}

void Explosion::create(float x, float y, float scale, float timeScale, int timeDelay)
{
	Explosion::explosion.push_back(std::make_shared <Explosion>(x, y, scale, timeScale, timeDelay));
}

void Explosion::renderAll()
{
	for (int i = Explosion::explosion.size() - 1; i >= 0; i--)
	{
		Explosion::explosion[i]->render(i);
	}
}

void Explosion::render(int explosionNumber)
{
	timeDelay -= GameInfo::getDeltaTime();

	if(timeDelay <= 0)
	{
		if (destroyed)
		{
			deltaTime += GameInfo::getDeltaTime();
			if (deltaTime > 5000) Explosion::explosion.erase(Explosion::explosion.begin() + explosionNumber);
		}
		else
		{
			Animation::animation[animationObject]->render(&sprite);
			if (Animation::animation[animationObject]->licznik2 == 26)
			{
				Animation::animation[animationObject]->licznik2 = 0;
				destroyed = true;
			}
		}
	}

	
	
}
