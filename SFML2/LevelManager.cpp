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
	case 3: level3(); break;
	case 4: level4(); break;
	case 5: level5(); break;
	case 6: level6(); break;
	case 7: level7(); break;
	case 8: level8(); break;
	case 9: level9(); break;
	case 10: level10(); break;
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
		EnemyMedium::create(i * 300 + 325, -100, 1, 0);
	}
}

void LevelManager::level3()
{
	for (int i = 0; i < 6; i++)
	{
		EnemyEasy::create(i * 250 + 175, -100, 1, 0);
	}
}

void LevelManager::level4()
{
	for (int i = 0; i < 6; i++)
	{
		EnemyEasy::create(i * 250 + 175, -100, 2, 0);
	}
}

void LevelManager::level5()
{
	for (int i = 0; i < 4; i++)
	{
		EnemyEasy::create(-i * 200 - 200, 100, 2, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		EnemyEasy::create(i * 200 + 1800, 200, 2, 1);
	}
}

void LevelManager::level6()
{
	for (int i = 0; i < 2; i++)
	{
		EnemyEasy::create(i * 600 + 475, -500, 3, 1);
	}

	for (int i = 0; i < 4; i++)
	{
		EnemyEasy::create(i * 300 + 325, -200, 1, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		EnemyEasy::create(i * 300 + 325, -100, 1, 0);
	}
}

void LevelManager::level7()
{
	
}

void LevelManager::level8()
{
	
}

void LevelManager::level9()
{
	for (int i = 0; i < 7; i++)
	{
		EnemyEasy::create(i * 150 + 325, -500, 3, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		EnemyEasy::create(i * 300 + 325, -100, 1, 0);
	}
}

void LevelManager::level10()
{
	
}

