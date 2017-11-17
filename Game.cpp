#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL Initialized!" << endl;

		// create window
		this->window = SDL_CreateWindow("Game Title", xpos, ypos, width, height, flags);

		if (window) // window successfully made
		{
			cout << "Window successfully created!" << endl;
		}
		else
		{
			cout << "Could not create window: " << SDL_GetError() << endl;
		}

		// create renderer
		this->renderer = SDL_CreateRenderer(window, -1, 0);

		if (this->renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Renderer successfully created!" << endl;
		}
		else
		{
			cout << "Could not create renderer: " << SDL_GetError() << endl;
		}

		this->running = true;
	}
	else 
	{
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
		this->running = false;
	}

	SDL_Surface *tempSurface = IMG_Load("assets/turtle2.png");
	playerTexture = SDL_CreateTextureFromSurface(this->renderer, tempSurface);
	SDL_FreeSurface(tempSurface);


}

void Game::update()
{
	
}

void Game::render()
{
	SDL_RenderClear(this->renderer);
	// this is where we would add stuff to render
	SDL_RenderCopy(this->renderer, playerTexture, NULL, NULL);
	SDL_RenderPresent(this->renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();

	cout << "Game cleaned." << endl;
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		this->running = false;
		break;

	default:
		break;
	}
}

bool Game::isRunning()
{
	return this->running;
}
