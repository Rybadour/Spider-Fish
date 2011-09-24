#ifndef SDL_GAME_ENGINE__GAME_H
#define SDL_GAME_ENGINE__GAME_H

// SDL
#include "SDL.h"

// C++
#include <string>

// Engine
#include "SpriteManager.h"

const int SCREEN_BPP = 32;

class Game
{
public:
	SpriteManager* spriteManager;

	Game();
	bool start(std::string title, int width, int height);


private:
	SDL_Surface*	_screen;
	SDL_Event		_eventManager;

	bool _quit;

	bool initialize(std::string title, int width, int height);
	void cleanup();
};

#endif