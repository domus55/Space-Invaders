#include "Animation.h"

std::vector < std::shared_ptr <Animation> > Animation::animation;
std::vector <std::vector <sf::Texture>> Animation::textures;

Animation::Animation(int animationNumber, int time)
{
	this->time = time;
	this->animationNumber = animationNumber;
	licznik = 0;
	licznik2 = 0;
}

int Animation::addAnimation()
{
	std::vector < sf::Texture> anim;
	textures.push_back(anim);
	return textures.size() - 1;
}

int Animation::addObject(int animationNumber, int time)
{
	Animation::animation.push_back(std::make_shared <Animation>(animationNumber, time));
	return Animation::animation.size() - 1;
}

void Animation::addImage(int animationNumber, std::string texture)
{
	sf::Texture texture2;
	texture2.loadFromFile(texture);
	//this->textures.push_back(texture2);
	Animation::textures[animationNumber].push_back(texture2);
}

void Animation::render(sf::Sprite *sprite)
{
	licznik += GameInfo::getDeltaTime();
	if (licznik >= time)
	{
		licznik2++;
		licznik = 0;
	}

	if (licznik2 == textures[animationNumber].size()) licznik2 = 0;
	sprite->setTexture(textures[animationNumber][licznik2]);
	Window::window.draw(*sprite);//
}

void Animation::restart()
{
	//for (int i = animation.size() - 1; i >= 0; i--)
	//{
		Animation::animation.clear();
	//	animation[i]->licznik2 = 0;
	//	animation[i]->licznik = 0;
	//}
}
