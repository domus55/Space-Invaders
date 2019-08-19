#include "Animation.h"

std::vector < sf::Texture > texture;
std::vector < std::shared_ptr <Animation> > Animation::animation;

Animation::Animation(int time)
{
	this->time = time;
	licznik = 0;
	licznik2 = 0;
	blockAmount = 0;
}

int Animation::addAnimation(int time)
{
	Animation::animation.push_back(std::make_shared <Animation>(time));
	return animation.size() - 1;
}

void Animation::addImage(std::string texture)
{
	sf::Texture texture2;
	texture2.loadFromFile(texture);
	this->texture.push_back(texture2);
}

void Animation::render(sf::Sprite *sprite, sf::RenderWindow *window)
{
	//int deltaTime = 2;	//naprawiæ deltaTime
	licznik += GameInfo::getDeltaTime() / 16.0;
	if (licznik >= time * blockAmount)
	{
		licznik2++;
		licznik = 0;
	}

	if (licznik2 == texture.size()) licznik2 = 0;
	sprite->setTexture(texture[licznik2]);
	window->draw(*sprite);
}

void Animation::restart()
{
	for (int i = animation.size() - 1; i >= 0; i--)
	{
		animation[i]->licznik2 = 0;
		animation[i]->licznik = 0;
		animation[i]->blockAmount = 0;
	}
}
