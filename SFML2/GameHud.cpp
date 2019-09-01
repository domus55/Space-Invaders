#include "GameHud.h"

sf::Font GameHud::font;
sf::Text GameHud::text;
int GameHud::shootDelay;
int GameHud::shootSpeed;
int GameHud::shootAmmount;
int GameHud::sizeDown;

std::string shootDelayString;
std::string shootSpeedString;
std::string shootAmmountString;
std::string sizeDownString;

void GameHud::create()
{
	font.loadFromFile("Images/Arial.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color(255, 255, 255, 255));
	text.setPosition(10, 750);
	text.setCharacterSize(13);
	text.setLetterSpacing(2);
	text.setLineSpacing(1.2);

	shootDelay = 0;
	shootSpeed = 0;
	shootAmmount = 0;
	sizeDown = 0;

	shootDelayString = "0";
	shootSpeedString = "0";
	shootAmmountString = "0";
	sizeDownString = "0";

	hud();
}

void GameHud::render()
{
	Window::window.draw(text);
}

void GameHud::hud()
{
	text.setString("Shoot delay: " + shootDelayString + " LVL" + "\n" + "Shoot speed: " + shootSpeedString + " LVL" + "\n" +
		"Shoot ammount: " + shootAmmountString + " LVL" + "\n" + "Size down: " + sizeDownString + " LVL");
}

void GameHud::shootDelayLevel()
{
	shootDelay = shootDelay + 1;
	shootDelayString = std::to_string(shootDelay);
	hud();
}

void GameHud::shootSpeedLevel()
{
	shootSpeed = shootSpeed + 1;
	shootSpeedString = std::to_string(shootSpeed);
	hud();
}

void GameHud::shootAmmountLevel()
{
	shootAmmount = shootAmmount + 1;
	shootAmmountString = std::to_string(shootAmmount);
	hud();
}

void GameHud::sizeDownLevel()
{
	sizeDown = sizeDown + 1;
	sizeDownString = std::to_string(sizeDown);
	hud();
}

void GameHud::resetHud()
{
	shootDelay = 0;
	shootSpeed = 0;
	shootAmmount = 0;
	sizeDown = 0;
	shootDelayString = std::to_string(shootDelay);
	shootSpeedString = std::to_string(shootSpeed);
	shootAmmountString = std::to_string(shootAmmount);
	sizeDownString = std::to_string(sizeDown);
	hud();
}