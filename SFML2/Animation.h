#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "GameInfo.h"

class Animation
{
public:
	Animation(int time);
	static int addAnimation(int time);
	void addImage(std::string texture);
	void render(sf::Sprite *sprite, sf::RenderWindow *window);
	static void restart();

	static std::vector < std::shared_ptr <Animation> > animation;
	int blockAmount;	//iloœæ bloków które wykonuj¹ tê animacje
	int licznik2;	//aktualnie wyœwietlana textura
private:

	int time;
	float licznik;
	std::vector <sf::Texture> texture;
};