#ifndef SDL_GAME_ENGINE__SPRITE_H
#define SDL_GAME_ENGINE__SPRITE_H

// SDL
#include "SDL.h"

// Engine
class SpriteManager; // Forward declaration, acts like including the header

class Sprite
{
public:
	SpriteManager* spriteManager;
	int x;
	int y;

	Sprite(SpriteManager* spriteManager, SDL_Surface* image);
	void draw(SDL_Surface* screen);

private:
	SDL_Surface* _image;
};

#endif