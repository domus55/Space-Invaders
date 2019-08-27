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
	case 11: level11(); break;
	case 12: level12(); break;
	case 13: level13(); break;
	case 14: level14(); break;
	case 15: level15(); break;
	case 16: level16(); break;
	case 17: level17(); break;
	case 18: level18(); break;
	case 19: level19(); break;
	case 20: level20(); break;
	case 21: level21(); break;
	case 22: level22(); break;
	case 23: level23(); break;
	case 24: level24(); break;
	case 25: level25(); break;
	case 26: level26(); break;
	case 27: level27(); break;
	case 28: level28(); break;
	case 29: level29(); break;
	case 30: level30(); break;
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
	for (int i = 0; i < 4; i++)
	{
		EnemyMedium::create(i * 300 + 325, -100, 1, 0);
	}
}

void LevelManager::level8()
{
	for (int i = 0; i < 2; i++)
	{
		EnemyMedium::create(i * 600 + 475, -225, 1, 1);
	}

	for (int i = 0; i < 4; i++)
	{
		EnemyEasy::create(i * 300 + 325, -200, 2, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		EnemyEasy::create(i * 300 + 325, -100, 2, 0);
	}
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
	BossBrown::create(800, -200);
}

void LevelManager::level11()
{
	for (int i = 0; i < 3; i++)
	{
		EnemyTank::create(i * 300 + 500, -200, 1, 0);
	}
}

void LevelManager::level12()
{
	EnemyTank::create(-500, 400, 1, 0);
	EnemyTank::create(-200, 400, 1, 0);
	EnemyTank::create(1800, 400, 1, 1);
	EnemyTank::create(2100, 400, 1, 1);

	for (int i = 0; i < 6; i++)
	{
		EnemyEasy::create(i * 250 + 175, -450, 1, 2);
	}
}

void LevelManager::level13()
{
	for (int i = 0; i < 4; i++)
	{
		EnemyEasy::create(-i * 200 - 200, 100, 3, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		EnemyEasy::create(i * 200 + 1800, 200, 3, 1);
	}

	for (int i = 0; i < 4; i++)
	{
		EnemyEasy::create(-i * 200 - 200, 300, 3, 0);
	}
}

void LevelManager::level14()
{
	EnemyMedium::create(-500, 400, 1, 0);
	EnemyMedium::create(-200, 400, 1, 0);
	EnemyMedium::create(1800, 400, 1, 1);
	EnemyMedium::create(2100, 400, 1, 1);

	for (int i = 0; i < 3; i++)
	{
		EnemyFast::create(i * 300 + 500, -1000, 1, 2);
	}
}

void LevelManager::level15()
{
	for (int i = 0; i < 4; i++)
	{
		EnemyFast::create(i * 200 + 500, -1000, 3, 0);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyMedium::create(-i * 250 - 200, 250, 3, 1);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyMedium::create(i * 250 + 1800, 250, 3, 2);
	}
}

void LevelManager::level16()
{
	for (int i = 0; i < 2; i++)
	{
		EnemyEasy::create(i * 600 + 475, -575, 3, 1);
	}

	for (int i = 0; i < 4; i++)
	{
		EnemyMedium::create(i * 300 + 325, -300, 2, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		EnemyTank::create(i * 300 + 325, -100, 1, 0);
	}
}

void LevelManager::level17()
{
	EnemyMedium::create(-500, 400, 2, 0);
	EnemyMedium::create(-200, 400, 2, 0);
	EnemyMedium::create(1800, 400, 2, 1);
	EnemyMedium::create(2100, 400, 2, 1);

	for (int i = 0; i < 5; i++)
	{
		EnemyFast::create(i * 300 + 200, -500, 1, 2);
	}
}

void LevelManager::level18()
{
	EnemyTank::create(-500, 400, 2, 0);
	EnemyTank::create(-200, 400, 1, 0);
	EnemyTank::create(1800, 400, 1, 1);
	EnemyTank::create(2100, 400, 2, 1);

	for (int i = 0; i < 8; i++)
	{
		EnemyEasy::create(i * 180 + 175, -450, 3, 2);
	}
}

void LevelManager::level19()
{
	for (int i = 0; i < 4; i++)
	{
		EnemyFast::create(i * 200 + 500, -1000, 3, 0);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyMedium::create(-i * 250 - 200, 250, 3, 1);
	}

	for (int i = 0; i < 2; i++)
	{
		EnemyTank::create(-i * 400 - 200, 500, 3, 2);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyMedium::create(i * 250 + 1800, 250, 3, 3);
	}

	for (int i = 0; i < 2; i++)
	{
		EnemyTank::create(i * 400 + 1800, 500, 3, 4);
	}
}

void LevelManager::level20()
{
	//for (int i = 0; i < 3; i++)
	//{
		EnemyFidgetSpinner::create(1 * 300 + 500, 100, 3);
		//EnemyEasy::create(1 * 300 + 500, 100, 1);
	//}
}

void LevelManager::level21()
{
}

void LevelManager::level22()
{
	EnemyMedium::create(-600, 400, 3, 0);
	EnemyMedium::create(-400, 400, 3, 0);
	EnemyMedium::create(-200, 400, 3, 0);
	EnemyMedium::create(1800, 400, 3, 1);
	EnemyMedium::create(2000, 400, 3, 1);
	EnemyMedium::create(2200, 400, 3, 1);

	for (int i = 0; i < 5; i++)
	{
		EnemyFast::create(i * 300 + 200, -500, 2, 2);
	}
}

void LevelManager::level23()
{
}

void LevelManager::level24()
{
	for (int i = 0; i < 4; i++)
	{
		EnemyMedium::create(-i * 200 - 200, 100, 3, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		EnemyMedium::create(i * 200 + 1800, 200, 3, 1);
	}

	for (int i = 0; i < 4; i++)
	{
		EnemyMedium::create(-i * 200 - 200, 300, 3, 0);
	}
}

void LevelManager::level25()
{
}

void LevelManager::level26()
{
}

void LevelManager::level27()
{
}

void LevelManager::level28()
{
}

void LevelManager::level29()
{
}

void LevelManager::level30()
{
}
