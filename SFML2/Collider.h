#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Collider
{
public:
	static bool checkCollision(sf::Sprite sprite, sf::Sprite sprite2);
	static bool checkCollision(sf::Sprite sprite, sf::RectangleShape sprite2);
	static bool checkCollision(sf::Sprite sprite, sf::CircleShape circle);
};