#ifndef SDL_GAME_ENGINE__SPRITE_H
#define SDL_GAME_ENGINE__SPRITE_H

// SDL
#include "SDL.h"

// Engine
#include "Types.h"
class SpriteManager; // Forward declaration, acts like including the header

class Sprite
{
public:
    friend class SpriteManager;

	SpriteManager* spriteManager;
	int x;
	int y;

	Sprite(uint id, SpriteManager* spriteManager, SDL_Surface* image);
	void draw(SDL_Surface* screen);

private:
    uint id_;
	SDL_Surface* _image;
};

#endif