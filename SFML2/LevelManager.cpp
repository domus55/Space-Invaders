#include "LevelManager.h"

int LevelManager::actualLevel = 0;
bool LevelManager::animation = false;
sf::Text LevelManager::text;
sf::Font LevelManager::font;

void LevelManager::create()
{
	font.loadFromFile("Images/arial.ttf");
	text.setFont(font);
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::White);
	text.setPosition(800, 425);
	text.setStyle(sf::Text::Bold);
}

void LevelManager::update()
{
	if (BasicEnemy::enemy.size() == 0) animation = true;
	else animation = false;
}

void LevelManager::render()
{
	if (animation)
	{
		static std::string tekst;
		static int deltaTime = 0;
		if (deltaTime == 0)
		{
			LevelManager::actualLevel++;
			tekst = "Level ";
			tekst += std::to_string(actualLevel);
			text.setString(tekst);

			sf::FloatRect textRect = text.getLocalBounds();
			text.setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);

			deltaTime = 1;
		}
		deltaTime += GameInfo::getDeltaTime();
		
		if(deltaTime <= 765)text.setFillColor(sf::Color(255, 255, 255, deltaTime / 3));
		else text.setFillColor(sf::Color(255, 255, 255, 255));

		Window::window.draw(text);


		if (deltaTime > 1500)
		{
			Animation::restart();
			deltaTime = 0;
			nextLevel();
		}
	}
}

void LevelManager::nextLevel()
{
	switch (actualLevel)
	{
	case 1: level1(); break;
	case 2: level2(); break;
	}
}

void LevelManager::level1()
{
	for (int i = 0; i < 3; i++)
	{
		EnemyEasy::create(i * 300 + 500, 100, 1);
	}
}

void LevelManager::level2()
{
	for (int i = 0; i < 4; i++)
	{
		EnemyEasy::create(i * 300 + 325, -100, 1, 0);
	}
}

