#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using std::cout;
using std::endl;

class Game
{
public:
	Game();
	~Game();

	void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen); // initializes game window
	void update(); // updates object locations
	void render(); // puts changes on screen
	void clean();
	void handleEvents();

	bool isRunning();

	SDL_Texture *playerTexture;
private:
	bool running;
	SDL_Window *window;
	SDL_Renderer *renderer;

};

#endif