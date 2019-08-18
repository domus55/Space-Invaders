#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Collider
{
public:
	static bool checkCollision(sf::Sprite sprite, sf::Sprite sprite2);
};