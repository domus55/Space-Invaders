#include "Game.h"

Game *game = nullptr;

int main()
{
	game = new Game;

	while (game->isRunning)
	{
		game->update();
		game->output();
		game->exit();
		game->wait();
	}
	delete game;

	return 0;
}