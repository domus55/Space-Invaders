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
	text2.setFillColor(sf::Color::White);

	/*sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);*/

	text.setCharacterSize(10);
	text.setPosition(700, 880);
	text.setLetterSpacing(10);
	text.setString("SPACE INVADERS");

	text2.setCharacterSize(10);
	text2.setFillColor(sf::Color(255, 255, 255, 200));
	text2.setPosition(10, 880);
	text2.setString("version 0.1");
}

void GameVersion::render()
{
	Window::window.draw(text);
	Window::window.draw(text2);
}
