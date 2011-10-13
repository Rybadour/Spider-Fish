#ifndef SDL_GAME_ENGINE__SPRITE_H
#define SDL_GAME_ENGINE__SPRITE_H

// SDL
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include "SDL.h"
#endif

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

private:

	Sprite(uint id, SpriteManager* spriteManager, SDL_Surface* image);
	void draw(SDL_Surface* screen);

	// hide the destructor. only the SpriteManager should be able
	// to free sprites from memory.
	~Sprite();

    uint _id;
	SDL_Surface* _image;
};

#endif