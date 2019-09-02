#include "ClosingCredits.h"

float ClosingCredits::time;
sf::Font ClosingCredits::headerFont;
sf::Font ClosingCredits::font;
sf::Text ClosingCredits::gameName;
sf::Text ClosingCredits::thanks;
sf::Text ClosingCredits::authors;
sf::Text ClosingCredits::authorsNames;
sf::RectangleShape ClosingCredits::background;

void ClosingCredits::create()
{
	time = 0;

	background.setSize(sf::Vector2f(2000, 2000));
	background.setFillColor(sf::Color(0, 0, 0, 0));

	headerFont.loadFromFile("Fonts/Roboto-Black.ttf");
	font.loadFromFile("Images/Arial.ttf");

	gameName.setFont(headerFont);
	gameName.setCharacterSize(40);
	gameName.setLetterSpacing(4);
	gameName.setFillColor(sf::Color(255, 255, 255, 0));
	gameName.setString("SPACE INVADERS");

	thanks.setFont(font);
	thanks.setCharacterSize(24);
	thanks.setFillColor(sf::Color(255, 255, 255, 0));
	thanks.setString("Thank you for finishing the game.");

	authors.setFont(font);
	authors.setCharacterSize(24);
	authors.setLetterSpacing(4);
	authors.setFillColor(sf::Color(255, 255, 255));
	authors.setString("AUTHORS");

	authorsNames.setFont(font);
	authorsNames.setCharacterSize(18);
	authorsNames.setFillColor(sf::Color(255, 255, 255, 255));
	authorsNames.setString("Dominik Palenik\nKamil Palenik");

	sf::FloatRect textRect = gameName.getLocalBounds();
	gameName.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	gameName.setPosition(sf::Vector2f(1600 / 2.0f, 450));

	sf::FloatRect textRect2 = thanks.getLocalBounds();
	thanks.setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top + textRect2.height / 2.0f);
	thanks.setPosition(sf::Vector2f(1600 / 2.0f,  475));

	sf::FloatRect authorsRect = authors.getLocalBounds();
	authors.setOrigin(authorsRect.left + authorsRect.width / 2.0f, authorsRect.top + authorsRect.height / 2.0f);
	authors.setPosition(1600 / 2.0f, 1000);

	sf::FloatRect authorsNamesRect = authorsNames.getLocalBounds();
	authorsNames.setOrigin(authorsNamesRect.left + authorsNamesRect.width / 2.0f, authorsNamesRect.top + authorsNamesRect.height / 2.0f);
	authorsNames.setPosition(1600 / 2.0f, 1050);
}

bool ClosingCredits::render()
{
	if (LevelManager::actualLevel == 51)
	{
		static bool firstTime = true;

		static clock_t prevTime = clock();
		if (clock() - prevTime > 5000)
		{
			firstTime = true;
		}
		prevTime = clock();

		time += GameInfo::getDeltaTime();
		backgroundTransition();
		Window::window.draw(background);
		Window::window.draw(gameName);
		Window::window.draw(thanks);
		Window::window.draw(authors);
		Window::window.draw(authorsNames);
		textTransition();
		Music::backgroundMusic.setVolume((-time+22000) / 220);
		if (time > 22000) return true;
	}
	return false;
}

void ClosingCredits::textTransition()
{
	if (time > 4000 && time < 6040) gameName.setFillColor(sf::Color(255, 255, 255, (time - 4000) / 8));
	if (time > 6040 && time < 6290) gameName.setPosition(800, (-time + 6040) / 10 + 450);
	if (time > 6290 && time < 7290) thanks.setFillColor(sf::Color(255, 255, 255, (time - 6290) / 5));

	sf::Vector2f pos = authors.getPosition();

	if (time > 10000 && pos.y > 450)
	{
		gameName.setPosition(800, (-time + 10000) / 10 + 425);
		thanks.setPosition(800, (-time + 10000) / 10 + 475);
		authors.setPosition(800, (-time + 10000) / 10 + 1000);
		authorsNames.setPosition(800, (-time + 10000) / 10 + 1050);
	}

	if (time > 20000 && time < 20255) authors.setFillColor(sf::Color(255, 255, 255, (-time + 20000) + 255));
	if (time > 20000 && time < 20255) authorsNames.setFillColor(sf::Color(255, 255, 255, (-time + 20000) + 255));
	if (time > 20255 && time < 21000) authors.setFillColor(sf::Color(255, 255, 255, 0));
	if (time > 20255 && time < 21000) authorsNames.setFillColor(sf::Color(255, 255, 255, 0));
}

void ClosingCredits::backgroundTransition()
{
	if (time > 999 && time < 3551) background.setFillColor(sf::Color(0, 0, 0, (time - 999) / 10));
	if (time > 3551 && time < 4000) background.setFillColor(sf::Color(0, 0, 0, 255));
}
