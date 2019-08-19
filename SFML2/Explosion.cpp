#include "Explosion.h"

int Explosion::animation = -1;
std::vector < std::shared_ptr <Explosion> > Explosion::explosion;

Explosion::Explosion(float x, float y)
{
	texture.loadFromFile("Images/explosion/explosion11.png");
	sprite.setTexture(texture);
	sf::Vector2u size = texture.getSize();
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(x, y);
}

void Explosion::create(float x, float y)
{
	Explosion::explosion.push_back(std::make_shared <Explosion>(x, y));
}

void Explosion::renderAll()
{
	for (int i = Explosion::explosion.size() - 1; i >= 0; i--)
	{
		Explosion::explosion[i]->render();
	}
}

void Explosion::render()
{
	Window::window.draw(sprite);
}
