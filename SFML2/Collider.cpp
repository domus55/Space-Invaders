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
}

bool Collider::checkCollision(sf::Sprite sprite, sf::RectangleShape sprite2)
{
	sf::Vector2u size1;
	size1 = sprite.getTexture()->getSize();
	size1.x = size1.x * sprite.getScale().x;
	size1.y = size1.y * sprite.getScale().y;

	sf::Vector2f position1;
	position1 = sprite.getPosition();

	sf::Vector2f size2;
	size2 = sprite2.getSize();
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
}

bool Collider::checkCollision(sf::RectangleShape sprite, sf::RectangleShape sprite2)
{
	sf::Vector2f size1;
	size1 = sprite.getSize();
	size1.x = size1.x * sprite.getScale().x;
	size1.y = size1.y * sprite.getScale().y;

	sf::Vector2f position1;
	position1 = sprite.getPosition();

	sf::Vector2f size2;
	size2 = sprite2.getSize();
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
}

bool Collider::checkCollision(sf::RectangleShape sprite, sf::CircleShape circle)
{
	float rw = sprite.getSize().x * sprite.getScale().x;
	float rh = sprite.getSize().y * sprite.getScale().y;

	float cx = circle.getPosition().x;
	float cy = circle.getPosition().y;

	float rx = sprite.getPosition().x - rw / 2;
	float ry = sprite.getPosition().y - rh / 2;

	float testX = cx;
	float testY = cy;

	// which edge is closest?
	if (cx < rx)         testX = rx;      // test left edge
	else if (cx > rx + rw) testX = rx + rw;   // right edge
	if (cy < ry)         testY = ry;      // top edge
	else if (cy > ry + rh) testY = ry + rh;   // bottom edge

	// get distance from closest edges
	float distX = cx - testX;
	float distY = cy - testY;
	float distance = sqrt((distX*distX) + (distY*distY));

	// if the distance is less than the radius, collision!
	if (distance <= circle.getRadius() * circle.getScale().x) {
		return true;
	}
	return false;
}

bool Collider::checkCollision(sf::Sprite sprite, sf::CircleShape circle)
{
	float rw = sprite.getTexture()->getSize().x * sprite.getScale().x;
	float rh = sprite.getTexture()->getSize().y * sprite.getScale().y;

	float cx = circle.getPosition().x;
	float cy = circle.getPosition().y;

	float rx = sprite.getPosition().x - rw / 2;
	float ry = sprite.getPosition().y - rh / 2;

	float testX = cx;
	float testY = cy;

	// which edge is closest?
	if (cx < rx)         testX = rx;      // test left edge
	else if (cx > rx + rw) testX = rx + rw;   // right edge
	if (cy < ry)         testY = ry;      // top edge
	else if (cy > ry + rh) testY = ry + rh;   // bottom edge

	// get distance from closest edges
	float distX = cx - testX;
	float distY = cy - testY;
	float distance = sqrt((distX*distX) + (distY*distY));

	// if the distance is less than the radius, collision!
	if (distance <= circle.getRadius() * circle.getScale().x) {
		return true;
	}
	return false;
}

bool Collider::checkCollision(sf::CircleShape circle1, sf::CircleShape circle2)
{
	float distanceX = abs(circle1.getPosition().x - circle2.getPosition().x);
	float distanceY = abs(circle1.getPosition().y - circle2.getPosition().y);

	float straightDistance = sqrt(powf(distanceX, 2) + powf(distanceY, 2));
	if (straightDistance - circle1.getRadius()* circle1.getScale().x - circle2.getRadius()* circle2.getScale().x > 0) return false;
	else return true;
}
