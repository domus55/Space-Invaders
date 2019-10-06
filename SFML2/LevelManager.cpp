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
	if (actualLevel > 51) actualLevel = 51;
	if (BasicEnemy::enemy.size() == 0 && actualLevel != 51) animation = true;
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

			for (int i = Explosion::explosion.size() - 1; i >= 0; i--)
			{
				Explosion::explosion[i]->destroyed = true;
			}
			
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
	case 31: level31(); break;
	case 32: level32(); break;
	case 33: level33(); break;
	case 34: level34(); break;
	case 35: level35(); break;
	case 36: level36(); break;
	case 37: level37(); break;
	case 38: level38(); break;
	case 39: level39(); break;
	case 40: level40(); break;
	case 41: level41(); break;
	case 42: level42(); break;
	case 43: level43(); break;
	case 44: level44(); break;
	case 45: level45(); break;
	case 46: level46(); break;
	case 47: level47(); break;
	case 48: level48(); break;
	case 49: level49(); break;
	case 50: level50(); break;
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
	BossBrown::create(800, -250, 1, 1);
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
		EnemyTank::create(-i * 400 - 200, 500, 2, 2);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyMedium::create(i * 250 + 1800, 250, 3, 3);
	}

	for (int i = 0; i < 2; i++)
	{
		EnemyTank::create(i * 400 + 1800, 500, 2, 4);
	}
}

void LevelManager::level20()
{
	BossBlack::create(800, -250, 1, 1);
}

void LevelManager::level21()
{
	EnemyFidgetSpinner::create(800, -300, 2, 0);
	EnemyTank::create(800, -100, 2, 0);
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
	for (int i = 0; i < 6; i++)
	{
		EnemyInvisible::create(i * 250 + 175, 200, 1);
	}
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
	BossBrown::create(800, -250, 2, 0);

	for (int i = 0; i < 3; i++)
	{
		EnemyMedium::create(-i * 250 - 200, 450, 3, 1);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyMedium::create(i * 250 + 1800, 450, 3, 2);
	}
}

void LevelManager::level26()
{
	for (int i = 0; i < 6; i++)
	{
		EnemyInvisible::create(i * 250 + 175, -200, 1, 0);
	}

	for (int i = 0; i < 6; i++)
	{
		EnemyInvisible::create(i * 250 + 175, -400, 2, 1);
	}
}

void LevelManager::level27()
{
	for (int i = 0; i < 2; i++)
	{
		EnemyFidgetSpinner::create(i * 600 + 500, -600, 1, 0);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyTank::create(-i * 250 - 200, 350, 2, 1);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyTank::create(i * 250 + 1800, 350, 2, 2);
	}
}

void LevelManager::level28()
{
	EnemyRocketMan::create(800, -350, 1, 0);
	EnemyTank::create(800, -100, 3, 0);
}

void LevelManager::level29()
{
	for (int i = 0; i < 6; i++)
	{
		EnemyInvisible::create(i * 250 + 175, -200, 2, 0);
	}

	for (int i = 0; i < 6; i++)
	{
		EnemyInvisible::create(i * 250 + 175, -400, 3, 1);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyMedium::create(-i * 250 - 200, 450, 3, 3);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyMedium::create(i * 250 + 1800, 450, 3, 2);
	}
}

void LevelManager::level30()
{
	BossGold::create(800, -250, 1, 1);
}

void LevelManager::level31()
{
	EnemyTrackingShots::create(800, -350, 1, 0);
	EnemyTank::create(800, -100, 3, 0);
}

void LevelManager::level32()
{
	EnemyFidgetSpinner::create(200, -400, 1, 4);
	EnemyFidgetSpinner::create(1400, -400, 1, 4);

	for (int i = 0; i < 6; i++)
	{
		EnemyInvisible::create(i * 250 + 175, -200, 2, 0);
	}

	for (int i = 0; i < 6; i++)
	{
		EnemyInvisible::create(i * 250 + 175, -400, 2, 1);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyTank::create(-i * 250 - 200, 450, 1, 3);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyTank::create(i * 250 + 1800, 450, 1, 2);
	}
}

void LevelManager::level33()
{
	EnemyRocketMan::create(700, -500, 3, 1);
	EnemyRocketMan::create(900, -500, 3, 1);

	EnemyTank::create(700, -200, 3, 1);
	EnemyTank::create(900, -200, 3, 1);

	EnemyFidgetSpinner::create(300, -300, 3, 1);
	EnemyFidgetSpinner::create(1300, -300, 3, 1);
}

void LevelManager::level34()
{
	for (int i = 0; i < 6; i++)
	{
		EnemyTank::create(i * 250 + 175, -150, 2, 2);
	}

	for (int i = 0; i < 6; i++)
	{
		EnemyFast::create(-i * 150 - 1600, 50, 3, 0);
	}

	for (int i = 0; i < 6; i++)
	{
		EnemyFast::create(i * 150 + 3200, 125, 3, 1);
	}

	for (int i = 0; i < 6; i++)
	{
		EnemyFast::create(-i * 150 - 1600, 200, 3, 3);
	}
}

void LevelManager::level35()
{
	EnemyRocketMan::create(300, -550, 2, 1);
	EnemyRocketMan::create(1300, -550, 2, 1);
	BossBlack::create(800, -250, 2, 1);
}

void LevelManager::level36()
{
	for (int i = 0; i < 3; i++)
	{
		EnemyRocketMan::create(i * 500 + 300, -300, 2, 0);
		EnemyTank::create(i * 500 + 300, -100, 1, 0);
	}
}

void LevelManager::level37()
{
	for (int i = 0; i < 6; i++)
	{
		EnemyTrackingShots::create(i * 250 + 175, -300, 1, 1);
		EnemyMedium::create(i * 250 + 175, -100, 3, 1);
	}
}

void LevelManager::level38()
{
	EnemyTrackingShots::create(-200, 100, 1, 1);
	EnemyTrackingShots::create(1800, 100, 1, 2);

	for (int i = 0; i < 2; i++)
	{
		EnemyTank::create(-i * 400 - 200, 600, 2, 3);
	}

	for (int i = 0; i < 2; i++)
	{
		EnemyTank::create(-i * 400 - 200, 300, 2, 3);
	}

	for (int i = 0; i < 2; i++)
	{
		EnemyTank::create(i * 400 + 1800, 600, 2, 4);
	}

	for (int i = 0; i < 2; i++)
	{
		EnemyTank::create(i * 400 + 1800, 300, 2, 4);
	}
}

void LevelManager::level39()
{
	for (int i = 0; i < 4; i++)
	{
		EnemyFidgetSpinner::create(i * 300 + 325, -300, 2, 1);
		EnemyTank::create(i * 300 + 325, -100, 2, 1);
	}
}

void LevelManager::level40()
{
	BossBlue::create(800, -250, 1);
}

void LevelManager::level41()
{
	EnemyTrackingShots::create(200, -400, 1, 4);
	EnemyTrackingShots::create(1400, -400, 1, 4);

	for (int i = 0; i < 6; i++)
	{
		EnemyInvisible::create(i * 250 + 175, -200, 3, 0);
	}

	for (int i = 0; i < 6; i++)
	{
		EnemyInvisible::create(i * 250 + 175, -400, 3, 1);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyTank::create(-i * 250 - 200, 450, 2, 3);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyTank::create(i * 250 + 1800, 450, 2, 2);
	}
}

void LevelManager::level42()
{
	EnemyTrackingShots::create(-300, 150, 2, 1);
	EnemyTrackingShots::create(1900, 150, 2, 2);


	EnemyTank::create(-200, 350, 3, 3);
	EnemyTank::create(1800, 350, 3, 4);
}

void LevelManager::level43()
{
	EnemyFidgetSpinner::create(300, -350, 3, 0);
	EnemyTank::create(300, -100, 3, 0);

	EnemyFidgetSpinner::create(1300, -350, 3, 0);
	EnemyTank::create(1300, -100, 3, 0);
}

void LevelManager::level44()
{
	for (int i = 0; i < 4; i++)
	{
		EnemyRocketMan::create(i * 400 + 200, -300, 3, 0);
		EnemyTank::create(i * 400 + 200, -100, 2, 0);
	}
}

void LevelManager::level45()
{
	EnemyRocketMan::create(300, -550, 3, 1);
	EnemyRocketMan::create(1300, -550, 3, 1);
	BossGold::create(800, -250, 2, 1);
}

void LevelManager::level46()
{
	EnemyTrackingShots::create(800, -300, 3, 0);
	EnemyTank::create(800, -100, 3, 0);

	EnemyTrackingShots::create(-200, 150, 2, 1);
	EnemyTrackingShots::create(1800, 150, 2, 2);


	EnemyTank::create(-200, 350, 3, 3);
	EnemyTank::create(1800, 350, 3, 4);

}

void LevelManager::level47()
{
	for (int i = 0; i < 6; i++)
	{
		EnemyFast::create(-i * 150 - 1600, 50, 3, 0);
	}

	for (int i = 0; i < 6; i++)
	{
		EnemyFast::create(i * 150 + 3200, 125, 3, 1);
	}

	for (int i = 0; i < 4; i++)
	{
		EnemyTank::create(-i * 225 - 200, 300, 3, 2);
	}

	for (int i = 0; i < 4; i++)
	{
		EnemyTank::create(i * 225 + 1800, 500, 3, 3);
	}
}

void LevelManager::level48()
{
	EnemyFidgetSpinner::create(300, -400, 100, 0);
	EnemyFidgetSpinner::create(800, -400, 2, 0);
	EnemyFidgetSpinner::create(1300, -400, 100, 0);

	for (int i = 0; i < 6; i++)
	{
		EnemyTank::create(i * 300 + 50, -100, 3, 0);
	}
}

void LevelManager::level49()
{
	EnemyFidgetSpinner::create(800, -800, 100, 0);

	EnemyTrackingShots::create(-400, 150, 1, 1);
	EnemyTrackingShots::create(2000, 150, 1, 2);

	for (int i = 0; i < 3; i++)
	{
		EnemyTank::create(-i * 300 - 200, 600, 3, 3);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyTank::create(-i * 300 - 200, 400, 3, 3);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyTank::create(i * 300 + 1800, 600, 3, 4);
	}

	for (int i = 0; i < 3; i++)
	{
		EnemyTank::create(i * 300 + 1800, 400, 3, 4);
	}
}

void LevelManager::level50()
{
	BossWhite::create(800, -300, 1);
	EnemyFidgetSpinner::create(300, -600, 99, 1);
	EnemyFidgetSpinner::create(1300, -600, 99, 1);
}
