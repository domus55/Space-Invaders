#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "GameInfo.h"
#include "Window.h"

class Animation
{
public:
	Animation(int animationNumber, int time);
	static int addAnimation();											//tworzy nowa animacje i zwraca jej numer, aby dodac tekstury do tej animacji nalezy uzyc addImage(numerAnimacji)
	static int addObject(int animationNumber, int time);				//zwraca numer tablicy animowanego obiektu
	static void addImage(int animationNumber, std::string texture);		//dodaje kolejna teksture do animacji
	void render(sf::Sprite *sprite);	
	static void restart();		//czysci wszytkie obiekty, najlepiej uzyc podczas ladowania kolejnego poziomu

	static std::vector < std::shared_ptr <Animation> > animation;	//tablica obiektow ktore sa animowane
	static std::vector <std::vector <sf::Texture>> textures;		//tablica wszystkich tekstur
	int licznik2;			//aktualnie wyœwietlana textura
	int animationNumber;	//numer vectora z odpowiednimi teksturami
private:

	int time;
	float licznik;
};