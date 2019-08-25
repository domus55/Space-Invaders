#include "Music.h"

sf::Music Music::backgroundMusic;

void Music::playMusic()
{
	backgroundMusic.openFromFile("Sounds/backgroundMusic.ogg");
	backgroundMusic.play();
	backgroundMusic.setLoop(1);
}
