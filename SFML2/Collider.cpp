#include "Collider.h"

bool Collider::checkCollision(sf::Sprite sprite, sf::Sprite sprite2)
{
	sf::Vector2u size1;
	size1 = sprite.getTexture()->getSize();
	size1.x = size1.x * sprite.getScale().x;
	size1.y = size1.y * sprite.getScale().y;

	sf::Vector2f position1;
	position1 = sprite.getPosition();

	sf::Vector2u size2;
	size2 = sprite2.getTexture()->getSize();
	size2.x = size2.x * sprite2.getScale().x;
	size2.y = size2.y * sprite2.getScale().y;

	sf::Vector2f position2;
	position2 = sprite2.getPosition();



	sf::Vector2f otherHalfSize;
	otherHalfSize.x = 0.5*size2.x;
	otherHalfSize.y = 0.5*size2.y;

	float deltaX = position2.x - position1.x;
	float deltaY = position2.y - position1.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + size1.x / 2);
	float intersectY = abs(deltaY) - (otherHalfSize.y + size1.y / 2);

	sf::Vector2f changePosition;
	changePosition.x = 0.0f;
	changePosition.y = 0.0f;

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		return true;
	}
	return false;

	//std::cout << "size.x: " << size.x << "    size.y" << size.y << std::endl;
}
