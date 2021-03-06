#include <iostream>
#include <SDL.h>

using std::cout;
using std::endl;

#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	game = new Game;

	game->init("Title here", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->isRunning())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}