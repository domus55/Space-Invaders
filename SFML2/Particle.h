#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>
#include "Window.h"
#include "GameInfo.h"


class Particle
{
public:
	Particle(float a, float h, std::string name, float speed);
	static void renderAll();
	void render();
	static void updateAll();
	void update();

	static void addParticle(float a, float h, std::string name, int ammount, float speed);
	static std::vector < std::shared_ptr <Particle> > particle;

private:
	sf::Sprite sprite;
	sf::Texture teksture;
	sf::Vector2f speed;
	int timee;
	float rotation;
};
