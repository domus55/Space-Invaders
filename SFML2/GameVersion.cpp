#include "GameVersion.h"

sf::Text GameVersion::text;
sf::Text GameVersion::text2;
sf::Font GameVersion::font;

void GameVersion::create()
{
	font.loadFromFile("Images/Arial.ttf");
	text.setFont(font);
	text2.setFont(font);

	text.setFillColor(sf::Color::White);
	text2.setFillColor(sf::Color(255, 255, 255, 100));

	text.setCharacterSize(10);
	text.setPosition(10, 880);
	text.setLetterSpacing(10);
	text.setString("SPACE INVADERS");

	text2.setCharacterSize(10);
	text2.setPosition(10, 870);
	text2.setString("version 1.0.2");
}

void GameVersion::render()
{
	Window::window.draw(text);
	Window::window.draw(text2);
}
